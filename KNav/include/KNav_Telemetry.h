#ifndef KNAV_TELEMETRY_H
#define KNAV_TELEMETRY_H

#include "stdafx.h"
#include "KRPCI.h"
#include "KRPCI_SpaceCenter.h"

#define KNAV_TELEMETRY_SLEEP_PERIOD_MS 50

class KNav_Telemetry
{
public:

  typedef struct Vector3d {
    Vector3d() : x(0.0), y(0.0), z(0.0) {}

    double x;
    double y;
    double z;
  } Vector3d_t;

  typedef struct VesselTelemetry {
    VesselTelemetry() : vessel(0), flight(0), control(0),
    situation(KRPCI_SpaceCenter::VesselSituation_PreLaunch), autopilot(0),
    name(""), mass(0.0), dry_mass(0.0), vessel_ref(0),
    surface_ref(0), orbit(0), orbit_body(0), orbit_body_ref(0),
    orbit_body_mass(0.0), orbit_body_distance(0.0),
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

  typedef struct Command {
    Command() : timestamp(0.0) {}

    double                timestamp;
    std::function<void()> controlFunction;
  } Command_t;

  KNav_Telemetry();
  ~KNav_Telemetry() {};

  void Open();
  void Close();

  VesselTelemetry_t   activeVessel;
  double              kspUniversalTime;
  double              kspGravConstant;

  void                GetDebugMessage(double &timestamp, std::string &msg);

  BOOL                inFlight;

  void                PushCommand(std::function<void()> &controlFunction);

private:

  void Update();
  void Control();

  // control structures
  std::list<Command_t> commandList;
  HANDLE               commandListMutex;
  BOOL                 PopCommand(KNav_Telemetry::Command_t &cmd);
  

  KNav_Telemetry::Vector3d_t Vessel_Position(KRPCI_SpaceCenter::VESSEL vessel, KRPCI_SpaceCenter::REFERENCEFRAME referenceFrame);
  double                     Vessel_DistanceToBody(KRPCI_SpaceCenter::VESSEL Vessel, KRPCI_SpaceCenter::REFERENCEFRAME referenceFrame);

  double       debugTimestamp;
  std::string  debugMessage;
  void         SetDebugMessage(std::string &msg);

  // threading
  static DWORD WINAPI rpcClientThread_stub(LPVOID lpParam);
  void                rpcClientThread_run();
  HANDLE              rpcClientThread;
  atomic<bool>        rpcClientTerminate;
  ULONGLONG           systemTime_ms, executionTime_ms;
  LONGLONG            sleepPeriod;
};

#endif // KNAV_TELEMETRY_H