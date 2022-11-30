#include "Button.h"

Button::Button(const int pin) : Component(pin) {
    pinMode(pin, INPUT);
}

bool Button::isPressed() {
  //per evitare il bouncing controllo di non aver appena premuto il bottone
  if (millis() - time > TBUTTON) {
    int buttonState = digitalRead(pin);
    if (buttonState == LOW) {
        //lo stato del bottone non cambia
        return pressed;
    }
    //se schiaccio è per togliere o mettere il controllo manuale
    //col controllo manuale attivo il bottone ha premuto a true
    if (!pressed) {
        pressed = true;
    } else {
        pressed = false;
    }
    time = millis();
  }
  return pressed;
}
