#include "Photoresistor.h"

Photoresistor::Photoresistor(const int pin) : Sensor(pin) {}

int Photoresistor::read() {
  int value = analogRead(pin);
  /*float voltage = value * (5.0 / 1023.0);
  int val = map(value, 0, 1023, 0, 255);
  analogWrite(11, val);*/
  return value;
}
