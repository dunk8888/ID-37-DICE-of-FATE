/*
  DICE of FATE: http://www.team-arg.org/dice-manual.html

  Arduboy version 1.5:  http://www.team-arg.org/dice-downloads.html

  MADE by TEAM a.r.g. : http://www.team-arg.org/more-about.html

  2016 - CASTPIXEL - JO3RI

  License: MIT : https://opensource.org/licenses/MIT

*/

//determine the game
#define GAME_ID 37

#include "Arglib.h"
#include "globals.h"
#include "menu.h"
#include "game.h"

typedef void (*FunctionPointer) ();
const FunctionPointer PROGMEM  mainGameLoop[] = {
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
  arduboy.initRandomSeed();
}

void loop()
{
  if (!(arduboy.nextFrame())) return;
  arduboy.poll();
  arduboy.clearDisplay();
  ((FunctionPointer) pgm_read_word (&mainGameLoop[gameState]))();
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

