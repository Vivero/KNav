// KNav.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KNav.h"
#include "KNav_Control.h"
#include "KNav_Display.h"
#include "KRPCI.h"
#include "KRPCI_SpaceCenter.h"

using namespace std;

#define KNAV_SLEEP_PERIOD 100

BOOL knavTerminate = FALSE;
SHORT knavKeyState1 = 0, knavKeyState2 = 0;
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

  // setup Display
  hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  KNav_Display knavDisplay(hStdout, knavTelemetry);

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
    //knavKeyState = GetAsyncKeyState(0x51); // Q key
    knavKeyState1 = GetAsyncKeyState(VK_LSHIFT);
    knavKeyState2 = GetAsyncKeyState(VK_ESCAPE);
    if ((knavKeyState1 & 0x8000) && (knavKeyState2 & 0x8000)) {
      printf("KNav terminated by user! \n");
      knavTerminate = TRUE;
      break;
    }

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

