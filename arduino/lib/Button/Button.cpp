#include "Button.h"

Button::Button(const int pin) : Component(pin) {
    pinMode(pin, INPUT);
}

bool Button::isPressed() {
  if (millis() - time > TBUTTON) {
    int buttonState = digitalRead(pin);
    if (buttonState == LOW) {
        return pressed;
    }
    if (!pressed) {
        pressed = true;
    } else {
        pressed = false;
    }
    time = millis();
  }
  return pressed;
}
