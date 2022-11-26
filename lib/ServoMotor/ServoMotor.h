#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

#include "Arduino.h"
#include "Sensor.h"
#include "Const.h"
#include "ServoTimer2.h"

class ServoMotor : public Component, ServoTimer2 {
  //int prev = 0;

  public:
    ServoMotor(const int pin); 
    void move(float waterLevel);
};

#endif
