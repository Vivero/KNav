#ifndef KNAV_TELEMETRY_H
#define KNAV_TELEMETRY_H

#include "stdafx.h"
#include "KRPCI.h"
#include "KRPCI_SpaceCenter.h"

#define KNAV_TELEMETRY_SLEEP_PERIOD_MS 50

class KNav_Telemetry
{
  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                   %=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%  P U B L I C   I N T E R F A C E  %=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                   %=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
public:

  //
  //  TYPES
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // struct for general 3-value vector
  //
  typedef struct Vector3d {
    Vector3d() : x(0.0), y(0.0), z(0.0) {}

    double x;
    double y;
    double z;
  } Vector3d_t;

  // struct to hold all vessel telemetry
  //
  typedef struct VesselTelemetry {
    VesselTelemetry() : vessel(0), flight(0), control(0),
    situation(KRPCI_SpaceCenter::VesselSituation_PreLaunch), autopilot(0),
    name(""), mass(0.0), dry_mass(0.0), mission_elapsed_time(0.0), 
    vessel_ref(0), surface_ref(0), orbit(0), orbit_body(0), 
    orbit_body_ref(0), orbit_body_mass(0.0), orbit_body_distance(0.0),
    verticalSpeed(0.0), radarAltitude(0.0), maxThrust(0.0),
    throttle(0.0), gravitationalForce(0.0) {}

    KRPCI_SpaceCenter::VESSEL          vessel;
    KRPCI_SpaceCenter::FLIGHT          flight;
    KRPCI_SpaceCenter::CONTROL         control;
    KRPCI_SpaceCenter::VesselSituation situation;
    KRPCI_SpaceCenter::AUTOPILOT       autopilot;
    std::string                        name;
    double                             mass;
    double                             dry_mass;
    double                             mission_elapsed_time;
    KRPCI_SpaceCenter::REFERENCEFRAME  vessel_ref;
    KRPCI_SpaceCenter::REFERENCEFRAME  surface_ref;
    KRPCI_SpaceCenter::ORBIT           orbit;
    KRPCI_SpaceCenter::CELESTIALBODY   orbit_body;
    KRPCI_SpaceCenter::REFERENCEFRAME  orbit_body_ref;
    double                             orbit_body_mass;
    double                             orbit_body_distance;
    double                             verticalSpeed;
    double                             radarAltitude;
    double                             maxThrust;
    double                             throttle;
    double                             gravitationalForce;
  } VesselTelemetry_t;

  // struct for one-way commands to kRPC
  //
  typedef struct Command {
    Command() : timestamp(0.0) {}

    double                timestamp;
    std::function<void()> controlFunction;
  } Command_t;

  // struct for asynchronous messaging with kRPC
  //
  template<class output_t> struct AsyncMessage {
    std::function<output_t()> controlFunction;
    output_t                  output;
    BOOL                      complete;
  };

  // define message with Tuple return value
  typedef AsyncMessage<KRPC::Tuple> AsyncMessageTuple_t;

  //
  //  METHODS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // constructor/destructor
  //
  KNav_Telemetry();
  ~KNav_Telemetry() {};

  // entry point functions
  //
  void                      Open();
  void                      Close();

  // debug
  //
  void                      GetDebugMessage(double &timestamp, std::string &msg);
  void                      SetDebugMessage(std::string &msg);

  // command buffering
  //
  void                      PushCommand(std::function<void()> &controlFunction);

  // async messaging
  //
  static VOID CALLBACK      AsyncMessage(ULONG_PTR dwParam);


  //
  //  PUBLIC MEMBERS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  AsyncMessageTuple_t       asyncMessage;


  //
  //  READ-ONLY MEMBERS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // class info
  const HANDLE             &rpcClientThread;

  // vessel info
  const VesselTelemetry_t  &activeVessel;
  const BOOL               &inFlight;

  // environment info
  const double             &kspUniversalTime;
  const double             &kspGravConstant;

  // performance counters
  const double             &avgExecutionTime_ms;
  const UINT               &executionCount;
  const UINT               &commandBufferSize;
  const UINT               &numAsyncCalls;



  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                  =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%  P R I V A T E   M E M B E R S   =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                  =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
private:

  //
  //  METHODS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // entry point functions
  //
  void                 Update();
  void                 Control();

  // command buffering
  //
  BOOL                 PopCommand(KNav_Telemetry::Command_t &cmd);

  // threading
  //
  static DWORD WINAPI  rpcClientThread_stub(LPVOID lpParam);
  void                 rpcClientThread_run();

  // utility functions
  //
  Vector3d_t           Vessel_Position(
                         KRPCI_SpaceCenter::VESSEL vessel, 
                         KRPCI_SpaceCenter::REFERENCEFRAME referenceFrame);

  double               Vessel_DistanceToBody(
                         KRPCI_SpaceCenter::VESSEL Vessel, 
                         KRPCI_SpaceCenter::REFERENCEFRAME referenceFrame);


  //
  //  PRIVATE MEMBERS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // command buffer structures
  std::list<Command_t> commandList;
  HANDLE               commandListMutex;
  
  // debug information
  double               debugTimestamp;
  std::string          debugMessage;

  // class info
  ULONGLONG            systemTime_ms;

  // performance counters
  ULONGLONG            executionTime_ms;
  ULONGLONG            accExecutionTime_ms;
  
  // threading
  atomic<bool>         rpcClientTerminate;
  ULONGLONG            elapsedTime_ms;
  LONGLONG             sleepPeriod;



  // private copies of read-only members
  //----------------------------------------------------------------------------

  // class info
  HANDLE              _rpcClientThread;

  // vessel info
  VesselTelemetry_t   _activeVessel;
  BOOL                _inFlight;

  // environment info
  double              _kspUniversalTime;
  double              _kspGravConstant;

  // performance counters
  double              _avgExecutionTime_ms;
  UINT                _executionCount;
  UINT                _commandBufferSize;
  UINT                _numAsyncCalls;
  
};

#endif // KNAV_TELEMETRY_H
