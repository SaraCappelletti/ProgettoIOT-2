#include "LbTask.h"
#include "Led.h"

LbTask::LbTask(const Led& led) : led(led) {}

void LbTask::init(const unsigned long period) {
    LbTask::period = period;
}

void LbTask::tick() {
  switch (Scheduler::getState()) {
    case State::ALARM: {
      led.turnOff();
      break;
    }
    case State::NORMAL || State::PREALARM: {
      led.turnOn();
      break;
    }
  }
}
