#ifndef __PIR__
#define __PIR__

#include "Arduino.h"
#include "Component.h"

#define CALIBRATION_TIME 100000 // milliseconds

class Pir : Component {
  const int pin;
  long unsigned time = 0.0;
  bool calibrated = false;
  
  public:
    Pir(const int pin); 
    float read();
};

#endif