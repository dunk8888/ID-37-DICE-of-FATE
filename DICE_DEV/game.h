#ifndef GAME_H
#define GAME_H

#include "inputs.h"
#include "bitmaps.h"

byte currentDice;
byte amountOfDice;
byte frameDice;
int slideCounter;
boolean slideLeft;
boolean slidingDice;
boolean goBack;

//define menu states (on main menu)
#define STATE_MENU_INTRO             0
#define STATE_MENU_MAIN              1
#define STATE_MENU_HELP              2
#define STATE_MENU_PLAY              3
#define STATE_MENU_INFO              4
#define STATE_MENU_SOUNDFX           5

//define game states (on main menu)
#define STATE_DICE_TYPE_AND_AMOUNT   6
#define STATE_DICE_RESULT            7


extern Arduboy arduboy;
extern byte gameState;
Sprites sprites(arduboy);

struct Dice
{
  public:
    int x, y;
    byte type;
    byte result[5];
};

Dice rollingDice[5];


void drawNumbers(byte numbersX, byte numbersY, int number)
{
  char buf[10];
  //number = arduboy.cpuLoad();
  itoa(number, buf, 10);
  char charLen = strlen(buf);
  char pad = 3 - charLen;

  for (byte i = 0; i < charLen; i++)
  {
    char digit = buf[i];
    byte j;
    if (digit <= 48)
    {
      digit = 0;
    }
    else {
      digit -= 48;
      if (digit > 9) digit = 0;
    }

    for (byte z = 0; z < 10; z++)
    {
      if (digit == z) j = z;
    }
    sprites.drawSelfMasked(numbersX + (pad * 5) + (10 * i), numbersY, allNumbers, digit);
  }
}

void stateMenuPlay()
{
  for (byte i = 0; i < 5; i++)
  {
    rollingDice[i].type = i;
    rollingDice[i].x = 42 * i;
    rollingDice[i].y = 0;
    for (byte k = 0; k < 5; k++)
    {
      rollingDice[i].result[k] = 1;
    }
  }
  slideLeft = true;
  slidingDice = false;
  goBack = false;
  currentDice = 3;
  slideCounter = 0;
  amountOfDice = 2;
  frameDice = 0;
  gameState = STATE_DICE_TYPE_AND_AMOUNT;
}


void stateDiceTypeAndAmount()
{
  for (byte i = 0; i < 5; i++)
  {
    sprites.drawSelfMasked(rollingDice[i].x - 40 , rollingDice[i].y, allDice, 3 * rollingDice[i].type + frameDice);
  }
  if (buttons.justPressed(RIGHT_BUTTON) && !slidingDice && (currentDice < 5))
  {
    slidingDice = true;
    slideLeft = true;
    currentDice++;
  }
  if (buttons.justPressed(LEFT_BUTTON) && !slidingDice && (currentDice > 1))
  {
    slidingDice = true;
    slideLeft = false;
    currentDice--;
  }
  if (buttons.justPressed(UP_BUTTON) && amountOfDice < 5) amountOfDice++;
  if (buttons.justPressed(DOWN_BUTTON) && amountOfDice > 1) amountOfDice--;
  
  if (buttons.justPressed(B_BUTTON))
  {

    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].type = currentDice - 1;
      rollingDice[i].x = 42;
      rollingDice[i].y = 12;
    }

    gameState = STATE_DICE_TYPE_AND_AMOUNT;
  }
  if (buttons.justPressed(A_BUTTON))
  {
    gameState = STATE_MENU_MAIN;
  }

  if (slideLeft && slidingDice && (slideCounter < 41))
  {
    slideCounter += 2;
    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].x -= 2;
    }
  }

  if (!slideLeft && slidingDice && (slideCounter < 41))
  {
    slideCounter += 2;
    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].x += 2;
    }
  }
  if (slideCounter > 41)
  {
    slideCounter = 0;
    slidingDice = false;
  }
  /*
  if (currentDice > 1)sprites.drawSelfMasked(52 , 49, arrows, 0);
  if (amountOfDice < 5)sprites.drawSelfMasked(60 , 42, arrows, 1);
  if (currentDice < 5)sprites.drawSelfMasked(72 , 49, arrows, 2);
  if (amountOfDice > 1)sprites.drawSelfMasked(60 , 60, arrows, 3);
  */

  drawNumbers(50, 47, amountOfDice);
  
  //sprites.drawSelfMasked(0, 49, backButton, 0);
  //sprites.drawSelfMasked(93, 49, rollButton, 0);
}

void stateDiceRolling()
{
  sprites.drawSelfMasked(0, -2, allDice, 4 * rollingDice[0].type + frameDice);
  sprites.drawSelfMasked(22, 26, allDice, rollingDice[1].type);
  sprites.drawSelfMasked(44, -2, allDice, rollingDice[2].type);
  sprites.drawSelfMasked(66, 26, allDice, rollingDice[3].type);
  sprites.drawSelfMasked(88, -2, allDice, rollingDice[4].type);
  
  if (buttons.justPressed(A_BUTTON)) gameState = STATE_DICE_TYPE_AND_AMOUNT;
}

void stateDiceResult()
{

}



#endif
