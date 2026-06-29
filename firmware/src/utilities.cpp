#include <Arduino.h>

#include "utilities.h"

int clamp(int value, int minimum, int maximum)
{
    if(value < minimum)
        return minimum;

    if(value > maximum)
        return maximum;

    return value;
}

int mapVolume(int volume)
{
    return map(volume,0,4095,0,255);
}

CRGB randomColor()
{
    return CHSV(random8(),255,255);
}

uint32_t randomDelay()
{
    return random(20,120);
}