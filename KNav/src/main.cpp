// KNav.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KNav_Control.h"
#include "KNav_Display.h"
#include "KRPCI.h"
#include "KRPCI_SpaceCenter.h"

using namespace std;

#define KNAV_SLEEP_PERIOD 100

BOOL knavTerminate = FALSE;
ULONGLONG systemTime_ms = 0, executionTime_ms = 0;
LONGLONG  sleepPeriod = 0;
ULONG execCounts = 0;
double avgExecTime = 0.0;
HANDLE hStdout;


int _tmain(int argc, _TCHAR* argv[])
{
  KRPCI& krpcInterface = KRPCI::getInstance();
  
  // setup Telemetry capture
  KNav_Telemetry knavTelemetry;

  // setup Flight Controller
  KNav_Control knavControl(knavTelemetry);

  // setup user input struct
  KNav_Display::UserInput_t  prevInput;
  SHORT knavKeyState_Lshift = 0, knavKeyState = 0;

  // setup Display
  hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  KNav_Display knavDisplay(hStdout, knavTelemetry);
  KNav_Display::UserInput_t &userInput = knavDisplay.GetUserInput();
  BOOL userInputLocked = FALSE;

  cout << endl << "Boot up sequence ... " << endl;

  // get IP address from cmd line
  const int ipAddrBufSize = 16;
  char krpcIpAddress[ipAddrBufSize]; ZeroMemory(krpcIpAddress, ipAddrBufSize);
  if (argc > 1) {
    _snprintf_s(krpcIpAddress, ipAddrBufSize - 1, "%S", argv[1]);
  }
  else {
    _snprintf_s(krpcIpAddress, ipAddrBufSize - 1, "127.0.0.1");
  }
  cout << "Connecting to " << krpcIpAddress << " ... " << endl;

  // open interface to KRPC
  krpcInterface.Open(krpcIpAddress);
  cout << "KRPC Version: " << krpcInterface.GetKRPCServerVersion() << endl << endl;

  // initialize KNav Telemetry
  knavTelemetry.Open();

  // main processing loop
  while (!knavTerminate) {
    systemTime_ms = GetTickCount64();

    // get user input
    knavKeyState_Lshift = GetAsyncKeyState(VK_LSHIFT);
    if (knavKeyState_Lshift & 0x8000)
    {
      // terminate if ESC is pressed
      knavKeyState = GetAsyncKeyState(VK_ESCAPE);
      if (knavKeyState & 0x8000) {
        printf("KNav terminated by user! \n");
        knavTerminate = TRUE;
        break;
      }

      // process other user input keys
      else {
        userInputLocked = knavDisplay.LockUserInput();

        if (userInputLocked) {
          userInput.up = (GetAsyncKeyState(VK_UP) & 0x8000);
          userInput.down = (GetAsyncKeyState(VK_DOWN) & 0x8000);
          userInput.left = (GetAsyncKeyState(VK_LEFT) & 0x8000);
          userInput.right = (GetAsyncKeyState(VK_RIGHT) & 0x8000);

          if (prevInput != userInput) {
            userInput.latched = TRUE;
          }

          prevInput.copy(userInput);
          knavDisplay.UnlockUserInput();
        } // userInputLocked
      } // escape pressed
    } // shift pressed

    
    //knavKeyState = GetAsyncKeyState(0x51); // Q key
    

    // render display
    knavDisplay.Display();

    // execute controls
    knavControl.Control();


    // calculate sleep period
    executionTime_ms = GetTickCount64() - systemTime_ms;
    sleepPeriod = KNAV_SLEEP_PERIOD - executionTime_ms;
    if (sleepPeriod > 0) {
      Sleep(sleepPeriod);
    }

  }

  // close Telemetry
  knavTelemetry.Close();

  // close interface to KRPC
  krpcInterface.Close();

  // reset console
  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

  return 0;
}

