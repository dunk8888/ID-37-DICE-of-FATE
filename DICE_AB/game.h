#ifndef GAME_H
#define GAME_H

#include "inputs.h"
#include "dice.h"
#include "numbers.h"

byte currentDice;
byte amountOfDice;
byte frameDice;
int slideCounter;
boolean slideLeft;
boolean slidingDice;
boolean goBack;

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

PROGMEM const unsigned char rollButton[] = {
// width, height
35, 16,
0xFF, 0x01, 0x7D, 0x15, 0x15, 0x7D, 0x01, 0xFF, 0x00, 0x00, 0x44, 0x00, 0x00, 0xFE, 0x82, 0xDA, 0xDA, 0xA2, 0xFE, 0x82, 0xBA, 0xBA, 0x82, 0xFE, 0x82, 0xBE, 0xA0, 0xA0, 0xFE, 0x82, 0xBE, 0xA0, 0xA0, 0xE0, 0x00, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


PROGMEM const unsigned char backButton[] = {
// width, height
35, 16,
0xFF, 0x01, 0x7D, 0x55, 0x55, 0x6D, 0x01, 0xFF, 0x00, 0x00, 0x44, 0x00, 0x00, 0xFE, 0x82, 0xBA, 0xAA, 0x92, 0xFE, 0x82, 0xDA, 0xDA, 0x82, 0xFE, 0x82, 0xBA, 0xBA, 0xBE, 0xFE, 0x82, 0xEE, 0xEE, 0x92, 0xFE, 0x00, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

PROGMEM const unsigned char arrows[] = {
// width, height
8, 8,
// frame 0
0x18, 0x3C, 0x7E, 0xFF, 0x00, 0x00, 0x00, 0x00, 

// frame 1
0x08, 0x0C, 0x0E, 0x0F, 0x0F, 0x0E, 0x0C, 0x08, 

// frame 2
0xFF, 0x7E, 0x3C, 0x18, 0x00, 0x00, 0x00, 0x00, 

// frame 3
0x01, 0x03, 0x07, 0x0F, 0x0F, 0x07, 0x03, 0x01, 
};

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
  gameState = STATE_DICE_TYPE;
}


void stateDiceType()
{
  for (byte i = 0; i < 5; i++)
  {
    sprites.drawSelfMasked(rollingDice[i].x - 40 , rollingDice[i].y, allDice, 4 * rollingDice[i].type + frameDice);
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

    gameState = STATE_DICE_AMOUNT;
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
  if (currentDice > 1)sprites.drawSelfMasked(52 , 49, arrows, 0);
  if (amountOfDice < 5)sprites.drawSelfMasked(60 , 42, arrows, 1);
  if (currentDice < 5)sprites.drawSelfMasked(72 , 49, arrows, 2);
  if (amountOfDice > 1)sprites.drawSelfMasked(60 , 60, arrows, 3);

  drawNumbers(50, 47, amountOfDice);
  
  sprites.drawSelfMasked(0, 49, backButton, 0);
  sprites.drawSelfMasked(93, 49, rollButton, 0);
}

void stateDiceAmount()
{

  sprites.drawSelfMasked(rollingDice[0].x , rollingDice[0].y, allDice, 4 * rollingDice[0].type + frameDice);
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
  sprites.drawSelfMasked(0, -2, allDice, 4 * rollingDice[0].type + frameDice);
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
