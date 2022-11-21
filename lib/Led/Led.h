#ifndef __LED__
#define __LED__

#include "Arduino.h"
#include "Component.h"

class Led : protected Component {
  long unsigned lastTime = 0.0;
  enum {ON, OFF} state = OFF;
  
  public:
    Led(const int pin); 
    void turnOn();
    void turnOff();
    void blinking(const long unsigned timeOn, const long unsigned timeOff);
};

#endif
