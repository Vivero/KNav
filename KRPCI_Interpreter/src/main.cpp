// KNav.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KRPCI.h"
#include "KRPCI_Interpreter.h"

#define SLEEP_PERIOD                       100

#define DEFAULT_KRPC_SERVER_IP      "127.0.0.1"
#define DEFAULT_KRPC_SERVER_IP_LEN           9

BOOL knavTerminate = false;
SHORT knavKeyState = 0;

void print_usage();

int _tmain(int argc, _TCHAR* argv[])
{
  KRPCI& krpcInterface = KRPCI::getInstance();
  KRPC::Services krpcServices;
  KRPC::Service krpcService;
  int retval = EXIT_FAILURE;

  char *serviceName;
  char *outputPath;
  char *ipAddress;

  // get command line arguments:
  //   argv[0]     service name to query kRPC
  //   argv[1]     output directory
  //   argv[2]     optional: ip address
  //
  if (argc < 3) {
    printf("too few arguments! \n\n");
    print_usage();
    exit(retval);
  }
  else {
    size_t numCharsConverted = 0;

    // parse kRPC service name
    size_t argNumChars = wcslen(argv[1]);
    serviceName = new char[argNumChars + 1];
    wcstombs_s(&numCharsConverted, serviceName, argNumChars + 1, argv[1], _TRUNCATE);

    // parse output path
    argNumChars = wcslen(argv[2]);
    outputPath = new char[argNumChars + 1];
    wcstombs_s(&numCharsConverted, outputPath, argNumChars + 1, argv[2], _TRUNCATE);

    // parse IP address, if provided
    if (argc > 3) {
      argNumChars = wcslen(argv[3]);
      ipAddress = new char[argNumChars + 1];
      wcstombs_s(&numCharsConverted, ipAddress, argNumChars + 1, argv[3], _TRUNCATE);
    }
    else {
      ipAddress = new char[DEFAULT_KRPC_SERVER_IP_LEN + 1];
      _snprintf_s(ipAddress, DEFAULT_KRPC_SERVER_IP_LEN + 1, _TRUNCATE, DEFAULT_KRPC_SERVER_IP);
    }

    // print out cmd line args
    printf("kRPC Service Name : %s \n", serviceName);
    printf("Output directory  : %s \n", outputPath);
    printf("kRPC IP address   : %s \n", ipAddress);
  }


  // open interface to KRPC
  krpcInterface.Open(ipAddress);

  // main processing
  krpcInterface.GetServices(krpcServices);
  string krpcVersion = krpcInterface.GetKRPCServerVersion();

  // find the service name
  string serviceName_str = string(serviceName);
  BOOL found = FALSE;
  for (int i = 0; i < krpcServices.services_size(); i++) {
    if (serviceName_str.compare(krpcServices.services(i).name()) == 0) {
      krpcService = krpcServices.services(i);
      found = TRUE;
      break;
    }
  }

  if (!found) {
    printf("ERROR: could not find service \"%s\" while querying kRPC! \n", serviceName);
  }
  else {
    KRPCI_Interpreter interpreter(krpcService, serviceName_str, krpcVersion);

    stringstream ss;

    // header filename
    ss << outputPath << serviceName << ".h";
    std::string genHeaderFilename = ss.str();

    // source filename
    ss.str(string());
    ss << outputPath << serviceName << ".cpp";
    std::string genSourceFilename = ss.str();

    // summary filename
    ss.str(string());
    ss << outputPath << serviceName << "_" << krpcVersion << ".txt";
    std::string genTxtFilename = ss.str();

    // output files
    printf("Header File       : %s \n", genHeaderFilename.c_str());
    printf("Source File       : %s \n", genSourceFilename.c_str());
    printf("Summary File      : %s \n\n", genTxtFilename.c_str());

    interpreter.OutputCppHeaderFile(genHeaderFilename);
    interpreter.OutputCppSourceFile(genSourceFilename);
    interpreter.OutputSummaryFile(krpcServices, genTxtFilename);

    retval = EXIT_SUCCESS;
  }


  // close interface to KRPC
  krpcInterface.Close();

  // clean up
  delete serviceName;
  delete outputPath;
  delete ipAddress;

	return retval;
}

void print_usage()
{
  printf("Usage: \n\n");

  printf("KRPCI_Interpreter.exe <service name> <output dir> [ip address] \n\n");
  printf("<service name>       The name of kRPC service to query, e.g. SpaceCenter \n");
  printf("<output dir>         Directory to place output files (include trailing slash) \n");
  printf("[ip address]         Optional: IP address of kRPC host (defaults to localhost) \n\n");
}