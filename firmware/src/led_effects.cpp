#include <Arduino.h>
#include <FastLED.h>

#include "led_effects.h"
#include "config.h"
#include "pins.h"

CRGB leds[NUM_LEDS];

uint8_t rainbowHue = 0;
uint8_t waveOffset = 0;

void initializeLEDs()
{
    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);

    FastLED.setBrightness(BRIGHTNESS);

    FastLED.clear();

    FastLED.show();
}

void clearLEDs()
{
    fill_solid(leds, NUM_LEDS, CRGB::Black);

    FastLED.show();
}

void turnRed()
{
    fill_solid(leds, NUM_LEDS, CRGB::Red);

    FastLED.show();
}

void turnGreen()
{
    fill_solid(leds, NUM_LEDS, CRGB::Green);

    FastLED.show();
}

void turnBlue()
{
    fill_solid(leds, NUM_LEDS, CRGB::Blue);

    FastLED.show();
}

void turnWhite()
{
    fill_solid(leds, NUM_LEDS, CRGB::White);

    FastLED.show();
}

void rainbow()
{
    fill_rainbow(leds, NUM_LEDS, rainbowHue, 7);

    FastLED.show();

    rainbowHue++;
}

void sparkle()
{
    fadeToBlackBy(leds, NUM_LEDS, 20);

    int pixel = random(NUM_LEDS);

    leds[pixel] = CRGB::White;

    FastLED.show();
}

void wave()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CHSV(sin8(i * 5 + waveOffset), 255, 255);
    }

    FastLED.show();

    waveOffset += 4;
}

void fire()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CHSV(random8(0, 40), 255, random8(160, 255));
    }

    FastLED.show();
}

void galaxy()
{
    fadeToBlackBy(leds, NUM_LEDS, 10);

    leds[random(NUM_LEDS)] = CRGB::White;

    leds[random(NUM_LEDS)] = CRGB::Blue;

    FastLED.show();
}

void meteor()
{
    static int position = 0;

    fadeToBlackBy(leds, NUM_LEDS, 35);

    leds[position] = CRGB::White;

    FastLED.show();

    position++;

    if(position >= NUM_LEDS)
    {
        position = 0;
    }
}

void explosion()
{
    fill_solid(leds, NUM_LEDS, CRGB::White);

    FastLED.show();

    delay(60);

    fadeToBlackBy(leds, NUM_LEDS, 255);

    FastLED.show();
}