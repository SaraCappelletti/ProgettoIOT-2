#include "Potentiometer.h"

Potentiometer::Potentiometer(const int pin) : Component(pin) {}

float Potentiometer::read() {
  Serial.println(analogRead(pin) / 5.7);
  return (analogRead(pin) / 5.7);
}
