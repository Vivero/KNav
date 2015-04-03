#include "KNav_Control.h"

using namespace std;

KNav_Control::KNav_Control(KNav_Telemetry &telemetry) :
knavTelemetry(telemetry),
knavTelemetryThread(telemetry.rpcClientThread),
programActiveIndex(NONE),
controlHover_altitude(50.0),
deltaTime(0.0),
prevSystemTime_ms(GetTickCount64())
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

  prevSystemTime_ms = systemTime_ms;
}

void KNav_Control::Control_Hover()
{
  ///// throttle control

  double mass = knavTelemetry.activeVessel.mass;
  double grav = knavTelemetry.activeVessel.gravitationalForce;
  double maxT = knavTelemetry.activeVessel.maxThrust;
  double alt = knavTelemetry.activeVessel.radarAltitude;

  static double alt_prev = alt;

  double u_gain = mass * grav / maxT;
  double p_osc = 8.0;
  double p_gain = 0.6 * u_gain;
  double i_gain = 2.0 * p_gain / p_osc;
  double d_gain = p_gain * p_osc / 8.0;
  double h = 0.1;

  static double throttle_cmd = 0.0;
  static double throttle_sat = 0.0;

  static double i = 0.0;

  static double d_prev = 0.0;

  double altitude_error = controlHover_altitude - alt;
  double p = p_gain * altitude_error;
  i = i + i_gain * h * altitude_error + h / p_osc * (throttle_sat - throttle_cmd);
  double d = p_osc / (p_osc + h) * d_prev - d_gain / (p_osc + h) * (alt - alt_prev);


  /*DOUBLE throttleCmd = knavTelemetry.activeVessel.mass *
    (knavTelemetry.activeVessel.gravitationalForce - knavTelemetry.activeVessel.verticalSpeed + altitude_error) /
    knavTelemetry.activeVessel.maxThrust;*/

  //throttle_cmd = mass * grav / maxT;

  throttle_cmd = p + i + d;

  throttle_sat = (throttle_cmd > 1.f) ? 1.f : ((throttle_cmd < 0.f) ? 0.f : throttle_cmd);

  function<void()> commandFn = std::bind(KRPCI_SpaceCenter::Control_set_Throttle, knavTelemetry.activeVessel.control, throttle_sat);
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
  knavTelemetry.PushCommand(commandFn);

  KRPC::Tuple dir = KRPCI::GenerateTuple(1.0, 0.0, 0.0);
  KRPC::Tuple col = KRPCI::GenerateTuple(1.0, 0.0, 0.0);
  float length = 10.0;
  commandFn = std::bind(KRPCI_SpaceCenter::DrawDirection, dir, knavTelemetry.activeVessel.reference_vessel, col, length);
  knavTelemetry.PushCommand(commandFn);


  alt_prev = alt;
  d_prev = d;
}

void KNav_Control::Control_Emergency()
{
  DOUBLE throttleCmd = 0.0;
  function<void()> commandFn = std::bind(KRPCI_SpaceCenter::Control_set_Throttle, knavTelemetry.activeVessel.control, throttleCmd);
  knavTelemetry.PushCommand(commandFn);
}