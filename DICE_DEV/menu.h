#ifndef MENU_H
#define MENU_H

#include "globals.h"

byte titleFrame = 0;
byte titleCounter = 27;
boolean slideMenuLeft;
boolean slidingMenu;
byte slideMenuCounter = 0;
byte menuX;
byte soundMenuX;

void titleScreen()
{
  if (arduboy.everyXFrames(6)) titleCounter++;
  if (titleCounter > 47)titleCounter = 0;
  titleFrame = titleCounter;
  if (titleFrame > 7) titleFrame = 0;
  arduboy.drawBitmap(0, 0, titleTop, 128, 12, 1);
  arduboy.drawBitmap(0, 12, titleGleam[titleFrame], 128, 24, 1);
}

void updateSlidingMenu(byte amount)
{
  if (slideMenuLeft && slidingMenu && (slideMenuCounter < amount + 1))
  {
    slideMenuCounter++;
    if (amount == 25)menuX++;
    if (amount == 21)soundMenuX++;
  }

  if (!slideMenuLeft && slidingMenu && (slideMenuCounter < amount + 1))
  {
    slideMenuCounter++;
    if (amount == 25)menuX--;
    if (amount == 21)soundMenuX--;
  }

  if (slideMenuCounter > amount - 1)
  {
    slideMenuCounter = 0;
    slidingMenu = false;
  }
}

void stateMenuIntro()
{
  counter++;
  arduboy.drawBitmap(0, 8, TEAMarg, 128, 48, WHITE);
  if (counter > 180)
  {
    gameState = STATE_MENU_MAIN;
    slideMenuLeft = false;
    slidingMenu = false;
    menuX = 25 * (menuSelection - 2);
    soundMenuX = 21 * soundYesNo;
  }
}

void stateMenuMain()
{
  titleScreen();
  arduboy.drawBitmap(0, 36, titleBottom, 128, 12, 1);
  updateSlidingMenu(25);
  if (!slidingMenu) sprites.drawSelfMasked(52, 47, titleLine, 0);
  for (byte i = 0; i < 4; i++)
  {
    {
      if (((2 + i) - menuSelection) != 0 || slidingMenu)
      {
        sprites.drawPlusMask(52 - menuX + (25 * i), 48, titleText_plus_mask, i);
      }
      if ((((2 + i) - menuSelection) == 0) && !slidingMenu)
      {
        sprites.drawPlusMask(52 - menuX + (25 * i), 48, titleText_plus_mask, i + 7);
      }
    }
  }

  sprites.drawSelfMasked(51, 56, titleSelector, 0);
  if (buttons.justPressed(LEFT_BUTTON) && !slidingMenu && (menuSelection > 2))
  {
    slidingMenu = true;
    slideMenuLeft = false;
    menuSelection--;
  }
  if (buttons.justPressed(RIGHT_BUTTON) && !slidingMenu && (menuSelection < 5))
  {
    slidingMenu = true;
    slideMenuLeft = true;
    menuSelection++;
  }

  if (buttons.justPressed(B_BUTTON)) gameState = menuSelection;
}

void stateMenuHelp()
{
  arduboy.drawBitmap(32, 0, qrcode, 64, 64, WHITE);
  if (buttons.justPressed(A_BUTTON | B_BUTTON)) gameState = STATE_MENU_MAIN;
}


void stateMenuInfo()
{
  titleScreen();
  arduboy.drawBitmap(0, 36, infoScreen, 128, 32, WHITE);
  if (buttons.justPressed(A_BUTTON | B_BUTTON)) gameState = STATE_MENU_MAIN;
}

void stateMenuSoundfx()
{
  titleScreen();
  arduboy.drawBitmap(0, 36, titleBottom, 128, 12, WHITE);
  updateSlidingMenu(21);
  if (!slidingMenu) sprites.drawSelfMasked(54, 47, titleLine, 1);
  
  sprites.drawPlusMask(33 + soundMenuX - 21, 48, titleText_plus_mask, 6);
  if (!slidingMenu)sprites.drawPlusMask(33 + soundMenuX, 48, titleText_plus_mask, 4 + (7 * soundYesNo));
  if (!slidingMenu)sprites.drawPlusMask(33 + soundMenuX + 21 , 48, titleText_plus_mask, 5 + (7 * (1 - soundYesNo)));
  if (slidingMenu)sprites.drawPlusMask(33 + soundMenuX, 48, titleText_plus_mask, 4 );
  if (slidingMenu)sprites.drawPlusMask(33 + soundMenuX + 21 , 48, titleText_plus_mask, 5 );
  






  sprites.drawSelfMasked(51, 56, titleSelector, 1);
  if (buttons.justPressed(LEFT_BUTTON) && !slidingMenu && !soundYesNo)
  {
    slidingMenu = true;
    slideMenuLeft = true;
    soundYesNo = true;
  }
  if (buttons.justPressed(RIGHT_BUTTON) && !slidingMenu && soundYesNo)
  {
    slidingMenu = true;
    slideMenuLeft = false;
    soundYesNo = false;
  }
  if (buttons.justPressed(A_BUTTON | B_BUTTON))
  {
    arduboy.audio.saveOnOff();
    gameState = STATE_MENU_MAIN;
  }
  if (soundYesNo == true) arduboy.audio.on();
  else arduboy.audio.off();
}

#endif
