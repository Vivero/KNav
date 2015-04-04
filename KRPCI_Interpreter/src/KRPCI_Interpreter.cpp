#include "KRPCI_Interpreter.h"

using namespace std;

KRPCI_Interpreter::KRPCI_Interpreter(KRPC::Service svc, std::string className, std::string version)
{
  krpcService = svc;
  krpcServiceName = svc.name();
  generatedClassName = className;
  krpcServerVersion = version;
}

void KRPCI_Interpreter::OutputCppHeaderFile(std::string filename)
{
  int numProcedures = krpcService.procedures_size();
  int numClasses = krpcService.classes_size();
  int numEnums = krpcService.enumerations_size();
  KRPC::Procedure krpcProcedure;
  KRPC::Class krpcClass;
  KRPC::Enumeration krpcEnum;
  KRPC::EnumerationValue krpcEnumValue;

  FILE *pFile = fopen(filename.c_str(), "w");

  string krpcServiceName_cap = _toUpper(krpcServiceName);

  // header guard
  fprintf(pFile, "#ifndef %s_H \n", krpcServiceName_cap.c_str());
  fprintf(pFile, "#define %s_H \n\n", krpcServiceName_cap.c_str());

  // include files
  fprintf(pFile, "#include \"stdafx.h\"\n");
  fprintf(pFile, "#include \"KRPCI.h\"\n");
  fprintf(pFile, "#include \"KRPC.pb.h\"\n\n");

  // definitions
  fprintf(pFile, "#define KRPC_SERVER_VERSION \"%s\" \n\n", krpcServerVersion.c_str());

  // declare class
  fprintf(pFile, "class %s { \n\npublic: \n\n", generatedClassName.c_str());

  // enumerate classes
  string className;
  for (int i = 0; i < numClasses; i++) {
    krpcClass = krpcService.classes(i);
    className = _toUpper(krpcClass.name());

    fprintf(pFile, "  typedef %s %s; \n", "UINT64", className.c_str());
  }
  fprintf(pFile, "\n\n");

  // enumerate enums
  string enumName, enumValueName;
  for (int i = 0; i < numEnums; i++) {
    krpcEnum = krpcService.enumerations(i);
    enumName = krpcEnum.name();
    int numEnumValues = krpcEnum.values_size();

    INT enumValueInt = 0;
    fprintf(pFile, "  enum %s { \n", enumName.c_str());
    for (int j = 0; j < numEnumValues; j++) {
      krpcEnumValue = krpcEnum.values(j);
      enumValueName = krpcEnumValue.name();
      enumValueInt  = krpcEnumValue.value();

      fprintf(pFile, "    %s_%s = %d", enumName.c_str(), enumValueName.c_str(), enumValueInt);
      if (j < (numEnumValues - 1)) fprintf(pFile, ", \n");
      else fprintf(pFile, " \n");
    }
    fprintf(pFile, "  }; \n\n", enumName.c_str());
  }
  fprintf(pFile, "\n\n");

  // enumerate procedures
  for (int i = 0; i < numProcedures; i++) {
    krpcProcedure = krpcService.procedures(i);

    fprintf(pFile, "  %s; \n", FunctionDeclaration(krpcProcedure, true, false).c_str());
  }

  // close class declaration
  fprintf(pFile, "\n};\n\n");
  fprintf(pFile, "#endif // %s_H \n", _toUpper(krpcServiceName).c_str());

  fclose(pFile);
}

void KRPCI_Interpreter::OutputCppSourceFile(std::string filename)
{
  int numProcedures = krpcService.procedures_size();
  KRPC::Procedure krpcProcedure;

  FILE *pFile = fopen(filename.c_str(), "w");

  // include files
  fprintf(pFile, "#include \"%s.h\"\n\n", generatedClassName.c_str());

  // enumerate procedures
  for (int i = 0; i < numProcedures; i++) {
    krpcProcedure = krpcService.procedures(i);

    fprintf(pFile, "%s %s \n\n", FunctionDeclaration(krpcProcedure, false, true).c_str(), FunctionBody(krpcProcedure).c_str());
  }

  fclose(pFile);
}

void KRPCI_Interpreter::OutputSummaryFile(KRPC::Services &krpcServices, std::string filename)
{
  const char *function_k = "RecvResponse_Services";

  INT numProcedures, numClasses, numEnums, numServices, numParameters, numAttributes, numEnumValues;
  KRPC::Service          serviceMsg;
  KRPC::Procedure        procedureMsg;
  KRPC::Class            classMsg;
  KRPC::Enumeration      enumMsg;
  KRPC::Parameter        parameterMsg;
  KRPC::EnumerationValue enumValueMsg;

  FILE *pFile = fopen(filename.c_str(), "w");

  numServices = krpcServices.services_size();

  printf("%s received. Found %d services. \n", function_k, numServices);

  // enumerate services
  fprintf(pFile, "%-16s%-16s%-16s%-16s \n", "Service", "Procedures", "Classes", "Enums");
  fprintf(pFile, "---------------------------------------------------------------- \n");
  for (int i = 0; i < numServices; i++) {
    serviceMsg = krpcServices.services(i);
    fprintf(pFile, "%-16s%-16d%-16d%-16d \n", serviceMsg.name().c_str(), serviceMsg.procedures_size(),
      serviceMsg.classes_size(), serviceMsg.enumerations_size());
  }
  fprintf(pFile, "\n");

  // enumerate services
  for (int i = 0; i < numServices; i++) {
    serviceMsg = krpcServices.services(i);
    numProcedures = serviceMsg.procedures_size();
    numClasses = serviceMsg.classes_size();
    numEnums = serviceMsg.enumerations_size();

    fprintf(pFile, "***\n*** Service: %s \n***\n", serviceMsg.name().c_str());

    // enumerate procedures
    if (numProcedures > 0) {
      fprintf(pFile, "== PROCEDURES == \n");
      for (int j = 0; j < numProcedures; j++) {
        procedureMsg = serviceMsg.procedures(j);
        fprintf(pFile, "> %s \n", procedureMsg.name().c_str());

        // enumerate parameters
        numParameters = procedureMsg.parameters_size();
        numAttributes = procedureMsg.attributes_size();
        for (int j = 0; j < numParameters; j++) {
          parameterMsg = procedureMsg.parameters(j);
          fprintf(pFile, "    Param: %20s, %20s", parameterMsg.name().c_str(), parameterMsg.type().c_str());
          if (parameterMsg.has_default_argument()) {
            fprintf(pFile, ", (%2db) (", parameterMsg.default_argument().length());
            for (int k = 0; k < parameterMsg.default_argument().length(); k++)
              fprintf(pFile, "0x%02X ", (unsigned char)parameterMsg.default_argument().at(k));
            fprintf(pFile, ") ");

            if (parameterMsg.type().compare("double") == 0) {
              double default_argument;
              parameterMsg.default_argument().copy((char *)&default_argument, parameterMsg.default_argument().length(), 0);
              fprintf(pFile, "%f", default_argument);
            }
            else if (parameterMsg.type().compare("float") == 0) {
              float default_argument;
              parameterMsg.default_argument().copy((char *)&default_argument, parameterMsg.default_argument().length(), 0);
              fprintf(pFile, "%f", default_argument);
            }
          }
          fprintf(pFile, "\n");
        }

        // enumerate return type
        if (procedureMsg.has_return_type()) {
          fprintf(pFile, "    Retrn: %20s \n", procedureMsg.return_type().c_str());
        }

        // enumerate attributes
        for (int j = 0; j < numAttributes; j++) {
          fprintf(pFile, "    Attrb: %20s \n", procedureMsg.attributes(j).c_str());
        }


        fprintf(pFile, "\n");
      } // procedures
      fprintf(pFile, "\n");
    }

    // enumerate classes
    if (numClasses > 0) {
      fprintf(pFile, "=== CLASSES ==== \n");
      for (int j = 0; j < numClasses; j++) {
        classMsg = serviceMsg.classes(j);
        fprintf(pFile, "> %s \n", classMsg.name().c_str());
      }
      fprintf(pFile, "\n");
    } // classes

    // enumerate enums
    if (numEnums > 0) {
      fprintf(pFile, "==== ENUMS ===== \n");
      for (int j = 0; j < numEnums; j++) {
        enumMsg = serviceMsg.enumerations(j);
        fprintf(pFile, "> %s \n", enumMsg.name().c_str());

        numEnumValues = enumMsg.values_size();
        for (int k = 0; k < numEnumValues; k++) {
          enumValueMsg = enumMsg.values(k);
          fprintf(pFile, "    %-15s, %-10d \n", enumValueMsg.name().c_str(), enumValueMsg.value());
        }
        fprintf(pFile, "\n");
      }
      fprintf(pFile, "\n");
    } // enums
  } // services
}

std::string KRPCI_Interpreter::ClassName(KRPC::Procedure &krpcProcedure)
{
  string functionName = krpcProcedure.name();
  string className;

  // find underscore
  size_t underscorePos = functionName.find_first_of("_");
  if (underscorePos != string::npos) {
    className = functionName.substr(0, underscorePos);
    if (className.compare("get") == 0) {
      className.clear();
    }
  }

  return className;
}

std::string KRPCI_Interpreter::FunctionSignature(KRPC::Procedure &krpcProcedure)
{
  //string functionSignature = KRPCI_INTERPRETER_GENERATED_CLASS;
  //functionSignature += "::" + krpcProcedure.name() + "(";
  string functionSignature = krpcProcedure.name() + "(";

  int numParameters = krpcProcedure.parameters_size();
  KRPC::Parameter krpcParameter;

  // append parameters
  for (int i = 0; i < numParameters; i++) {
    // get parameter
    krpcParameter = krpcProcedure.parameters(i);

    // replace "this" with class object name
    string className = ClassName(krpcProcedure);
    string paramName = krpcParameter.name();
    if (paramName.compare("this") == 0) {
      paramName = className;
    }

    // append parameter with type
    string typeName = krpcParameter.type();
    if (typeName.compare(KRPCI_INTERPRETER_DEFAULT_TYPE) == 0) {
      BOOL isClassType = FALSE;
      typeName = FindClassType_Parameter(krpcProcedure, i, isClassType);
    }
    else {
      BOOL isKrpcType = FALSE;
      typeName = ParseKRPCType(typeName, isKrpcType);
    }

    // correction for type names
    typeName = TranslatePBtoCPP(typeName);

    functionSignature += typeName + " " + paramName;

    // append comma separator between params
    if (i < (numParameters - 1)) {
      functionSignature += ", ";
    }
  }

  // finalize
  functionSignature += ")";

  return functionSignature;
}

std::string KRPCI_Interpreter::FunctionReturnType(KRPC::Procedure &krpcProcedure)
{
  string typeName;
  BOOL isKrpcType = FALSE;

  if (krpcProcedure.has_return_type()) {
    typeName = ParseKRPCType(krpcProcedure.return_type(), isKrpcType);
  }
  else {
    typeName = "void";
  }

  // determine if its a class type
  if (typeName.compare("uint64") == 0) {
    typeName = generatedClassName + "::" + FindClassType_Return(krpcProcedure);
  }

  // correction for type name
  typeName = TranslatePBtoCPP(typeName);

  return typeName;
}

std::string KRPCI_Interpreter::FunctionDeclaration(KRPC::Procedure &krpcProcedure, bool makeStatic, bool withClassName)
{
  string typeName;
  string fnDeclaration;

  typeName = FunctionReturnType(krpcProcedure);
  if (makeStatic) {
    fnDeclaration = "static " + typeName + " ";
  }
  else {
    fnDeclaration = typeName + " ";
  }

  // generated class name
  if (withClassName) {
    fnDeclaration += KRPCI_INTERPRETER_GENERATED_CLASS;
    fnDeclaration += "::";
  }
  
  fnDeclaration += FunctionSignature(krpcProcedure);

  return fnDeclaration;
}

std::string KRPCI_Interpreter::FunctionBody(KRPC::Procedure &krpcProcedure)
{
  string body = "{\n";
  string returnType = FunctionReturnType(krpcProcedure);
  bool hasReturnValue = (returnType.compare("void") != 0);

  // determine if primitive
  BOOL isInt = FALSE, isFloat = FALSE, isBool = FALSE;
  BOOL is32b = FALSE, is64b = FALSE, isSigned = FALSE, isString = FALSE;
  CheckCPPType(returnType, isInt, isFloat, isBool, is32b, is64b, isSigned, isString);

  // but also check if it was a ProtoBuf uint64
  if (krpcProcedure.return_type().compare("uint64") == 0) {
    isInt = true; is64b = true;
  }

  if (hasReturnValue) {
    body += "  " + returnType + " retval";
    if (isInt) body += " = 0";
    else if (isFloat) body += " = 0.0";
    else if (isBool) body += " = false";
    body += "; \n";
  }

  body += "  KRPC::Request krpcRequest; \n";
  body += "  KRPCI &krpcInterface = KRPCI::getInstance(); \n\n";

  body += "  krpcRequest.set_service(\"" + krpcServiceName + "\"); \n";
  body += "  krpcRequest.set_procedure(\"" + krpcProcedure.name() + "\"); \n\n";

  body += "  BYTE uint_buf[10]; INT uint_size = 0; \n";

  // add arguments
  int numArgs = krpcProcedure.parameters_size();
  for (int i = 0; i < numArgs; i++) {
    stringstream ss;

    KRPC::Parameter param = krpcProcedure.parameters(i);
    BOOL isKrpcType = FALSE;
    string typeName = param.type();
    typeName = ParseKRPCType(typeName, isKrpcType);
    string paramName = param.name();

    // replace "this" with class object name
    string className = ClassName(krpcProcedure);
    if (paramName.compare("this") == 0) {
      paramName = className;
    }

    ss << "  KRPC::Argument *arg" << i << " = krpcRequest.add_arguments(); " << endl;
    ss << "  arg" << i << "->set_position(" << i << "); " << endl;

    if (isKrpcType) {
      ss << "  arg" << i << "->set_value(" << paramName << ".SerializeAsString()); " << endl;
    } 
    else {
      BOOL typeIsInt = FALSE, typeIsFloat = FALSE, typeIsBool = FALSE;
      BOOL typeIs32b = FALSE, typeIs64b = FALSE, typeIsSigned = FALSE, typeIsString = FALSE;
      typeName = TranslatePBtoCPP(typeName);
      CheckCPPType(typeName, typeIsInt, typeIsFloat, typeIsBool, typeIs32b, typeIs64b, typeIsSigned, typeIsString);
      
      if (typeIsInt || typeIsBool) {
        if (typeIs32b) {
          ss << "  UINT32 uint_arg" << i << " = 0;" << endl;
          ss << "  CopyMemory((void *)&uint_arg" << i << ", (void *)&" << paramName << ", sizeof(" << paramName << "));" << endl;
        }
        else if (typeIs64b) {
          ss << "  UINT64 uint_arg" << i << " = 0;" << endl;
          ss << "  CopyMemory((void *)&uint_arg" << i << ", (void *)&" << paramName << ", sizeof(" << paramName << "));" << endl;
        }
        else if (typeIsBool) {
          ss << "  UINT32 uint_arg" << i << " = " << paramName << ";" << endl;
        }
        ss << "  KRPCI::EncodeVarint(uint_arg" << i << ", uint_buf, uint_size);" << endl;
        ss << "  arg" << i << "->set_value((const char *)uint_buf, uint_size); " << endl;
      }
      else if (typeIsString) {
        ss << "  arg" << i << "->set_value(KRPCI::EncodeString(" << paramName << ")); " << endl;
      }
      else {
        ss << "  arg" << i << "->set_value((const char *)(&" << paramName << "), sizeof(" << paramName << ")); " << endl;
      }
      
    }
    body += ss.str() + "\n";
  }

  body += "  krpcInterface.SendRequest(krpcRequest); \n\n";

  body += "  INT header = krpcInterface.RecvHeader(); \n";
  body += "  KRPC::Response krpcResponse; \n";
  body += "  krpcInterface.RecvResponse(krpcResponse, header); \n\n";

#ifdef KRPCI_DEBUG
  body += "  printf(\"" + krpcProcedure.name() + ": Received %d bytes. \\n\", header); \n\n";
#endif // KRPCI_DEBUG

  body += "  if (krpcResponse.has_error()) { \n";
  //body += "    printf(\"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \\n\"); \n";
  //body += "    printf(\"@@@  ERROR RECEIVING: " + krpcProcedure.name() + " \\n\"); \n";
  //body += "    printf(\"%s \\n\\n\", krpcResponse.error().c_str()); \n";
  body += "    throw KRPC_Exception(krpcResponse.error()); \n";
  /*if (hasReturnValue) {
    body += "    return retval; \n";
  }
  else {
    body += "    return; \n";
  }*/
  body += "  } \n";

  // return value
  if (hasReturnValue) {
    body += "  else if (krpcResponse.has_return_value()) { \n";

    if (isFloat) {
      body += "    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); \n";
    }
    else if (isInt) {
      if (isSigned) {
        if (is32b) {
          body += "    UINT32 signedInt = 0; \n";
        }
        else {
          body += "    UINT64 signedInt = 0; \n";
        }
        body += "    KRPCI::DecodeVarint(signedInt, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); \n\n";
        body += "    CopyMemory(&retval, &signedInt, sizeof(retval)); \n";
      }
      else {
        body += "    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); \n";
      }
    }
    else if (isBool) {
      body += "    UINT32 boolValue = 0; \n";
      body += "    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); \n";
      body += "    retval = (boolValue != 0); \n";
    }
    else if (returnType.compare("string") == 0) {
      body += "    retval = string(krpcResponse.return_value().data() + 1, krpcResponse.return_value().size() - 1); \n";
    }
    else {
      body += "    retval.ParseFromString(krpcResponse.return_value()); \n";
    }
    body += "  } \n\n";

    body += "  return retval; \n";
  }

  // finalize
  body += "}";
  return body;
}

///
/// Replaces "." with "::"
///
std::string KRPCI_Interpreter::ParseKRPCType(std::string krpcType, BOOL &isKrpcType)
{
  string parsedKRPCType = krpcType;
  isKrpcType = FALSE;

  size_t dotPos = parsedKRPCType.find_first_of(".");
  if (dotPos != string::npos) {
    parsedKRPCType = parsedKRPCType.replace(dotPos, 1, "::", 2);
    isKrpcType = TRUE;
  }
  return parsedKRPCType;
}

std::string KRPCI_Interpreter::FindClassType_Parameter(KRPC::Procedure &krpcProcedure, INT paramNumber, BOOL &isClassType)
{
  int numAttributes = krpcProcedure.attributes_size();
  int paramAttributeIndex = -1;
  isClassType = false;

  string className = krpcProcedure.parameters(paramNumber).name();

  stringstream ss;
  ss << "ParameterType(" << paramNumber << ")";
  string paramNumberAttributeStr = ss.str();
  //printf("*** paramNumberAttributeStr = %s \n", paramNumberAttributeStr.c_str());
  
  for (int i = 0; i < numAttributes; i++)
  {
    string fullAttributeStr = krpcProcedure.attributes(i);

    // find "ParameterType(n)"
    if (fullAttributeStr.find(paramNumberAttributeStr) == 0) {

      // find "Class"
      string classKeywordStr = "Class";
      paramNumberAttributeStr += "." + classKeywordStr;
      if (fullAttributeStr.find(paramNumberAttributeStr) == 0) {
        //className = paramNumberAttributeStr.substr(classKeywordStr.length() + 1, paramNumberAttributeStr.length() - classKeywordStr.length() - 2);

        int fullClassNameLen = fullAttributeStr.length() - paramNumberAttributeStr.length() - 2;
        string fullClassName = fullAttributeStr.substr(paramNumberAttributeStr.length() + 1, fullClassNameLen);

        // cut off first part
        int dotPos = string::npos;
        if ((dotPos = fullClassName.find(".")) != string::npos) {
          className = _toUpper(fullClassName.substr(dotPos + 1));
          isClassType = true;
        }
        else {
          className = fullClassName;
        }
        break;
      }

    }
  }

  return className;
}

std::string KRPCI_Interpreter::FindClassType_Return(KRPC::Procedure &krpcProcedure)
{
  string className = "";
  int numAttributes = krpcProcedure.attributes_size();

  if (!krpcProcedure.has_return_type()) {
    return className;
  }

  className = krpcProcedure.return_type();
  string paramNumberAttributeStr = "ReturnType";

  for (int i = 0; i < numAttributes; i++)
  {
    string fullAttributeStr = krpcProcedure.attributes(i);

    // find "ReturnType"
    if (fullAttributeStr.find(paramNumberAttributeStr) == 0) {

      // find "Class"
      string classKeywordStr = "Class";
      paramNumberAttributeStr += "." + classKeywordStr;
      if (fullAttributeStr.find(paramNumberAttributeStr) == 0) {
        //className = paramNumberAttributeStr.substr(classKeywordStr.length() + 1, paramNumberAttributeStr.length() - classKeywordStr.length() - 2);

        int fullClassNameLen = fullAttributeStr.length() - paramNumberAttributeStr.length() - 2;
        string fullClassName = fullAttributeStr.substr(paramNumberAttributeStr.length() + 1, fullClassNameLen);

        // cut off first part
        int dotPos = string::npos;
        if ((dotPos = fullClassName.find(".")) != string::npos) {
          className = _toUpper(fullClassName.substr(dotPos + 1));
        }
        else {
          className = fullClassName;
        }
        break;
      }

    }
  }

  return className;
}

std::string KRPCI_Interpreter::TranslatePBtoCPP(std::string protobufType)
{
  string cppType = protobufType;

  if (protobufType.compare("uint64") == 0) {
    cppType = "UINT64";
  }
  else if (protobufType.compare("uint32") == 0) {
    cppType = "UINT32";
  }
  else if (protobufType.compare("int64") == 0) {
    cppType = "INT64";
  }
  else if (protobufType.compare("int32") == 0) {
    cppType = "INT32";
  }

  return cppType;
}

void KRPCI_Interpreter::CheckCPPType(std::string type, 
  BOOL &isIntegral, BOOL &isFloatingPoint, BOOL &isBoolean, 
  BOOL &is32bit,    BOOL &is64bit,         BOOL &isSigned,
  BOOL &isString)
{
  isIntegral = FALSE;
  isFloatingPoint = FALSE;
  isBoolean = FALSE;
  is32bit = FALSE;
  is64bit = FALSE;
  isSigned = FALSE;
  isString = FALSE;

  if (type.compare("UINT64") == 0) {
    isIntegral = TRUE;
    is64bit = TRUE;
  }
  else if (type.compare("UINT32") == 0) {
    isIntegral = TRUE;
    is32bit = TRUE;
  }
  else if (type.compare("INT64") == 0) {
    isIntegral = TRUE;
    is64bit = TRUE;
    isSigned = TRUE;
  }
  else if (type.compare("INT32") == 0) {
    isIntegral = TRUE;
    is32bit = TRUE;
    isSigned = TRUE;
  }
  else if (type.compare("float") == 0) {
    isFloatingPoint = TRUE;
    is32bit = TRUE;
  }
  else if (type.compare("double") == 0) {
    isFloatingPoint = TRUE;
    is64bit = TRUE;
  }
  else if (type.compare("bool") == 0) {
    isBoolean = TRUE;
  }
  else if (type.compare("string") == 0) {
    isString = TRUE;
  }
}

std::string KRPCI_Interpreter::_toUpper(const std::string &in)
{
  stringstream ss;
  for (int i = 0; i < in.length(); i++) {
    char upperCase[] = { toupper(in.at(i)), '\0' };
    ss << string(upperCase);
  }
  return ss.str();
}
