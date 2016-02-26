#ifndef MENU_BITMAPS_H
#define MENU_BITMAPS_H

#include "inputs.h"
#include "game.h"


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

extern byte gameState;

boolean soundYesNo;
int menuSelection;
byte counter = 0;

void stateMenuIntro()
{
  counter++;
  if (counter < 46)
  {
    arduboy.drawCompressed(0, 0, TEAMarg, WHITE);
  }

  if (counter > 45)
  {
    if (arduboy.everyXFrames(2))
    {
      frames++;
      blinkingFrame++;
    }
    if (frames > 4) frames = 0;
    if (blinkingFrame > 11) blinkingFrame = 0;
    arduboy.drawCompressed(0, 0, titleScreen, WHITE);
    arduboy.drawCompressed(85, 45, mysticBalloon, WHITE);
    sprites.drawSelfMasked(79, 43, stars, frames);
    sprites.drawSelfMasked(9, 9, leftGuyLeftEye, pgm_read_byte(&blinkingEyesLeftGuy[blinkingFrame]));
    sprites.drawSelfMasked(15, 13, leftGuyRightEye, pgm_read_byte(&blinkingEyesLeftGuy[blinkingFrame]));
    sprites.drawSelfMasked(109, 34, rightGuyLeftEye, pgm_read_byte(&blinkingEyesRightGuy[blinkingFrame]));
  }
  if ((counter > 90) || buttons.justPressed(A_BUTTON | B_BUTTON))
  {
    gameState = STATE_MENU_MAIN;
  }
}

void stateMenuMain()
{
  if (arduboy.everyXFrames(2))
  {
    frames++;
    blinkingFrame++;
  }
  if (frames > 4) frames = 0;
  if (blinkingFrame > 11) blinkingFrame = 0;
  arduboy.drawCompressed(0, 0, titleScreen, WHITE);
  arduboy.drawCompressed(85, 45, mysticBalloon, WHITE);
  sprites.drawSelfMasked(79, 43, stars, frames);
  sprites.drawSelfMasked(9, 9, leftGuyLeftEye, pgm_read_byte(&blinkingEyesLeftGuy[blinkingFrame]));
  sprites.drawSelfMasked(15, 13, leftGuyRightEye, pgm_read_byte(&blinkingEyesLeftGuy[blinkingFrame]));
  sprites.drawSelfMasked(109, 34, rightGuyLeftEye, pgm_read_byte(&blinkingEyesRightGuy[blinkingFrame]));

  arduboy.drawCompressed(51, 9, mainMenuMask, BLACK);
  arduboy.drawCompressed(51, 9, mainMenu, WHITE);
  if (buttons.justPressed(DOWN_BUTTON) && (menuSelection < 5)) menuSelection++;
  if (buttons.justPressed(UP_BUTTON) && (menuSelection > 2)) menuSelection--;
  if (buttons.justPressed(A_BUTTON | B_BUTTON)) gameState = menuSelection;
  arduboy.drawCompressed(46, 9 + 9 * (menuSelection - 2), selectorMask, BLACK);
  arduboy.drawCompressed(46, 9 + 9 * (menuSelection - 2), selector, WHITE);
}

void stateMenuHelp()
{
  arduboy.drawCompressed(32, 0, qrcode, WHITE);
  if (buttons.justPressed(A_BUTTON | B_BUTTON)) gameState = STATE_MENU_MAIN;
}

void stateMenuPlay()
{
  gameState = STATE_GAME_PLAYING;
}

void stateMenuInfo()
{
  if (arduboy.everyXFrames(10)) frames++;
  if (frames > 4) frames = 0;
  arduboy.drawCompressed(43, 23, mysticBalloon, WHITE);
  sprites.drawSelfMasked(37, 21, stars, frames);
  if (buttons.justPressed(A_BUTTON | B_BUTTON)) gameState = STATE_MENU_MAIN;
}

void stateMenuSoundfx()
{
  if (arduboy.everyXFrames(3)) frames++;
  if (frames > 4) frames = 0;
  arduboy.drawCompressed(0, 0, titleScreen, WHITE);
  arduboy.drawCompressed(85, 45, mysticBalloon, WHITE);
  sprites.drawSelfMasked(79, 42, stars, frames);
  arduboy.drawCompressed(51, 9, soundMenuMask, BLACK);
  arduboy.drawCompressed(51, 9, soundMenu, WHITE);
  if (buttons.justPressed(DOWN_BUTTON)) soundYesNo = true;
  if (buttons.justPressed(UP_BUTTON)) soundYesNo = false;
  arduboy.drawCompressed(54, 18 + 9 * soundYesNo, selectorMask, BLACK);
  arduboy.drawCompressed(54, 18 + 9 * soundYesNo, selector, WHITE);
  if (buttons.justPressed(A_BUTTON | B_BUTTON))
  {
    arduboy.audio.save_on_off();
    gameState = STATE_MENU_MAIN;
  }
  if (soundYesNo == true) arduboy.audio.on();
  else arduboy.audio.off();
}

#endif
