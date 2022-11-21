#ifndef __PIR__
#define __PIR__

#include "Arduino.h"
#include "Sensor.h"

#define CALIBRATION_TIME 100000 // milliseconds

class Pir : protected Sensor {
  long unsigned time = 0.0;
  bool calibrated = false;
  
  public:
    Pir(const int pin); 
    bool read();
};

#endif
