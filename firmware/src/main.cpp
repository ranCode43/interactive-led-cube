#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Interactive LED Cube starting...");
}

void loop() {
  Serial.println("Looping...");
  delay(1000);
}