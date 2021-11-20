#include "lcd.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_CHARS, LCD_LINES);

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
}

void setup_lcd()
{
    lcd.init();      // initialize the led
    lcd.backlight(); // open the backlight
}