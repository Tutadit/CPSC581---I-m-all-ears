#ifndef LCD_ALL_EARS
#define LCD_ALL_EARS

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x3F
#define LCD_LINES 2
#define LCD_CHARS 16

#define MESSAGE_SCROLL_TIME 250  // ms
#define MESSAGE_DISPLAY_TIME 1600 // ms
#define SCROLL_LAPS 2

void scrollMessage(char *message, unsigned int length);
void printMessage(char *message);
void setup_lcd();

#endif