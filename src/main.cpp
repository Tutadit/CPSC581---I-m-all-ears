#include <Arduino.h>

#include <wifi.h>
#include <mqtt.h>
#include <lcd.h>
#include <vibrate.h>

void setup()
{
  setup_lcd();  
  setup_wifi();
  setup_mqtt(vibrate, printMessage);
}

void loop()
{
  mqtt_loop();
}
