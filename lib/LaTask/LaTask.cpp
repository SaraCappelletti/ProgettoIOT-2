#include "LaTask.h"
#include <stdio.h>

LaTask::LaTask(const Led& led, const Photoresistor& photoresistor, const Pir& pir) : led(led), photoresistor(photoresistor), pir(pir) {}

void LaTask::init(const unsigned long period) {
  Task::init(period);
}

void LaTask::tick() {
  switch (Scheduler::getState()) {
    case State::ALARM: {
      break;
    }
    default: {
      if(1)
      /*if(photoresistor.read() > THL){
        led.turnOff();
        return;
      }
      else if(pir.read()) {
        led.turnOn();
        time = millis();
        return;
        }
      else if(millis() - time > T1){
        led.turnOff();
        return;
      }
      */
      break;
    }
  }
}
