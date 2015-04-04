#include "stdafx.h"

class KNav_PID
{
  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                   %=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%  P U B L I C   I N T E R F A C E  %=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                   %=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
public:

  //
  //  METHODS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // constructor/destructor
  //
  KNav_PID(
    const double &output, 
    double controlMin,
    double controlMax,
    double h = 0.1,
    double tosc = 1.0);
  ~KNav_PID() {};

  // entry point functions
  //
  double Control(
    double deltaTime,
    double outputReference);

  // utility functions
  //
  double Saturated(double control);
  void   Reset();

  //
  //  PUBLIC FIELDS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // control variables
  //double Ku;
  //double Tosc;
  double Kp;
  double Ki;
  double Kd;
  double h;
  double Tosc;


  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                  =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%  P R I V A T E   M E M B E R S   =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                  =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
private:

  //
  //  PRIVATE MEMBERS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // control variables
  const double &outputVariable;

  double controlInput;
  double controlInputSat;
  double controlInputMin;
  double controlInputMax;

  double proportional;
  double integral;
  double derivative;

  double prev_derivative;
  double prev_outputVariable;

};