#ifndef KRPCI_INTERPRETER_H
#define KRPCI_INTERPRETER_H

#include "stdafx.h"
#include "KRPC.pb.h"

#define KRPCI_INTERPRETER_GENERATED_CLASS "KRPCI_SpaceCenter"
#define KRPCI_INTERPRETER_DEFAULT_TYPE    "uint64"

class KRPCI_Interpreter {

public:

  std::string krpcServiceName;
  std::string generatedClassName;

  KRPCI_Interpreter(KRPC::Service svc, std::string className, std::string version);

  void OutputCppHeaderFile(std::string filename);
  void OutputCppSourceFile(std::string filename);
  static void OutputSummaryFile(KRPC::Services &krpcServices, std::string filename);

private:

  KRPC::Service krpcService;
  std::string   krpcServerVersion;
  
  std::string ParseKRPCType(std::string krpcType, BOOL &isKrpcType);
  std::string ClassName(KRPC::Procedure &krpcProcedure);
  std::string FunctionSignature(KRPC::Procedure &krpcProcedure);
  std::string FunctionReturnType(KRPC::Procedure &krpcProcedure);
  std::string FunctionDeclaration(KRPC::Procedure &krpcProcedure, bool makeStatic, bool withClassName);
  std::string FunctionBody(KRPC::Procedure &krpcProcedure);
  std::string FindClassType_Parameter(KRPC::Procedure &krpcProcedure, INT paramNumber, BOOL &isClassType);
  std::string FindClassType_Return(KRPC::Procedure &krpcProcedure);
  std::string TranslatePBtoCPP(std::string protobufType);
  void CheckCPPType(std::string type, BOOL &isIntegral, BOOL &isFloatingPoint, BOOL &isBoolean, BOOL &is32bit, BOOL &is64bit, BOOL &isSigned);

  static std::string _toUpper(const std::string &in);

};

#endif // KRPCI_INTERPRETER_H
