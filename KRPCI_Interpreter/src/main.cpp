// KNav.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KRPCI.h"
#include "KRPCI_Interpreter.h"

#define SLEEP_PERIOD 100

BOOL knavTerminate = false;
SHORT knavKeyState = 0;

int _tmain(int argc, _TCHAR* argv[])
{
  KRPCI& krpcInterface = KRPCI::getInstance();
  KRPC::Services krpcServices;

  // get IP address from cmd line
  const int ipAddrBufSize = 16;
  char krpcIpAddress[ipAddrBufSize];
  if (argc > 1) {
    _snprintf_s(krpcIpAddress, ipAddrBufSize - 1, "%S", argv[1]);
  }
  else {
    _snprintf_s(krpcIpAddress, ipAddrBufSize - 1, "127.0.0.1");
  }

  // open interface to KRPC
  krpcInterface.Open(krpcIpAddress);

  // main processing
  krpcInterface.GetServices(krpcServices);
  string krpcVersion = krpcInterface.GetKRPCServerVersion();

  std::string genClassName = "KRPCI_SpaceCenter";
  KRPCI_Interpreter interpreter(krpcServices.services(0), genClassName, krpcVersion);

  std::string outputPathInclude = "C:\\Users\\Charlie\\Documents\\Visual Studio 2013\\Projects\\KNav\\KRPCI_SpaceCenter\\include\\";
  std::string outputPathSource = "C:\\Users\\Charlie\\Documents\\Visual Studio 2013\\Projects\\KNav\\KRPCI_SpaceCenter\\src\\";
  std::string outputPathTxt = "C:\\Users\\Charlie\\Documents\\Visual Studio 2013\\Projects\\KNav\\KRPCI_SpaceCenter\\";
  std::string genHeaderFilename = outputPathInclude + genClassName + ".h";
  std::string genSourceFilename = outputPathSource + genClassName + ".cpp";
  std::string genTxtFilename = outputPathTxt + genClassName + "_" + krpcVersion + ".txt";
  interpreter.OutputCppHeaderFile(genHeaderFilename);
  interpreter.OutputCppSourceFile(genSourceFilename);
  interpreter.OutputSummaryFile(krpcServices, genTxtFilename);

  // close interface to KRPC
  krpcInterface.Close();

	return 0;
}

