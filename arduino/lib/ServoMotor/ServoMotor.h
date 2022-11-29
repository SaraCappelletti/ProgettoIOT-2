#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

#include "Arduino.h"
#include "Sensor.h"
#include "Const.h"
#include "ServoTimer2.h"

class ServoMotor : public Component {
  //int prev = 0;
  ServoTimer2 motor;
  float coeff = ((float)MAX_PULSE_WIDTH-(float)MIN_PULSE_WIDTH)/180;
  int angle = 0; 

  public:
    ServoMotor(const int pin); 
    void move(int angle);
    int getAngle();
};

#endif
