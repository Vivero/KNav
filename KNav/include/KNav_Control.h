#ifndef KNAV_CONTROL_H
#define KNAV_CONTROL_H

#include "stdafx.h"
#include "KNav_Telemetry.h"

class KNav_Control
{
  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                   %=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%  P U B L I C   I N T E R F A C E  %=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                   %=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
public:

  //
  //  TYPES
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // programs
  //
  enum ProgramID_t {
    NONE = 0,
    HOVER = 1,
    ASCENT = 2,
    EMERGENCY = 3
  };

  typedef struct ControlProgram {
    ControlProgram() : id(NONE), name("") {}
    ControlProgram(ProgramID_t id, string name) : id(id), name(name) {}

    ProgramID_t id;
    string      name;
  } ControlProgram_t;


  //
  //  METHODS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // constructor/destructor
  //
  KNav_Control(KNav_Telemetry &telemetry);
  ~KNav_Control() {};

  // entry point functions
  //
  void Control();


  //
  //  PUBLIC FIELDS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // program list
  vector<ControlProgram_t> programList;
  atomic<ProgramID_t>      programActiveIndex;

  // control variables
  atomic<double>           controlHover_altitude;


  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                  =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%  P R I V A T E   M E M B E R S   =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                  =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
private:

  //
  //  METHODS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // control programs
  //
  void Control_Hover();
  void Control_Emergency();


  //
  //  PRIVATE MEMBERS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // external object handles
  KNav_Telemetry &knavTelemetry;
  const HANDLE   &knavTelemetryThread;

  // class members
  double          deltaTime;
  ULONGLONG       prevSystemTime_ms;

};

#endif // KNAV_CONTROL_H