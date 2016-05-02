#ifndef MENU_H
#define MENU_H

#include "globals.h"

byte titleFrame = 0;
byte titleCounter = 27;

void titleScreen()
{
  if (arduboy.everyXFrames(6)) titleCounter++;
  if (titleCounter > 47)titleCounter = 0;
  titleFrame = titleCounter;
  if (titleFrame > 7) titleFrame = 0;
  arduboy.drawBitmap(0, 0, titleTop, 128, 12, 1);
  arduboy.drawBitmap(0, 12, titleGleam[titleFrame], 128, 24, 1);
  arduboy.drawBitmap(0, 36, titleBottom, 128, 12, 1);
}

void stateMenuIntro()
{
  counter++;
  arduboy.drawBitmap(0, 8, TEAMarg, 128, 48, WHITE);
  if (counter > 180) gameState = STATE_MENU_MAIN;
}

void stateMenuMain()
{
  titleScreen();
  sprites.drawSelfMasked(52, 47, titleLine, 0);
  for (byte i = 0; i < 4; i++)
  {
    {
      if (((2 + i) - menuSelection) != 0)
      {
        sprites.drawPlusMask(52 - (25 * (menuSelection - 2)) + (25 * i), 48, titleText_plus_mask, i);
      }
      if (((2 + i) - menuSelection) == 0) sprites.drawPlusMask(52 - (25 * (menuSelection - 2)) + (25 * i), 48, titleText_plus_mask, i + 7);
    }
  }
  
  sprites.drawSelfMasked(51, 56, titleSelector, 0);
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
  titleScreen();
  sprites.drawSelfMasked(54, 47, titleLine, 1);
  sprites.drawPlusMask(33 + (21 * soundYesNo) - 21, 48, titleText_plus_mask, 6);
  if (soundYesNo)
  {
    sprites.drawPlusMask(33 + (21 * soundYesNo), 48, titleText_plus_mask, 4 + 7);
    sprites.drawPlusMask(33 + (21 * soundYesNo) + 21 , 48, titleText_plus_mask, 5);
  }
  if (!soundYesNo)
  {
    sprites.drawPlusMask(33 + (21 * soundYesNo), 48, titleText_plus_mask, 4);
    sprites.drawPlusMask(33 + (21 * soundYesNo) + 21 , 48, titleText_plus_mask, 5 + 7);
  }
  sprites.drawSelfMasked(51, 56, titleSelector, 1);
  if (buttons.justPressed(LEFT_BUTTON)) soundYesNo = true;
  if (buttons.justPressed(RIGHT_BUTTON)) soundYesNo = false;
  if (buttons.justPressed(A_BUTTON | B_BUTTON))
  {
    arduboy.audio.saveOnOff();
    gameState = STATE_MENU_MAIN;
  }
  if (soundYesNo == true) arduboy.audio.on();
  else arduboy.audio.off();
}

#endif
