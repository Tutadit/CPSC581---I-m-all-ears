#include "lcd.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_CHARS, LCD_LINES);

uint8_t earChar[8] = {
    0x0E,
    0x11,
    0x15,
    0x01,
    0x05,
    0x01,
    0x09,
    0x06};

uint8_t wave01[8] = {
    0x00,
    0x00,
    0x04,
    0x09,
    0x0A,
    0x09,
    0x04,
    0x00};

uint8_t wave02[8] = {
    0x00,
    0x01,
    0x02,
    0x02,
    0x02,
    0x02,
    0x02,
    0x01};

void scrollMessage(char *message, unsigned int length)
{
    for (int lap = 0; lap < SCROLL_LAPS; lap++)
    {
        lcd.setCursor(15, 0);
        for (unsigned int i = 0; i < length; i++)
        {
            lcd.scrollDisplayLeft();
            lcd.print(message[i]);
            delay(MESSAGE_SCROLL_TIME);
        }
    }
}

void printMessage(char *message)
{

    int message_length = strlen(message);
    lcd.backlight();
    lcd.clear();
    if (message_length > 16)
    {
        scrollMessage(message, message_length);
    }
    else
    {
        lcd.print(message);
    }
    delay(MESSAGE_DISPLAY_TIME);
    lcd.clear();
    lcd.noBacklight();
}

void setup_lcd()
{
    lcd.init();
    lcd.createChar(0, earChar);
    lcd.createChar(1, wave01);
    lcd.createChar(2, wave02);

    lcd.clear();
    lcd.backlight();
    lcd.printByte(2);
    lcd.printByte(1);
    lcd.printByte(0);
    lcd.print(" I'm all ears");
    lcd.setCursor(0,1);
    lcd.print(" CPSC 581 Prject");
    delay(MESSAGE_DISPLAY_TIME * 2);
    lcd.noBacklight();
    lcd.clear();
}