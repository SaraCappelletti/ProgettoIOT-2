#ifndef __BUTTON__
#define __BUTTON__ 

#include "Arduino.h"
#include "Component.h"
#include "Const.h"

class Button : public Component {
  bool pressed = false;
  unsigned long time = 0;
  

  public:
    Button(const int pin); 
    bool isPressed();
};

#endif
