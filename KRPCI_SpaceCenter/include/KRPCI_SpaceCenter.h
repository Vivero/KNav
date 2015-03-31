#ifndef SPACECENTER_H 
#define SPACECENTER_H 

#include "stdafx.h"
#include "KRPCI.h"
#include "KRPC.pb.h"

#define KRPC_SERVER_VERSION "0.1.6" 

class KRPCI_SpaceCenter { 

public: 

  typedef UINT64 AUTOPILOT; 
  typedef UINT64 CELESTIALBODY; 
  typedef UINT64 COMMS; 
  typedef UINT64 CONTROL; 
  typedef UINT64 FLIGHT; 
  typedef UINT64 NODE; 
  typedef UINT64 ORBIT; 
  typedef UINT64 DECOUPLER; 
  typedef UINT64 DOCKINGPORT; 
  typedef UINT64 ENGINE; 
  typedef UINT64 LANDINGGEAR; 
  typedef UINT64 LANDINGLEG; 
  typedef UINT64 LAUNCHCLAMP; 
  typedef UINT64 LIGHT; 
  typedef UINT64 MODULE; 
  typedef UINT64 PARACHUTE; 
  typedef UINT64 PART; 
  typedef UINT64 PARTS; 
  typedef UINT64 PARTRESOURCES; 
  typedef UINT64 REACTIONWHEEL; 
  typedef UINT64 SENSOR; 
  typedef UINT64 SOLARPANEL; 
  typedef UINT64 REFERENCEFRAME; 
  typedef UINT64 VESSEL; 
  typedef UINT64 VESSELRESOURCES; 


  enum DockingPortState { 
    DockingPortState_Ready = 0, 
    DockingPortState_Docked = 1, 
    DockingPortState_Docking = 2, 
    DockingPortState_Undocking = 3, 
    DockingPortState_Shielded = 4, 
    DockingPortState_Moving = 5 
  }; 

  enum LandingGearState { 
    LandingGearState_Deployed = 0, 
    LandingGearState_Retracted = 1, 
    LandingGearState_Deploying = 2, 
    LandingGearState_Retracting = 3 
  }; 

  enum LandingLegState { 
    LandingLegState_Deployed = 0, 
    LandingLegState_Retracted = 1, 
    LandingLegState_Deploying = 2, 
    LandingLegState_Retracting = 3, 
    LandingLegState_Broken = 4, 
    LandingLegState_Repairing = 5 
  }; 

  enum ParachuteState { 
    ParachuteState_Active = 0, 
    ParachuteState_Cut = 1, 
    ParachuteState_Deployed = 2, 
    ParachuteState_SemiDeployed = 3, 
    ParachuteState_Stowed = 4 
  }; 

  enum PartState { 
    PartState_Idle = 0, 
    PartState_Active = 1, 
    PartState_Dead = 2 
  }; 

  enum SolarPanelState { 
    SolarPanelState_Extended = 0, 
    SolarPanelState_Retracted = 1, 
    SolarPanelState_Extending = 2, 
    SolarPanelState_Retracting = 3, 
    SolarPanelState_Broken = 4 
  }; 

  enum VesselType { 
    VesselType_Ship = 0, 
    VesselType_Station = 1, 
    VesselType_Lander = 2, 
    VesselType_Probe = 3, 
    VesselType_Rover = 4, 
    VesselType_Base = 5, 
    VesselType_Debris = 6 
  }; 

  enum VesselSituation { 
    VesselSituation_Docked = 0, 
    VesselSituation_Escaping = 1, 
    VesselSituation_Flying = 2, 
    VesselSituation_Landed = 3, 
    VesselSituation_Orbiting = 4, 
    VesselSituation_PreLaunch = 5, 
    VesselSituation_Splashed = 6, 
    VesselSituation_SubOrbital = 7 
  }; 



  static void ClearTarget(); 
  static void WarpTo(double UT, double maxRate); 
  static KRPC::Tuple TransformPosition(KRPC::Tuple position, REFERENCEFRAME from, REFERENCEFRAME to); 
  static KRPC::Tuple TransformDirection(KRPC::Tuple direction, REFERENCEFRAME from, REFERENCEFRAME to); 
  static KRPC::Tuple TransformRotation(KRPC::Tuple rotation, REFERENCEFRAME from, REFERENCEFRAME to); 
  static KRPC::Tuple TransformVelocity(KRPC::Tuple position, KRPC::Tuple velocity, REFERENCEFRAME from, REFERENCEFRAME to); 
  static void DrawDirection(KRPC::Tuple direction, REFERENCEFRAME referenceFrame, KRPC::Tuple color, float length); 
  static void ClearDirections(); 
  static KRPCI_SpaceCenter::VESSEL get_ActiveVessel(); 
  static KRPC::List get_Vessels(); 
  static KRPC::Dictionary get_Bodies(); 
  static KRPCI_SpaceCenter::CELESTIALBODY get_TargetBody(); 
  static void set_TargetBody(CELESTIALBODY value); 
  static KRPCI_SpaceCenter::VESSEL get_TargetVessel(); 
  static void set_TargetVessel(VESSEL value); 
  static KRPCI_SpaceCenter::DOCKINGPORT get_TargetDockingPort(); 
  static void set_TargetDockingPort(DOCKINGPORT value); 
  static double get_UT(); 
  static double get_G(); 
  static bool get_FARAvailable(); 
  static bool get_RemoteTechAvailable(); 
  static void AutoPilot_SetRotation(AUTOPILOT AutoPilot, double pitch, double heading, double roll, REFERENCEFRAME referenceFrame, bool wait); 
  static void AutoPilot_SetDirection(AUTOPILOT AutoPilot, KRPC::Tuple direction, double roll, REFERENCEFRAME referenceFrame, bool wait); 
  static void AutoPilot_Disengage(AUTOPILOT AutoPilot); 
  static double AutoPilot_get_Error(AUTOPILOT AutoPilot); 
  static double AutoPilot_get_RollError(AUTOPILOT AutoPilot); 
  static double CelestialBody_AtmospherePressureAt(CELESTIALBODY CelestialBody, double altitude); 
  static double CelestialBody_AtmosphereDensityAt(CELESTIALBODY CelestialBody, double altitude); 
  static KRPC::Tuple CelestialBody_Position(CELESTIALBODY CelestialBody, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple CelestialBody_Velocity(CELESTIALBODY CelestialBody, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple CelestialBody_Rotation(CELESTIALBODY CelestialBody, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple CelestialBody_Direction(CELESTIALBODY CelestialBody, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple CelestialBody_AngularVelocity(CELESTIALBODY CelestialBody, REFERENCEFRAME referenceFrame); 
  static string CelestialBody_get_Name(CELESTIALBODY CelestialBody); 
  static KRPC::List CelestialBody_get_Satellites(CELESTIALBODY CelestialBody); 
  static double CelestialBody_get_Mass(CELESTIALBODY CelestialBody); 
  static double CelestialBody_get_GravitationalParameter(CELESTIALBODY CelestialBody); 
  static double CelestialBody_get_SurfaceGravity(CELESTIALBODY CelestialBody); 
  static double CelestialBody_get_RotationalPeriod(CELESTIALBODY CelestialBody); 
  static double CelestialBody_get_RotationalSpeed(CELESTIALBODY CelestialBody); 
  static double CelestialBody_get_EquatorialRadius(CELESTIALBODY CelestialBody); 
  static double CelestialBody_get_SphereOfInfluence(CELESTIALBODY CelestialBody); 
  static KRPCI_SpaceCenter::ORBIT CelestialBody_get_Orbit(CELESTIALBODY CelestialBody); 
  static bool CelestialBody_get_HasAtmosphere(CELESTIALBODY CelestialBody); 
  static double CelestialBody_get_AtmospherePressure(CELESTIALBODY CelestialBody); 
  static double CelestialBody_get_AtmosphereDensity(CELESTIALBODY CelestialBody); 
  static double CelestialBody_get_AtmosphereScaleHeight(CELESTIALBODY CelestialBody); 
  static double CelestialBody_get_AtmosphereMaxAltitude(CELESTIALBODY CelestialBody); 
  static KRPCI_SpaceCenter::REFERENCEFRAME CelestialBody_get_ReferenceFrame(CELESTIALBODY CelestialBody); 
  static KRPCI_SpaceCenter::REFERENCEFRAME CelestialBody_get_NonRotatingReferenceFrame(CELESTIALBODY CelestialBody); 
  static KRPCI_SpaceCenter::REFERENCEFRAME CelestialBody_get_OrbitalReferenceFrame(CELESTIALBODY CelestialBody); 
  static double Comms_SignalDelayToVessel(COMMS Comms, VESSEL other); 
  static bool Comms_get_HasFlightComputer(COMMS Comms); 
  static bool Comms_get_HasConnection(COMMS Comms); 
  static bool Comms_get_HasConnectionToGroundStation(COMMS Comms); 
  static double Comms_get_SignalDelay(COMMS Comms); 
  static double Comms_get_SignalDelayToGroundStation(COMMS Comms); 
  static KRPC::List Control_ActivateNextStage(CONTROL Control); 
  static bool Control_GetActionGroup(CONTROL Control, UINT32 group); 
  static void Control_SetActionGroup(CONTROL Control, UINT32 group, bool state); 
  static void Control_ToggleActionGroup(CONTROL Control, UINT32 group); 
  static KRPCI_SpaceCenter::NODE Control_AddNode(CONTROL Control, double UT, double prograde, double normal, double radial); 
  static void Control_RemoveNodes(CONTROL Control); 
  static bool Control_get_SAS(CONTROL Control); 
  static void Control_set_SAS(CONTROL Control, bool value); 
  static bool Control_get_RCS(CONTROL Control); 
  static void Control_set_RCS(CONTROL Control, bool value); 
  static bool Control_get_Gear(CONTROL Control); 
  static void Control_set_Gear(CONTROL Control, bool value); 
  static bool Control_get_Lights(CONTROL Control); 
  static void Control_set_Lights(CONTROL Control, bool value); 
  static bool Control_get_Brakes(CONTROL Control); 
  static void Control_set_Brakes(CONTROL Control, bool value); 
  static bool Control_get_Abort(CONTROL Control); 
  static void Control_set_Abort(CONTROL Control, bool value); 
  static float Control_get_Throttle(CONTROL Control); 
  static void Control_set_Throttle(CONTROL Control, float value); 
  static float Control_get_Pitch(CONTROL Control); 
  static void Control_set_Pitch(CONTROL Control, float value); 
  static float Control_get_Yaw(CONTROL Control); 
  static void Control_set_Yaw(CONTROL Control, float value); 
  static float Control_get_Roll(CONTROL Control); 
  static void Control_set_Roll(CONTROL Control, float value); 
  static float Control_get_Forward(CONTROL Control); 
  static void Control_set_Forward(CONTROL Control, float value); 
  static float Control_get_Up(CONTROL Control); 
  static void Control_set_Up(CONTROL Control, float value); 
  static float Control_get_Right(CONTROL Control); 
  static void Control_set_Right(CONTROL Control, float value); 
  static float Control_get_WheelThrottle(CONTROL Control); 
  static void Control_set_WheelThrottle(CONTROL Control, float value); 
  static float Control_get_WheelSteering(CONTROL Control); 
  static void Control_set_WheelSteering(CONTROL Control, float value); 
  static INT32 Control_get_CurrentStage(CONTROL Control); 
  static KRPC::List Control_get_Nodes(CONTROL Control); 
  static double Flight_get_GForce(FLIGHT Flight); 
  static double Flight_get_MeanAltitude(FLIGHT Flight); 
  static double Flight_get_SurfaceAltitude(FLIGHT Flight); 
  static double Flight_get_BedrockAltitude(FLIGHT Flight); 
  static double Flight_get_Elevation(FLIGHT Flight); 
  static double Flight_get_Latitude(FLIGHT Flight); 
  static double Flight_get_Longitude(FLIGHT Flight); 
  static KRPC::Tuple Flight_get_Velocity(FLIGHT Flight); 
  static double Flight_get_Speed(FLIGHT Flight); 
  static double Flight_get_HorizontalSpeed(FLIGHT Flight); 
  static double Flight_get_VerticalSpeed(FLIGHT Flight); 
  static KRPC::Tuple Flight_get_CenterOfMass(FLIGHT Flight); 
  static KRPC::Tuple Flight_get_Rotation(FLIGHT Flight); 
  static KRPC::Tuple Flight_get_Direction(FLIGHT Flight); 
  static double Flight_get_Pitch(FLIGHT Flight); 
  static double Flight_get_Heading(FLIGHT Flight); 
  static double Flight_get_Roll(FLIGHT Flight); 
  static KRPC::Tuple Flight_get_Prograde(FLIGHT Flight); 
  static KRPC::Tuple Flight_get_Retrograde(FLIGHT Flight); 
  static KRPC::Tuple Flight_get_Normal(FLIGHT Flight); 
  static KRPC::Tuple Flight_get_AntiNormal(FLIGHT Flight); 
  static KRPC::Tuple Flight_get_Radial(FLIGHT Flight); 
  static KRPC::Tuple Flight_get_AntiRadial(FLIGHT Flight); 
  static double Flight_get_AtmosphereDensity(FLIGHT Flight); 
  static double Flight_get_Drag(FLIGHT Flight); 
  static double Flight_get_DynamicPressure(FLIGHT Flight); 
  static double Flight_get_AngleOfAttack(FLIGHT Flight); 
  static double Flight_get_SideslipAngle(FLIGHT Flight); 
  static double Flight_get_StallFraction(FLIGHT Flight); 
  static double Flight_get_MachNumber(FLIGHT Flight); 
  static double Flight_get_TerminalVelocity(FLIGHT Flight); 
  static double Flight_get_DragCoefficient(FLIGHT Flight); 
  static double Flight_get_LiftCoefficient(FLIGHT Flight); 
  static double Flight_get_PitchingMomentCoefficient(FLIGHT Flight); 
  static double Flight_get_BallisticCoefficient(FLIGHT Flight); 
  static double Flight_get_ThrustSpecificFuelConsumption(FLIGHT Flight); 
  static string Flight_get_FARStatus(FLIGHT Flight); 
  static KRPC::Tuple Node_BurnVector(NODE Node, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple Node_RemainingBurnVector(NODE Node, REFERENCEFRAME referenceFrame); 
  static void Node_Remove(NODE Node); 
  static KRPC::Tuple Node_Position(NODE Node, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple Node_Direction(NODE Node, REFERENCEFRAME referenceFrame); 
  static double Node_get_Prograde(NODE Node); 
  static void Node_set_Prograde(NODE Node, double value); 
  static double Node_get_Normal(NODE Node); 
  static void Node_set_Normal(NODE Node, double value); 
  static double Node_get_Radial(NODE Node); 
  static void Node_set_Radial(NODE Node, double value); 
  static double Node_get_DeltaV(NODE Node); 
  static void Node_set_DeltaV(NODE Node, double value); 
  static double Node_get_RemainingDeltaV(NODE Node); 
  static double Node_get_UT(NODE Node); 
  static void Node_set_UT(NODE Node, double value); 
  static double Node_get_TimeTo(NODE Node); 
  static KRPCI_SpaceCenter::ORBIT Node_get_Orbit(NODE Node); 
  static KRPCI_SpaceCenter::REFERENCEFRAME Node_get_ReferenceFrame(NODE Node); 
  static KRPCI_SpaceCenter::REFERENCEFRAME Node_get_OrbitalReferenceFrame(NODE Node); 
  static KRPC::Tuple Orbit_ReferencePlaneNormal(ORBIT Orbit, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple Orbit_ReferencePlaneDirection(ORBIT Orbit, REFERENCEFRAME referenceFrame); 
  static KRPCI_SpaceCenter::CELESTIALBODY Orbit_get_Body(ORBIT Orbit); 
  static double Orbit_get_Apoapsis(ORBIT Orbit); 
  static double Orbit_get_Periapsis(ORBIT Orbit); 
  static double Orbit_get_ApoapsisAltitude(ORBIT Orbit); 
  static double Orbit_get_PeriapsisAltitude(ORBIT Orbit); 
  static double Orbit_get_SemiMajorAxis(ORBIT Orbit); 
  static double Orbit_get_SemiMinorAxis(ORBIT Orbit); 
  static double Orbit_get_Radius(ORBIT Orbit); 
  static double Orbit_get_Speed(ORBIT Orbit); 
  static double Orbit_get_Period(ORBIT Orbit); 
  static double Orbit_get_TimeToApoapsis(ORBIT Orbit); 
  static double Orbit_get_TimeToPeriapsis(ORBIT Orbit); 
  static double Orbit_get_Eccentricity(ORBIT Orbit); 
  static double Orbit_get_Inclination(ORBIT Orbit); 
  static double Orbit_get_LongitudeOfAscendingNode(ORBIT Orbit); 
  static double Orbit_get_ArgumentOfPeriapsis(ORBIT Orbit); 
  static double Orbit_get_MeanAnomalyAtEpoch(ORBIT Orbit); 
  static double Orbit_get_Epoch(ORBIT Orbit); 
  static double Orbit_get_MeanAnomaly(ORBIT Orbit); 
  static double Orbit_get_EccentricAnomaly(ORBIT Orbit); 
  static KRPCI_SpaceCenter::ORBIT Orbit_get_NextOrbit(ORBIT Orbit); 
  static double Orbit_get_TimeToSOIChange(ORBIT Orbit); 
  static void Decoupler_Decouple(DECOUPLER Decoupler); 
  static KRPCI_SpaceCenter::PART Decoupler_get_Part(DECOUPLER Decoupler); 
  static bool Decoupler_get_Decoupled(DECOUPLER Decoupler); 
  static float Decoupler_get_Impulse(DECOUPLER Decoupler); 
  static KRPCI_SpaceCenter::VESSEL DockingPort_Undock(DOCKINGPORT DockingPort); 
  static KRPC::Tuple DockingPort_Position(DOCKINGPORT DockingPort, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple DockingPort_Direction(DOCKINGPORT DockingPort, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple DockingPort_Rotation(DOCKINGPORT DockingPort, REFERENCEFRAME referenceFrame); 
  static KRPCI_SpaceCenter::PART DockingPort_get_Part(DOCKINGPORT DockingPort); 
  static string DockingPort_get_Name(DOCKINGPORT DockingPort); 
  static void DockingPort_set_Name(DOCKINGPORT DockingPort, string value); 
  static INT32 DockingPort_get_State(DOCKINGPORT DockingPort); 
  static KRPCI_SpaceCenter::PART DockingPort_get_DockedPart(DOCKINGPORT DockingPort); 
  static float DockingPort_get_ReengageDistance(DOCKINGPORT DockingPort); 
  static bool DockingPort_get_HasShield(DOCKINGPORT DockingPort); 
  static bool DockingPort_get_Shielded(DOCKINGPORT DockingPort); 
  static void DockingPort_set_Shielded(DOCKINGPORT DockingPort, bool value); 
  static KRPCI_SpaceCenter::REFERENCEFRAME DockingPort_get_ReferenceFrame(DOCKINGPORT DockingPort); 
  static KRPCI_SpaceCenter::PART Engine_get_Part(ENGINE Engine); 
  static bool Engine_get_Activated(ENGINE Engine); 
  static void Engine_set_Activated(ENGINE Engine, bool value); 
  static float Engine_get_ThrustLimit(ENGINE Engine); 
  static void Engine_set_ThrustLimit(ENGINE Engine, float value); 
  static float Engine_get_Thrust(ENGINE Engine); 
  static float Engine_get_MaxThrust(ENGINE Engine); 
  static float Engine_get_SpecificImpulse(ENGINE Engine); 
  static float Engine_get_VacuumSpecificImpulse(ENGINE Engine); 
  static float Engine_get_KerbinSeaLevelSpecificImpulse(ENGINE Engine); 
  static KRPC::List Engine_get_Propellants(ENGINE Engine); 
  static bool Engine_get_HasFuel(ENGINE Engine); 
  static bool Engine_get_ThrottleLocked(ENGINE Engine); 
  static bool Engine_get_CanRestart(ENGINE Engine); 
  static bool Engine_get_CanShutdown(ENGINE Engine); 
  static bool Engine_get_Gimballed(ENGINE Engine); 
  static float Engine_get_GimbalRange(ENGINE Engine); 
  static bool Engine_get_GimbalLocked(ENGINE Engine); 
  static void Engine_set_GimbalLocked(ENGINE Engine, bool value); 
  static KRPCI_SpaceCenter::PART LandingGear_get_Part(LANDINGGEAR LandingGear); 
  static INT32 LandingGear_get_State(LANDINGGEAR LandingGear); 
  static bool LandingGear_get_Deployed(LANDINGGEAR LandingGear); 
  static void LandingGear_set_Deployed(LANDINGGEAR LandingGear, bool value); 
  static KRPCI_SpaceCenter::PART LandingLeg_get_Part(LANDINGLEG LandingLeg); 
  static INT32 LandingLeg_get_State(LANDINGLEG LandingLeg); 
  static bool LandingLeg_get_Deployed(LANDINGLEG LandingLeg); 
  static void LandingLeg_set_Deployed(LANDINGLEG LandingLeg, bool value); 
  static void LaunchClamp_Release(LAUNCHCLAMP LaunchClamp); 
  static KRPCI_SpaceCenter::PART LaunchClamp_get_Part(LAUNCHCLAMP LaunchClamp); 
  static KRPCI_SpaceCenter::PART Light_get_Part(LIGHT Light); 
  static bool Light_get_Active(LIGHT Light); 
  static void Light_set_Active(LIGHT Light, bool value); 
  static float Light_get_PowerUsage(LIGHT Light); 
  static bool Module_HasField(MODULE Module, string name); 
  static string Module_GetField(MODULE Module, string name); 
  static bool Module_HasEvent(MODULE Module, string name); 
  static void Module_TriggerEvent(MODULE Module, string name); 
  static bool Module_HasAction(MODULE Module, string name); 
  static void Module_SetAction(MODULE Module, string name, bool value); 
  static string Module_get_Name(MODULE Module); 
  static KRPCI_SpaceCenter::PART Module_get_Part(MODULE Module); 
  static KRPC::Dictionary Module_get_Fields(MODULE Module); 
  static KRPC::List Module_get_Events(MODULE Module); 
  static KRPC::List Module_get_Actions(MODULE Module); 
  static void Parachute_Deploy(PARACHUTE Parachute); 
  static KRPCI_SpaceCenter::PART Parachute_get_Part(PARACHUTE Parachute); 
  static bool Parachute_get_Deployed(PARACHUTE Parachute); 
  static INT32 Parachute_get_State(PARACHUTE Parachute); 
  static float Parachute_get_DeployAltitude(PARACHUTE Parachute); 
  static void Parachute_set_DeployAltitude(PARACHUTE Parachute, float value); 
  static float Parachute_get_DeployMinPressure(PARACHUTE Parachute); 
  static void Parachute_set_DeployMinPressure(PARACHUTE Parachute, float value); 
  static KRPC::Tuple Part_Position(PART Part, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple Part_Direction(PART Part, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple Part_Velocity(PART Part, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple Part_Rotation(PART Part, REFERENCEFRAME referenceFrame); 
  static string Part_get_Name(PART Part); 
  static string Part_get_Title(PART Part); 
  static double Part_get_Cost(PART Part); 
  static KRPCI_SpaceCenter::VESSEL Part_get_Vessel(PART Part); 
  static KRPCI_SpaceCenter::PART Part_get_Parent(PART Part); 
  static KRPC::List Part_get_Children(PART Part); 
  static bool Part_get_AxiallyAttached(PART Part); 
  static bool Part_get_RadiallyAttached(PART Part); 
  static INT32 Part_get_Stage(PART Part); 
  static INT32 Part_get_DecoupleStage(PART Part); 
  static bool Part_get_Massless(PART Part); 
  static double Part_get_Mass(PART Part); 
  static double Part_get_DryMass(PART Part); 
  static double Part_get_ImpactTolerance(PART Part); 
  static double Part_get_Temperature(PART Part); 
  static double Part_get_MaxTemperature(PART Part); 
  static KRPCI_SpaceCenter::PARTRESOURCES Part_get_Resources(PART Part); 
  static bool Part_get_Crossfeed(PART Part); 
  static KRPC::List Part_get_FuelLinesFrom(PART Part); 
  static KRPC::List Part_get_FuelLinesTo(PART Part); 
  static KRPC::List Part_get_Modules(PART Part); 
  static KRPCI_SpaceCenter::DECOUPLER Part_get_Decoupler(PART Part); 
  static KRPCI_SpaceCenter::DOCKINGPORT Part_get_DockingPort(PART Part); 
  static KRPCI_SpaceCenter::ENGINE Part_get_Engine(PART Part); 
  static KRPCI_SpaceCenter::LANDINGGEAR Part_get_LandingGear(PART Part); 
  static KRPCI_SpaceCenter::LANDINGLEG Part_get_LandingLeg(PART Part); 
  static KRPCI_SpaceCenter::LAUNCHCLAMP Part_get_LaunchClamp(PART Part); 
  static KRPCI_SpaceCenter::LIGHT Part_get_Light(PART Part); 
  static KRPCI_SpaceCenter::PARACHUTE Part_get_Parachute(PART Part); 
  static KRPCI_SpaceCenter::REACTIONWHEEL Part_get_ReactionWheel(PART Part); 
  static KRPCI_SpaceCenter::SENSOR Part_get_Sensor(PART Part); 
  static KRPCI_SpaceCenter::SOLARPANEL Part_get_SolarPanel(PART Part); 
  static KRPCI_SpaceCenter::REFERENCEFRAME Part_get_ReferenceFrame(PART Part); 
  static KRPC::List Parts_WithName(PARTS Parts, string name); 
  static KRPC::List Parts_WithTitle(PARTS Parts, string title); 
  static KRPC::List Parts_WithModule(PARTS Parts, string moduleName); 
  static KRPC::List Parts_InStage(PARTS Parts, INT32 stage); 
  static KRPC::List Parts_InDecoupleStage(PARTS Parts, INT32 stage); 
  static KRPC::List Parts_ModulesWithName(PARTS Parts, string moduleName); 
  static KRPCI_SpaceCenter::DOCKINGPORT Parts_DockingPortWithName(PARTS Parts, string name); 
  static KRPC::List Parts_get_All(PARTS Parts); 
  static KRPCI_SpaceCenter::PART Parts_get_Root(PARTS Parts); 
  static KRPCI_SpaceCenter::PART Parts_get_Controlling(PARTS Parts); 
  static void Parts_set_Controlling(PARTS Parts, PART value); 
  static KRPC::List Parts_get_Decouplers(PARTS Parts); 
  static KRPC::List Parts_get_DockingPorts(PARTS Parts); 
  static KRPC::List Parts_get_Engines(PARTS Parts); 
  static KRPC::List Parts_get_LandingGear(PARTS Parts); 
  static KRPC::List Parts_get_LandingLegs(PARTS Parts); 
  static KRPC::List Parts_get_LaunchClamps(PARTS Parts); 
  static KRPC::List Parts_get_Lights(PARTS Parts); 
  static KRPC::List Parts_get_Parachutes(PARTS Parts); 
  static KRPC::List Parts_get_ReactionWheels(PARTS Parts); 
  static KRPC::List Parts_get_Sensors(PARTS Parts); 
  static KRPC::List Parts_get_SolarPanels(PARTS Parts); 
  static bool PartResources_HasResource(PARTRESOURCES PartResources, string name); 
  static double PartResources_Max(PARTRESOURCES PartResources, string name); 
  static double PartResources_Amount(PARTRESOURCES PartResources, string name); 
  static KRPC::List PartResources_get_Names(PARTRESOURCES PartResources); 
  static KRPCI_SpaceCenter::PART ReactionWheel_get_Part(REACTIONWHEEL ReactionWheel); 
  static bool ReactionWheel_get_Active(REACTIONWHEEL ReactionWheel); 
  static void ReactionWheel_set_Active(REACTIONWHEEL ReactionWheel, bool value); 
  static bool ReactionWheel_get_Broken(REACTIONWHEEL ReactionWheel); 
  static float ReactionWheel_get_PitchTorque(REACTIONWHEEL ReactionWheel); 
  static float ReactionWheel_get_YawTorque(REACTIONWHEEL ReactionWheel); 
  static float ReactionWheel_get_RollTorque(REACTIONWHEEL ReactionWheel); 
  static KRPCI_SpaceCenter::PART Sensor_get_Part(SENSOR Sensor); 
  static bool Sensor_get_Active(SENSOR Sensor); 
  static void Sensor_set_Active(SENSOR Sensor, bool value); 
  static string Sensor_get_Value(SENSOR Sensor); 
  static float Sensor_get_PowerUsage(SENSOR Sensor); 
  static KRPCI_SpaceCenter::PART SolarPanel_get_Part(SOLARPANEL SolarPanel); 
  static bool SolarPanel_get_Deployed(SOLARPANEL SolarPanel); 
  static void SolarPanel_set_Deployed(SOLARPANEL SolarPanel, bool value); 
  static INT32 SolarPanel_get_State(SOLARPANEL SolarPanel); 
  static float SolarPanel_get_EnergyFlow(SOLARPANEL SolarPanel); 
  static float SolarPanel_get_SunExposure(SOLARPANEL SolarPanel); 
  static KRPCI_SpaceCenter::FLIGHT Vessel_Flight(VESSEL Vessel, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple Vessel_Position(VESSEL Vessel, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple Vessel_Velocity(VESSEL Vessel, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple Vessel_Rotation(VESSEL Vessel, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple Vessel_Direction(VESSEL Vessel, REFERENCEFRAME referenceFrame); 
  static KRPC::Tuple Vessel_AngularVelocity(VESSEL Vessel, REFERENCEFRAME referenceFrame); 
  static string Vessel_get_Name(VESSEL Vessel); 
  static void Vessel_set_Name(VESSEL Vessel, string value); 
  static INT32 Vessel_get_Type(VESSEL Vessel); 
  static void Vessel_set_Type(VESSEL Vessel, INT32 value); 
  static INT32 Vessel_get_Situation(VESSEL Vessel); 
  static double Vessel_get_MET(VESSEL Vessel); 
  static KRPCI_SpaceCenter::VESSEL Vessel_get_Target(VESSEL Vessel); 
  static void Vessel_set_Target(VESSEL Vessel, VESSEL value); 
  static KRPCI_SpaceCenter::ORBIT Vessel_get_Orbit(VESSEL Vessel); 
  static KRPCI_SpaceCenter::CONTROL Vessel_get_Control(VESSEL Vessel); 
  static KRPCI_SpaceCenter::AUTOPILOT Vessel_get_AutoPilot(VESSEL Vessel); 
  static KRPCI_SpaceCenter::VESSELRESOURCES Vessel_get_Resources(VESSEL Vessel); 
  static KRPCI_SpaceCenter::PARTS Vessel_get_Parts(VESSEL Vessel); 
  static KRPCI_SpaceCenter::COMMS Vessel_get_Comms(VESSEL Vessel); 
  static double Vessel_get_Mass(VESSEL Vessel); 
  static double Vessel_get_DryMass(VESSEL Vessel); 
  static double Vessel_get_CrossSectionalArea(VESSEL Vessel); 
  static double Vessel_get_Thrust(VESSEL Vessel); 
  static double Vessel_get_SpecificImpulse(VESSEL Vessel); 
  static KRPCI_SpaceCenter::REFERENCEFRAME Vessel_get_ReferenceFrame(VESSEL Vessel); 
  static KRPCI_SpaceCenter::REFERENCEFRAME Vessel_get_OrbitalReferenceFrame(VESSEL Vessel); 
  static KRPCI_SpaceCenter::REFERENCEFRAME Vessel_get_SurfaceReferenceFrame(VESSEL Vessel); 
  static KRPCI_SpaceCenter::REFERENCEFRAME Vessel_get_SurfaceVelocityReferenceFrame(VESSEL Vessel); 
  static bool VesselResources_HasResource(VESSELRESOURCES VesselResources, string name); 
  static double VesselResources_Max(VESSELRESOURCES VesselResources, string name, INT32 stage, bool cumulative); 
  static double VesselResources_Amount(VESSELRESOURCES VesselResources, string name, INT32 stage, bool cumulative); 
  static KRPC::List VesselResources_get_Names(VESSELRESOURCES VesselResources); 

};

#endif // SPACECENTER_H 
