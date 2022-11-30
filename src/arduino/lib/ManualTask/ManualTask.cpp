#include "ManualTask.h"

ManualTask::ManualTask(Button* button) : button(button) {}

void ManualTask::init(const unsigned long period) {
    Task::init(period);
}

void ManualTask::tick() {
  if (Scheduler::getState() == State::ALARM) {
    //posso settare il controllo manuale solo se sono in allarme
    Scheduler::setManual(button->isPressed());
  }
}
