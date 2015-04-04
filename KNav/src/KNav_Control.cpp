#include "KNav_Control.h"

using namespace std;

KNav_Control::KNav_Control(KNav_Telemetry &telemetry) :
knavTelemetry(telemetry),
knavTelemetryThread(telemetry.rpcClientThread),
programActiveIndex(NONE),
reference(5.0),
deltaTime(0.0),
prevSystemTime_ms(GetTickCount64()),
PID_vspeed(telemetry.activeVessel.verticalSpeed, 0.0, 1.0, 0.1),
PID_altitude(telemetry.activeVessel.radarAltitude, -0.5, 0.5, 0.1),
ref_vspeed(0.0)
{
  programList.emplace_back(NONE, "None");
  programList.emplace_back(HOVER, "Hover");
  programList.emplace_back(ASCENT, "Ascent");
  programList.emplace_back(EMERGENCY, "Emergency Shut Off");
}

void KNav_Control::Control()
{
  ULONGLONG systemTime_ms = GetTickCount64();
  deltaTime = ((double)(systemTime_ms - prevSystemTime_ms)) / 1000.0;

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

  else {
    PID_vspeed.Reset();
  }

  prevSystemTime_ms = systemTime_ms;
}

void KNav_Control::Control_Hover()
{


  ///// throttle control

  double mass = knavTelemetry.activeVessel.mass;
  double grav = knavTelemetry.activeVessel.gravitationalForce;
  double maxT = knavTelemetry.activeVessel.maxThrust;
  double alt = knavTelemetry.activeVessel.radarAltitude;
  double vspeed = knavTelemetry.activeVessel.verticalSpeed;

  if (deltaTime <= 0.0 || maxT <= 0.0)
    return;

  // altitude control
  PID_altitude.Tosc = 1.0;
  PID_altitude.Kp = deltaTime;
  PID_altitude.Ki = 2.0 * PID_altitude.Kp / PID_altitude.Tosc;
  PID_altitude.Kd = PID_altitude.Kp * PID_altitude.Tosc / 8.0 * 10.0;
  ref_vspeed = PID_altitude.Control(deltaTime, reference);

  // thrust control
  double u_gain = maxT / (mass * grav) * deltaTime;
  PID_vspeed.Tosc = 1.0;
  PID_vspeed.Kp = 0.06 * u_gain;
  PID_vspeed.Ki = 2.0 * PID_vspeed.Kp / PID_vspeed.Tosc;
  PID_vspeed.Kd = PID_vspeed.Kp * PID_vspeed.Tosc / 8.0;

  float throttle_cmd = (float)PID_vspeed.Control(deltaTime, ref_vspeed);
  function<void()> commandFn = std::bind(KRPCI_SpaceCenter::Control_set_Throttle, knavTelemetry.activeVessel.control, throttle_cmd);
  knavTelemetry.PushCommand(commandFn);





  ///// directional control
  BOOL flightControlsPressed = (GetAsyncKeyState('W') & 0x8000) || (GetAsyncKeyState('S') & 0x8000);
  //if (!flightControlsPressed)
  if (0)
  {
    //knavTelemetry.SetDebugMessage("pitch pressed!");
    double pitch = 90.0;
    double heading = 0.0;
    double roll = 0.0;
    bool wait = false;

    commandFn = std::bind(KRPCI_SpaceCenter::AutoPilot_SetRotation, knavTelemetry.activeVessel.autopilot,
      pitch, heading, roll, knavTelemetry.activeVessel.reference_surface, wait);
    knavTelemetry.PushCommand(commandFn);
  }
  /*else {
    commandFn = std::bind(KRPCI_SpaceCenter::AutoPilot_Disengage, knavTelemetry.activeVessel.autopilot);
    knavTelemetry.PushCommand(commandFn);
  }*/

  ///// draw vectors

  commandFn = std::bind(KRPCI_SpaceCenter::ClearDirections);
  //knavTelemetry.PushCommand(commandFn);

  KRPC::Tuple dir = KRPCI::GenerateTuple(1.0, 0.0, 0.0);
  KRPC::Tuple col = KRPCI::GenerateTuple(1.0, 0.0, 0.0);
  float length = 10.0;
  commandFn = std::bind(KRPCI_SpaceCenter::DrawDirection, dir, knavTelemetry.activeVessel.reference_vessel, col, length);
  //knavTelemetry.PushCommand(commandFn);








  // clean up
  //
}

void KNav_Control::Control_Emergency()
{
  DOUBLE throttleCmd = 0.0;
  function<void()> commandFn = std::bind(KRPCI_SpaceCenter::Control_set_Throttle, knavTelemetry.activeVessel.control, throttleCmd);
  knavTelemetry.PushCommand(commandFn);
}