#include "Potentiometer.h"

Potentiometer::Potentiometer(const int pin) : Component(pin) {}

int Potentiometer::read() {
  return map(analogRead(pin), 0, 1024, 0 , 180);
}
