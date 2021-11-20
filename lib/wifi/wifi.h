#ifndef WIFI_ALL_EARS
#define WIFI_ALL_EARS

#include <ESP8266WiFi.h>

#define SSID "TELUS5828-2.4G"
#define PASSPHRASE "s5t3vkv5nq"

#define WIFI_CONNECTION_RETRY 500 // ms
#define WIFI_INITIAL_DELAY 10     // ms

extern WiFiClient espClient;

void setup_wifi();

#endif