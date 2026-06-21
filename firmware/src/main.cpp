#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Interactive LED Cube starting...");

   /* TODO
    INTILIZE W2812b LED Matrices
     INTILIZE MAX4466 microphone
     Intilize MMPU6050 sensor
     INitlaize push button*/
}

void loop() {
  Serial.println("Looping...");
  delay(1000);
}