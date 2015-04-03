#include "KNav_Control.h"

using namespace std;

KNav_Control::KNav_Control(KNav_Telemetry &telemetry) :
knavTelemetry(telemetry),
knavTelemetryThread(telemetry.rpcClientThread),
programActiveIndex(NONE),
controlHover_altitude(10.0)
{
  programList.emplace_back(NONE, "None");
  programList.emplace_back(HOVER, "Hover");
  programList.emplace_back(ASCENT, "Ascent");
  programList.emplace_back(EMERGENCY, "Emergency Shut Off");
}

void KNav_Control::Control()
{
  // perform controls only if in flight
  if (knavTelemetry.inFlight)
  {
    switch (programActiveIndex)
    {
    case HOVER:
      Control_Hover();
      break;

    case EMERGENCY:
      Control_Emergency();

    default:
      break;
    }


  }

}

void KNav_Control::Control_Hover()
{
  ///// throttle control

  DOUBLE altError = controlHover_altitude - knavTelemetry.activeVessel.radarAltitude;
  DOUBLE throttleCmd = knavTelemetry.activeVessel.mass *
    (knavTelemetry.activeVessel.gravitationalForce - knavTelemetry.activeVessel.verticalSpeed + altError) /
    knavTelemetry.activeVessel.maxThrust;

  throttleCmd = (throttleCmd > 1.f) ? 1.f : ((throttleCmd < 0.f) ? 0.f : throttleCmd);

  function<void()> commandFn = std::bind(KRPCI_SpaceCenter::Control_set_Throttle, knavTelemetry.activeVessel.control, throttleCmd);
  knavTelemetry.PushCommand(commandFn);

  ///// directional control
  BOOL flightControlsPressed = (GetAsyncKeyState('W') & 0x8000) || (GetAsyncKeyState('S') & 0x8000);
  if (!flightControlsPressed)
  {
    //knavTelemetry.SetDebugMessage("pitch pressed!");
    double pitch = 90.0;
    double heading = 0.0;
    double roll = 0.0;
    bool wait = false;

    commandFn = std::bind(KRPCI_SpaceCenter::AutoPilot_SetRotation, knavTelemetry.activeVessel.autopilot,
      pitch, heading, roll, knavTelemetry.activeVessel.surface_ref, wait);
    knavTelemetry.PushCommand(commandFn);
  }
  else {
    commandFn = std::bind(KRPCI_SpaceCenter::AutoPilot_Disengage, knavTelemetry.activeVessel.autopilot);
    knavTelemetry.PushCommand(commandFn);
  }
}

void KNav_Control::Control_Emergency()
{
  DOUBLE throttleCmd = 0.0;
  function<void()> commandFn = std::bind(KRPCI_SpaceCenter::Control_set_Throttle, knavTelemetry.activeVessel.control, throttleCmd);
  knavTelemetry.PushCommand(commandFn);
}