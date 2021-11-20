#ifndef VIBRATE_ALL_EARS
#define VIBRATE_ALL_EARS

#include <Arduino.h>

#define VIBRATE_FREQUENCY 31 // Hz
#define VIBRATE_LENGTH 500   // ms

#define VIBRATOR_UP 13
#define VIBRATOR_MIDDLE 12
#define VIBRATOR_DOWN 14

void vibrate(char *direction);

#endif