#include "KNav_Control.h"

using namespace std;

KNav_Control::KNav_Control(KNav_Telemetry &telemetry) :
knavTelemetry(telemetry),
knavTelemetryThread(telemetry.rpcClientThread) { }

void KNav_Control::Control()
{
  // perform controls only if in flight
  if (knavTelemetry.inFlight)
  {
    ///// throttle control

    DOUBLE altError = 9.0 - knavTelemetry.activeVessel.radarAltitude;
    DOUBLE throttleCmd = knavTelemetry.activeVessel.mass *
      (knavTelemetry.activeVessel.gravitationalForce - knavTelemetry.activeVessel.verticalSpeed + altError) /
      knavTelemetry.activeVessel.maxThrust;

    throttleCmd = (throttleCmd > 1.f) ? 1.f : ((throttleCmd < 0.f) ? 0.f : throttleCmd);

    function<void()> commandFn = std::bind(KRPCI_SpaceCenter::Control_set_Throttle, knavTelemetry.activeVessel.control, throttleCmd);

    knavTelemetry.PushCommand(commandFn);
  }

}
