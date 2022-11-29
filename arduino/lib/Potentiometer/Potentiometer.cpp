#include "Potentiometer.h"

Potentiometer::Potentiometer(const int pin) : Component(pin) {}

int Potentiometer::read() {
  int value = map(analogRead(pin), 0, 1024, 0 , 180);
  if (abs(prev - value) > POT_SENSIBILITY) {
    prev = value;
    return value;
  }
  return prev;
}
