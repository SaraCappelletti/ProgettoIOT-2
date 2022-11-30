#include "LcdTask.h"

LcdTask::LcdTask(Lcd* lcd, Sonar* sonar, ServoMotor* motor) : lcd(lcd), sonar(sonar), motor(motor) {}

void LcdTask::init(const unsigned long period) {
    Task::init(period);
}

void LcdTask::tick() {
  switch (Scheduler::getState()) {
    case State::ALARM : {
      lcd->turnOn();
      lcd->write(0, 0, "State: " + (String)Scheduler::getStateToString());
      lcd->write(0, 1, "Water level: " + (String)sonar->read());
      lcd->write(0, 2, "Opening degrees: " + (String)motor->getAngle());
      break;
    } 
    case State::PREALARM : {
      lcd->turnOn();
      lcd->write(0, 0, "State: " + (String)Scheduler::getStateToString());
      lcd->write(0, 1, "Water level: " + (String)sonar->read() );
      break;
    }
    case State::NORMAL : {
      lcd->turnOff();
      break;
    }
  }

}
