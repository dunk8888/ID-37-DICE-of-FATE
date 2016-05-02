/*
  DIGITAL DICE SIM: http://www.team-arg.org/dice-manual.html

  Arduboy version 0.1:  http://www.team-arg.org/dice-downloads.html

  MADE by TEAM a.r.g. : http://www.team-arg.org/more-about.html

  2016 - CASTPIXEL - JO3RI

  License: MIT : https://opensource.org/licenses/MIT

*/

#include "Arglib.h"
#include "globals.h"
#include "menu.h"
#include "game.h"

//determine the game
#define GAME_ID 37

typedef void (*FunctionPointer) ();
FunctionPointer mainGameLoop[] = {
  stateMenuIntro,
  stateMenuMain,
  stateMenuHelp,
  stateMenuPlay,
  stateMenuInfo,
  stateMenuSoundfx,
  stateDiceTypeAndAmount,
  stateDiceRolling,
  stateDiceResult,
};

void setup()
{
  arduboy.start();
  arduboy.setFrameRate(60);
  gameState = STATE_MENU_INTRO;
  //gameState = STATE_MENU_MAIN;
  menuSelection = STATE_MENU_PLAY;
  if (EEPROM.read(EEPROM_AUDIO_ON_OFF)) soundYesNo = true;
  arduboy.initRandomSeed();
}

void loop()
{
  if (!(arduboy.nextFrame())) return;
  buttons.poll();
  if (soundYesNo == true) arduboy.audio.on();
  else arduboy.audio.off();
  arduboy.clearDisplay();
  mainGameLoop[gameState]();
  arduboy.display();
  for (byte i = 0; i < 4; i++) if (buttonPressed[i] == true) pressedButtonCounter++;
  if (pressedButtonCounter > 6)
  {
    for (byte i = 0; i < 4; i++)
    {
      buttonPressed[i] = false;
    }
    pressedButtonCounter = 0;
  }

}

