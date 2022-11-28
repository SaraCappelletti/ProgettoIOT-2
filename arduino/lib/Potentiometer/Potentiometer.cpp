#include "Potentiometer.h"

Potentiometer::Potentiometer(const int pin) : Component(pin) {}

float Potentiometer::read() {
  return (analogRead(pin) / 5.7);
}
