#include "KNav_Control.h"

//using namespace std;

KNav_Control::KNav_Control(KNav_Telemetry &telemetry) :
knavTelemetry(telemetry)
{
  
}

void KNav_Control::Control()
{
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

    KRPC::Tuple direction = KRPCI::GenerateTuple(1.0, 0.0, 0.0);
    KRPC::Tuple color = KRPCI::GenerateTuple(1.0, 0.0, 0.0);
    float length = 10.0;

    commandFn = std::bind(KRPCI_SpaceCenter::DrawDirection, direction, knavTelemetry.activeVessel.surface_ref, color, length);
    knavTelemetry.PushCommand(commandFn);

    /////

    double roll = 0.0;
    bool wait = false;

    commandFn = std::bind(KRPCI_SpaceCenter::AutoPilot_SetDirection, knavTelemetry.activeVessel.autopilot, 
      direction, roll, knavTelemetry.activeVessel.surface_ref, wait);
    knavTelemetry.PushCommand(commandFn);
  }


}
