#include "animations.h"
#include "cube_state.h"

#include "led_effects.h"
#include "wifi_canvas.h"

unsigned long previousDemoTime = 0;

void nextMode()
{
    cubeState.currentMode++;

    if (cubeState.currentMode > 7)
    {
        cubeState.currentMode = 0;
    }
}

int getCurrentMode()
{
    return cubeState.currentMode;
}

void runAnimation()
{
    switch (cubeState.currentMode)
    {

        // ============================
        // Mode 0 - Rainbow
        // ============================
        case 0:
        {
            rainbow();
            break;
        }

        // ============================
        // Mode 1 - Fire
        // ============================
        case 1:
        {
            fire();
            break;
        }

        // ============================
        // Mode 2 - Wave
        // ============================
        case 2:
        {
            wave();
            break;
        }

        // ============================
        // Mode 3 - Sparkle
        // ============================
        case 3:
        {
            sparkle();
            break;
        }

        // ============================
        // Mode 4 - Music Reactive
        // ============================
        case 4:
        {
            if (cubeState.clapDetected)
            {
                explosion();
            }
            else if (cubeState.beatDetected)
            {
                turnRed();
            }
            else
            {
                rainbow();
            }

            break;
        }

        // ============================
        // Mode 5 - Motion Reactive
        // ============================
        case 5:
        {
            if (cubeState.shakeDetected)
            {
                explosion();
            }
            else if (cubeState.tiltLeft)
            {
                turnBlue();
            }
            else if (cubeState.tiltRight)
            {
                turnGreen();
            }
            else if (cubeState.flipDetected)
            {
                turnWhite();
            }
            else
            {
                galaxy();
            }

            break;
        }

        // ============================
        // Mode 6 - Demo Mode
        // ============================
        case 6:
        {
            static int demoMode = 0;

            if (millis() - previousDemoTime > 5000)
            {
                previousDemoTime = millis();

                demoMode++;

                if (demoMode > 5)
                {
                    demoMode = 0;
                }
            }

            switch (demoMode)
            {
                case 0:
                    rainbow();
                    break;

                case 1:
                    fire();
                    break;

                case 2:
                    wave();
                    break;

                case 3:
                    sparkle();
                    break;

                case 4:
                    galaxy();
                    break;

                case 5:
                    meteor();
                    break;
            }

            break;
        }

        // ============================
        // Mode 7 - Live Canvas (WiFi)
        // ============================
        case 7:
        {
            runWiFiCanvas();
            break;
        }

        // ============================
        // Default
        // ============================
        default:
        {
            rainbow();
            break;
        }
    }
}