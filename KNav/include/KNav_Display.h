#ifndef KNAV_DISPLAY_H
#define KNAV_DISPLAY_H

#include "stdafx.h"
#include "KNav_Telemetry.h"
#include "KNav_Control.h"

/*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
/*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=                 %=%=%=%=%=%=%=%=%=%=%=%=%=%=%=*/
/*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=  D E F I N E S  %=%=%=%=%=%=%=%=%=%=%=%=%=%=%=*/
/*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=                 %=%=%=%=%=%=%=%=%=%=%=%=%=%=%=*/
/*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/

//#define KNAV_DISPLAY_DEBUG

#define KNAV_DISPLAY_WIDTH            80

#define KNAV_DISPLAY_BANNER_X         0
#define KNAV_DISPLAY_BANNER_Y         0
#define KNAV_DISPLAY_BANNER_H         6
#define KNAV_DISPLAY_BANNER_W         KNAV_DISPLAY_WIDTH

#define KNAV_DISPLAY_TIME_X           0
#define KNAV_DISPLAY_TIME_Y          (KNAV_DISPLAY_BANNER_Y + KNAV_DISPLAY_BANNER_H)
#define KNAV_DISPLAY_TIME_H           4
#define KNAV_DISPLAY_TIME_W           KNAV_DISPLAY_WIDTH

#define KNAV_DISPLAY_VESSEL_X         0
#define KNAV_DISPLAY_VESSEL_Y        (KNAV_DISPLAY_TIME_Y + KNAV_DISPLAY_TIME_H)
#define KNAV_DISPLAY_VESSEL_H         15
#define KNAV_DISPLAY_VESSEL_W        (KNAV_DISPLAY_BANNER_W >> 1)

#define KNAV_DISPLAY_PROGRAM_X       (KNAV_DISPLAY_VESSEL_X + KNAV_DISPLAY_VESSEL_W)
#define KNAV_DISPLAY_PROGRAM_Y       (KNAV_DISPLAY_TIME_Y + KNAV_DISPLAY_TIME_H)
#define KNAV_DISPLAY_PROGRAM_H        KNAV_DISPLAY_VESSEL_H
#define KNAV_DISPLAY_PROGRAM_W       (KNAV_DISPLAY_BANNER_W >> 1)

#define KNAV_DISPLAY_SELECT_X         0
#define KNAV_DISPLAY_SELECT_Y        (KNAV_DISPLAY_VESSEL_Y + KNAV_DISPLAY_VESSEL_H)
#define KNAV_DISPLAY_SELECT_H         12
#define KNAV_DISPLAY_SELECT_W         KNAV_DISPLAY_WIDTH

#define KNAV_DISPLAY_DEBUG_X          0
#define KNAV_DISPLAY_DEBUG_Y         (KNAV_DISPLAY_SELECT_Y + KNAV_DISPLAY_SELECT_H)
#define KNAV_DISPLAY_DEBUG_H          10
#define KNAV_DISPLAY_DEBUG_W          KNAV_DISPLAY_WIDTH
#define KNAV_DISPLAY_DEBUG_TIMEOUT_S  20.0

#define KNAV_DISPLAY_HEIGHT          (KNAV_DISPLAY_BANNER_H + KNAV_DISPLAY_TIME_H + KNAV_DISPLAY_VESSEL_H + KNAV_DISPLAY_DEBUG_H + 1)

class KNav_Display
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

  // struct for storing user input
  //
  typedef struct UserInput {
    UserInput() : up(FALSE), down(FALSE), left(FALSE), right(FALSE),
    enter(FALSE), clear(FALSE), key0(FALSE), key1(FALSE), key3(FALSE),
    key5(FALSE), key7(FALSE), key9(FALSE),
    latched(FALSE) { }

    BOOL operator==(const UserInput &rhs) {
      return !(up ^ rhs.up) && !(down ^ rhs.down) && 
        !(left ^ rhs.left) && !(right ^ rhs.right) &&
        !(enter ^ rhs.enter) && !(clear ^ rhs.clear) &&
        !(key0 ^ rhs.key0) && !(key1 ^ rhs.key1) && 
        !(key3 ^ rhs.key3) && !(key5 ^ rhs.key5) && 
        !(key7 ^ rhs.key7) && !(key9 ^ rhs.key9);
    };
    BOOL operator!=(const UserInput &rhs) {
      return !operator==(rhs);
    };
    void copy(const UserInput &rhs) {
      up = rhs.up; down = rhs.down; left = rhs.left; right = rhs.right;
      enter = rhs.enter; clear = rhs.clear; key0 = rhs.key0; key1 = rhs.key1;
      key3 = rhs.key3; key5 = rhs.key5; key7 = rhs.key7; key9 = rhs.key9;
    };
    BOOL pressed() {
      return up || down || left || right ||
        enter || clear || key0 || key1 || key3 || 
        key5 || key7 || key9;
    };

    BOOL up;
    BOOL down;
    BOOL left;
    BOOL right;
    BOOL enter;
    BOOL clear;
    BOOL key0;
    BOOL key1;
    BOOL key3;
    BOOL key5;
    BOOL key7;
    BOOL key9;

    BOOL latched;
  } UserInput_t;


  //
  //  METHODS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // constructor/destructor
  //
  KNav_Display(const HANDLE &con, KNav_Telemetry &telemetry, KNav_Control &control);
  ~KNav_Display() {};

  // entry point functions
  //
  void         Display();

  // user input
  //
  UserInput_t& GetUserInput();
  BOOL         LockUserInput();
  void         UnlockUserInput();


  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                  =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%  P R I V A T E   M E M B E R S   =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%                                  =%=%=%=%=%=%=%=%=%=%*/
  /*=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%*/
private:

  //
  //  METHODS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // entry point functions
  //
  void   Display_Time();
  void   Display_VesselInfo();
  void   Display_Program();
  void   Display_Select();
  void   Display_Debug();

  // utility functions
  //
  void   cls();
  void   cls_Debug();
  void   clear(UINT x, UINT y, UINT w, UINT h);

  void   ProgramSelectionIndex_Increment();
  void   ProgramSelectionIndex_Decrement();

  //
  //  PRIVATE MEMBERS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // external object handles
  KNav_Telemetry &knavTelemetry;
  KNav_Control   &knavControl;
  const HANDLE   &console;

  // class info
  vector<string>  VESSEL_SITUATION_K;
  BOOL            clearScreen;
  DOUBLE          systemTime;
  UserInput_t     userInput;
  HANDLE          userInputMutex;
  string          prevDebugMsg;

  // program selection
  UINT            programSelectionIndex;
  UINT            programActiveIndex;

};

#endif // KNAV_DISPLAY_H
