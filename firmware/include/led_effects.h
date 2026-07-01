#ifndef LED_EFFECTS_H
#define LED_EFFECTS_H

#include <FastLED.h>
#include "config.h"

// Shared LED buffer, defined in led_effects.cpp.
// Exposed so other modules (like wifi_canvas) can write directly to it.
extern CRGB leds[NUM_LEDS];

void initializeLEDs();

void clearLEDs();

void turnRed();

void turnGreen();

void turnBlue();

void turnWhite();

void rainbow();

void sparkle();

void wave();

void fire();

void galaxy();

void meteor();

void explosion();

#endif