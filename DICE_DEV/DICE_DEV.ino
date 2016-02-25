/*
  DICE: http://www.team-arg.org/dice-manual.html

  Arduboy version 0.1:  http://www.team-arg.org/dice-downloads.html

  MADE by TEAM a.r.g. : http://www.team-arg.org/more-about.html

  2016 JO3RI - CASTPIXEL

  License: MIT : https://opensource.org/licenses/MIT

*/

#include <SPI.h>
#include <EEPROM.h>
#include <Arduboy.h>
#include <ArduboyExtra.h>
#include <sprites.h>
#include <simple_buttons.h>

//determine the game
#define GAME_ID 37

//define menu states (on main menu)
#define STATE_MENU_INTRO         0
#define STATE_MENU_MAIN          1
#define STATE_MENU_HELP          2
#define STATE_MENU_PLAY          3
#define STATE_MENU_INFO          4
#define STATE_MENU_SOUNDFX       5

//define game states (on main menu)
#define STATE_GAME_PLAYING       6
#define STATE_GAME_PAUSE         7
#define STATE_GAME_OVER          8

Arduboy arduboy;
SimpleButtons buttons (arduboy);

/*
typedef void (*FunctionPointer) ();
FunctionPointer whatToDo[] = {stateMenuIntro, stateMenuMain, stateMenuHelp, stateMenuPlay, stateMenuInfo, stateMenuSoundfx, stateGamePlaying, stateGamePause, stateGameOver};
*/
byte gameState;
boolean soundYesNo;
int menuSelection;
byte counter = 0;

void setup()
{
  arduboy.begin();
  arduboy.setFrameRate(60);
  gameState = STATE_MENU_INTRO;
  if (EEPROM.read(EEPROM_AUDIO_ON_OFF)) soundYesNo = true;
  menuSelection = STATE_MENU_PLAY;
}

void loop()
{
  
}

