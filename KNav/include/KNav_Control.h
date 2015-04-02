#ifndef KNAV_CONTROL_H
#define KNAV_CONTROL_H

#include "stdafx.h"
#include "KNav_Telemetry.h"

class KNav_Control
{
public:
  KNav_Control(KNav_Telemetry &telemetry);
  ~KNav_Control() {};

  void Control();

private:


  KNav_Telemetry &knavTelemetry;
  HANDLE         &knavTelemetryThread;

};

#endif // KNAV_CONTROL_H