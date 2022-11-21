#ifndef __SONAR__
#define __SONAR__

#include "Arduino.h"
#include "Sensor.h"

class Sonar : Sensor {
  const float vs = 331.45 + 0.62*20;
  const int echoPin;

  public:
    Sonar(const int pin); 
    float read();
};

#endif