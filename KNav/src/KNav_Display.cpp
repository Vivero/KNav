#include "KNav_Display.h"

KNav_Display::KNav_Display(const HANDLE &con, KNav_Telemetry &telemetry, KNav_Control &control) :
knavTelemetry(telemetry),
knavControl(control),
console(con),
clearScreen(TRUE),
systemTime(0.0),
userInputMutex(NULL),
prevDebugMsg(""),
programSelectionIndex(0),
programActiveIndex(0)
{
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

  // set screen size
  COORD dwSize = { KNAV_DISPLAY_WIDTH, KNAV_DISPLAY_HEIGHT };
  SetConsoleScreenBufferSize(console, dwSize);

  // create user input mutex
  userInputMutex = CreateMutex(
    NULL,              // default security attributes
    FALSE,             // initially not owned
    L"userInput");     // mutex name

  if (userInputMutex == NULL) {
    printf("WARNING: Failed to create mutex userInputMutex");
  }
}

void KNav_Display::Display()
{
  // get current time
  ULONGLONG systemTime_ms = GetTickCount64();
  systemTime = (DOUBLE)systemTime_ms / 1000.0;

  // process user input
  if (LockUserInput()) {

    string msg;

    // process single-presses
    if (userInput.latched) {


      if (userInput.up) {
        msg = "Pressed UP";
        ProgramSelectionIndex_Decrement();
      }
      else if (userInput.down) {
        msg = "Pressed DOWN";
        ProgramSelectionIndex_Increment();
      }
      else if (userInput.enter) {
        programActiveIndex = programSelectionIndex;
        knavControl.programActiveIndex = (KNav_Control::ProgramID_t)programActiveIndex;
      }

      if (userInput.key0) {
        programSelectionIndex = (UINT)KNav_Control::EMERGENCY;
        programActiveIndex = (UINT)KNav_Control::EMERGENCY;
        knavControl.programActiveIndex = KNav_Control::EMERGENCY;
        knavControl.reference = 0.0;
      }
      else if(userInput.key7) {
        knavControl.reference = knavControl.reference + 0.1;
      }
      else if (userInput.key1) {
        knavControl.reference = knavControl.reference - 0.1;
      }

      if (userInput.left) {
        msg = "Pressed LEFT";
      }
      if (userInput.right) {
        msg = "Pressed RIGHT";
      }

      if (userInput.pressed()) {
#ifdef KNAV_DISPLAY_DEBUG
        knavTelemetry.SetDebugMessage(msg);
#endif
      }


      userInput.latched = FALSE;
    }

    // process continuous input

    UnlockUserInput();
  }

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

  // show Selection info
  Display_Select();

  // show debug info
  Display_Debug();

  // reset attributes
  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

KNav_Display::UserInput_t& KNav_Display::GetUserInput() {
  return userInput;
}
BOOL KNav_Display::LockUserInput() {
  DWORD dwWaitResult = WaitForSingleObject(
    userInputMutex,    // handle to mutex
    100);              // time-out interval (ms)
  return (dwWaitResult == WAIT_OBJECT_0);
}

void KNav_Display::UnlockUserInput() {
  ReleaseMutex(userInputMutex);
}

void KNav_Display::cls() {
  // clear whole screen
  clear(0, 0, KNAV_DISPLAY_WIDTH, KNAV_DISPLAY_HEIGHT);
}

void KNav_Display::cls_Debug() {
  CONSOLE_SCREEN_BUFFER_INFO   csbi;
  UINT                         clearHeight = 0;

  // get current screen dims
  if (!GetConsoleScreenBufferInfo(console, &csbi)) {
    clearHeight = KNAV_DISPLAY_DEBUG_H - KNAV_DISPLAY_DEBUG_Y - 1;
  }
  else {
    clearHeight = csbi.dwSize.Y;
  }

  // clear debug screen
  clear(KNAV_DISPLAY_DEBUG_X, KNAV_DISPLAY_DEBUG_Y + 1, KNAV_DISPLAY_DEBUG_W, clearHeight);
}

void KNav_Display::clear(UINT x, UINT y, UINT w, UINT h)
{
  COORD                        coordScreen = { x, y };
  DWORD                        dwConSize = w * h;
  DWORD                        cCharsWritten = 0;
  CONSOLE_SCREEN_BUFFER_INFO   csbi;

  // fill portion with blanks
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

void KNav_Display::ProgramSelectionIndex_Increment() {
  UINT numPrograms = knavControl.programList.size();
  programSelectionIndex++;
  programSelectionIndex = (programSelectionIndex < numPrograms) ? programSelectionIndex : 0;
}

void KNav_Display::ProgramSelectionIndex_Decrement() {
  UINT numPrograms = knavControl.programList.size();
  LONG num = (LONG)programSelectionIndex - 1;
  programSelectionIndex = (num < 0) ? (numPrograms - 1) : (UINT)num;
}

void KNav_Display::Display_Time()
{
  COORD cursorPos;
  cursorPos.X = KNAV_DISPLAY_TIME_X;
  cursorPos.Y = KNAV_DISPLAY_TIME_Y;

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
  printf("%11.3f", knavTelemetry.activeVessel.mission_elapsed_time);

  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  printf(" ]");
}

void KNav_Display::Display_VesselInfo()
{
  COORD cursorPos;
  cursorPos.X = KNAV_DISPLAY_VESSEL_X;
  cursorPos.Y = KNAV_DISPLAY_VESSEL_Y;

  SetConsoleCursorPosition(console, cursorPos);
  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  printf("[------  V E S S E L   I N F O  ------]\n\n");
  
  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
  printf(" %-17s : %17s\n", "vessel name", knavTelemetry.activeVessel.name.c_str());
  printf(" %-17s : %17d\n", "vessel id", knavTelemetry.activeVessel.vessel);
  printf(" %-17s : %17d\n", "parts id", knavTelemetry.activeVessel.parts);
  printf("\n");
  printf(" %-17s : %17.0f\n", "mass", knavTelemetry.activeVessel.mass);
  printf(" %-17s : %17.0f\n", "weight", knavTelemetry.activeVessel.mass * knavTelemetry.activeVessel.gravitationalForce);
  printf(" %-17s : %17.0f\n", "thrust", knavTelemetry.activeVessel.maxThrust * knavTelemetry.activeVessel.throttle);
  printf(" %-17s : %17.0f\n", "max thrust", knavTelemetry.activeVessel.maxThrust);
  printf(" %-17s : %17.1f\n", "radar altitude", knavTelemetry.activeVessel.radarAltitude);
  printf(" %-17s : %17.1f\n", "v. speed", knavTelemetry.activeVessel.verticalSpeed);
  printf("\n");
  printf(" %-17s : %17.2f\n", "rotatron", knavTelemetry.activeVesselParts.rotatron1_angle);
}

void KNav_Display::Display_Program()
{
  COORD cursorPos;
  cursorPos.X = KNAV_DISPLAY_PROGRAM_X;
  cursorPos.Y = KNAV_DISPLAY_PROGRAM_Y;

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

  printf("%17s", flightStatus.c_str());

  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
  cursorPos.Y += 2;
  SetConsoleCursorPosition(console, cursorPos);
  printf(" %-17s : %17d", "executions", knavTelemetry.executionCount);

  cursorPos.Y++;
  SetConsoleCursorPosition(console, cursorPos);
  printf(" %-17s : %17d", "async calls", knavTelemetry.numAsyncCalls);

  cursorPos.Y++;
  SetConsoleCursorPosition(console, cursorPos);
  printf(" %-17s : %17.1f", "avg exec time", knavTelemetry.avgExecutionTime_ms);

  cursorPos.Y++;
  SetConsoleCursorPosition(console, cursorPos);
  printf(" %-17s : %17d", "cmd buffer size", knavTelemetry.commandBufferSize);

  cursorPos.Y += 2;
  SetConsoleCursorPosition(console, cursorPos);
  printf(" %-17s : %17.1f", "reference", knavControl.reference);

  cursorPos.Y++;
  SetConsoleCursorPosition(console, cursorPos);
  printf(" %-17s : %17.1f", "vspeed ref", knavControl.ref_vspeed);
}

void KNav_Display::Display_Select()
{
  COORD cursorPos;
  cursorPos.X = KNAV_DISPLAY_SELECT_X;
  cursorPos.Y = KNAV_DISPLAY_SELECT_Y;

  SetConsoleCursorPosition(console, cursorPos);
  SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
  printf("[------------------------------   S E L E C T   ------------------------------]\n");

  cursorPos.X += 2;
  cursorPos.Y += 2;

  UINT numPrograms = knavControl.programList.size();
  WORD textAttrDefault = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
  for (UINT i = 0; i < numPrograms; i++)
  {
    // set cursor and color
    WORD textAttr = textAttrDefault;
    SetConsoleCursorPosition(console, cursorPos);
    if (i == programActiveIndex) {
      textAttr = textAttr & (~FOREGROUND_GREEN); // subtract green
    }
    if (i == programSelectionIndex) {
      textAttr = textAttr << 4;
    }
    SetConsoleTextAttribute(console, textAttr);

    printf("%s", knavControl.programList.at(i).name.c_str());

    cursorPos.Y++;
  }
}

void KNav_Display::Display_Debug()
{
  COORD cursorPos;
  cursorPos.X = KNAV_DISPLAY_DEBUG_X;
  cursorPos.Y = KNAV_DISPLAY_DEBUG_Y;

  SetConsoleCursorPosition(console, cursorPos);
  SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  printf("[-------------------------------   D E B U G   -------------------------------]\n");
  printf("[-- TIME : ");

  // retrieve debug message
  double debugTime = 0.0;
  string debugMsg;
  knavTelemetry.GetDebugMessage(debugTime, debugMsg);

  // display message if it is recent
  if ((systemTime < (debugTime + KNAV_DISPLAY_DEBUG_TIMEOUT_S)) &&
    (prevDebugMsg.compare(debugMsg) == 0)) 
  {
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    printf("%.3f\n\n", debugTime);

    printf("%s\n", debugMsg.c_str());
  }
  else {
    cls_Debug();
  }

  prevDebugMsg.assign(debugMsg);
}


