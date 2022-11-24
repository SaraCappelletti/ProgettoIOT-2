#ifndef __PIR__
#define __PIR__

#include "Arduino.h"
#include "Sensor.h"
#include "Const.h"

class Pir : public Sensor {
  long unsigned time = 0.0;
  bool calibrated = false;
  
  public:
    Pir(const int pin); 
    bool read();
};

#endif
