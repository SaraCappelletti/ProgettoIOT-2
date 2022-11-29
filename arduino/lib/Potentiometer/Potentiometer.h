#ifndef __POTENTIOMETER__
#define __POTENTIOMETER__ 

#include "Arduino.h"
#include "Component.h"

class Potentiometer : public Component {
  
  public:
    Potentiometer(const int pin); 
    int read();
};

#endif
