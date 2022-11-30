#include "Led.h"

Led::Led(const int pin) : Component(pin), state(OFF) {
  pinMode(pin, OUTPUT);
}

void Led::turnOn() {
  //se non era già acceso lo accendo
  if (this->state != Led::ON) {
    this->state = Led::ON;
    digitalWrite(pin, HIGH);
  }
}

void Led::turnOff() {
  //se non era già spento lo spengo
  if (this->state != Led::OFF) {
    this->state = Led::OFF;
    digitalWrite(pin, LOW);
  }
}

void Led::blinking(const unsigned long timeOn, const unsigned long timeOff) {

  unsigned long tempTime = millis();

  if (this->state == ON) {
    //controllo che sia passato abbastanza tempo dall'ultimo cambio di stato
    if (tempTime - this->lastTime >= timeOn) {
      this->turnOff();
      this->lastTime = tempTime;
    }  
  } else {
    if (tempTime - this->lastTime >= timeOff) {
    this->turnOn();
    this->lastTime = tempTime;
    }
  }
}

bool Led::isOn() {
  return Led::state == ON;
}
