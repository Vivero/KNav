#include "KNav_Display.h"

KNav_Display::KNav_Display(HANDLE console, KNav_Telemetry &telemetry) :
clearScreen(TRUE),
knavTelemetry(telemetry)
{
  this->console = console;
  VESSEL_SITUATION_K.push_back("DOCKED");
  VESSEL_SITUATION_K.push_back("ESCAPING");
  VESSEL_SITUATION_K.push_back("FLYING");
  VESSEL_SITUATION_K.push_back("LANDED");
  VESSEL_SITUATION_K.push_back("ORBITING");
  VESSEL_SITUATION_K.push_back("PRELAUNCH");
  VESSEL_SITUATION_K.push_back("SPLASHED");
  VESSEL_SITUATION_K.push_back("SUBORBITAL");

  /*
  Docked         , 0
  Escaping       , 1
  Flying         , 2
  Landed         , 3
  Orbiting       , 4
  PreLaunch      , 5
  Splashed       , 6
  SubOrbital     , 7
  */
}

void KNav_Display::Display()
{
  // get current time
  ULONGLONG systemTime_ms = GetTickCount64();
  systemTime = (double)systemTime_ms / 1000.0;

  // re-render whole screen
  if (clearScreen) {
    cls();

    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%" << endl;
    cout << "%=%                                                                         %=%" << endl;
    //cout << "%=%                      KNav - Kerbal Navigation Suite                     %=%" << endl;
    cout << "%=%                      ";
    SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "KNav - Kerbal Navigation Suite";
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "                     %=%" << endl;
    cout << "%=%                                                                         %=%" << endl;
    cout << "%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%" << endl;
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    clearScreen = FALSE;
  }

  // show time info
  Display_Time();

  // show vessel telemetry
  Display_VesselInfo();

  // show Program info
  Display_Program();

  // show debug info
  Display_Debug();

  // reset attributes
  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
};

void KNav_Display::Display_Time()
{
  COORD cursorPos;
  cursorPos.X = 0;
  cursorPos.Y = KNAV_DISPLAY_TIME_Y_POS;

  SetConsoleCursorPosition(console, cursorPos);
  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  printf("[--------------------------------   T I M E   --------------------------------]\n");
  printf("[                                                                             ]\n");
  printf("[ SYSTEM: ");

  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
  printf("%-19.3f", systemTime);

  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  printf("KSP UT: ");

  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
  printf("%-20.3f", knavTelemetry.kspUniversalTime);

  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  printf("KSP MET: ");

  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
  printf("%11.3f", 0.0);

  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  printf(" ]");
}

void KNav_Display::Display_VesselInfo()
{
  COORD cursorPos;
  cursorPos.X = 0;
  cursorPos.Y = KNAV_DISPLAY_VESSEL_Y_POS;

  SetConsoleCursorPosition(console, cursorPos);
  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  printf("[------  V E S S E L   I N F O  ------]\n\n");
  
  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
  printf(" %-17s : %17s\n", "vessel name", knavTelemetry.activeVessel.name.c_str());
  printf(" %-17s : %17d\n", "vessel id", knavTelemetry.activeVessel.vessel);
  printf("\n");
  printf(" %-17s : %17.0f\n", "mass", knavTelemetry.activeVessel.mass);
  printf(" %-17s : %17.0f\n", "weight", knavTelemetry.activeVessel.mass * knavTelemetry.activeVessel.gravitationalForce);
  printf(" %-17s : %17.0f\n", "thrust", knavTelemetry.activeVessel.maxThrust * knavTelemetry.activeVessel.throttle);
  printf("\n");
  printf(" %-17s : %17.1f\n", "radar altitude", knavTelemetry.activeVessel.radarAltitude);
}

void KNav_Display::Display_Program()
{
  COORD cursorPos;
  cursorPos.X = KNAV_DISPLAY_PROGRAM_X_POS;
  cursorPos.Y = KNAV_DISPLAY_PROGRAM_Y_POS;

  SetConsoleCursorPosition(console, cursorPos);
  SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  printf("[----------  P R O G R A M  ----------]\n\n");

  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
  cursorPos.Y += 2;
  SetConsoleCursorPosition(console, cursorPos);
  printf(" %-17s : ", "flight status");

  string flightStatus;
  if (knavTelemetry.inFlight) {
    flightStatus = VESSEL_SITUATION_K[knavTelemetry.activeVessel.situation];
  }
  else {
    flightStatus = "NOT IN FLIGHT ";
    SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | BACKGROUND_RED);
  }

  printf("%17s\n", flightStatus.c_str());

  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

}

void KNav_Display::Display_Debug()
{
  COORD cursorPos;
  cursorPos.X = 0;
  cursorPos.Y = KNAV_DISPLAY_DEBUG_Y_POS;

  SetConsoleCursorPosition(console, cursorPos);
  SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  printf("[-------------------------------   D E B U G   -------------------------------]\n");
  printf("[-- TIME : ");

  // retrieve debug message
  double debugTime = 0.0;
  string debugMsg;
  knavTelemetry.GetDebugMessage(debugTime, debugMsg);

  // display message if it is recent
  if (systemTime < (debugTime + KNAV_DISPLAY_DEBUG_TIMEOUT_S)) {
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    printf("%.3f\n\n", debugTime);

    printf("%s\n", debugMsg.c_str());
  }
  else {
    cursorPos.Y = KNAV_DISPLAY_DEBUG_Y_POS + 1;
    SetConsoleCursorPosition(console, cursorPos);

    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    GetConsoleScreenBufferInfo(console, &csbi);
    dwConSize = csbi.dwSize.X * (csbi.dwSize.Y - cursorPos.Y);
    FillConsoleOutputCharacter(
      console,
      (TCHAR) ' ',
      dwConSize,
      cursorPos,
      &cCharsWritten);
  }
}

void KNav_Display::cls()
{
  COORD coordScreen = { 0, 0 };
  DWORD cCharsWritten;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD dwConSize;

  // get num chars in current buffer
  if (!GetConsoleScreenBufferInfo(console, &csbi)) {
    return;
  }
  dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

  // fill screen with blanks
  if (!FillConsoleOutputCharacter(
    console,
    (TCHAR) ' ',
    dwConSize,
    coordScreen,
    &cCharsWritten)) {
    return;
  }

  // get current text attribute
  if (!GetConsoleScreenBufferInfo(console, &csbi)) {
    return;
  }

  // set buffer's attributes accordingly
  if (!FillConsoleOutputAttribute(
    console,
    csbi.wAttributes,
    dwConSize,
    coordScreen,
    &cCharsWritten)) {
    return;
  }

  // put cursor at home coords
  SetConsoleCursorPosition(console, coordScreen);
}
