#ifndef GAME_H
#define GAME_H

#include "inputs.h"
#include "dice.h"
#include "numbers.h"

byte currentDice;
byte amountOfDice;
int slideCounter;
boolean slideLeft;
boolean slidingDice;
<<<<<<< HEAD
boolean goBack;
=======
>>>>>>> origin/master

//define menu states (on main menu)
#define STATE_MENU_INTRO         0
#define STATE_MENU_MAIN          1
#define STATE_MENU_HELP          2
#define STATE_MENU_PLAY          3
#define STATE_MENU_INFO          4
#define STATE_MENU_SOUNDFX       5

//define game states (on main menu)
#define STATE_DICE_TYPE          6
#define STATE_DICE_AMOUNT        7
#define STATE_DICE_SHAKE         8
#define STATE_DICE_RESULT        9


extern Arduboy arduboy;
extern byte gameState;

struct Dice
{
  public:
    int x, y;
    byte type;
    byte result[5];
};

Dice rollingDice[5];


void stateMenuPlay()
{
  for (byte i = 0; i < 5; i++)
  {
    rollingDice[i].type = i;
    rollingDice[i].x = 44 * i;
    rollingDice[i].y = 12;
    for (byte k = 0; k < 5; k++)
    {
      rollingDice[i].result[k] = 1;
    }
  }
  slideLeft = true;
  slidingDice = false;
<<<<<<< HEAD
  goBack = false;
  currentDice = 3;
=======
  currentDice = 2;
>>>>>>> origin/master
  slideCounter = 0;
  amountOfDice = 2;
  gameState = STATE_DICE_TYPE;
}


void stateDiceType()
{
  arduboy.drawPixel(63, 11, WHITE);
  arduboy.drawPixel(64, 11, WHITE);
  arduboy.drawPixel(63, 52, WHITE);
  arduboy.drawPixel(64, 52, WHITE);
  for (byte i = 0; i < 5; i++)
  {
    sprites.drawSelfMasked(rollingDice[i].x - 44 , rollingDice[i].y, allDice, rollingDice[i].type);
  }
<<<<<<< HEAD
  if (buttons.justPressed(RIGHT_BUTTON) && !slidingDice && (currentDice < 5))
=======
  if (buttons.justPressed(RIGHT_BUTTON) && !slidingDice)
>>>>>>> origin/master
  {
    slidingDice = true;
    slideLeft = true;
    currentDice++;
  }
<<<<<<< HEAD
  if (buttons.justPressed(LEFT_BUTTON) && !slidingDice && (currentDice > 1))
=======
  if (buttons.justPressed(LEFT_BUTTON) && !slidingDice)
>>>>>>> origin/master
  {
    slidingDice = true;
    slideLeft = false;
    currentDice--;
  }
<<<<<<< HEAD

  if (buttons.justPressed(B_BUTTON))
=======
  if (buttons.justPressed(RIGHT_BUTTON) && slidingDice)
>>>>>>> origin/master
  {

    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].type = currentDice - 1;
      rollingDice[i].x = 44;
      rollingDice[i].y = 12;
    }

    gameState = STATE_DICE_AMOUNT;
  }
<<<<<<< HEAD
  if (buttons.justPressed(A_BUTTON))
=======
  if (buttons.justPressed(LEFT_BUTTON) && slidingDice)
>>>>>>> origin/master
  {
    gameState = STATE_MENU_MAIN;
  }

<<<<<<< HEAD
  if (slideLeft && slidingDice && (slideCounter < 43))
=======
  if (slideLeft && slidingDice && (slideCounter < 44))
>>>>>>> origin/master
  {
    slideCounter += 2;
    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].x -= 2;
    }
  }

<<<<<<< HEAD
  if (!slideLeft && slidingDice && (slideCounter < 43))
=======
  if (!slideLeft && slidingDice && (slideCounter < 44))
>>>>>>> origin/master
  {
    slideCounter += 2;
    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].x += 2;
    }
  }
<<<<<<< HEAD
  if (slideCounter > 43)
  {
    slideCounter = 0;
    slidingDice = false;
  }
=======
  if (buttons.justPressed(UP_BUTTON || DOWN_BUTTON))
  {
    slidingDice = false;
  }
  if (slidingDice) Serial.println (slidecounter);
>>>>>>> origin/master
}

void stateDiceAmount()
{

  sprites.drawSelfMasked(rollingDice[0].x , rollingDice[0].y, allDice, rollingDice[0].type);
  if (rollingDice[0].x < 23)
  {
    drawNumbers(88, 24, amountOfDice);
  }
  if (rollingDice[0].x > 22 && !goBack) rollingDice[0].x -= 2;
  if ((rollingDice[0].x < 44) && goBack)
  {
    rollingDice[0].x += 2;
  }
  if (rollingDice[0].x > 43)
  {
    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].type = i;
      rollingDice[i].x = (44 * i) - 44 * (currentDice - 3);
    }
    Serial.println(currentDice);
    gameState = STATE_DICE_TYPE;
    goBack = false;
  }
  if (buttons.justPressed(B_BUTTON))
  {
    gameState = STATE_DICE_SHAKE;
  }
  if (buttons.justPressed(UP_BUTTON) && amountOfDice < 5) amountOfDice++;
  if (buttons.justPressed(DOWN_BUTTON) && amountOfDice > 1) amountOfDice--;
  if (buttons.justPressed(A_BUTTON)) goBack = true;
}

void stateDiceShake()
{
  sprites.drawSelfMasked(0, -2, allDice, rollingDice[0].type);
  sprites.drawSelfMasked(22, 26, allDice, rollingDice[1].type);
  sprites.drawSelfMasked(44, -2, allDice, rollingDice[2].type);
  sprites.drawSelfMasked(66, 26, allDice, rollingDice[3].type);
  sprites.drawSelfMasked(88, -2, allDice, rollingDice[4].type);
  
  if (buttons.justPressed(A_BUTTON)) gameState = STATE_DICE_AMOUNT;
}

void stateDiceResult()
{

}


#endif
