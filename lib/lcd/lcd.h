#ifndef LCD_ALL_EARS
#define LCD_ALL_EARS

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x3F
#define LCD_LINES 2
#define LCD_CHARS 16

#define MESSAGE_SCROLL_TIME 340  // ms
#define MESSAGE_DISPLAY_TIME 2600 // ms
#define SCROLL_LAPS 2

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

void scrollMessage(char *message, unsigned int length);
void printMessage(char *message);
void setup_lcd();

#endif