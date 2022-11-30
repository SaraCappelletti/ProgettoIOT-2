#include "LaTask.h"

LaTask::LaTask(Led* led, Photoresistor* photoresistor, Pir* pir) : led(led), photoresistor(photoresistor), pir(pir) {}

void LaTask::init(const unsigned long period) {
  Task::init(period);
}

void LaTask::tick() {
  switch (Scheduler::getState()) {
    case State::NORMAL:
    case State::PREALARM: {
      if (photoresistor->read() > THL) {
        //controllo se c'è troppa luce
        led->turnOff();
      } else if (pir->read()) {
        //controllo se c'è movimento
        led->turnOn();
        time = millis();
      } else if (millis() - time > T1) {
        //controllo se è passato il tempo T1
        led->turnOff();
      }
      break;
    }
    case State::ALARM: {
      led->turnOff();
      break;
    }
  }
}
