#ifndef KNAV_DISPLAY_H
#define KNAV_DISPLAY_H

#include "stdafx.h"
#include "KNav_Telemetry.h"

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
    latched(FALSE) { }

    BOOL operator==(const UserInput &rhs) {
      return !(up ^ rhs.up) && !(down ^ rhs.down) && 
        !(left ^ rhs.left) && !(right ^ rhs.right);
    };
    BOOL operator!=(const UserInput &rhs) {
      return !operator==(rhs);
    };
    void copy(const UserInput &rhs) {
      up = rhs.up; down = rhs.down; left = rhs.left; right = rhs.right;
    };
    BOOL pressed() {
      return up || down || left || right;
    };

    BOOL up;
    BOOL down;
    BOOL left;
    BOOL right;

    BOOL latched;
  } UserInput_t;


  //
  //  METHODS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // constructor/destructor
  //
  KNav_Display(const HANDLE &con, KNav_Telemetry &telemetry);
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


  //
  //  PRIVATE MEMBERS
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  // external object handles
  KNav_Telemetry &knavTelemetry;
  const HANDLE   &console;

  // class info
  vector<string>  VESSEL_SITUATION_K;
  BOOL            clearScreen;
  DOUBLE          systemTime;
  UserInput_t     userInput;
  HANDLE          userInputMutex;
  string          prevDebugMsg;

};

#endif // KNAV_DISPLAY_H
