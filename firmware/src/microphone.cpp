#include <Arduino.h>

#include "microphone.h"
#include "pins.h"
#include "config.h"

void initializeMic()
{
    pinMode(MIC_PIN, INPUT);
}

int getVolume()
{
    return analogRead(MIC_PIN);
}

bool detectBeat()
{
    int volume = getVolume();

    return volume > MIC_THRESHOLD;
}

bool detectClap()
{
    int volume = getVolume();

    return volume > (MIC_THRESHOLD + 300);
}

bool isQuiet()
{
    return getVolume() < (MIC_THRESHOLD - 100);
}