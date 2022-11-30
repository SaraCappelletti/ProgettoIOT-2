#include "LbTask.h"

LbTask::LbTask(Led* led) : led(led) {}

void LbTask::init(const unsigned long period) {
    Task::init(period);
}

void LbTask::tick() {
  switch (Scheduler::getState()) {
    case State::NORMAL:
    case State::PREALARM: {
      led->turnOn();
      break;
    }
    case State::ALARM: {
      led->turnOff();
      break;
    }
  }
}
