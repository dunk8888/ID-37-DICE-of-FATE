#ifndef GAME_H
#define GAME_H

#include "inputs.h"
#include "dice.h"

byte currentDice;
int slideCounter;
boolean slideLeft;
boolean sliding;

//define menu states (on main menu)
#define STATE_MENU_INTRO         0
#define STATE_MENU_MAIN          1
#define STATE_MENU_HELP          2
#define STATE_MENU_PLAY          3
#define STATE_MENU_INFO          4
#define STATE_MENU_SOUNDFX       5

//define game states (on main menu)
#define STATE_GAME_PLAYING       6


Sprites sprites(arduboy);

extern Arduboy arduboy;
extern byte gameState;

struct Dice
{
  public:
    int x, y;
    byte type;
    byte amount[5];
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
      rollingDice[i].amount[k] = 2;
    }
  }
  slideLeft = true;
  sliding = false;
  currentDice = 2;
  slideCounter = 0;
  gameState = STATE_GAME_PLAYING;
}


void stateDiceType()
{
  for (byte i = 0; i < 5; i++)
  {
    sprites.drawSelfMasked(rollingDice[i].x, rollingDice[i].y, allDice, rollingDice[i].type);
  }
  if (buttons.justPressed(RIGHT_BUTTON) && !sliding)
  {
    sliding = true;
    slideLeft = true;
  }
  if (buttons.justPressed(LEFT_BUTTON) && !sliding)
  {
    sliding = true;
    slideLeft = false;
  }
  if (buttons.justPressed(RIGHT_BUTTON) && sliding)
  {
    slideCounter = 43 - slideCounter;
    slideLeft = true;
  }
  if (buttons.justPressed(LEFT_BUTTON) && sliding)
  {
    slideCounter = 43 - slideCounter;
    slideLeft = false;
  }

  if (slideLeft && sliding && (slideCounter < 44))
  {
    slideCounter++;
    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].x -=2;
    }
  }

  if (!slideLeft && sliding && (slideCounter < 44))
  {
    slideCounter++;
    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].x +=2;
    }
  }
  /*
  if (slideCounter > 43)
  {
    slideCounter = 0;
    sliding = false;
    slideLeft = false;
  }
  */
}

void stateDiceAmount()
{

}

void stateDiceShake()
{

}

void stateDiceResult()
{

}


#endif
