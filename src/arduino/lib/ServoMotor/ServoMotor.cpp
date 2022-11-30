#include "ServoMotor.h"

ServoMotor::ServoMotor(const int pin) : Component(pin) {
    motor.attach(pin);
}

void ServoMotor::move(int angle) {
  //muovo il motore e mi salvo l'ultimo valore dell'angolo
  motor.write(MIN_PULSE_WIDTH + angle*coeff);
  this->angle = angle;
}

int ServoMotor::getAngle() {
  return angle;
}
