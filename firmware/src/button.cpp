#include <Arduino.h>

#include "button.h"
#include "pins.h"

bool lastButtonState = HIGH;

void initializeButton()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

bool buttonPressed()
{
    bool currentState = digitalRead(BUTTON_PIN);

    if(lastButtonState == HIGH && currentState == LOW)
    {
        lastButtonState = currentState;
        return true;
    }

    lastButtonState = currentState;

    return false;
}

bool buttonHeld()
{
    return digitalRead(BUTTON_PIN) == LOW;
}

void resetButton()
{
    lastButtonState = HIGH;
}