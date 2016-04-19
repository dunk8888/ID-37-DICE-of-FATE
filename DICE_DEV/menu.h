#ifndef MENU_H
#define MENU_H

#include "globals.h"

void stateMenuIntro()
{
  counter++;
  arduboy.drawBitmap(0, 8, TEAMarg, 128, 48, WHITE);
  if (counter > 180) gameState = STATE_MENU_MAIN;
}

void stateMenuMain()
{
  arduboy.drawBitmap(0, 0, titleScreen, 128, 64, WHITE);
  if (buttons.justPressed(RIGHT_BUTTON) && (menuSelection < 5)) menuSelection++;
  if (buttons.justPressed(LEFT_BUTTON) && (menuSelection > 2)) menuSelection--;
  if (buttons.justPressed(B_BUTTON)) gameState = menuSelection;
}

void stateMenuHelp()
{
  arduboy.drawBitmap(32, 0, qrcode, 64, 64, WHITE);
  if (buttons.justPressed(A_BUTTON | B_BUTTON)) gameState = STATE_MENU_MAIN;
}


void stateMenuInfo()
{
  
  if (buttons.justPressed(A_BUTTON | B_BUTTON)) gameState = STATE_MENU_MAIN;
}

void stateMenuSoundfx()
{
  if (buttons.justPressed(DOWN_BUTTON)) soundYesNo = true;
  if (buttons.justPressed(UP_BUTTON)) soundYesNo = false;
  if (buttons.justPressed(A_BUTTON | B_BUTTON))
  {
    arduboy.audio.saveOnOff();
    gameState = STATE_MENU_MAIN;
  }
  if (soundYesNo == true) arduboy.audio.on();
  else arduboy.audio.off();
}

#endif
