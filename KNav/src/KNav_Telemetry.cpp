#include "KNav_Telemetry.h"

KNav_Telemetry::KNav_Telemetry() :
// read-only fields
rpcClientThread(_rpcClientThread),
activeVessel(_activeVessel),
activeVesselParts(_activeVesselParts),
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
_activeVessel(),
_activeVesselParts(),
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
    _activeVessel.resources = KRPCI_SpaceCenter::Vessel_get_Resources(_activeVessel.vessel);
    _activeVessel.name = KRPCI_SpaceCenter::Vessel_get_Name(_activeVessel.vessel);
    _activeVessel.parts = KRPCI_SpaceCenter::Vessel_get_Parts(_activeVessel.vessel);
    _activeVessel.mission_elapsed_time = KRPCI_SpaceCenter::Vessel_get_MET(_activeVessel.vessel);
    _activeVessel.autopilot = KRPCI_SpaceCenter::Vessel_get_AutoPilot(_activeVessel.vessel);
    _activeVessel.orbit = KRPCI_SpaceCenter::Vessel_get_Orbit(_activeVessel.vessel);
    _activeVessel.orbit_body = KRPCI_SpaceCenter::Orbit_get_Body(_activeVessel.orbit);
    _activeVessel.reference_vessel = KRPCI_SpaceCenter::Vessel_get_ReferenceFrame(_activeVessel.vessel);
    _activeVessel.reference_surface = KRPCI_SpaceCenter::Vessel_get_SurfaceReferenceFrame(_activeVessel.vessel);
    _activeVessel.reference_orbit_body = KRPCI_SpaceCenter::CelestialBody_get_ReferenceFrame(_activeVessel.orbit_body);
    _activeVessel.orbit_body_mass = KRPCI_SpaceCenter::CelestialBody_get_Mass(_activeVessel.orbit_body);
    _activeVessel.orbit_body_distance = Vessel_DistanceToBody(_activeVessel.vessel, _activeVessel.reference_orbit_body);
    _activeVessel.flight = KRPCI_SpaceCenter::Vessel_Flight(_activeVessel.vessel, _activeVessel.reference_orbit_body);
    _activeVessel.situation = (KRPCI_SpaceCenter::VesselSituation)KRPCI_SpaceCenter::Vessel_get_Situation(_activeVessel.vessel);

    _activeVessel.verticalSpeed = KRPCI_SpaceCenter::Flight_get_VerticalSpeed(_activeVessel.flight);
    _activeVessel.radarAltitude = KRPCI_SpaceCenter::Flight_get_SurfaceAltitude(_activeVessel.flight);
    _activeVessel.maxThrust = KRPCI_SpaceCenter::Vessel_get_Thrust(_activeVessel.vessel);
    _activeVessel.mass = KRPCI_SpaceCenter::Vessel_get_Mass(_activeVessel.vessel);

    _activeVessel.control = KRPCI_SpaceCenter::Vessel_get_Control(_activeVessel.vessel);
    _activeVessel.control_pitch = KRPCI_SpaceCenter::Control_get_Pitch(_activeVessel.control);
    _activeVessel.throttle = KRPCI_SpaceCenter::Control_get_Throttle(_activeVessel.control);

    _kspGravConstant = KRPCI_SpaceCenter::get_G();
    _activeVessel.gravitationalForce = (_activeVessel.orbit_body_mass * kspGravConstant) /
      (_activeVessel.orbit_body_distance * _activeVessel.orbit_body_distance);

    KRPC::Tuple vessel_direction = KRPCI_SpaceCenter::Vessel_Direction(_activeVessel.vessel, _activeVessel.reference_surface);
    KRPCI::UnpackTuple(vessel_direction, _activeVessel.vessel_direction.x, _activeVessel.vessel_direction.y, _activeVessel.vessel_direction.z);


    /// PARTS
    KRPC::List partsList; string partName = "IR Rotatron";
    partsList = KRPCI_SpaceCenter::Parts_WithTitle(_activeVessel.parts, partName);
    //partsList = KRPCI_SpaceCenter::Parts_get_All(_activeVessel.parts);
    //partsList = KRPCI_SpaceCenter::Parts_InStage(_activeVessel.parts, 0);
    int numParts = partsList.items_size();

    stringstream ss;

    if (numParts > 0) {
      KRPCI::DecodeVarint(_activeVesselParts.rotatron1, (BYTE *)partsList.items(0).data(), partsList.items(0).size());
      partName = KRPCI_SpaceCenter::Part_get_Name(_activeVesselParts.rotatron1);

      ss << "Found Part: " << partName << endl;

      KRPC::List modulesList = KRPCI_SpaceCenter::Part_get_Modules(_activeVesselParts.rotatron1);
      KRPC::List moduleEvents, moduleActions;
      KRPC::Dictionary moduleFields; KRPC::DictionaryEntry moduleField;
      int numModules = modulesList.items_size();
      int numModuleEvents = 0;
      int numModuleActions = 0;
      int numModuleFields = 0;
      ss << "Found " << numModules << " modules: " << endl << endl;

      for (int i = 0; i < numModules; i++) {
        KRPCI_SpaceCenter::MODULE module;
        KRPCI::DecodeVarint(module, (BYTE *)modulesList.items(i).data(), modulesList.items(i).size());

        string moduleName = KRPCI_SpaceCenter::Module_get_Name(module);
        ss << "  " << moduleName;

        if (moduleName.compare("MuMechToggle") == 0) {
          _activeVesselParts.rotatron1_module = module;
          ss << " (" << module << ")";

          moduleEvents = KRPCI_SpaceCenter::Module_get_Events(_activeVesselParts.rotatron1_module);
          numModuleEvents = moduleEvents.items_size();

          moduleActions = KRPCI_SpaceCenter::Module_get_Actions(_activeVesselParts.rotatron1_module);
          numModuleActions = moduleActions.items_size();

          moduleFields = KRPCI_SpaceCenter::Module_get_Fields(_activeVesselParts.rotatron1_module);
          numModuleFields = moduleFields.entries_size();
        }
        ss << endl;
      } // numModules

      if (numModuleEvents > 0) {
        ss << endl << "Found " << numModuleEvents << " events: " << endl << endl;
      }
      for (int i = 0; i < numModuleEvents; i++) {
        string moduleEventName = moduleEvents.items(i).substr(1);
        ss << "  " << moduleEventName << endl;
      } // numModuleEvents

      if (numModuleActions > 0) {
        ss << endl << "Found " << numModuleActions << " actions: " << endl << endl;
      }
      for (int i = 0; i < numModuleActions; i++) {
        string moduleActionName = moduleActions.items(i).substr(1);
        
        ss << "  " << moduleActionName << " ";

        if (moduleActionName.compare("Move +") == 0) {
          _activeVesselParts.rotatron1_move_plus.assign(moduleActionName);
          ss << "(STORED)";
        }
        else if (moduleActionName.compare("Move -") == 0) {
          _activeVesselParts.rotatron1_move_minus.assign(moduleActionName);
          ss << "(STORED)";
        }

        ss << endl;
      } // numModuleActions

      if (numModuleFields > 0) {
        ss << endl << "Found " << numModuleFields << " fields: " << endl << endl;
      }
      for (int i = 0; i < numModuleFields; i++) {
        moduleField = moduleFields.entries(i);
        string moduleFieldKey = moduleField.key().substr(1);
        string moduleFieldVal = moduleField.value().substr(1);

        if (moduleFieldKey.compare("Rotation:") == 0) {
          _activeVesselParts.rotatron1_angle = std::stod(moduleFieldVal);
          //_activeVesselParts.rotatron1_angle = 0.0;
        }

        ss << "  " << moduleFieldKey << " : " << moduleFieldVal << endl;
      } // numModuleActions

    } // numParts > 0

    

    /*ss << "found " << numParts << " parts" << endl;
    for (int i = 0; i < numParts; i++) {
      KRPCI_SpaceCenter::PART part;
      KRPCI::DecodeVarint(part, (BYTE *)partsList.items(i).data(), partsList.items(i).size());
      partName = KRPCI_SpaceCenter::Part_get_Title(part);
      
      ss << "  " << i << ": " << partName << " (" << partName.length() << ")" << endl;
    }*/

    //SetDebugMessage(ss.str());
  }
  catch (KRPC_Exception &e)
  {
    SetDebugMessage(e.what());
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

void KNav_Telemetry::SetDebugMessage(const char *msg) {
  string msg_str(msg);
  SetDebugMessage(msg_str);
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