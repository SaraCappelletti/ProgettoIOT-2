#ifndef __BUTTON__
#define __BUTTON__ 

#include "Arduino.h"
#include "Component.h"

class Button : public Component {
  
  public:
    Button(const int pin); 
    bool pressed();
};

#endif
