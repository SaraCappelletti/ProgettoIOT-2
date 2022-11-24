#include "ServoMotor.h"

ServoMotor::ServoMotor(const int pin) : Component(pin) {}

void ServoMotor::move(int waterLevel){
  int angle = map(waterLevel, WL1, WLMAX, 0, 180);
  this->attach(pin); 
  Serial.println("Move");
  this->write(angle);                     
  //prev = angle;
  this->detach();
}
