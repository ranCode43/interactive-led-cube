#ifndef WIFI_CANVAS_H
#define WIFI_CANVAS_H

// Starts the WiFi Access Point + web server for Live Canvas mode.
// Call once from setup().
void initWiFiCanvas();

// Must be called every loop iteration while in Live Canvas mode.
// Handles incoming web requests and pushes the canvas buffer to the LEDs.
void runWiFiCanvas();

// Clears the canvas buffer (all pixels off).
void clearCanvas();

#endif
