#include "KNav_Control.h"

using namespace std;

KNav_Control::KNav_Control(KNav_Telemetry &telemetry) :
knavTelemetry(telemetry),
knavTelemetryThread(telemetry.rpcClientThread) { }

void KNav_Control::Control()
{
  static BOOL vectorsDrawn = FALSE;

  if (knavTelemetry.inFlight)
  {
    double altError = 12.0 - knavTelemetry.activeVessel.radarAltitude;
    double throttleCmd = knavTelemetry.activeVessel.mass *
      (knavTelemetry.activeVessel.gravitationalForce - knavTelemetry.activeVessel.verticalSpeed + altError) /
      knavTelemetry.activeVessel.maxThrust;

    throttleCmd = (throttleCmd > 1.f) ? 1.f : ((throttleCmd < 0.f) ? 0.f : throttleCmd);

    function<void()> commandFn = std::bind(KRPCI_SpaceCenter::Control_set_Throttle, knavTelemetry.activeVessel.control, throttleCmd);

    knavTelemetry.PushCommand(commandFn);

    /////

    if (!vectorsDrawn)
    {
      KRPC::Tuple direction = KRPCI::GenerateTuple(1.0, 0.0, 0.0);
      KRPC::Tuple color = KRPCI::GenerateTuple(1.0, 0.0, 0.0);
      float length = 10.0;

      // draw UP vector
      commandFn = std::bind(KRPCI_SpaceCenter::DrawDirection, direction, knavTelemetry.activeVessel.surface_ref, color, length);
      knavTelemetry.PushCommand(commandFn);

      // draw NORTH vector
      direction = KRPCI::GenerateTuple(0.0, 1.0, 0.0);
      color = KRPCI::GenerateTuple(0.0, 1.0, 0.0);
      commandFn = std::bind(KRPCI_SpaceCenter::DrawDirection, direction, knavTelemetry.activeVessel.surface_ref, color, length);
      knavTelemetry.PushCommand(commandFn);

      // draw EAST vector
      direction = KRPCI::GenerateTuple(0.0, 0.0, 1.0);
      color = KRPCI::GenerateTuple(0.0, 0.0, 1.0);
      commandFn = std::bind(KRPCI_SpaceCenter::DrawDirection, direction, knavTelemetry.activeVessel.surface_ref, color, length);
      knavTelemetry.PushCommand(commandFn);

      /////

      direction = KRPCI::GenerateTuple(1.0, 0.0, 0.0);
      color = KRPCI::GenerateTuple(1.0, 0.0, 0.0);
      length = 6.0;

      // draw STARBOARD vector
      commandFn = std::bind(KRPCI_SpaceCenter::DrawDirection, direction, knavTelemetry.activeVessel.vessel_ref, color, length);
      knavTelemetry.PushCommand(commandFn);

      // draw FORWARD vector
      direction = KRPCI::GenerateTuple(0.0, 1.0, 0.0);
      color = KRPCI::GenerateTuple(0.0, 1.0, 0.0);
      commandFn = std::bind(KRPCI_SpaceCenter::DrawDirection, direction, knavTelemetry.activeVessel.vessel_ref, color, length);
      knavTelemetry.PushCommand(commandFn);

      // draw ZENITH vector
      direction = KRPCI::GenerateTuple(0.0, 0.0, 1.0);
      color = KRPCI::GenerateTuple(0.0, 0.0, 1.0);
      commandFn = std::bind(KRPCI_SpaceCenter::DrawDirection, direction, knavTelemetry.activeVessel.vessel_ref, color, length);
      knavTelemetry.PushCommand(commandFn);

      vectorsDrawn = TRUE;
    }

    /////

    double pitch = 90.0;
    double heading = 0.0;
    double roll = 0.0;
    bool wait = false;

    //commandFn = std::bind(KRPCI_SpaceCenter::AutoPilot_SetDirection, knavTelemetry.activeVessel.autopilot, 
    //  direction, roll, knavTelemetry.activeVessel.surface_ref, wait);

    commandFn = std::bind(KRPCI_SpaceCenter::AutoPilot_SetRotation, knavTelemetry.activeVessel.autopilot,
      pitch, heading, roll, knavTelemetry.activeVessel.surface_ref, wait);

    knavTelemetry.PushCommand(commandFn);
  }


}
