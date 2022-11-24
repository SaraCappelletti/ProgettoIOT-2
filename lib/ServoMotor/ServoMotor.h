#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

#include "Arduino.h"
#include "Sensor.h"
#include "Const.h"
#include "Servo.h"

class ServoMotor : public Component, Servo {
  //int prev = 0;

  public:
    ServoMotor(const int pin); 
    void move(int waterLevel);
};

#endif
