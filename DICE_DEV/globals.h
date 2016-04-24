#ifndef GLOBALS_H
#define GLOBALS_H

#include "Arglib.h"
#include "bitmaps.h"

//define menu states (on main menu)
#define STATE_MENU_INTRO             0
#define STATE_MENU_MAIN              1
#define STATE_MENU_HELP              2
#define STATE_MENU_PLAY              3
#define STATE_MENU_INFO              4
#define STATE_MENU_SOUNDFX           5

//define game states (on main menu)
#define STATE_DICE_TYPE_AND_AMOUNT   6
#define STATE_DICE_ROLLING           7
#define STATE_DICE_RESULT            8

#define BUTTON_A                     1
#define BUTTON_B                     0
#define BUTTON_UP                    2
#define BUTTON_DOWN                  3

Arduboy arduboy;
Sprites sprites(arduboy);
SimpleButtons buttons (arduboy);

unsigned char gameState;
boolean soundYesNo;
int menuSelection;
byte counter = 0;
byte pressedButtonCounter = 0;
boolean buttonPressed[] = {false, false, false, false};

#endif
