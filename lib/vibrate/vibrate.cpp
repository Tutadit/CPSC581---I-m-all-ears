#include "vibrate.h"

void pulsate(int which)
{
    if (which != VIBRATOR_DOWN && which != VIBRATOR_UP && which != VIBRATOR_MIDDLE)
        return;

    tone(which, VIBRATE_FREQUENCY);
    delay(VIBRATE_LENGTH);
    noTone(which);
    pinMode(which, INPUT);
}

void vibrate(char *direction)
{
    if (strcmp(direction, "up") == 0)
        pulsate(VIBRATOR_UP);
    else if (strcmp(direction, "down") == 0)
        pulsate(VIBRATOR_DOWN);
    else if (strcmp(direction, "middle") == 0)
        pulsate(VIBRATOR_MIDDLE);
}