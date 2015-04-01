#ifndef KNAV_DISPLAY_H
#define KNAV_DISPLAY_H

#include "stdafx.h"
#include "KNav_Telemetry.h"

#define KNAV_DISPLAY_BANNER_Y_POS    0
#define KNAV_DISPLAY_BANNER_HEIGHT   6

#define KNAV_DISPLAY_TIME_Y_POS      (KNAV_DISPLAY_BANNER_Y_POS + KNAV_DISPLAY_BANNER_HEIGHT)
#define KNAV_DISPLAY_TIME_HEIGHT     4

#define KNAV_DISPLAY_VESSEL_X_POS    0
#define KNAV_DISPLAY_VESSEL_Y_POS    (KNAV_DISPLAY_TIME_Y_POS + KNAV_DISPLAY_TIME_HEIGHT)
#define KNAV_DISPLAY_VESSEL_HEIGHT   10
#define KNAV_DISPLAY_VESSEL_WIDTH    40

#define KNAV_DISPLAY_PROGRAM_X_POS   (KNAV_DISPLAY_VESSEL_X_POS + KNAV_DISPLAY_VESSEL_WIDTH)
#define KNAV_DISPLAY_PROGRAM_Y_POS    (KNAV_DISPLAY_TIME_Y_POS + KNAV_DISPLAY_TIME_HEIGHT)
#define KNAV_DISPLAY_PROGRAM_HEIGHT  10
#define KNAV_DISPLAY_PROGRAM_WIDTH   39

#define KNAV_DISPLAY_DEBUG_Y_POS     30
#define KNAV_DISPLAY_DEBUG_TIMEOUT_S 20.0

class KNav_Display
{
public:
  KNav_Display(HANDLE console, KNav_Telemetry &telemetry);
  ~KNav_Display() {};

  void Display();

private:

  vector<string> VESSEL_SITUATION_K;

  HANDLE console;
  BOOL   clearScreen;

  void   Display_Time();
  void   Display_VesselInfo();
  void   Display_Program();
  void   Display_Debug();
  void   cls();

  double systemTime;

  KNav_Telemetry &knavTelemetry;
};

#endif // KNAV_DISPLAY_H
