#include <Arduino.h>

#include "animations.h"
#include "button.h"
#include "cube_state.h"
#include "led_effects.h"
#include "microphone.h"
#include "motion.h"
#include "wifi_canvas.h"

unsigned long lastButtonPress = 0;

void setup()
{
    Serial.begin(115200);

    initializeLEDs();

    initializeMic();

    initializeMPU();

    initializeButton();

    initWiFiCanvas();

    cubeState.currentMode = 0;

    turnGreen();

    delay(1000);

    clearLEDs();
}

void loop()
{
    // ----------------------------
    // Read Button
    // ----------------------------

    cubeState.buttonPressed = buttonPressed();

    if (cubeState.buttonPressed)
    {
        if (millis() - lastButtonPress > 250)
        {
            nextMode();

            lastButtonPress = millis();
        }
    }

    // ----------------------------
    // Read Microphone
    // ----------------------------

    cubeState.microphoneVolume = getVolume();

    cubeState.beatDetected = detectBeat();

    cubeState.clapDetected = detectClap();

    // ----------------------------
    // Read MPU6050
    // ----------------------------

    cubeState.shakeDetected = detectShake();

    cubeState.tiltLeft = detectTiltLeft();

    cubeState.tiltRight = detectTiltRight();

    cubeState.flipDetected = detectFlip();

    // ----------------------------
    // Run Current Animation
    // ----------------------------

    runAnimation();

    delay(20);
}