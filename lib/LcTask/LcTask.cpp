#include "LcTask.h"

LcTask::LcTask(Led* led) : led(led) {}

void LcTask::init(const unsigned long period) {
    Task::init(period);
}

void LcTask::tick() {
  switch (Scheduler::getState()) {
    case NORMAL: {
      led->turnOff();
      break;
    }
    case State::PREALARM: {
      led->blinking(2000, 2000);
      break;
    }
    case ALARM: {
      led->turnOn();
      break;
    }
  }
}
