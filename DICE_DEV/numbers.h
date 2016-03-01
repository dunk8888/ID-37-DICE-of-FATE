#ifndef MENU_BITMAPS_H
#define MENU_BITMAPS_H

extern Arduboy arduboy;
Sprites sprites(arduboy);

PROGMEM const unsigned char numbers[] = {
// width, height
8, 16,
// number 0
0xE0, 0xFC, 0x3E, 0x0F, 0x07, 0x0F, 0xFF, 0xFE, 
0x3F, 0x7F, 0xF8, 0xF0, 0xF0, 0xF8, 0x7F, 0x1F, 
// number 1
0x00, 0x00, 0x1C, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 
0x00, 0x00, 0xE0, 0xFF, 0xFF, 0x7F, 0x60, 0x00, 
// number 2
0x00, 0x1C, 0x1E, 0x07, 0x83, 0xC7, 0xFF, 0x7E, 
0xF0, 0xFC, 0xEE, 0xE7, 0xE3, 0x61, 0x70, 0x70, 
// number 3
0x00, 0x0E, 0x0F, 0x87, 0xC3, 0xE7, 0xBF, 0x1E, 
0x70, 0xF8, 0xF8, 0xF0, 0xE0, 0xF1, 0x7F, 0x3F, 
// number 4
0xC0, 0xF0, 0xFC, 0x8F, 0x83, 0xFF, 0xFE, 0xC0, 
0x03, 0x03, 0x03, 0x03, 0xFF, 0xFF, 0x7F, 0x00, 
// number 5
0x00, 0xFE, 0xFE, 0xC7, 0xC7, 0xC7, 0xC7, 0x83, 
0x78, 0xF8, 0xF0, 0xE0, 0xE0, 0xF1, 0x7F, 0x3F, 
// number 6
0xE0, 0xF8, 0xBC, 0xCE, 0xC7, 0xC3, 0x80, 0x00, 
0x3F, 0x7F, 0xF1, 0xE0, 0xE0, 0xF1, 0x7F, 0x3F, 
// number 7
0x0E, 0x0F, 0x0F, 0x07, 0xC7, 0xF3, 0x7F, 0x0F, 
0x00, 0x00, 0xF0, 0xFE, 0x1F, 0x03, 0x00, 0x00, 
// number 8
0x00, 0x7C, 0xFE, 0xE7, 0xC3, 0xE7, 0x7F, 0x3E, 
0x3E, 0x7F, 0xF3, 0xE1, 0xE1, 0xF3, 0x7F, 0x3E, 
// number 9
0xFC, 0xFE, 0x8F, 0x07, 0x07, 0x8F, 0xFE, 0xFC, 
0x00, 0x01, 0xC3, 0xE3, 0x73, 0x3D, 0x1F, 0x07, 
};


void drawNumbers(byte numbersX, byte numbersY, int number)
{
  char buf[10];
  //number = arduboy.cpuLoad();
  //number = 16;
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
    sprites.drawSelfMasked(numbersX + (pad * 5) + (10 * i), numbersY, numbers, digit);
  }
}

#endif
