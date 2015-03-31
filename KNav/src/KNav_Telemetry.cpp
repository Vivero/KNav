#include "KNav_Telemetry.h"

KNav_Telemetry::KNav_Telemetry() :
kspUniversalTime(0.0),
systemTime_ms(0),
executionTime_ms(0),
sleepPeriod(0),
inFlight(FALSE),
debugTimestamp(0.0)
{
  commandListMutex = CreateMutex(
    NULL,              // default security attributes
    FALSE,             // initially not owned
    L"controlList");   // mutex name

  if (commandListMutex == NULL) {
    printf("WARNING: Failed to create mutex controlList");
  }
}


void KNav_Telemetry::Open()
{
  rpcClientTerminate = FALSE;
  rpcClientThread = CreateThread(
    NULL,                   // default security attributes
    0,                      // use default stack size  
    rpcClientThread_stub,   // thread function name
    this,                   // argument to thread function 
    0,                      // use default creation flags 
    NULL);                  // returns the thread identifier
}

void KNav_Telemetry::Close()
{
  rpcClientTerminate = true;
}

void KNav_Telemetry::Update()
{
  try
  {
    activeVessel.vessel = KRPCI_SpaceCenter::get_ActiveVessel();
    activeVessel.name = KRPCI_SpaceCenter::Vessel_get_Name(activeVessel.vessel);
    activeVessel.autopilot = KRPCI_SpaceCenter::Vessel_get_AutoPilot(activeVessel.vessel);
    activeVessel.surface_ref = KRPCI_SpaceCenter::Vessel_get_SurfaceReferenceFrame(activeVessel.vessel);
    activeVessel.orbit = KRPCI_SpaceCenter::Vessel_get_Orbit(activeVessel.vessel);
    activeVessel.orbit_body = KRPCI_SpaceCenter::Orbit_get_Body(activeVessel.orbit);
    activeVessel.orbit_body_ref = KRPCI_SpaceCenter::CelestialBody_get_ReferenceFrame(activeVessel.orbit_body);
    activeVessel.orbit_body_mass = KRPCI_SpaceCenter::CelestialBody_get_Mass(activeVessel.orbit_body);
    activeVessel.orbit_body_distance = Vessel_DistanceToBody(activeVessel.vessel, activeVessel.orbit_body_ref);
    activeVessel.flight = KRPCI_SpaceCenter::Vessel_Flight(activeVessel.vessel, activeVessel.orbit_body_ref);
    //activeVessel.situation = KRPCI_SpaceCenter::Vessel_get_Situation(activeVessel.vessel);
    activeVessel.situation = (KRPCI_SpaceCenter::VesselSituation)KRPCI_SpaceCenter::Vessel_get_Situation(activeVessel.vessel);

    activeVessel.verticalSpeed = KRPCI_SpaceCenter::Flight_get_VerticalSpeed(activeVessel.flight);
    activeVessel.radarAltitude = KRPCI_SpaceCenter::Flight_get_SurfaceAltitude(activeVessel.flight);
    activeVessel.maxThrust = KRPCI_SpaceCenter::Vessel_get_Thrust(activeVessel.vessel);
    activeVessel.mass = KRPCI_SpaceCenter::Vessel_get_Mass(activeVessel.vessel);

    activeVessel.control = KRPCI_SpaceCenter::Vessel_get_Control(activeVessel.vessel);
    activeVessel.throttle = KRPCI_SpaceCenter::Control_get_Throttle(activeVessel.control);

    kspGravConstant = KRPCI_SpaceCenter::get_G();
    activeVessel.gravitationalForce = (activeVessel.orbit_body_mass * kspGravConstant) /
      (activeVessel.orbit_body_distance * activeVessel.orbit_body_distance);
  }
  catch (KRPC_Exception &e)
  {
    SetDebugMessage(string(e.what()));
  }
}

KNav_Telemetry::Vector3d_t KNav_Telemetry::Vessel_Position(KRPCI_SpaceCenter::VESSEL vessel, KRPCI_SpaceCenter::REFERENCEFRAME referenceFrame)
{
  KRPC::Tuple krpcPos = KRPCI_SpaceCenter::Vessel_Position(vessel, referenceFrame);
  Vector3d_t pos;

  CopyMemory(&(pos.x), krpcPos.items(0).data(), krpcPos.items(0).size());
  CopyMemory(&(pos.y), krpcPos.items(1).data(), krpcPos.items(0).size());
  CopyMemory(&(pos.z), krpcPos.items(2).data(), krpcPos.items(0).size());

  return pos;
}

double KNav_Telemetry::Vessel_DistanceToBody(KRPCI_SpaceCenter::VESSEL vessel, KRPCI_SpaceCenter::REFERENCEFRAME referenceFrame) {
  Vector3d_t pos = Vessel_Position(vessel, referenceFrame);
  return sqrt(pos.x * pos.x + pos.y * pos.y + pos.z * pos.z);
}

void KNav_Telemetry::Control()
{
  if (commandList.size() > 0) {
    Command_t command;
    BOOL retval = PopCommand(command);

    if (retval) {
      try {
        command.controlFunction();
      }
      catch (KRPC_Exception &e) {
        SetDebugMessage(string(e.what()));
      }
      
    }
  }
}

DWORD WINAPI KNav_Telemetry::rpcClientThread_stub(LPVOID lpParam)
{
  if (lpParam != NULL)
    ((KNav_Telemetry *)lpParam)->rpcClientThread_run();

  return 0;
}

void KNav_Telemetry::rpcClientThread_run()
{
  const char *function_k = "KNav_Telemetry::rpcClientThread_run";

  BOOL status;

  // main processing loop.
  // maintains a connection until terminated by the user.
  while (!rpcClientTerminate)
  {

    // determine if we are in flight,
    // by trying to get KSP time
    try {
      kspUniversalTime = KRPCI_SpaceCenter::get_UT();
      inFlight = TRUE;
    }
    catch (KRPC_Exception &e) {
      kspUniversalTime = 0.0;
      inFlight = FALSE;
      SetDebugMessage(string(e.what()));
    }

    if (inFlight) {
      Update();
      Control();
    }
    else {
      // clear telemetry
      activeVessel = VesselTelemetry_t();
    }

    // calculate sleep period
    executionTime_ms = GetTickCount64() - systemTime_ms;
    sleepPeriod = KNAV_TELEMETRY_SLEEP_PERIOD_MS - executionTime_ms;
    if (sleepPeriod > 0) {
      Sleep(sleepPeriod);
    }
  }
}

void KNav_Telemetry::GetDebugMessage(double &timestamp, std::string &msg) {
  timestamp = debugTimestamp;
  msg = debugMessage;
}

void KNav_Telemetry::SetDebugMessage(std::string &msg) {
  debugTimestamp = (double)GetTickCount64() / 1000.0;
  debugMessage = msg;
}

void KNav_Telemetry::PushCommand(std::function<void()> &controlFunction)
{
  DWORD retval = WaitForSingleObject(commandListMutex, 500);
  char errorMsg[128];

  if (retval == WAIT_OBJECT_0)
  {
    double timestamp = (double)GetTickCount64() / 1000.0;
    Command_t cmd;

    cmd.timestamp = timestamp;
    cmd.controlFunction = controlFunction;

    commandList.push_back(cmd);

    if (!ReleaseMutex(commandListMutex)) {
      _snprintf(errorMsg, 128, "WARNING: Failed to release commandListMutex! \n");
      SetDebugMessage(string(errorMsg));
    }
  }
}

BOOL KNav_Telemetry::PopCommand(KNav_Telemetry::Command_t &cmd)
{
  DWORD retval = 0;
  BOOL status = FALSE;
  char errorMsg[128];

  if (commandList.size() > 0)
  {
    retval = WaitForSingleObject(commandListMutex, 500);

    if (retval == WAIT_OBJECT_0)
    {
      double sysTime = (double)GetTickCount64() / 1000.0;
      cmd = commandList.front();
      commandList.pop_front();

      if (sysTime < (cmd.timestamp + 500)) {
        status = TRUE;
      }
      else {
        _snprintf(errorMsg, 128, "WARNING: Late command (sys time = %.3f, arrived = %.3f) \n",
          sysTime, cmd.timestamp);
        SetDebugMessage(string(errorMsg));
      }

      if (!ReleaseMutex(commandListMutex)) {
        _snprintf(errorMsg, 128, "WARNING: Failed to release commandListMutex! \n");
        SetDebugMessage(string(errorMsg));
      }
    }
  }

  return status;
}