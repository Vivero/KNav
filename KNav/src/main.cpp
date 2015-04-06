// KNav.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KNav_Control.h"
#include "KNav_Display.h"
#include "KRPCI.h"
#include "KRPCI_SpaceCenter.h"

using namespace std;

#define KNAV_SLEEP_PERIOD 80

#define DEFAULT_KRPC_SERVER_IP           "127.0.0.1"
#define DEFAULT_KRPC_SERVER_IP_LEN                9
#define DEFAULT_KRPC_SERVER_PORT             "50000"
#define DEFAULT_KRPC_SERVER_PORT_LEN              5
#define DEFAULT_KRPC_STREAM_PORT             "50001"
#define DEFAULT_KRPC_STREAM_PORT_LEN              5

BOOL knavTerminate = FALSE;
ULONGLONG systemTime_ms = 0, executionTime_ms = 0;
LONGLONG  sleepPeriod = 0;
ULONG execCounts = 0;
double avgExecTime = 0.0;
HANDLE hStdout;

char *krpc_ipAddress;
char *krpc_rpcPort;
char *krpc_streamPort;

HRESULT ParseCmdLine(int &argc, _TCHAR* argv[]);

int _tmain(int argc, _TCHAR* argv[])
{
  // process command line args
  ParseCmdLine(argc, argv);

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
  KNav_Display knavDisplay(hStdout, knavTelemetry, knavControl);
  KNav_Display::UserInput_t &userInput = knavDisplay.GetUserInput();
  BOOL userInputLocked = FALSE;

  cout << endl << "Boot up sequence ... " << endl;
  cout << "Connecting to " << krpc_ipAddress << " ... " << endl;

  // open interface to KRPC
  krpcInterface.Open(krpc_ipAddress);
  cout << "KRPC Version: " << krpcInterface.GetKRPCServerVersion() << endl << endl;

  // initialize KNav Telemetry
  knavTelemetry.Open();

  // main processing loop
  while (!knavTerminate) {
    systemTime_ms = GetTickCount64();

    // get user input
    knavKeyState_Lshift = GetAsyncKeyState(VK_TAB);
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
          userInput.up = (GetAsyncKeyState(VK_NUMPAD8) & 0x8000);
          userInput.down = (GetAsyncKeyState(VK_NUMPAD2) & 0x8000);
          userInput.left = (GetAsyncKeyState(VK_NUMPAD4) & 0x8000);
          userInput.right = (GetAsyncKeyState(VK_NUMPAD6) & 0x8000);
          userInput.enter = (GetAsyncKeyState(VK_ADD) & 0x8000);
          userInput.clear = (GetAsyncKeyState(VK_SUBTRACT) & 0x8000);
          userInput.key0 = (GetAsyncKeyState(VK_NUMPAD0) & 0x8000);
          userInput.key1 = (GetAsyncKeyState(VK_NUMPAD1) & 0x8000);
          userInput.key3 = (GetAsyncKeyState(VK_NUMPAD3) & 0x8000);
          userInput.key5 = (GetAsyncKeyState(VK_NUMPAD5) & 0x8000);
          userInput.key7 = (GetAsyncKeyState(VK_NUMPAD7) & 0x8000);
          userInput.key9 = (GetAsyncKeyState(VK_NUMPAD9) & 0x8000);

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

  delete krpc_ipAddress;
  delete krpc_rpcPort;
  delete krpc_streamPort;

  return 0;
}

HRESULT ParseCmdLine(int &argc, _TCHAR* argv[])
{
  // get command line arguments:
  //   argv[0]     optional: ip address
  //   argv[1]     optional: rpc server port
  //   argv[2]     optional: stream server port
  //
  size_t numCharsConverted = 0;
  size_t argNumChars = 0;
  HRESULT retval = S_OK;

  // parse IP address
  if (argc > 1) {
    argNumChars = wcslen(argv[1]);
    krpc_ipAddress = new char[argNumChars + 1];
    wcstombs_s(&numCharsConverted, krpc_ipAddress, argNumChars + 1, argv[1], _TRUNCATE);
  }
  else {
    krpc_ipAddress = new char[DEFAULT_KRPC_SERVER_IP_LEN + 1];
    _snprintf_s(krpc_ipAddress, DEFAULT_KRPC_SERVER_IP_LEN + 1, _TRUNCATE, DEFAULT_KRPC_SERVER_IP);
  }

  // parse RPC server port
  if (argc > 2) {
    argNumChars = wcslen(argv[2]);
    krpc_rpcPort = new char[argNumChars + 1];
    wcstombs_s(&numCharsConverted, krpc_rpcPort, argNumChars + 1, argv[2], _TRUNCATE);
  }
  else {
    krpc_rpcPort = new char[DEFAULT_KRPC_SERVER_PORT_LEN + 1];
    _snprintf_s(krpc_rpcPort, DEFAULT_KRPC_SERVER_PORT_LEN + 1, _TRUNCATE, DEFAULT_KRPC_SERVER_PORT);
  }

  // parse stream server port
  if (argc > 3) {
    argNumChars = wcslen(argv[3]);
    krpc_streamPort = new char[argNumChars + 1];
    wcstombs_s(&numCharsConverted, krpc_streamPort, argNumChars + 1, argv[3], _TRUNCATE);
  }
  else {
    krpc_streamPort = new char[DEFAULT_KRPC_STREAM_PORT_LEN + 1];
    _snprintf_s(krpc_streamPort, DEFAULT_KRPC_STREAM_PORT_LEN + 1, _TRUNCATE, DEFAULT_KRPC_STREAM_PORT);
  }

  // print out cmd line args
  printf("kRPC Host IP Address      : %s \n", krpc_ipAddress);
  printf("kRPC RPC Server Port      : %s \n", krpc_rpcPort);
  printf("kRPC Stream Server Port   : %s \n", krpc_streamPort);

  return retval;
}
