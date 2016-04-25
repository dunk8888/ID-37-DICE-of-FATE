#ifndef GAME_H
#define GAME_H

#include "globals.h"

byte currentDice;
byte amountOfDice;
byte frameDice;
int slideCounter;
boolean slideLeft;
boolean slidingDice;
boolean goBack;
boolean showDiceName;
boolean showResult;
byte diceMax[] = {5, 7, 9, 13, 21};
byte bandPositionX[] = {0, 8, 16, 24, 32, 56, 54, 56};
byte frameBand = 0;
byte diceResult;



struct Dice
{
  public:
    int x, y;
    byte type;
    byte result;
};

Dice rollingDice[5];

void placeDice()
{
  for (byte i = 0; i < 5; i++)
  {
    rollingDice[i].type = i;
    rollingDice[i].x = 8 + (38 * (-(currentDice - 2) + i));
    rollingDice[i].y = 7;
    for (byte k = 0; k < 5; k++)
    {
      rollingDice[i].result = 0;
    }
  }
  rollingDice[currentDice - 1].y = 1;
  frameDice = 0;
}

void drawNumbers(byte numbersX, byte numbersY, int number)
{
  char buf[10];
  //number = arduboy.cpuLoad();
  itoa(number, buf, 10);
  char charLen = strlen(buf);

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
    sprites.drawSelfMasked(numbersX - (4 + (5 * (charLen - 1))) + (10 * i), numbersY, allNumbers, digit);
  }
}

void drawBorders()
{
  for (byte i = 0; i < 128; i++)
  {
    sprites.drawPlusMask(i, 24, resultBorders_plus_mask, 0);
  }
  for (byte i = 56; i < 128 - 56; i++)
  {
    sprites.drawPlusMask(i, 24, resultBorders_plus_mask, 1);
  }
}

void drawBands()
{
  sprites.drawSelfMasked(130 - bandPositionX[frameBand], 28, resultBands, 0);
  sprites.drawSelfMasked(bandPositionX[frameBand] - 56, 28, resultBands, 1);

}

void drawResult()
{
  drawNumbers(64, 31, diceResult);
}



void stateMenuPlay()
{
  currentDice = 3;
  placeDice();
  slideLeft = true;
  slidingDice = false;
  goBack = false;
  showDiceName = true;
  slideCounter = 0;
  amountOfDice = 2;
  gameState = STATE_DICE_TYPE_AND_AMOUNT;
}


void stateDiceTypeAndAmount()
{
  for (byte i = 0; i < 5; i++)
  {
    sprites.drawSelfMasked(rollingDice[i].x , rollingDice[i].y, allDice, 3 * rollingDice[i].type + frameDice);
  }
  if (buttons.justPressed(RIGHT_BUTTON) && !slidingDice && (currentDice < 5))
  {
    slidingDice = true;
    slideLeft = true;
    currentDice++;
    for (byte i = 0; i < 5; i++) rollingDice[i].y = 7;
    showDiceName = false;
  }
  if (buttons.justPressed(LEFT_BUTTON) && !slidingDice && (currentDice > 1))
  {
    slidingDice = true;
    slideLeft = false;
    currentDice--;
    for (byte i = 0; i < 5; i++) rollingDice[i].y = 7;
    showDiceName = false;
  }
  if (buttons.justPressed(UP_BUTTON) && amountOfDice < 5)
  {
    buttonPressed[BUTTON_UP] = true;
    amountOfDice++;
  }
  if (buttons.justPressed(DOWN_BUTTON) && amountOfDice > 1)
  {
    buttonPressed[BUTTON_DOWN] = true;
    amountOfDice--;
  }

  if (buttons.justPressed(B_BUTTON))
  {
    buttonPressed[BUTTON_B] = true;
    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].type = currentDice - 1;
      rollingDice[i].x = 44;
      rollingDice[i].y = 12;
    }
    gameState = STATE_DICE_ROLLING;
  }

  if (buttons.justPressed(A_BUTTON))
  {
    buttonPressed[BUTTON_A] = true;
    gameState = STATE_MENU_MAIN;
  }

  if (slideLeft && slidingDice && (slideCounter < 37))
  {
    slideCounter += 2;
    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].x -= 2;
    }
  }

  if (!slideLeft && slidingDice && (slideCounter < 37))
  {
    slideCounter += 2;
    for (byte i = 0; i < 5; i++)
    {
      rollingDice[i].x += 2;
    }
  }
  if (slideCounter == 34)rollingDice[currentDice - 1].y = 6;
  if (slideCounter == 36)rollingDice[currentDice - 1].y = 4;
  if (slideCounter > 37)
  {
    slideCounter = 0;
    slidingDice = false;
    rollingDice[currentDice - 1].y = 1;
    showDiceName = true;
  }
  sprites.drawSelfMasked(52, 48, numberFrame, 0);
  drawNumbers(60, 50, amountOfDice);
  sprites.drawSelfMasked(1, 53, allButtons, 2 * BUTTON_A + buttonPressed[BUTTON_A]);
  sprites.drawSelfMasked(97, 53, allButtons, 2 * BUTTON_B + buttonPressed[BUTTON_B]);
  sprites.drawSelfMasked(66, 48, allButtons, 2 * BUTTON_UP + buttonPressed[BUTTON_UP]);
  sprites.drawSelfMasked(66, 55, allButtons, 2 * BUTTON_DOWN + buttonPressed[BUTTON_DOWN]);
  sprites.drawSelfMasked(12, 56, allWords, 0);
  sprites.drawSelfMasked(108, 56, allWords, 1);
  if (showDiceName)sprites.drawSelfMasked(57, 40, diceName, currentDice - 1);
}

void stateDiceRolling()
{
  diceResult = 0;
  for (byte i = 0; i < 5; i++)
  {
    rollingDice[i].result = random (1, diceMax[currentDice - 1]);
  }
  if (arduboy.everyXFrames(8)) frameDice++;
  if (frameDice > 2) frameDice = 0;
  if (buttons.justPressed(A_BUTTON))
  {
    buttonPressed[BUTTON_A] = true;
    gameState = STATE_DICE_TYPE_AND_AMOUNT;
    placeDice();
  }
  if (buttons.justPressed(B_BUTTON))
  {
    buttonPressed[BUTTON_B] = true;
    frameBand = 0;
    showResult = false;
    for (byte i = 0; i < amountOfDice; i++)
    {
      diceResult = diceResult + rollingDice[i].result;
    }
    gameState = STATE_DICE_RESULT;
  }
  sprites.drawSelfMasked(rollingDice[0].x, rollingDice[0].y, allDice, 3 * rollingDice[0].type + frameDice);
  sprites.drawSelfMasked(1, 53, allButtons, 2 * BUTTON_A + buttonPressed[BUTTON_A]);
  sprites.drawSelfMasked(97, 53, allButtons, 2 * BUTTON_B + buttonPressed[BUTTON_B]);
  sprites.drawSelfMasked(12, 56, allWords, 0);
  sprites.drawSelfMasked(108, 56, allWords, 2);
}

void stateDiceResult()
{
  if (buttons.justPressed(A_BUTTON))
  {
    buttonPressed[BUTTON_A] = true;
    gameState = STATE_DICE_TYPE_AND_AMOUNT;
    placeDice();
  }
  if (buttons.justPressed(B_BUTTON))
  {
    buttonPressed[BUTTON_B] = true;
    gameState = STATE_DICE_ROLLING;
  }

  drawBorders();
  drawBands();
  if (showResult) drawResult();

  if (arduboy.everyXFrames(2)) frameBand++;
  if (frameBand > 7)
  {
    frameBand = 7;
    showResult = true;
  }
  if (amountOfDice > 1)
  {
    for (byte i = 0; i < amountOfDice; i++)
    {
      drawNumbers(77 - (13 * amountOfDice) + (26 * i), 8, rollingDice[i].result);
    }
    for (byte i = 0; i < (amountOfDice - 1); i++)
    {
      sprites.drawSelfMasked(88 - (13 * amountOfDice) + (26 * i), 12, justADot, 0);
    }
  }
  sprites.drawSelfMasked(1, 53, allButtons, 2 * BUTTON_A + buttonPressed[BUTTON_A]);
  sprites.drawSelfMasked(97, 53, allButtons, 2 * BUTTON_B + buttonPressed[BUTTON_B]);
  sprites.drawSelfMasked(12, 56, allWords, 0);
  sprites.drawSelfMasked(108, 56, allWords, 1);
}



#endif
