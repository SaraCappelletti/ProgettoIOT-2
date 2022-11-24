#include "LaTask.h"

LaTask::LaTask(Led* led, Photoresistor* photoresistor, Pir* pir) : led(led), photoresistor(photoresistor), pir(pir) {}

void LaTask::init(const unsigned long period) {
  Task::init(period);
}

void LaTask::tick() {
  switch (Scheduler::getState()) {
    case State::NORMAL:
    case State::PREALARM: {
      Serial.println(pir->read());
      if(photoresistor->read() > THL){
        led->turnOff();
        return;
      }
      else if(pir->read()) {
        Serial.println("LedA");
        led->turnOn();
        time = millis();
        return;
        }
      else if(millis() - time > T1){
        led->turnOff();
        return;
      }
      break;
    }
    case State::ALARM: {
      led->turnOff();
      break;
    }
  }
}
