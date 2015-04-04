#ifndef KRPCI_H
#define KRPCI_H

#include <atomic>
#include <google/protobuf/message.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <sstream>

#include "stdafx.h"
#include "KRPC.pb.h"

//#define KRPCI_DEBUG

#define KRPCI_SERVER_IP             "127.0.0.1"
#define KRPCI_RPC_SERVER_PORT           "50000"
#define KRPCI_STREAM_SERVER_PORT        "50001"

#define KRPCI_CLIENT_GUID_LEN               16
#define KRPCI_CLIENT_NAME_LEN               32

#define KRPCI_RECV_BUFFER_SIZE         1048576
#define KRPCI_HEADER_BUFFER_SIZE            10

using namespace std;

class KRPC_Exception : public exception
{
private: 
  std::string krpcErrorMessage;

public:
  KRPC_Exception(std::string msg) { krpcErrorMessage = msg; };

  virtual const char* what() const throw() {
    return krpcErrorMessage.c_str();
  }
};

class KRPCI
{
public:
  static KRPCI& getInstance();

  void Open();
  void Open(string ipAddress);
  void Close();

  void GetServices(KRPC::Services &krpcServices);

  INT  RecvHeader();
  BOOL SendRequest(KRPC::Request &krpcRequest);
  BOOL SendRequest(string krpcService, string krpcProcedure);
  BOOL RecvResponse(KRPC::Response &krpcResponse, INT numBytes);

  string GetKRPCServerVersion();

  // general util
  static void        PrintBytesHex(const char *buf, UINT size);

  static string      EncodeString(UINT16 tagNum, string str);

  static void        EncodeVarint(UINT32 value, BYTE *buf, INT &size);
  static void        EncodeVarint(UINT64 value, BYTE *buf, INT &size);

  static void        DecodeVarint(UINT32 &value, BYTE *buf, INT size);
  static void        DecodeVarint(UINT64 &value, BYTE *buf, INT size);

  static KRPC::Tuple GenerateTuple(double x, double y, double z);
  static void        UnpackTuple(KRPC::Tuple &tuple, double &x, double &y, double &z);

  atomic<bool> rpcServerIsConnected;

private:
  KRPCI() {};

  // dummy implementations.
  // avoids duplicates of this singleton class.
  KRPCI(KRPCI const&) = delete;
  void operator=(KRPCI const&) = delete;

  // KRPC Client thread
  static DWORD WINAPI rpcClientThread_stub(LPVOID lpParam);
  void                rpcClientThread_run();
  HANDLE              rpcClientThread;

  const UINT          RPC_CLIENT_THREAD_PERIOD_MS = 100;
  const UINT          RPC_CLIENT_RETRY_WAIT_MS    = 5000;
  const UINT          RPC_SERVER_HELLO_BUF_LEN    = 12;
  static const BYTE   RPC_SERVER_HELLO_BUF[];

  // KRPC Interface
  string krpcIPAddress;

  bool Connect_RPCServer();

  BOOL Request_Services(KRPC::Services &krpcServices);
  BOOL SendRequest_Services();
  BOOL RecvResponse_Services(KRPC::Services &krpcServices);

  BOOL Request_Status();
  BOOL SendRequest_Status();
  BOOL RecvResponse_Status(double &time, string &version);

  // KRPC Data
  ULONGLONG systemTime = 0l; // milliseconds
  string    KRPC_VERSION;
  BYTE      KRPCI_CLIENT_NAME[KRPCI_CLIENT_NAME_LEN];
  BYTE      KRPCI_CLIENT_GUID[KRPCI_CLIENT_GUID_LEN];
  double    krpcTime = 0.0;

  // threading variables
  atomic<bool> rpcServerTerminate;

  // networking
  WSADATA wsaData;
  SOCKET  rpcClientSocket           = INVALID_SOCKET;
  SOCKET  streamClientSocket        = INVALID_SOCKET;
  BYTE    rpcClientHeaderBuffer[KRPCI_HEADER_BUFFER_SIZE];
  BYTE   *rpcClientDataBuffer       = NULL;
  BYTE   *streamClientRecvBuffer    = NULL;

  SOCKET _connectToServer(char *ipAddr, char *port);
  INT    _recvData(SOCKET skt, BYTE *buffer, UINT size);
  INT    _sendVarint32(SOCKET skt, UINT32 value);
};

#endif // KRPCI_H
