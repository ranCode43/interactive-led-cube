#ifndef UTILITIES_H
#define UTILITIES_H

#include <FastLED.h>

int clamp(int value,int minimum,int maximum);

int mapVolume(int volume);

CRGB randomColor();

uint32_t randomDelay();

#endif