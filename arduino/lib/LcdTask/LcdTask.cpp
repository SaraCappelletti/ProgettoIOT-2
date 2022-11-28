#include "LcdTask.h"

LcdTask::LcdTask(Lcd* lcd, Sonar* sonar) : lcd(lcd), sonar(sonar) {}

void LcdTask::init(const unsigned long period) {
    Task::init(period);
}

void LcdTask::tick() {
  switch (Scheduler::getState()){
    case State::ALARM : {
      lcd->clear();
      lcd->turnOn();
      lcd->write(0, 1, "State: " + (String)Scheduler::getStateToString());
      lcd->write(0, 2, "Water level: " + (String)sonar->read());
      lcd->write(0, 3, "Opening degrees: 180");
      break;
    } 
    case State::PREALARM : {
      lcd->clear();
      lcd->turnOn();
      lcd->write(0, 1, "State: " + (String)Scheduler::getStateToString());
      lcd->write(0, 2, "Water level: " + (String)sonar->read() );
      break;
    }
    case State::NORMAL : {
      lcd->turnOff();
      break;
    }
  }

}
