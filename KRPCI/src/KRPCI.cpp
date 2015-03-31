#include "KRPCI.h"

const BYTE KRPCI::RPC_SERVER_HELLO_BUF[] = { 'H', 'E', 'L', 'L', 'O', '-', 'R', 'P', 'C', 0x00, 0x00, 0x00 };

KRPCI& KRPCI::getInstance()
{
  // guaranteed to be destroyed.
  // instantiated on first use.
  static KRPCI instance;
  return instance;
}

void KRPCI::Open() {
  krpcIPAddress = string(KRPCI_SERVER_IP);
  Open(krpcIPAddress);
}

void KRPCI::Open(string ipAddress)
{
  int result;
  krpcIPAddress = ipAddress;

  printf("Opening KRPC Interface ... \n");

  // allocate memory buffers
  rpcClientDataBuffer = new BYTE[KRPCI_RECV_BUFFER_SIZE];
  streamClientRecvBuffer = new BYTE[KRPCI_RECV_BUFFER_SIZE];

  // zero out memory buffers
  ZeroMemory(rpcClientDataBuffer, KRPCI_RECV_BUFFER_SIZE);
  ZeroMemory(streamClientRecvBuffer, KRPCI_RECV_BUFFER_SIZE);

  // threading variables
  rpcServerTerminate = false;
  rpcServerIsConnected = false;

  // Initialize Winsock
  result = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (result != 0) {
    printf("WSAStartup failed. Code: %d \n", result);
    return;
  }

  rpcClientThread = CreateThread(
    NULL,                   // default security attributes
    0,                      // use default stack size  
    rpcClientThread_stub,   // thread function name
    this,                   // argument to thread function 
    0,                      // use default creation flags 
    NULL);                  // returns the thread identifier

  while (!rpcServerIsConnected);
}

void KRPCI::Close()
{
  printf("Closing KRPC Interface ... \n");

  // cleanup variables
  rpcServerTerminate = true;

  // wait for thread to terminate
  WaitForSingleObject(rpcClientThread, 10000);

  // cleanup memory
  delete rpcClientDataBuffer;
  delete streamClientRecvBuffer;

  // cleanup WSA
  WSACleanup();
}

void KRPCI::GetServices(KRPC::Services &krpcServices) {
  Request_Services(krpcServices);
}

DWORD WINAPI KRPCI::rpcClientThread_stub(LPVOID lpParam)
{
  if (lpParam != NULL)
    ((KRPCI *)lpParam)->rpcClientThread_run();

  return 0;
}

void KRPCI::rpcClientThread_run()
{
  const char *function_k = "rpcClientThread_run";

  BOOL status;
  INT header;

  ULONGLONG systemTime = GetTickCount64();
  printf("KRPC client thread started ... \n");
  printf("System Time: %.3f seconds \n", (double)systemTime / 1000.0);
  

  // main processing loop.
  // maintains a connection until terminated by the user.
  while(!rpcServerTerminate)
  {

    if (!rpcServerIsConnected)
    {
      // establish connection with KRPC Server
      status = Connect_RPCServer();
      if (!status) {
        printf("%s: failed to connect to server! Retry in %d seconds ... \n", 
          function_k, RPC_CLIENT_RETRY_WAIT_MS / 1000);
        Sleep(RPC_CLIENT_RETRY_WAIT_MS);
        continue;
      }

      // get system time
      systemTime = GetCurrentTime();

      // request KSP status
      status = Request_Status();

      // report good connection
      rpcServerIsConnected = true;
    }

    Sleep(RPC_CLIENT_THREAD_PERIOD_MS);
  }

  closesocket(rpcClientSocket);
}

INT KRPCI::RecvHeader()
{
  const char *function_k = "RecvHeader";

  INT retval;
  UINT header = 0;
  BYTE *pRcv = rpcClientHeaderBuffer;
  BOOL foundHeader = false, bufferFull = false;;
  INT bytesReceived = 0;

  // initialize receive buffer
  ZeroMemory(rpcClientHeaderBuffer, KRPCI_HEADER_BUFFER_SIZE);

  // start receiving bytes
  do {
    retval = recv(rpcClientSocket, (char *)pRcv, 1, 0);

    if (retval > 0) { // received data
      bytesReceived += 1;
      foundHeader = !(*pRcv & 0x80);
      pRcv += 1;
      bufferFull = (bytesReceived >= KRPCI_HEADER_BUFFER_SIZE);
    }
    else if (retval == 0) { // server closed connection
      return -2;
    }
    else { // receive error
      printf("%s: recv error! Code: %d \n", function_k, WSAGetLastError());
    }

  } while (!foundHeader && !bufferFull);

  // return if no header found
  if (!foundHeader && bufferFull) {
    return -1;
  }

  // init coded stream
  google::protobuf::io::ZeroCopyInputStream *zcos = new google::protobuf::io::ArrayInputStream(rpcClientHeaderBuffer, bytesReceived);
  google::protobuf::io::CodedInputStream *cos = new google::protobuf::io::CodedInputStream(zcos);
  cos->ReadVarint32(&header);

  delete cos;
  delete zcos;

  // print a warning if message is too big
  if (header > KRPCI_RECV_BUFFER_SIZE) {
    printf("*** WARNING ***  incoming message size (%db) exceeds buffer size (%db) \n",
      header, KRPCI_HEADER_BUFFER_SIZE);
  }

#ifdef KRPCI_DEBUG
  printf("%s: Expecting %d bytes [", function_k, header);
  PrintBytesHex((char *)rpcClientHeaderBuffer, bytesReceived);
  printf("] \n\n");
#endif // KRPCI_DEBUG

  return (INT)header;
}

bool KRPCI::Connect_RPCServer()
{
  const char *function_k = "Connect_RPCServer";

  INT retval;

  // connect to RPC Server
  rpcClientSocket = _connectToServer((char *)krpcIPAddress.c_str(), KRPCI_RPC_SERVER_PORT);
  if (rpcClientSocket == INVALID_SOCKET) {
    printf("%s: error! \n", function_k);
    return false;
  }

  // send welcome message to RPC Server
  retval = send(rpcClientSocket, (const char *)RPC_SERVER_HELLO_BUF, RPC_SERVER_HELLO_BUF_LEN, 0);
  if (retval == SOCKET_ERROR) {
    printf("%s: error sending Welcome Message \n", function_k);
    return false;
  }

  // send client name to RPC Server
  memset(KRPCI_CLIENT_NAME, 0, KRPCI_CLIENT_NAME_LEN);
  sprintf((char *)KRPCI_CLIENT_NAME, "KRPCI");
  retval = send(rpcClientSocket, (const char *)KRPCI_CLIENT_NAME, KRPCI_CLIENT_NAME_LEN, 0);
  if (retval == SOCKET_ERROR) {
    printf("%s: error sending client name \n", function_k);
    return false;
  }

  // receive KRPC client GUID
  INT bytesRecv = 0;
  BYTE *pGuidBuf = KRPCI_CLIENT_GUID;
  while (bytesRecv < KRPCI_CLIENT_GUID_LEN) {
    retval = recv(rpcClientSocket, (char *)pGuidBuf, KRPCI_CLIENT_GUID_LEN, 0);

    // check received data
    if (retval > 0) {
      bytesRecv += retval;
      pGuidBuf += retval;
    }
    else if (retval == 0) {
      printf("%s: Connection to RPC Server unexpectedly closed! \n", function_k);
      return false;
    }
    else {
      printf("%s: recv error. Code: %d \n", function_k, WSAGetLastError());
    }
  }

  printf("Client GUID: ");
  for (INT i = 0; i < (KRPCI_CLIENT_GUID_LEN / 4); i++) {
    for (INT j = 0; j < 4; j++) {
      if ((i * 4 + j) < KRPCI_CLIENT_GUID_LEN) {
        printf("%02X", (unsigned char)KRPCI_CLIENT_GUID[i * 4 + j]);
      }
    }
    if (i < ((KRPCI_CLIENT_GUID_LEN / 4) - 1)) {
      printf("-");
    }
  }
  //PrintBytesHex((const char *)KRPCI_CLIENT_GUID, KRPCI_CLIENT_GUID_LEN);
  printf("\n\n");

  return true;
}

BOOL KRPCI::SendRequest(KRPC::Request &krpcRequest)
{
  const char *function_k = "SendRequest";

  BOOL status = true;

  // init KRPC message
  INT sizeMessageRequest = krpcRequest.ByteSize();

  // serial message to string
  std::string serialMessageRequest;
  krpcRequest.SerializeToString(&serialMessageRequest);
  UINT sizeSerialMessageRequest = serialMessageRequest.length();

  // send header (varint-coded message size)
  status = _sendVarint32(rpcClientSocket, sizeSerialMessageRequest);

  // send RPC GetStatus
  INT retval = send(rpcClientSocket, (const char *)serialMessageRequest.c_str(), 
    sizeSerialMessageRequest, 0);
  if (retval == SOCKET_ERROR) {
    status = false;
    printf("%s: error sending RPC Request. svc:%s proc:%s \n", function_k, 
      krpcRequest.service().c_str(), krpcRequest.procedure().c_str());
  }
#ifdef KRPCI_DEBUG
  else {
    printf("%s: sent RPC Request. svc:%s proc:%s \n", function_k, 
      krpcRequest.service().c_str(), krpcRequest.procedure().c_str());
  }
#endif // KRPCI_DEBUG

  return status;
}

BOOL KRPCI::SendRequest(std::string krpcService, std::string krpcProcedure)
{
  // init KRPC message
  KRPC::Request messageRequest;
  messageRequest.set_service(krpcService.c_str());
  messageRequest.set_procedure(krpcProcedure.c_str());

  return SendRequest(messageRequest);
}

BOOL KRPCI::RecvResponse(KRPC::Response &krpcResponse, INT numBytes)
{
  if (numBytes > 0) {
    INT bytesReceived = _recvData(rpcClientSocket, rpcClientDataBuffer, numBytes);
    krpcResponse.ParseFromArray(rpcClientDataBuffer, bytesReceived);
    return TRUE;
  }
  return FALSE;
}

string KRPCI::GetKRPCServerVersion() {
  return KRPC_VERSION;
}

BOOL KRPCI::Request_Services(KRPC::Services &krpcServices)
{
  const char *function_k = "Request_Services";

  HRESULT result = S_OK;
  BOOL retval = true;

  // send Services request
  retval = SendRequest_Services();
  if (!retval) {
    result = E_FAIL;
    printf("%s: failed to send Services message! \n", function_k);
  }

  // wait for response
  if (result == S_OK) {
    retval = RecvResponse_Services(krpcServices);
    if (!retval) {
      result = E_FAIL;
      printf("%s: failed to receive Services response! \n", function_k);
    }
  }

  return retval;
}

BOOL KRPCI::SendRequest_Services() {
  return SendRequest("KRPC", "GetServices");
}

BOOL KRPCI::RecvResponse_Services(KRPC::Services &krpcServices)
{
  const char *function_k = "RecvResponse_Services";

  BOOL status = true;
  INT bytesReceived = 0;

  INT numProcedures, numClasses, numEnums, numServices, numParameters, numAttributes, numEnumValues;
  KRPC::Service          serviceMsg;
  KRPC::Procedure        procedureMsg;
  KRPC::Class            classMsg;
  KRPC::Enumeration      enumMsg;
  KRPC::Parameter        parameterMsg;
  KRPC::EnumerationValue enumValueMsg;

  // check for incoming header data
  INT header = RecvHeader();

  if (header > 0) {
    bytesReceived = _recvData(rpcClientSocket, rpcClientDataBuffer, header);

    KRPC::Response dataMsg;
    dataMsg.ParseFromArray(rpcClientDataBuffer, bytesReceived);

    // check for error message
    if (dataMsg.has_error()) {
      printf("%s: response error: %s \n", function_k, dataMsg.error().c_str());
      status = false;
    }

    krpcServices.ParseFromString(dataMsg.return_value());
    numServices = krpcServices.services_size();

    printf("%s received. Found %d services. \n", function_k, numServices);

    // enumerate services
    printf("%-16s%-16s%-16s%-16s \n", "Service", "Procedures", "Classes", "Enums");
    printf("---------------------------------------------------------------- \n");
    for (int i = 0; i < numServices; i++) {
      serviceMsg = krpcServices.services(i);
      printf("%-16s%-16d%-16d%-16d \n", serviceMsg.name().c_str(), serviceMsg.procedures_size(),
        serviceMsg.classes_size(), serviceMsg.enumerations_size());
    }
    printf("\n");

#if 0
    // enumerate services
    for (int i = 0; i < numServices; i++) {
      serviceMsg = servicesMsg.services(i);
      numProcedures = serviceMsg.procedures_size();
      numClasses = serviceMsg.classes_size();
      numEnums = serviceMsg.enumerations_size();

      printf("***\n*** Service: %s \n***\n", serviceMsg.name().c_str());

      // enumerate procedures
      if (numProcedures > 0) {
        printf("== PROCEDURES == \n");
        for (int j = 0; j < numProcedures; j++) {
          procedureMsg = serviceMsg.procedures(j);
          printf("> %s \n", procedureMsg.name().c_str());
        }
        printf("\n");
      }

      // enumerate classes
      if (numClasses > 0) {
        printf("=== CLASSES ==== \n");
        for (int j = 0; j < numClasses; j++) {
          classMsg = serviceMsg.classes(j);
          printf("> %s \n", classMsg.name().c_str());
        }
        printf("\n");
      }

      // enumerate enums
      if (numEnums > 0) {
        printf("==== ENUMS ===== \n");
        for (int j = 0; j < numEnums; j++) {
          enumMsg = serviceMsg.enumerations(j);
          printf("> %s \n", enumMsg.name().c_str());
        }
        printf("\n");
      }

      printf("\n");
    } // services
#endif

#if 0
    // enumerate services
    for (int i = 0; i < numServices; i++) {
      serviceMsg = servicesMsg.services(i);
      numProcedures = serviceMsg.procedures_size();
      numClasses = serviceMsg.classes_size();
      numEnums = serviceMsg.enumerations_size();

      printf("***\n*** Service: %s \n***\n", serviceMsg.name().c_str());

      // enumerate procedures
      if (numProcedures > 0) {
        printf("== PROCEDURES == \n");
        for (int j = 0; j < numProcedures; j++) {
          procedureMsg = serviceMsg.procedures(j);
          printf("> %s \n", procedureMsg.name().c_str());

          // enumerate parameters
          numParameters = procedureMsg.parameters_size();
          numAttributes = procedureMsg.attributes_size();
          for (int j = 0; j < numParameters; j++) {
            parameterMsg = procedureMsg.parameters(j);
            printf("    Param: %20s, %20s", parameterMsg.name().c_str(), parameterMsg.type().c_str());
            if (parameterMsg.has_default_argument()) {
              printf(", (%2db) (", parameterMsg.default_argument().length());
              _printBytesHex(parameterMsg.default_argument().c_str(), parameterMsg.default_argument().length());
              printf(") ");

              if (parameterMsg.type().compare("double") == 0) {
                double default_argument;
                parameterMsg.default_argument().copy((char *)&default_argument, parameterMsg.default_argument().length(), 0);
                printf("%f", default_argument);
              }
              else if (parameterMsg.type().compare("float") == 0) {
                float default_argument;
                parameterMsg.default_argument().copy((char *)&default_argument, parameterMsg.default_argument().length(), 0);
                printf("%f", default_argument);
              }
            }
            printf("\n");
          }

          // enumerate return type
          if (procedureMsg.has_return_type()) {
            printf("    Retrn: %20s \n", procedureMsg.return_type().c_str());
          }

          // enumerate attributes
          for (int j = 0; j < numAttributes; j++) {
            printf("    Attrb: %20s \n", procedureMsg.attributes(j).c_str());
          }


          printf("\n");
        } // procedures
        printf("\n");
      }

      // enumerate classes
      if (numClasses > 0) {
        printf("=== CLASSES ==== \n");
        for (int j = 0; j < numClasses; j++) {
          classMsg = serviceMsg.classes(j);
          printf("> %s \n", classMsg.name().c_str());
        }
        printf("\n");
      } // classes

      // enumerate enums
      if (numEnums > 0) {
        printf("==== ENUMS ===== \n");
        for (int j = 0; j < numEnums; j++) {
          enumMsg = serviceMsg.enumerations(j);
          printf("> %s \n", enumMsg.name().c_str());

          numEnumValues = enumMsg.values_size();
          for (int k = 0; k < numEnumValues; k++) {
            enumValueMsg = enumMsg.values(k);
            printf("    %-15s, %-10d \n", enumValueMsg.name().c_str(), enumValueMsg.value());
          }
          printf("\n");
        }
        printf("\n");
      } // enums
    } // services
#endif

#if 0
    // enumerate services
    for (int i = 0; i < numServices; i++) {
      serviceMsg = servicesMsg.services(i);

      if (serviceMsg.name().compare("SpaceCenter") != 0) continue;

      std::string CLASS_NAME = "KRPCI";

      // enumerate procedures
      numProcedures = serviceMsg.procedures_size();
      for (int j = 0; j < numProcedures; j++) {
        procedureMsg = serviceMsg.procedures(j);

        printf("%s %s \n\n", KRPCI_Interpreter::FunctionDeclaration(procedureMsg).c_str(),
          KRPCI_Interpreter::FunctionBody(procedureMsg).c_str());
      }
    }
#endif


  }
  else if (header < -1) {
    status = false;
  }

  return status;
}

BOOL KRPCI::Request_Status()
{
  const char *function_k = "Request_Status";

  HRESULT result = S_OK;
  BOOL retval = true;

  // send Status request
  retval = SendRequest_Status();
  if (!retval) {
    result = E_FAIL;
    printf("%s: failed to send Status message! \n", function_k);
  }

  // wait for response
  if (result == S_OK) {
    retval = RecvResponse_Status(krpcTime, KRPC_VERSION);
    if (!retval) {
      result = E_FAIL;
      printf("%s: failed to receive Status response! \n", function_k);
    }
  }

  return retval;
}

BOOL KRPCI::SendRequest_Status() { 
  return SendRequest("KRPC", "GetStatus");
}

BOOL KRPCI::RecvResponse_Status(double &time, std::string &version)
{
  BOOL status = true;
  INT bytesReceived = 0;

  // check for incoming header data
  INT header = RecvHeader();

  if (header > 0) {
    bytesReceived = _recvData(rpcClientSocket, rpcClientDataBuffer, header);

    KRPC::Response dataMsg;
    dataMsg.ParseFromArray(rpcClientDataBuffer, bytesReceived);

    KRPC::Status statusMsg;
    statusMsg.ParseFromString(dataMsg.return_value());

    time = dataMsg.time();
    version = statusMsg.version();
#ifdef KRPCI_DEBUG
    printf("[%.3f] RecvResponse_Status received. KRPC Version: %s \n", time, version.c_str());
#endif
  }
  else if (header < -1) {
    status = false;
  }

  return status;
}

SOCKET KRPCI::_connectToServer(char *ipAddr, char *port)
{
  SOCKET socketToServer;
  HRESULT result = S_OK;
  INT retval;
  struct addrinfo *addrResolved = NULL, *pAddr = NULL, addrHints;

  ZeroMemory(&addrHints, sizeof(addrHints));
  addrHints.ai_family = AF_INET;
  addrHints.ai_socktype = SOCK_STREAM;
  addrHints.ai_protocol = IPPROTO_TCP;

  // Resolve the server address and port
  retval = getaddrinfo(ipAddr, port, &addrHints, &addrResolved);
  if (retval != 0) {
    printf("getaddrinfo failed: %d \n", retval);
    result = E_FAIL;
  }

  if (result == S_OK) {
    for (pAddr = addrResolved; pAddr != NULL; pAddr = pAddr->ai_next) {
      // create socket
      socketToServer = socket(pAddr->ai_family, pAddr->ai_socktype, pAddr->ai_protocol);

      // check socket
      if (socketToServer == INVALID_SOCKET) {
        printf("socket failed. Code: %d \n", WSAGetLastError());
        result = E_FAIL;
        break;
      }

      // attempt to connect
      retval = connect(socketToServer, pAddr->ai_addr, (int)pAddr->ai_addrlen);
      if (retval == SOCKET_ERROR) {
        closesocket(socketToServer);
        socketToServer = INVALID_SOCKET;
        continue;
      }
      break;
    }
  }

  // no more need for address information
  freeaddrinfo(addrResolved);

  // check socket
  if (result == S_OK && socketToServer == INVALID_SOCKET) {
    printf("Unable to connect to server! \n");
    result = E_FAIL;
  }

  return socketToServer;
}

INT KRPCI::_sendVarint32(SOCKET skt, UINT32 value)
{
  INT varintSize = 0;
  BYTE varintBuffer[10];
  ZeroMemory(varintBuffer, 10);

  EncodeVarint(value, varintBuffer, varintSize);

  INT retval = send(skt, (const char *)varintBuffer, varintSize, 0);
  if (retval == SOCKET_ERROR) {
    printf("_sendVarint32: socket error! Code: %d \n", WSAGetLastError());
    rpcServerIsConnected = false;
  }

  return retval;
}

INT KRPCI::_recvData(SOCKET skt, BYTE *buffer, UINT size)
{
  INT retval;
  ZeroMemory(buffer, size);

  UINT bufferFreeBytes = size;
  UINT bytesReceived = 0;
  BYTE *pRcv = buffer;

  // start receiving bytes
  do {
    retval = recv(skt, (char *)pRcv, bufferFreeBytes, 0);

    if (retval > 0) { // received data
      bytesReceived += retval;
      bufferFreeBytes -= retval;
      pRcv += retval;
    }
    else if (retval == 0) { // server closed connection
      rpcServerIsConnected = false;
      return -2;
    }
    else { // receive error
      printf("_recvData: socket error! Code: %d \n", WSAGetLastError());
    }

  } while (bytesReceived < size);

  return bytesReceived;
}

void KRPCI::PrintBytesHex(const char *buf, UINT size)
{
  for (int i = 0; i < size; i++)
    printf("0x%02X ", (unsigned char)buf[i]);
}

void KRPCI::EncodeVarint(UINT32 value, BYTE *buf, INT &size)
{
  size = google::protobuf::io::CodedOutputStream::VarintSize32(value);

  google::protobuf::io::ZeroCopyOutputStream *zcos = new google::protobuf::io::ArrayOutputStream(buf, size);
  google::protobuf::io::CodedOutputStream *cos = new google::protobuf::io::CodedOutputStream(zcos);
  cos->WriteVarint32(value);

  delete cos;
  delete zcos;
}

void KRPCI::EncodeVarint(UINT64 value, BYTE *buf, INT &size)
{
  size = google::protobuf::io::CodedOutputStream::VarintSize64(value);

  google::protobuf::io::ZeroCopyOutputStream *zcos = new google::protobuf::io::ArrayOutputStream(buf, size);
  google::protobuf::io::CodedOutputStream *cos = new google::protobuf::io::CodedOutputStream(zcos);
  cos->WriteVarint64(value);

  delete cos;
  delete zcos;
}

void KRPCI::DecodeVarint(UINT32 &value, BYTE *buf, INT size)
{
  // init coded stream
  google::protobuf::io::ZeroCopyInputStream *zcos = new google::protobuf::io::ArrayInputStream(buf, size);
  google::protobuf::io::CodedInputStream *cos = new google::protobuf::io::CodedInputStream(zcos);
  cos->ReadVarint32(&value);

  delete cos;
  delete zcos;
}

void KRPCI::DecodeVarint(UINT64 &value, BYTE *buf, INT size)
{
  // init coded stream
  google::protobuf::io::ZeroCopyInputStream *zcos = new google::protobuf::io::ArrayInputStream(buf, size);
  google::protobuf::io::CodedInputStream *cos = new google::protobuf::io::CodedInputStream(zcos);
  cos->ReadVarint64(&value);

  delete cos;
  delete zcos;
}

KRPC::Tuple KRPCI::GenerateTuple(double x, double y, double z)
{ 
  KRPC::Tuple tuple;
  string *x_str = tuple.add_items();
  string *y_str = tuple.add_items();
  string *z_str = tuple.add_items();

  x_str->assign((char *)&x, sizeof(x));
  y_str->assign((char *)&y, sizeof(y));
  z_str->assign((char *)&z, sizeof(z));

  return tuple;
}
