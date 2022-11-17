#include "Led.h"

Led::Led(const int pin) : pin(pin) {};

Led::turnOn() {
    if (this->state != Led::ON) {
        this->state = Led::ON;
        digitalWrite(pin, HIGH);
    }
}

Led::turnOff(){
    if (this->state != Led::OFF) {
        this->state = Led::OFF;
        digitalWrite(pin, LOW);
    }
}

Led::blinking(const unsigned long timeOn, const unsigned long timeOff) {

    unsigned long tempTime = millis();

    if (this->state == ON) {
        if (tempTime - this->lastTime >= timeOn)    this->turnOff();
    } else {
        if (tempTime - this->lastTime >= timeOff)   this->turnOn();
    }

    this->lastTime = tempTime;
}