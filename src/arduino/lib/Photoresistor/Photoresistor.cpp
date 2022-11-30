#include "Photoresistor.h"

Photoresistor::Photoresistor(const int pin) : Sensor(pin) {}

int Photoresistor::read() {
  //il valore va da 0 a 1023
  int value = analogRead(pin);
  return value;
}
