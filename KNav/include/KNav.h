#ifndef KNAV_H
#define KNAV_H

#include "stdafx.h"
#include "KRPCI.h"
#include "KRPCI_SpaceCenter.h"



class KNav
{
public:
  KNav();
  ~KNav() {};

  void Display();
  ULONGLONG Navigation();

  typedef struct Vector3d {
    double x;
    double y;
    double z;
  } Vector3d_t;

private:

  double                            kspTime;
  ULONGLONG                         sysTime_ms, sysTime_prev, dT_ms;
  BOOL                              inFlight;
  double                            gravConstant;

  KRPCI_SpaceCenter::VESSEL         activeVessel;
  KRPCI_SpaceCenter::FLIGHT         activeVessel_flight;
  std::string                       activeVessel_name;
  KRPCI_SpaceCenter::ORBIT          activeVessel_orbit;
  KRPCI_SpaceCenter::CELESTIALBODY  activeVessel_orbit_body;
  KRPCI_SpaceCenter::REFERENCEFRAME activeVessel_orbit_body_ref;
  double                            activeVessel_orbit_body_mass;

  double                            activeVessel_altitude;
  double                            activeVessel_verticalSpeed;
  double                            activeVessel_maxThrust;
  double                            activeVessel_mass;
  double                            activeVessel_GForce;
  double                            activeVessel_distToBody;

  KRPCI_SpaceCenter::CONTROL        activeVessel_control;
  float                             activeVessel_control_throttle;

  Vector3d_t Vessel_Position(KRPCI_SpaceCenter::VESSEL Vessel, KRPCI_SpaceCenter::REFERENCEFRAME referenceFrame);
  double     Vessel_DistanceToBody(KRPCI_SpaceCenter::VESSEL Vessel, KRPCI_SpaceCenter::REFERENCEFRAME referenceFrame);

  // test variables

  double prevVSpeed = 0.0;
  double verticalAccel = 0.0;

};

#endif // KNAV_H
