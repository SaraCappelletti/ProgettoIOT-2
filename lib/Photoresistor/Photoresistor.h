#ifndef __PHOTORESISTOR__
#define __PHOTORESISTOR__   

#include "Arduino.h"
#include "Sensor.h"

class Photoresistor : public Sensor {
  
  public:
    Photoresistor(const int pin); 
    int read();
};

#endif
