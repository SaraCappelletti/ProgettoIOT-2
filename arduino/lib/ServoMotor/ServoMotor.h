#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

#include "Arduino.h"
#include "Sensor.h"
#include "Const.h"
#include "ServoTimer2.h"

class ServoMotor : public Component {
  //int prev = 0;
  ServoTimer2 motor; 

  public:
    ServoMotor(const int pin); 
    void move(float waterLevel);
};

#endif
