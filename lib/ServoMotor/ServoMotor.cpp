#include "ServoMotor.h"

ServoMotor::ServoMotor(const int pin) : Component(pin) {}

void ServoMotor::move(float waterLevel){
  int angle = map(waterLevel, WLMAX, WL1, 0, 180);
  this->attach(pin);
  float coeff = (2250.0-750.0)/180;
  this->write(750 + angle*coeff);
  //prev = angle;
  this->detach();

}
