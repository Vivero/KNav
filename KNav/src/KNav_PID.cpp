#include "KNav_PID.h"

KNav_PID::KNav_PID(
  const double &output,
  double controlMin,
  double controlMax,
  double h,
  double tosc) :
  Kp(0.0), Ki(0.0), Kd(0.0), h(h), Tosc(tosc), outputVariable(output),
  controlInput(controlMin), controlInputSat(controlMin), 
  controlInputMin(controlMin), controlInputMax(controlMax),
  proportional(0.0), integral(0.0), derivative(0.0), prev_derivative(0.0),
  prev_outputVariable(0.0) {}

double KNav_PID::Control(double deltaTime, double reference)
{
  double output = outputVariable;
  double error = reference - output;
  //printf("p %.5f, i %.5f, d %.5f, tosc %.5f, h %.5f \n", Kp, Ki, Kd, Tosc, h);

  proportional = Kp * error;
  integral += Ki * h * error + h / Tosc * (controlInputSat - controlInput);
  derivative = Tosc / (Tosc + h) * prev_derivative - Kd / (Tosc + h) * (output - prev_outputVariable);

  controlInput = proportional + integral + derivative;
  controlInputSat = Saturated(controlInput);

  //printf("error = %.6f, sat = %.6f, ctrl = %.6f \n", error, controlInputSat, controlInput);
  //printf("p %.5f + i %.5f + d %.5f \n", proportional, integral, derivative);

  prev_outputVariable = output;
  prev_derivative = derivative;

  return controlInputSat;
}

double KNav_PID::Saturated(double in) {
  return (in > controlInputMax) ? controlInputMax : ((in < controlInputMin) ? controlInputMin : in);
}

void KNav_PID::Reset() {
  controlInput = 0.0;
  controlInputSat = 0.0;
  integral = 0.0;
}
