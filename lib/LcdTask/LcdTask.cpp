#include "LcdTask.h"

LcdTask::LcdTask(Lcd* lcd, Sonar* sonar) : lcd(lcd), sonar(sonar) {}

void LcdTask::init(const unsigned long period) {
    Task::init(period);
}

void LcdTask::tick() {
  char buffer[80];
  switch (Scheduler::getState()){
    case State::ALARM : {
      lcd->turnOn();
      sprintf(buffer, "State: %s", Scheduler::getStateToString());
      lcd->write(0, 1, buffer);
      sprintf(buffer, "Water level: %f", sonar->read());
      lcd->write(0, 2, buffer);
      sprintf(buffer, "Opening degrees: 180");
      lcd->write(0, 3, buffer);
      break;
    } 
    case State::PREALARM : {
      lcd->turnOn();
      sprintf(buffer, "State: %s", Scheduler::getStateToString());
      lcd->write(0, 1, buffer);
      sprintf(buffer, "Water level: %4.2f", sonar->read());
      lcd->write(0, 2, buffer);
      lcd->write(0, 3, "                                 ");
      break;
    }
    case State::NORMAL : {
      lcd->turnOff();
      break;
    }
  }

}
