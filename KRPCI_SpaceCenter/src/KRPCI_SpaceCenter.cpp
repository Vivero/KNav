#include "KRPCI_SpaceCenter.h"

void KRPCI_SpaceCenter::ClearTarget() {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("ClearTarget"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

void KRPCI_SpaceCenter::WarpTo(double UT, double maxRate) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("WarpTo"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  arg0->set_value((const char *)(&UT), sizeof(UT)); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&maxRate), sizeof(maxRate)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPC::Tuple KRPCI_SpaceCenter::TransformPosition(KRPC::Tuple position, REFERENCEFRAME from, REFERENCEFRAME to) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("TransformPosition"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  arg0->set_value(position.SerializeAsString()); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&from, sizeof(from));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  UINT64 uint_arg2 = 0;
  CopyMemory((void *)&uint_arg2, (void *)&to, sizeof(to));
  KRPCI::EncodeVarint(uint_arg2, uint_buf, uint_size);
  arg2->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::TransformDirection(KRPC::Tuple direction, REFERENCEFRAME from, REFERENCEFRAME to) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("TransformDirection"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  arg0->set_value(direction.SerializeAsString()); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&from, sizeof(from));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  UINT64 uint_arg2 = 0;
  CopyMemory((void *)&uint_arg2, (void *)&to, sizeof(to));
  KRPCI::EncodeVarint(uint_arg2, uint_buf, uint_size);
  arg2->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::TransformRotation(KRPC::Tuple rotation, REFERENCEFRAME from, REFERENCEFRAME to) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("TransformRotation"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  arg0->set_value(rotation.SerializeAsString()); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&from, sizeof(from));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  UINT64 uint_arg2 = 0;
  CopyMemory((void *)&uint_arg2, (void *)&to, sizeof(to));
  KRPCI::EncodeVarint(uint_arg2, uint_buf, uint_size);
  arg2->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::TransformVelocity(KRPC::Tuple position, KRPC::Tuple velocity, REFERENCEFRAME from, REFERENCEFRAME to) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("TransformVelocity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  arg0->set_value(position.SerializeAsString()); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(velocity.SerializeAsString()); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  UINT64 uint_arg2 = 0;
  CopyMemory((void *)&uint_arg2, (void *)&from, sizeof(from));
  KRPCI::EncodeVarint(uint_arg2, uint_buf, uint_size);
  arg2->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg3 = krpcRequest.add_arguments(); 
  arg3->set_position(3); 
  UINT64 uint_arg3 = 0;
  CopyMemory((void *)&uint_arg3, (void *)&to, sizeof(to));
  KRPCI::EncodeVarint(uint_arg3, uint_buf, uint_size);
  arg3->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::DrawDirection(KRPC::Tuple direction, REFERENCEFRAME referenceFrame, KRPC::Tuple color, float length) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DrawDirection"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  arg0->set_value(direction.SerializeAsString()); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  arg2->set_value(color.SerializeAsString()); 

  KRPC::Argument *arg3 = krpcRequest.add_arguments(); 
  arg3->set_position(3); 
  arg3->set_value((const char *)(&length), sizeof(length)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

void KRPCI_SpaceCenter::ClearDirections() {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("ClearDirections"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPCI_SpaceCenter::VESSEL KRPCI_SpaceCenter::get_ActiveVessel() {
  KRPCI_SpaceCenter::VESSEL retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("get_ActiveVessel"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::get_Vessels() {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("get_Vessels"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Dictionary KRPCI_SpaceCenter::get_Bodies() {
  KRPC::Dictionary retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("get_Bodies"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::CELESTIALBODY KRPCI_SpaceCenter::get_TargetBody() {
  KRPCI_SpaceCenter::CELESTIALBODY retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("get_TargetBody"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::set_TargetBody(CELESTIALBODY value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("set_TargetBody"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&value, sizeof(value));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPCI_SpaceCenter::VESSEL KRPCI_SpaceCenter::get_TargetVessel() {
  KRPCI_SpaceCenter::VESSEL retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("get_TargetVessel"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::set_TargetVessel(VESSEL value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("set_TargetVessel"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&value, sizeof(value));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPCI_SpaceCenter::DOCKINGPORT KRPCI_SpaceCenter::get_TargetDockingPort() {
  KRPCI_SpaceCenter::DOCKINGPORT retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("get_TargetDockingPort"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::set_TargetDockingPort(DOCKINGPORT value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("set_TargetDockingPort"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&value, sizeof(value));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

double KRPCI_SpaceCenter::get_UT() {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("get_UT"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::get_G() {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("get_G"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::get_FARAvailable() {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("get_FARAvailable"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::get_RemoteTechAvailable() {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("get_RemoteTechAvailable"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::AutoPilot_SetRotation(AUTOPILOT AutoPilot, double pitch, double heading, double roll, REFERENCEFRAME referenceFrame, bool wait) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("AutoPilot_SetRotation"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&AutoPilot, sizeof(AutoPilot));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&pitch), sizeof(pitch)); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  arg2->set_value((const char *)(&heading), sizeof(heading)); 

  KRPC::Argument *arg3 = krpcRequest.add_arguments(); 
  arg3->set_position(3); 
  arg3->set_value((const char *)(&roll), sizeof(roll)); 

  KRPC::Argument *arg4 = krpcRequest.add_arguments(); 
  arg4->set_position(4); 
  UINT64 uint_arg4 = 0;
  CopyMemory((void *)&uint_arg4, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg4, uint_buf, uint_size);
  arg4->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg5 = krpcRequest.add_arguments(); 
  arg5->set_position(5); 
  UINT32 uint_arg5 = wait;
  KRPCI::EncodeVarint(uint_arg5, uint_buf, uint_size);
  arg5->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

void KRPCI_SpaceCenter::AutoPilot_SetDirection(AUTOPILOT AutoPilot, KRPC::Tuple direction, double roll, REFERENCEFRAME referenceFrame, bool wait) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("AutoPilot_SetDirection"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&AutoPilot, sizeof(AutoPilot));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(direction.SerializeAsString()); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  arg2->set_value((const char *)(&roll), sizeof(roll)); 

  KRPC::Argument *arg3 = krpcRequest.add_arguments(); 
  arg3->set_position(3); 
  UINT64 uint_arg3 = 0;
  CopyMemory((void *)&uint_arg3, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg3, uint_buf, uint_size);
  arg3->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg4 = krpcRequest.add_arguments(); 
  arg4->set_position(4); 
  UINT32 uint_arg4 = wait;
  KRPCI::EncodeVarint(uint_arg4, uint_buf, uint_size);
  arg4->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

void KRPCI_SpaceCenter::AutoPilot_Disengage(AUTOPILOT AutoPilot) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("AutoPilot_Disengage"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&AutoPilot, sizeof(AutoPilot));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

double KRPCI_SpaceCenter::AutoPilot_get_Error(AUTOPILOT AutoPilot) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("AutoPilot_get_Error"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&AutoPilot, sizeof(AutoPilot));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::AutoPilot_get_RollError(AUTOPILOT AutoPilot) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("AutoPilot_get_RollError"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&AutoPilot, sizeof(AutoPilot));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_AtmospherePressureAt(CELESTIALBODY CelestialBody, double altitude) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_AtmospherePressureAt"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&altitude), sizeof(altitude)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_AtmosphereDensityAt(CELESTIALBODY CelestialBody, double altitude) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_AtmosphereDensityAt"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&altitude), sizeof(altitude)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::CelestialBody_Position(CELESTIALBODY CelestialBody, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_Position"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::CelestialBody_Velocity(CELESTIALBODY CelestialBody, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_Velocity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::CelestialBody_Rotation(CELESTIALBODY CelestialBody, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_Rotation"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::CelestialBody_Direction(CELESTIALBODY CelestialBody, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_Direction"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::CelestialBody_AngularVelocity(CELESTIALBODY CelestialBody, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_AngularVelocity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

string KRPCI_SpaceCenter::CelestialBody_get_Name(CELESTIALBODY CelestialBody) {
  string retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_Name"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval = string(krpcResponse.return_value().data() + 1, krpcResponse.return_value().size() - 1); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::CelestialBody_get_Satellites(CELESTIALBODY CelestialBody) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_Satellites"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_get_Mass(CELESTIALBODY CelestialBody) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_Mass"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_get_GravitationalParameter(CELESTIALBODY CelestialBody) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_GravitationalParameter"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_get_SurfaceGravity(CELESTIALBODY CelestialBody) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_SurfaceGravity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_get_RotationalPeriod(CELESTIALBODY CelestialBody) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_RotationalPeriod"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_get_RotationalSpeed(CELESTIALBODY CelestialBody) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_RotationalSpeed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_get_EquatorialRadius(CELESTIALBODY CelestialBody) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_EquatorialRadius"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_get_SphereOfInfluence(CELESTIALBODY CelestialBody) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_SphereOfInfluence"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::ORBIT KRPCI_SpaceCenter::CelestialBody_get_Orbit(CELESTIALBODY CelestialBody) {
  KRPCI_SpaceCenter::ORBIT retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_Orbit"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::CelestialBody_get_HasAtmosphere(CELESTIALBODY CelestialBody) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_HasAtmosphere"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_get_AtmospherePressure(CELESTIALBODY CelestialBody) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_AtmospherePressure"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_get_AtmosphereDensity(CELESTIALBODY CelestialBody) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_AtmosphereDensity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_get_AtmosphereScaleHeight(CELESTIALBODY CelestialBody) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_AtmosphereScaleHeight"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::CelestialBody_get_AtmosphereMaxAltitude(CELESTIALBODY CelestialBody) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_AtmosphereMaxAltitude"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::REFERENCEFRAME KRPCI_SpaceCenter::CelestialBody_get_ReferenceFrame(CELESTIALBODY CelestialBody) {
  KRPCI_SpaceCenter::REFERENCEFRAME retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_ReferenceFrame"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::REFERENCEFRAME KRPCI_SpaceCenter::CelestialBody_get_NonRotatingReferenceFrame(CELESTIALBODY CelestialBody) {
  KRPCI_SpaceCenter::REFERENCEFRAME retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_NonRotatingReferenceFrame"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::REFERENCEFRAME KRPCI_SpaceCenter::CelestialBody_get_OrbitalReferenceFrame(CELESTIALBODY CelestialBody) {
  KRPCI_SpaceCenter::REFERENCEFRAME retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("CelestialBody_get_OrbitalReferenceFrame"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&CelestialBody, sizeof(CelestialBody));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Comms_SignalDelayToVessel(COMMS Comms, VESSEL other) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Comms_SignalDelayToVessel"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Comms, sizeof(Comms));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&other, sizeof(other));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Comms_get_HasFlightComputer(COMMS Comms) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Comms_get_HasFlightComputer"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Comms, sizeof(Comms));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Comms_get_HasConnection(COMMS Comms) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Comms_get_HasConnection"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Comms, sizeof(Comms));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Comms_get_HasConnectionToGroundStation(COMMS Comms) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Comms_get_HasConnectionToGroundStation"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Comms, sizeof(Comms));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Comms_get_SignalDelay(COMMS Comms) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Comms_get_SignalDelay"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Comms, sizeof(Comms));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Comms_get_SignalDelayToGroundStation(COMMS Comms) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Comms_get_SignalDelayToGroundStation"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Comms, sizeof(Comms));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Control_ActivateNextStage(CONTROL Control) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_ActivateNextStage"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Control_GetActionGroup(CONTROL Control, UINT32 group) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_GetActionGroup"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&group, sizeof(group));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_SetActionGroup(CONTROL Control, UINT32 group, bool state) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_SetActionGroup"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&group, sizeof(group));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  UINT32 uint_arg2 = state;
  KRPCI::EncodeVarint(uint_arg2, uint_buf, uint_size);
  arg2->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

void KRPCI_SpaceCenter::Control_ToggleActionGroup(CONTROL Control, UINT32 group) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_ToggleActionGroup"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&group, sizeof(group));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPCI_SpaceCenter::NODE KRPCI_SpaceCenter::Control_AddNode(CONTROL Control, double UT, double prograde, double normal, double radial) {
  KRPCI_SpaceCenter::NODE retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_AddNode"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&UT), sizeof(UT)); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  arg2->set_value((const char *)(&prograde), sizeof(prograde)); 

  KRPC::Argument *arg3 = krpcRequest.add_arguments(); 
  arg3->set_position(3); 
  arg3->set_value((const char *)(&normal), sizeof(normal)); 

  KRPC::Argument *arg4 = krpcRequest.add_arguments(); 
  arg4->set_position(4); 
  arg4->set_value((const char *)(&radial), sizeof(radial)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_RemoveNodes(CONTROL Control) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_RemoveNodes"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

bool KRPCI_SpaceCenter::Control_get_SAS(CONTROL Control) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_SAS"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_SAS(CONTROL Control, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_SAS"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

bool KRPCI_SpaceCenter::Control_get_RCS(CONTROL Control) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_RCS"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_RCS(CONTROL Control, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_RCS"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

bool KRPCI_SpaceCenter::Control_get_Gear(CONTROL Control) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Gear"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_Gear(CONTROL Control, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_Gear"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

bool KRPCI_SpaceCenter::Control_get_Lights(CONTROL Control) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Lights"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_Lights(CONTROL Control, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_Lights"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

bool KRPCI_SpaceCenter::Control_get_Brakes(CONTROL Control) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Brakes"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_Brakes(CONTROL Control, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_Brakes"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

bool KRPCI_SpaceCenter::Control_get_Abort(CONTROL Control) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Abort"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_Abort(CONTROL Control, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_Abort"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Control_get_Throttle(CONTROL Control) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Throttle"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_Throttle(CONTROL Control, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_Throttle"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Control_get_Pitch(CONTROL Control) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Pitch"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_Pitch(CONTROL Control, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_Pitch"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Control_get_Yaw(CONTROL Control) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Yaw"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_Yaw(CONTROL Control, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_Yaw"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Control_get_Roll(CONTROL Control) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Roll"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_Roll(CONTROL Control, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_Roll"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Control_get_Forward(CONTROL Control) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Forward"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_Forward(CONTROL Control, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_Forward"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Control_get_Up(CONTROL Control) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Up"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_Up(CONTROL Control, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_Up"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Control_get_Right(CONTROL Control) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Right"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_Right(CONTROL Control, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_Right"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Control_get_WheelThrottle(CONTROL Control) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_WheelThrottle"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_WheelThrottle(CONTROL Control, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_WheelThrottle"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Control_get_WheelSteering(CONTROL Control) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_WheelSteering"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Control_set_WheelSteering(CONTROL Control, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_set_WheelSteering"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

INT32 KRPCI_SpaceCenter::Control_get_CurrentStage(CONTROL Control) {
  INT32 retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_CurrentStage"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 signedInt = 0; 
    KRPCI::DecodeVarint(signedInt, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 

    CopyMemory(&retval, &signedInt, sizeof(retval)); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Control_get_Nodes(CONTROL Control) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Control_get_Nodes"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Control, sizeof(Control));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_GForce(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_GForce"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_MeanAltitude(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_MeanAltitude"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_SurfaceAltitude(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_SurfaceAltitude"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_BedrockAltitude(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_BedrockAltitude"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_Elevation(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Elevation"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_Latitude(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Latitude"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_Longitude(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Longitude"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Flight_get_Velocity(FLIGHT Flight) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Velocity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_Speed(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Speed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_HorizontalSpeed(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_HorizontalSpeed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_VerticalSpeed(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_VerticalSpeed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Flight_get_CenterOfMass(FLIGHT Flight) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_CenterOfMass"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Flight_get_Rotation(FLIGHT Flight) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Rotation"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Flight_get_Direction(FLIGHT Flight) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Direction"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_Pitch(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Pitch"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_Heading(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Heading"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_Roll(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Roll"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Flight_get_Prograde(FLIGHT Flight) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Prograde"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Flight_get_Retrograde(FLIGHT Flight) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Retrograde"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Flight_get_Normal(FLIGHT Flight) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Normal"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Flight_get_AntiNormal(FLIGHT Flight) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_AntiNormal"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Flight_get_Radial(FLIGHT Flight) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Radial"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Flight_get_AntiRadial(FLIGHT Flight) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_AntiRadial"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_AtmosphereDensity(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_AtmosphereDensity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_Drag(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_Drag"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_DynamicPressure(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_DynamicPressure"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_AngleOfAttack(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_AngleOfAttack"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_SideslipAngle(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_SideslipAngle"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_StallFraction(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_StallFraction"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_MachNumber(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_MachNumber"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_TerminalVelocity(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_TerminalVelocity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_DragCoefficient(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_DragCoefficient"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_LiftCoefficient(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_LiftCoefficient"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_PitchingMomentCoefficient(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_PitchingMomentCoefficient"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_BallisticCoefficient(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_BallisticCoefficient"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Flight_get_ThrustSpecificFuelConsumption(FLIGHT Flight) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_ThrustSpecificFuelConsumption"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

string KRPCI_SpaceCenter::Flight_get_FARStatus(FLIGHT Flight) {
  string retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Flight_get_FARStatus"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Flight, sizeof(Flight));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval = string(krpcResponse.return_value().data() + 1, krpcResponse.return_value().size() - 1); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Node_BurnVector(NODE Node, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_BurnVector"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Node_RemainingBurnVector(NODE Node, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_RemainingBurnVector"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Node_Remove(NODE Node) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_Remove"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPC::Tuple KRPCI_SpaceCenter::Node_Position(NODE Node, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_Position"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Node_Direction(NODE Node, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_Direction"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Node_get_Prograde(NODE Node) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_get_Prograde"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Node_set_Prograde(NODE Node, double value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_set_Prograde"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

double KRPCI_SpaceCenter::Node_get_Normal(NODE Node) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_get_Normal"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Node_set_Normal(NODE Node, double value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_set_Normal"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

double KRPCI_SpaceCenter::Node_get_Radial(NODE Node) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_get_Radial"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Node_set_Radial(NODE Node, double value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_set_Radial"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

double KRPCI_SpaceCenter::Node_get_DeltaV(NODE Node) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_get_DeltaV"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Node_set_DeltaV(NODE Node, double value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_set_DeltaV"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

double KRPCI_SpaceCenter::Node_get_RemainingDeltaV(NODE Node) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_get_RemainingDeltaV"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Node_get_UT(NODE Node) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_get_UT"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Node_set_UT(NODE Node, double value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_set_UT"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

double KRPCI_SpaceCenter::Node_get_TimeTo(NODE Node) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_get_TimeTo"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::ORBIT KRPCI_SpaceCenter::Node_get_Orbit(NODE Node) {
  KRPCI_SpaceCenter::ORBIT retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_get_Orbit"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::REFERENCEFRAME KRPCI_SpaceCenter::Node_get_ReferenceFrame(NODE Node) {
  KRPCI_SpaceCenter::REFERENCEFRAME retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_get_ReferenceFrame"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::REFERENCEFRAME KRPCI_SpaceCenter::Node_get_OrbitalReferenceFrame(NODE Node) {
  KRPCI_SpaceCenter::REFERENCEFRAME retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Node_get_OrbitalReferenceFrame"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Node, sizeof(Node));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Orbit_ReferencePlaneNormal(ORBIT Orbit, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_ReferencePlaneNormal"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Orbit_ReferencePlaneDirection(ORBIT Orbit, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_ReferencePlaneDirection"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::CELESTIALBODY KRPCI_SpaceCenter::Orbit_get_Body(ORBIT Orbit) {
  KRPCI_SpaceCenter::CELESTIALBODY retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_Body"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_Apoapsis(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_Apoapsis"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_Periapsis(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_Periapsis"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_ApoapsisAltitude(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_ApoapsisAltitude"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_PeriapsisAltitude(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_PeriapsisAltitude"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_SemiMajorAxis(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_SemiMajorAxis"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_SemiMinorAxis(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_SemiMinorAxis"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_Radius(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_Radius"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_Speed(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_Speed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_Period(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_Period"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_TimeToApoapsis(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_TimeToApoapsis"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_TimeToPeriapsis(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_TimeToPeriapsis"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_Eccentricity(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_Eccentricity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_Inclination(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_Inclination"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_LongitudeOfAscendingNode(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_LongitudeOfAscendingNode"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_ArgumentOfPeriapsis(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_ArgumentOfPeriapsis"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_MeanAnomalyAtEpoch(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_MeanAnomalyAtEpoch"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_Epoch(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_Epoch"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_MeanAnomaly(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_MeanAnomaly"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_EccentricAnomaly(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_EccentricAnomaly"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::ORBIT KRPCI_SpaceCenter::Orbit_get_NextOrbit(ORBIT Orbit) {
  KRPCI_SpaceCenter::ORBIT retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_NextOrbit"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Orbit_get_TimeToSOIChange(ORBIT Orbit) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Orbit_get_TimeToSOIChange"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Orbit, sizeof(Orbit));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Decoupler_Decouple(DECOUPLER Decoupler) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Decoupler_Decouple"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Decoupler, sizeof(Decoupler));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::Decoupler_get_Part(DECOUPLER Decoupler) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Decoupler_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Decoupler, sizeof(Decoupler));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Decoupler_get_Decoupled(DECOUPLER Decoupler) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Decoupler_get_Decoupled"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Decoupler, sizeof(Decoupler));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::Decoupler_get_Impulse(DECOUPLER Decoupler) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Decoupler_get_Impulse"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Decoupler, sizeof(Decoupler));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::VESSEL KRPCI_SpaceCenter::DockingPort_Undock(DOCKINGPORT DockingPort) {
  KRPCI_SpaceCenter::VESSEL retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_Undock"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::DockingPort_Position(DOCKINGPORT DockingPort, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_Position"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::DockingPort_Direction(DOCKINGPORT DockingPort, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_Direction"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::DockingPort_Rotation(DOCKINGPORT DockingPort, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_Rotation"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::DockingPort_get_Part(DOCKINGPORT DockingPort) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

string KRPCI_SpaceCenter::DockingPort_get_Name(DOCKINGPORT DockingPort) {
  string retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_get_Name"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval = string(krpcResponse.return_value().data() + 1, krpcResponse.return_value().size() - 1); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::DockingPort_set_Name(DOCKINGPORT DockingPort, string value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_set_Name"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

INT32 KRPCI_SpaceCenter::DockingPort_get_State(DOCKINGPORT DockingPort) {
  INT32 retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_get_State"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 signedInt = 0; 
    KRPCI::DecodeVarint(signedInt, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 

    CopyMemory(&retval, &signedInt, sizeof(retval)); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::DockingPort_get_DockedPart(DOCKINGPORT DockingPort) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_get_DockedPart"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::DockingPort_get_ReengageDistance(DOCKINGPORT DockingPort) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_get_ReengageDistance"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::DockingPort_get_HasShield(DOCKINGPORT DockingPort) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_get_HasShield"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::DockingPort_get_Shielded(DOCKINGPORT DockingPort) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_get_Shielded"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::DockingPort_set_Shielded(DOCKINGPORT DockingPort, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_set_Shielded"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPCI_SpaceCenter::REFERENCEFRAME KRPCI_SpaceCenter::DockingPort_get_ReferenceFrame(DOCKINGPORT DockingPort) {
  KRPCI_SpaceCenter::REFERENCEFRAME retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("DockingPort_get_ReferenceFrame"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&DockingPort, sizeof(DockingPort));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::Engine_get_Part(ENGINE Engine) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Engine_get_Activated(ENGINE Engine) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_Activated"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Engine_set_Activated(ENGINE Engine, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_set_Activated"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Engine_get_ThrustLimit(ENGINE Engine) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_ThrustLimit"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Engine_set_ThrustLimit(ENGINE Engine, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_set_ThrustLimit"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Engine_get_Thrust(ENGINE Engine) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_Thrust"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::Engine_get_MaxThrust(ENGINE Engine) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_MaxThrust"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::Engine_get_SpecificImpulse(ENGINE Engine) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_SpecificImpulse"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::Engine_get_VacuumSpecificImpulse(ENGINE Engine) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_VacuumSpecificImpulse"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::Engine_get_KerbinSeaLevelSpecificImpulse(ENGINE Engine) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_KerbinSeaLevelSpecificImpulse"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Engine_get_Propellants(ENGINE Engine) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_Propellants"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Engine_get_HasFuel(ENGINE Engine) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_HasFuel"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Engine_get_ThrottleLocked(ENGINE Engine) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_ThrottleLocked"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Engine_get_CanRestart(ENGINE Engine) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_CanRestart"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Engine_get_CanShutdown(ENGINE Engine) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_CanShutdown"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Engine_get_Gimballed(ENGINE Engine) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_Gimballed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::Engine_get_GimbalRange(ENGINE Engine) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_GimbalRange"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Engine_get_GimbalLocked(ENGINE Engine) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_get_GimbalLocked"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Engine_set_GimbalLocked(ENGINE Engine, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Engine_set_GimbalLocked"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Engine, sizeof(Engine));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::LandingGear_get_Part(LANDINGGEAR LandingGear) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("LandingGear_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&LandingGear, sizeof(LandingGear));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

INT32 KRPCI_SpaceCenter::LandingGear_get_State(LANDINGGEAR LandingGear) {
  INT32 retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("LandingGear_get_State"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&LandingGear, sizeof(LandingGear));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 signedInt = 0; 
    KRPCI::DecodeVarint(signedInt, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 

    CopyMemory(&retval, &signedInt, sizeof(retval)); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::LandingGear_get_Deployed(LANDINGGEAR LandingGear) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("LandingGear_get_Deployed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&LandingGear, sizeof(LandingGear));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::LandingGear_set_Deployed(LANDINGGEAR LandingGear, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("LandingGear_set_Deployed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&LandingGear, sizeof(LandingGear));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::LandingLeg_get_Part(LANDINGLEG LandingLeg) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("LandingLeg_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&LandingLeg, sizeof(LandingLeg));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

INT32 KRPCI_SpaceCenter::LandingLeg_get_State(LANDINGLEG LandingLeg) {
  INT32 retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("LandingLeg_get_State"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&LandingLeg, sizeof(LandingLeg));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 signedInt = 0; 
    KRPCI::DecodeVarint(signedInt, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 

    CopyMemory(&retval, &signedInt, sizeof(retval)); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::LandingLeg_get_Deployed(LANDINGLEG LandingLeg) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("LandingLeg_get_Deployed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&LandingLeg, sizeof(LandingLeg));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::LandingLeg_set_Deployed(LANDINGLEG LandingLeg, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("LandingLeg_set_Deployed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&LandingLeg, sizeof(LandingLeg));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

void KRPCI_SpaceCenter::LaunchClamp_Release(LAUNCHCLAMP LaunchClamp) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("LaunchClamp_Release"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&LaunchClamp, sizeof(LaunchClamp));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::LaunchClamp_get_Part(LAUNCHCLAMP LaunchClamp) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("LaunchClamp_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&LaunchClamp, sizeof(LaunchClamp));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::Light_get_Part(LIGHT Light) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Light_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Light, sizeof(Light));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Light_get_Active(LIGHT Light) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Light_get_Active"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Light, sizeof(Light));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Light_set_Active(LIGHT Light, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Light_set_Active"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Light, sizeof(Light));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Light_get_PowerUsage(LIGHT Light) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Light_get_PowerUsage"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Light, sizeof(Light));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Module_HasField(MODULE Module, string name) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Module_HasField"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Module, sizeof(Module));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

string KRPCI_SpaceCenter::Module_GetField(MODULE Module, string name) {
  string retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Module_GetField"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Module, sizeof(Module));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval = string(krpcResponse.return_value().data() + 1, krpcResponse.return_value().size() - 1); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Module_HasEvent(MODULE Module, string name) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Module_HasEvent"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Module, sizeof(Module));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Module_TriggerEvent(MODULE Module, string name) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Module_TriggerEvent"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Module, sizeof(Module));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

bool KRPCI_SpaceCenter::Module_HasAction(MODULE Module, string name) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Module_HasAction"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Module, sizeof(Module));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Module_SetAction(MODULE Module, string name, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Module_SetAction"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Module, sizeof(Module));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  UINT32 uint_arg2 = value;
  KRPCI::EncodeVarint(uint_arg2, uint_buf, uint_size);
  arg2->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

string KRPCI_SpaceCenter::Module_get_Name(MODULE Module) {
  string retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Module_get_Name"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Module, sizeof(Module));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval = string(krpcResponse.return_value().data() + 1, krpcResponse.return_value().size() - 1); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::Module_get_Part(MODULE Module) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Module_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Module, sizeof(Module));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::Dictionary KRPCI_SpaceCenter::Module_get_Fields(MODULE Module) {
  KRPC::Dictionary retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Module_get_Fields"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Module, sizeof(Module));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Module_get_Events(MODULE Module) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Module_get_Events"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Module, sizeof(Module));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Module_get_Actions(MODULE Module) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Module_get_Actions"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Module, sizeof(Module));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Parachute_Deploy(PARACHUTE Parachute) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parachute_Deploy"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parachute, sizeof(Parachute));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::Parachute_get_Part(PARACHUTE Parachute) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parachute_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parachute, sizeof(Parachute));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Parachute_get_Deployed(PARACHUTE Parachute) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parachute_get_Deployed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parachute, sizeof(Parachute));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

INT32 KRPCI_SpaceCenter::Parachute_get_State(PARACHUTE Parachute) {
  INT32 retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parachute_get_State"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parachute, sizeof(Parachute));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 signedInt = 0; 
    KRPCI::DecodeVarint(signedInt, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 

    CopyMemory(&retval, &signedInt, sizeof(retval)); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::Parachute_get_DeployAltitude(PARACHUTE Parachute) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parachute_get_DeployAltitude"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parachute, sizeof(Parachute));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Parachute_set_DeployAltitude(PARACHUTE Parachute, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parachute_set_DeployAltitude"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parachute, sizeof(Parachute));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

float KRPCI_SpaceCenter::Parachute_get_DeployMinPressure(PARACHUTE Parachute) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parachute_get_DeployMinPressure"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parachute, sizeof(Parachute));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Parachute_set_DeployMinPressure(PARACHUTE Parachute, float value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parachute_set_DeployMinPressure"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parachute, sizeof(Parachute));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value((const char *)(&value), sizeof(value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPC::Tuple KRPCI_SpaceCenter::Part_Position(PART Part, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_Position"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Part_Direction(PART Part, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_Direction"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Part_Velocity(PART Part, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_Velocity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Part_Rotation(PART Part, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_Rotation"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

string KRPCI_SpaceCenter::Part_get_Name(PART Part) {
  string retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Name"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval = string(krpcResponse.return_value().data() + 1, krpcResponse.return_value().size() - 1); 
  } 

  return retval; 
} 

string KRPCI_SpaceCenter::Part_get_Title(PART Part) {
  string retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Title"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval = string(krpcResponse.return_value().data() + 1, krpcResponse.return_value().size() - 1); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Part_get_Cost(PART Part) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Cost"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::VESSEL KRPCI_SpaceCenter::Part_get_Vessel(PART Part) {
  KRPCI_SpaceCenter::VESSEL retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Vessel"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::Part_get_Parent(PART Part) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Parent"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Part_get_Children(PART Part) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Children"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Part_get_AxiallyAttached(PART Part) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_AxiallyAttached"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Part_get_RadiallyAttached(PART Part) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_RadiallyAttached"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

INT32 KRPCI_SpaceCenter::Part_get_Stage(PART Part) {
  INT32 retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Stage"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 signedInt = 0; 
    KRPCI::DecodeVarint(signedInt, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 

    CopyMemory(&retval, &signedInt, sizeof(retval)); 
  } 

  return retval; 
} 

INT32 KRPCI_SpaceCenter::Part_get_DecoupleStage(PART Part) {
  INT32 retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_DecoupleStage"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 signedInt = 0; 
    KRPCI::DecodeVarint(signedInt, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 

    CopyMemory(&retval, &signedInt, sizeof(retval)); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Part_get_Massless(PART Part) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Massless"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Part_get_Mass(PART Part) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Mass"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Part_get_DryMass(PART Part) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_DryMass"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Part_get_ImpactTolerance(PART Part) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_ImpactTolerance"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Part_get_Temperature(PART Part) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Temperature"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Part_get_MaxTemperature(PART Part) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_MaxTemperature"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PARTRESOURCES KRPCI_SpaceCenter::Part_get_Resources(PART Part) {
  KRPCI_SpaceCenter::PARTRESOURCES retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Resources"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Part_get_Crossfeed(PART Part) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Crossfeed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Part_get_FuelLinesFrom(PART Part) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_FuelLinesFrom"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Part_get_FuelLinesTo(PART Part) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_FuelLinesTo"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Part_get_Modules(PART Part) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Modules"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::DECOUPLER KRPCI_SpaceCenter::Part_get_Decoupler(PART Part) {
  KRPCI_SpaceCenter::DECOUPLER retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Decoupler"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::DOCKINGPORT KRPCI_SpaceCenter::Part_get_DockingPort(PART Part) {
  KRPCI_SpaceCenter::DOCKINGPORT retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_DockingPort"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::ENGINE KRPCI_SpaceCenter::Part_get_Engine(PART Part) {
  KRPCI_SpaceCenter::ENGINE retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Engine"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::LANDINGGEAR KRPCI_SpaceCenter::Part_get_LandingGear(PART Part) {
  KRPCI_SpaceCenter::LANDINGGEAR retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_LandingGear"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::LANDINGLEG KRPCI_SpaceCenter::Part_get_LandingLeg(PART Part) {
  KRPCI_SpaceCenter::LANDINGLEG retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_LandingLeg"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::LAUNCHCLAMP KRPCI_SpaceCenter::Part_get_LaunchClamp(PART Part) {
  KRPCI_SpaceCenter::LAUNCHCLAMP retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_LaunchClamp"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::LIGHT KRPCI_SpaceCenter::Part_get_Light(PART Part) {
  KRPCI_SpaceCenter::LIGHT retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Light"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PARACHUTE KRPCI_SpaceCenter::Part_get_Parachute(PART Part) {
  KRPCI_SpaceCenter::PARACHUTE retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Parachute"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::REACTIONWHEEL KRPCI_SpaceCenter::Part_get_ReactionWheel(PART Part) {
  KRPCI_SpaceCenter::REACTIONWHEEL retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_ReactionWheel"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::SENSOR KRPCI_SpaceCenter::Part_get_Sensor(PART Part) {
  KRPCI_SpaceCenter::SENSOR retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_Sensor"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::SOLARPANEL KRPCI_SpaceCenter::Part_get_SolarPanel(PART Part) {
  KRPCI_SpaceCenter::SOLARPANEL retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_SolarPanel"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::REFERENCEFRAME KRPCI_SpaceCenter::Part_get_ReferenceFrame(PART Part) {
  KRPCI_SpaceCenter::REFERENCEFRAME retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Part_get_ReferenceFrame"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Part, sizeof(Part));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_WithName(PARTS Parts, string name) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_WithName"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_WithTitle(PARTS Parts, string title) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_WithTitle"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, title)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_WithModule(PARTS Parts, string moduleName) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_WithModule"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, moduleName)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_InStage(PARTS Parts, INT32 stage) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_InStage"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&stage, sizeof(stage));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_InDecoupleStage(PARTS Parts, INT32 stage) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_InDecoupleStage"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&stage, sizeof(stage));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_ModulesWithName(PARTS Parts, string moduleName) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_ModulesWithName"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, moduleName)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::DOCKINGPORT KRPCI_SpaceCenter::Parts_DockingPortWithName(PARTS Parts, string name) {
  KRPCI_SpaceCenter::DOCKINGPORT retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_DockingPortWithName"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_All(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_All"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::Parts_get_Root(PARTS Parts) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_Root"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::Parts_get_Controlling(PARTS Parts) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_Controlling"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Parts_set_Controlling(PARTS Parts, PART value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_set_Controlling"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&value, sizeof(value));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_Decouplers(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_Decouplers"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_DockingPorts(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_DockingPorts"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_Engines(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_Engines"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_LandingGear(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_LandingGear"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_LandingLegs(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_LandingLegs"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_LaunchClamps(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_LaunchClamps"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_Lights(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_Lights"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_Parachutes(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_Parachutes"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_ReactionWheels(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_ReactionWheels"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_Sensors(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_Sensors"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::Parts_get_SolarPanels(PARTS Parts) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Parts_get_SolarPanels"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Parts, sizeof(Parts));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::PartResources_HasResource(PARTRESOURCES PartResources, string name) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("PartResources_HasResource"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&PartResources, sizeof(PartResources));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::PartResources_Max(PARTRESOURCES PartResources, string name) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("PartResources_Max"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&PartResources, sizeof(PartResources));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::PartResources_Amount(PARTRESOURCES PartResources, string name) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("PartResources_Amount"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&PartResources, sizeof(PartResources));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::PartResources_get_Names(PARTRESOURCES PartResources) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("PartResources_get_Names"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&PartResources, sizeof(PartResources));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::ReactionWheel_get_Part(REACTIONWHEEL ReactionWheel) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("ReactionWheel_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&ReactionWheel, sizeof(ReactionWheel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::ReactionWheel_get_Active(REACTIONWHEEL ReactionWheel) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("ReactionWheel_get_Active"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&ReactionWheel, sizeof(ReactionWheel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::ReactionWheel_set_Active(REACTIONWHEEL ReactionWheel, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("ReactionWheel_set_Active"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&ReactionWheel, sizeof(ReactionWheel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

bool KRPCI_SpaceCenter::ReactionWheel_get_Broken(REACTIONWHEEL ReactionWheel) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("ReactionWheel_get_Broken"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&ReactionWheel, sizeof(ReactionWheel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::ReactionWheel_get_PitchTorque(REACTIONWHEEL ReactionWheel) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("ReactionWheel_get_PitchTorque"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&ReactionWheel, sizeof(ReactionWheel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::ReactionWheel_get_YawTorque(REACTIONWHEEL ReactionWheel) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("ReactionWheel_get_YawTorque"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&ReactionWheel, sizeof(ReactionWheel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::ReactionWheel_get_RollTorque(REACTIONWHEEL ReactionWheel) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("ReactionWheel_get_RollTorque"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&ReactionWheel, sizeof(ReactionWheel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::Sensor_get_Part(SENSOR Sensor) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Sensor_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Sensor, sizeof(Sensor));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::Sensor_get_Active(SENSOR Sensor) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Sensor_get_Active"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Sensor, sizeof(Sensor));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Sensor_set_Active(SENSOR Sensor, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Sensor_set_Active"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Sensor, sizeof(Sensor));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

string KRPCI_SpaceCenter::Sensor_get_Value(SENSOR Sensor) {
  string retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Sensor_get_Value"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Sensor, sizeof(Sensor));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval = string(krpcResponse.return_value().data() + 1, krpcResponse.return_value().size() - 1); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::Sensor_get_PowerUsage(SENSOR Sensor) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Sensor_get_PowerUsage"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Sensor, sizeof(Sensor));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PART KRPCI_SpaceCenter::SolarPanel_get_Part(SOLARPANEL SolarPanel) {
  KRPCI_SpaceCenter::PART retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("SolarPanel_get_Part"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&SolarPanel, sizeof(SolarPanel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::SolarPanel_get_Deployed(SOLARPANEL SolarPanel) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("SolarPanel_get_Deployed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&SolarPanel, sizeof(SolarPanel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::SolarPanel_set_Deployed(SOLARPANEL SolarPanel, bool value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("SolarPanel_set_Deployed"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&SolarPanel, sizeof(SolarPanel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = value;
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

INT32 KRPCI_SpaceCenter::SolarPanel_get_State(SOLARPANEL SolarPanel) {
  INT32 retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("SolarPanel_get_State"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&SolarPanel, sizeof(SolarPanel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 signedInt = 0; 
    KRPCI::DecodeVarint(signedInt, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 

    CopyMemory(&retval, &signedInt, sizeof(retval)); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::SolarPanel_get_EnergyFlow(SOLARPANEL SolarPanel) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("SolarPanel_get_EnergyFlow"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&SolarPanel, sizeof(SolarPanel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

float KRPCI_SpaceCenter::SolarPanel_get_SunExposure(SOLARPANEL SolarPanel) {
  float retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("SolarPanel_get_SunExposure"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&SolarPanel, sizeof(SolarPanel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::FLIGHT KRPCI_SpaceCenter::Vessel_Flight(VESSEL Vessel, REFERENCEFRAME referenceFrame) {
  KRPCI_SpaceCenter::FLIGHT retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_Flight"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Vessel_Position(VESSEL Vessel, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_Position"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Vessel_Velocity(VESSEL Vessel, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_Velocity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Vessel_Rotation(VESSEL Vessel, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_Rotation"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Vessel_Direction(VESSEL Vessel, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_Direction"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

KRPC::Tuple KRPCI_SpaceCenter::Vessel_AngularVelocity(VESSEL Vessel, REFERENCEFRAME referenceFrame) {
  KRPC::Tuple retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_AngularVelocity"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&referenceFrame, sizeof(referenceFrame));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

string KRPCI_SpaceCenter::Vessel_get_Name(VESSEL Vessel) {
  string retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_Name"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval = string(krpcResponse.return_value().data() + 1, krpcResponse.return_value().size() - 1); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Vessel_set_Name(VESSEL Vessel, string value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_set_Name"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, value)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

INT32 KRPCI_SpaceCenter::Vessel_get_Type(VESSEL Vessel) {
  INT32 retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_Type"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 signedInt = 0; 
    KRPCI::DecodeVarint(signedInt, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 

    CopyMemory(&retval, &signedInt, sizeof(retval)); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Vessel_set_Type(VESSEL Vessel, INT32 value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_set_Type"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT32 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&value, sizeof(value));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

INT32 KRPCI_SpaceCenter::Vessel_get_Situation(VESSEL Vessel) {
  INT32 retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_Situation"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 signedInt = 0; 
    KRPCI::DecodeVarint(signedInt, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 

    CopyMemory(&retval, &signedInt, sizeof(retval)); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Vessel_get_MET(VESSEL Vessel) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_MET"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::VESSEL KRPCI_SpaceCenter::Vessel_get_Target(VESSEL Vessel) {
  KRPCI_SpaceCenter::VESSEL retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_Target"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

void KRPCI_SpaceCenter::Vessel_set_Target(VESSEL Vessel, VESSEL value) {
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_set_Target"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  UINT64 uint_arg1 = 0;
  CopyMemory((void *)&uint_arg1, (void *)&value, sizeof(value));
  KRPCI::EncodeVarint(uint_arg1, uint_buf, uint_size);
  arg1->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
} 

KRPCI_SpaceCenter::ORBIT KRPCI_SpaceCenter::Vessel_get_Orbit(VESSEL Vessel) {
  KRPCI_SpaceCenter::ORBIT retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_Orbit"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::CONTROL KRPCI_SpaceCenter::Vessel_get_Control(VESSEL Vessel) {
  KRPCI_SpaceCenter::CONTROL retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_Control"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::AUTOPILOT KRPCI_SpaceCenter::Vessel_get_AutoPilot(VESSEL Vessel) {
  KRPCI_SpaceCenter::AUTOPILOT retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_AutoPilot"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::VESSELRESOURCES KRPCI_SpaceCenter::Vessel_get_Resources(VESSEL Vessel) {
  KRPCI_SpaceCenter::VESSELRESOURCES retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_Resources"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::PARTS KRPCI_SpaceCenter::Vessel_get_Parts(VESSEL Vessel) {
  KRPCI_SpaceCenter::PARTS retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_Parts"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::COMMS KRPCI_SpaceCenter::Vessel_get_Comms(VESSEL Vessel) {
  KRPCI_SpaceCenter::COMMS retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_Comms"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Vessel_get_Mass(VESSEL Vessel) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_Mass"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Vessel_get_DryMass(VESSEL Vessel) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_DryMass"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Vessel_get_CrossSectionalArea(VESSEL Vessel) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_CrossSectionalArea"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Vessel_get_Thrust(VESSEL Vessel) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_Thrust"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::Vessel_get_SpecificImpulse(VESSEL Vessel) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_SpecificImpulse"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::REFERENCEFRAME KRPCI_SpaceCenter::Vessel_get_ReferenceFrame(VESSEL Vessel) {
  KRPCI_SpaceCenter::REFERENCEFRAME retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_ReferenceFrame"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::REFERENCEFRAME KRPCI_SpaceCenter::Vessel_get_OrbitalReferenceFrame(VESSEL Vessel) {
  KRPCI_SpaceCenter::REFERENCEFRAME retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_OrbitalReferenceFrame"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::REFERENCEFRAME KRPCI_SpaceCenter::Vessel_get_SurfaceReferenceFrame(VESSEL Vessel) {
  KRPCI_SpaceCenter::REFERENCEFRAME retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_SurfaceReferenceFrame"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPCI_SpaceCenter::REFERENCEFRAME KRPCI_SpaceCenter::Vessel_get_SurfaceVelocityReferenceFrame(VESSEL Vessel) {
  KRPCI_SpaceCenter::REFERENCEFRAME retval = 0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("Vessel_get_SurfaceVelocityReferenceFrame"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&Vessel, sizeof(Vessel));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    KRPCI::DecodeVarint(retval, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

bool KRPCI_SpaceCenter::VesselResources_HasResource(VESSELRESOURCES VesselResources, string name) {
  bool retval = false; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("VesselResources_HasResource"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&VesselResources, sizeof(VesselResources));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    UINT32 boolValue = 0; 
    KRPCI::DecodeVarint(boolValue, (BYTE *)krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
    retval = (boolValue != 0); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::VesselResources_Max(VESSELRESOURCES VesselResources, string name, INT32 stage, bool cumulative) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("VesselResources_Max"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&VesselResources, sizeof(VesselResources));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  UINT32 uint_arg2 = 0;
  CopyMemory((void *)&uint_arg2, (void *)&stage, sizeof(stage));
  KRPCI::EncodeVarint(uint_arg2, uint_buf, uint_size);
  arg2->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg3 = krpcRequest.add_arguments(); 
  arg3->set_position(3); 
  UINT32 uint_arg3 = cumulative;
  KRPCI::EncodeVarint(uint_arg3, uint_buf, uint_size);
  arg3->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

double KRPCI_SpaceCenter::VesselResources_Amount(VESSELRESOURCES VesselResources, string name, INT32 stage, bool cumulative) {
  double retval = 0.0; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("VesselResources_Amount"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&VesselResources, sizeof(VesselResources));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg1 = krpcRequest.add_arguments(); 
  arg1->set_position(1); 
  arg1->set_value(KRPCI::EncodeString(2, name)); 

  KRPC::Argument *arg2 = krpcRequest.add_arguments(); 
  arg2->set_position(2); 
  UINT32 uint_arg2 = 0;
  CopyMemory((void *)&uint_arg2, (void *)&stage, sizeof(stage));
  KRPCI::EncodeVarint(uint_arg2, uint_buf, uint_size);
  arg2->set_value((const char *)uint_buf, uint_size); 

  KRPC::Argument *arg3 = krpcRequest.add_arguments(); 
  arg3->set_position(3); 
  UINT32 uint_arg3 = cumulative;
  KRPCI::EncodeVarint(uint_arg3, uint_buf, uint_size);
  arg3->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    CopyMemory(&retval, krpcResponse.return_value().data(), krpcResponse.return_value().size()); 
  } 

  return retval; 
} 

KRPC::List KRPCI_SpaceCenter::VesselResources_get_Names(VESSELRESOURCES VesselResources) {
  KRPC::List retval; 
  KRPC::Request krpcRequest; 
  KRPCI &krpcInterface = KRPCI::getInstance(); 

  krpcRequest.set_service("SpaceCenter"); 
  krpcRequest.set_procedure("VesselResources_get_Names"); 

  BYTE uint_buf[10]; INT uint_size = 0; 
  KRPC::Argument *arg0 = krpcRequest.add_arguments(); 
  arg0->set_position(0); 
  UINT64 uint_arg0 = 0;
  CopyMemory((void *)&uint_arg0, (void *)&VesselResources, sizeof(VesselResources));
  KRPCI::EncodeVarint(uint_arg0, uint_buf, uint_size);
  arg0->set_value((const char *)uint_buf, uint_size); 

  krpcInterface.SendRequest(krpcRequest); 

  INT header = krpcInterface.RecvHeader(); 
  KRPC::Response krpcResponse; 
  krpcInterface.RecvResponse(krpcResponse, header); 

  if (krpcResponse.has_error()) { 
    throw KRPC_Exception(krpcResponse.error()); 
  } 
  else if (krpcResponse.has_return_value()) { 
    retval.ParseFromString(krpcResponse.return_value()); 
  } 

  return retval; 
} 

