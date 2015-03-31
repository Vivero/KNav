#include "KNav.h"

KNav::KNav() : 
kspTime(0.0),
sysTime_ms(0),
sysTime_prev(0),
dT_ms(0),
inFlight(FALSE),
activeVessel(0),
activeVessel_flight(0),
activeVessel_orbit(0),
activeVessel_orbit_body(0),
activeVessel_orbit_body_ref(0),
activeVessel_altitude(0.0),
activeVessel_verticalSpeed(0.0),
activeVessel_maxThrust(0.0),
activeVessel_mass(0.0),
activeVessel_GForce(0.0),
activeVessel_control(0),
activeVessel_control_throttle(0.f) {}

void KNav::Display()
{
  cout << "VESSEL INFORMATION" << endl;
  cout << "==================" << endl;
  printf("sys_time   : %.3f \n", (double)sysTime_ms / 1000.0);
  printf("time       : %.3f \n", kspTime);
  cout << "name       : " << activeVessel_name << endl;
  cout << "id         : " << activeVessel << endl;
  printf("vspeed     : %.3f \n", activeVessel_verticalSpeed);
  printf("r.alt      : %.3f \n", activeVessel_altitude);
  printf("mass       : %.3f \n", activeVessel_mass);
  printf("thrust     : %.3f \n", activeVessel_maxThrust * activeVessel_control_throttle);
  printf("weight     : %.3f \n", activeVessel_mass * activeVessel_GForce);
  printf("gforce     : %.3f \n", activeVessel_GForce);
  printf("vaccel     : %.3f \n", verticalAccel);
  printf("throttle   : %.3f \n\n", activeVessel_control_throttle);

}

ULONGLONG KNav::Navigation()
{
  sysTime_ms = GetTickCount64();
  dT_ms = sysTime_prev - sysTime_ms;

  // determine if we are in flight,
  // by trying to get KSP time
  try {
    kspTime = KRPCI_SpaceCenter::get_UT();
    inFlight = TRUE;
  }
  catch (KRPC_Exception &e) {
    inFlight = FALSE;
  }

  static float throttleCmd = 0.f;

  static bool gotActiveVessel = FALSE;
  if (!gotActiveVessel) {
    activeVessel = KRPCI_SpaceCenter::get_ActiveVessel();
    gotActiveVessel = TRUE;
  }

  // gather flight information
  if (inFlight)
  {
    gravConstant = KRPCI_SpaceCenter::get_G();

    KRPCI_SpaceCenter::VESSEL thisVessel = KRPCI_SpaceCenter::get_ActiveVessel();
    if (thisVessel != activeVessel) {
      KRPCI_SpaceCenter::Control_set_Throttle(activeVessel_control, 0.0);
      return 10;
    }
    
    activeVessel_name = KRPCI_SpaceCenter::Vessel_get_Name(activeVessel);
    activeVessel_orbit = KRPCI_SpaceCenter::Vessel_get_Orbit(activeVessel);
    activeVessel_orbit_body = KRPCI_SpaceCenter::Orbit_get_Body(activeVessel_orbit);
    activeVessel_orbit_body_ref = KRPCI_SpaceCenter::CelestialBody_get_ReferenceFrame(activeVessel_orbit_body);
    activeVessel_orbit_body_mass = KRPCI_SpaceCenter::CelestialBody_get_Mass(activeVessel_orbit_body);
    activeVessel_flight = KRPCI_SpaceCenter::Vessel_Flight(activeVessel, activeVessel_orbit_body_ref);

    activeVessel_verticalSpeed = KRPCI_SpaceCenter::Flight_get_VerticalSpeed(activeVessel_flight);
    activeVessel_altitude = KRPCI_SpaceCenter::Flight_get_SurfaceAltitude(activeVessel_flight);
    activeVessel_maxThrust = KRPCI_SpaceCenter::Vessel_get_Thrust(activeVessel);
    activeVessel_mass = KRPCI_SpaceCenter::Vessel_get_Mass(activeVessel);

    activeVessel_control = KRPCI_SpaceCenter::Vessel_get_Control(activeVessel);
    activeVessel_control_throttle = KRPCI_SpaceCenter::Control_get_Throttle(activeVessel_control);

    if (dT_ms > 0) {
      verticalAccel = (activeVessel_verticalSpeed - prevVSpeed) / ((double)dT_ms) * 1000.0;
    }

    double altError = 8.0 - activeVessel_altitude;

    double mom = activeVessel_mass * verticalAccel;
    double rad = Vessel_DistanceToBody(activeVessel, activeVessel_orbit_body_ref);
    activeVessel_GForce = (gravConstant * activeVessel_orbit_body_mass) / (rad * rad);
    double weight = activeVessel_mass * activeVessel_GForce;

    throttleCmd = activeVessel_mass * (activeVessel_GForce - activeVessel_verticalSpeed + altError) / activeVessel_maxThrust;

    throttleCmd = (throttleCmd > 1.f) ? 1.f : ((throttleCmd < 0.f) ? 0.f : throttleCmd);
    KRPCI_SpaceCenter::Control_set_Throttle(activeVessel_control, throttleCmd);


    printf("@@@ weight = %.3f \n", weight);
    printf("@@@ radius = %.3f \n", rad);
    printf("@@@ thrcmd = %.3f \n", throttleCmd);


    prevVSpeed = activeVessel_verticalSpeed;
  }

  sysTime_prev = sysTime_ms;

  ULONGLONG execTime = GetTickCount64() - sysTime_ms;
  printf("@@@ exec_t = %ld \n", execTime);

  return execTime;
}

KNav::Vector3d_t KNav::Vessel_Position(KRPCI_SpaceCenter::VESSEL Vessel, KRPCI_SpaceCenter::REFERENCEFRAME referenceFrame)
{
  KRPC::Tuple krpcPos = KRPCI_SpaceCenter::Vessel_Position(Vessel, referenceFrame);
  Vector3d_t pos;

  CopyMemory(&(pos.x), krpcPos.items(0).data(), krpcPos.items(0).size());
  CopyMemory(&(pos.y), krpcPos.items(1).data(), krpcPos.items(0).size());
  CopyMemory(&(pos.z), krpcPos.items(2).data(), krpcPos.items(0).size());

  return pos;
}

double KNav::Vessel_DistanceToBody(KRPCI_SpaceCenter::VESSEL Vessel, KRPCI_SpaceCenter::REFERENCEFRAME referenceFrame) {
  Vector3d_t pos = Vessel_Position(Vessel, referenceFrame);
  return sqrt(pos.x * pos.x + pos.y * pos.y + pos.z * pos.z);
}
