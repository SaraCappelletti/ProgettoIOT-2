#include "ServoMotor.h"

ServoMotor::ServoMotor(const int pin) : Component(pin) {
    motor.attach(pin);
}

void ServoMotor::move(float waterLevel){
  int angle = map(waterLevel*100, WLMAX*100, WL2*100, 180, 0);
  float coeff = ((float)MAX_PULSE_WIDTH-(float)MIN_PULSE_WIDTH)/180;
  motor.write(MIN_PULSE_WIDTH + angle*coeff);
}
