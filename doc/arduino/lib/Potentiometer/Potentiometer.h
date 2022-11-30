#ifndef __POTENTIOMETER__
#define __POTENTIOMETER__ 

#include "Arduino.h"
#include "Component.h"
#include "Const.h"

class Potentiometer : public Component {
  int prev = 0;

  public:
    Potentiometer(const int pin); 
    int read();
};

#endif
