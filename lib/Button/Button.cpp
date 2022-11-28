#include "Button.h"

Button::Button(const int pin) : Component(pin) {}

bool Button::pressed(){
    return false;
}
