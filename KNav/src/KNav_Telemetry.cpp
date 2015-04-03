#include "KNav_Telemetry.h"

KNav_Telemetry::KNav_Telemetry() :
// read-only fields
rpcClientThread(_rpcClientThread),
activeVessel(_activeVessel),
inFlight(_inFlight),
kspUniversalTime(_kspUniversalTime),
kspGravConstant(_kspGravConstant),
avgExecutionTime_ms(_avgExecutionTime_ms),
executionCount(_executionCount),
commandBufferSize(_commandBufferSize),
numAsyncCalls(_numAsyncCalls),

// private members
commandListMutex(NULL),
debugTimestamp(0.0),
systemTime_ms(0),
executionTime_ms(0),
accExecutionTime_ms(0),
rpcClientTerminate(FALSE),
elapsedTime_ms(0),
sleepPeriod(0),
_rpcClientThread(NULL),
_inFlight(FALSE),
_kspUniversalTime(0.0),
_kspGravConstant(0.0),
_avgExecutionTime_ms(0.0),
_executionCount(0),
_commandBufferSize(0),
_numAsyncCalls(0)
{
  commandListMutex = CreateMutex(
    NULL,              // default security attributes
    FALSE,             // initially not owned
    L"commandList");   // mutex name

  if (commandListMutex == NULL) {
    printf("WARNING: Failed to create mutex commandListMutex");
  }
}


void KNav_Telemetry::Open()
{
  rpcClientTerminate = FALSE;
  _rpcClientThread = CreateThread(
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
    _activeVessel.vessel = KRPCI_SpaceCenter::get_ActiveVessel();
    _activeVessel.name = KRPCI_SpaceCenter::Vessel_get_Name(activeVessel.vessel);
    _activeVessel.mission_elapsed_time = KRPCI_SpaceCenter::Vessel_get_MET(activeVessel.vessel);
    _activeVessel.autopilot = KRPCI_SpaceCenter::Vessel_get_AutoPilot(activeVessel.vessel);
    _activeVessel.vessel_ref = KRPCI_SpaceCenter::Vessel_get_ReferenceFrame(activeVessel.vessel);
    _activeVessel.surface_ref = KRPCI_SpaceCenter::Vessel_get_SurfaceReferenceFrame(activeVessel.vessel);
    _activeVessel.orbit = KRPCI_SpaceCenter::Vessel_get_Orbit(activeVessel.vessel);
    _activeVessel.orbit_body = KRPCI_SpaceCenter::Orbit_get_Body(activeVessel.orbit);
    _activeVessel.orbit_body_ref = KRPCI_SpaceCenter::CelestialBody_get_ReferenceFrame(activeVessel.orbit_body);
    _activeVessel.orbit_body_mass = KRPCI_SpaceCenter::CelestialBody_get_Mass(activeVessel.orbit_body);
    _activeVessel.orbit_body_distance = Vessel_DistanceToBody(activeVessel.vessel, activeVessel.orbit_body_ref);
    _activeVessel.flight = KRPCI_SpaceCenter::Vessel_Flight(activeVessel.vessel, activeVessel.orbit_body_ref);
    _activeVessel.situation = (KRPCI_SpaceCenter::VesselSituation)KRPCI_SpaceCenter::Vessel_get_Situation(activeVessel.vessel);

    _activeVessel.verticalSpeed = KRPCI_SpaceCenter::Flight_get_VerticalSpeed(activeVessel.flight);
    _activeVessel.radarAltitude = KRPCI_SpaceCenter::Flight_get_SurfaceAltitude(activeVessel.flight);
    _activeVessel.maxThrust = KRPCI_SpaceCenter::Vessel_get_Thrust(activeVessel.vessel);
    _activeVessel.mass = KRPCI_SpaceCenter::Vessel_get_Mass(activeVessel.vessel);

    _activeVessel.control = KRPCI_SpaceCenter::Vessel_get_Control(activeVessel.vessel);
    _activeVessel.throttle = KRPCI_SpaceCenter::Control_get_Throttle(activeVessel.control);

    _kspGravConstant = KRPCI_SpaceCenter::get_G();
    _activeVessel.gravitationalForce = (activeVessel.orbit_body_mass * kspGravConstant) /
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
  _commandBufferSize = commandList.size();
  Command_t command;
  BOOL retval = FALSE;

  for (UINT i = 0; i < commandBufferSize; i++)
  {
    retval = PopCommand(command);

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
    systemTime_ms = GetTickCount64();

    // determine if we are in flight,
    // by trying to get KSP time
    try {
      _kspUniversalTime = KRPCI_SpaceCenter::get_UT();
      _inFlight = TRUE;
    }
    catch (KRPC_Exception &e) {
      _kspUniversalTime = 0.0;
      _inFlight = FALSE;
      SetDebugMessage(string(e.what()));
    }

    if (inFlight) {
      Update();
      Control();
    }
    else {
      // clear telemetry
      _activeVessel = VesselTelemetry_t();
    }

    // calculate loop execution time
    executionTime_ms = GetTickCount64() - systemTime_ms;
    accExecutionTime_ms += executionTime_ms;
    _executionCount++;
    _avgExecutionTime_ms = (double)accExecutionTime_ms / (double)executionCount;
    elapsedTime_ms = executionTime_ms;

    do {
      // calculate sleep period
      sleepPeriod = KNAV_TELEMETRY_SLEEP_PERIOD_MS - elapsedTime_ms;
      if (sleepPeriod > 0) {
        SleepEx(sleepPeriod, TRUE);
      }
      elapsedTime_ms = GetTickCount64() - systemTime_ms;
    } while (elapsedTime_ms <= KNAV_TELEMETRY_SLEEP_PERIOD_MS);
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

      if (sysTime < (cmd.timestamp + 0.5)) {
        status = TRUE;
      }
      else {
        _snprintf(errorMsg, 128, "WARNING: Late command discarded\n  sys time = %.3f\n  arrived  = %.3f\n  delta    = %.1fms \n",
          sysTime, cmd.timestamp, (sysTime - cmd.timestamp) * 1000.0);
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

VOID CALLBACK KNav_Telemetry::AsyncMessage(ULONG_PTR dwParam)
{
  KNav_Telemetry *telemetry = (KNav_Telemetry *)dwParam;
  telemetry->SetDebugMessage(string("Async Command Running!"));
  telemetry->_numAsyncCalls++;
  telemetry->asyncMessage.complete = TRUE;
}