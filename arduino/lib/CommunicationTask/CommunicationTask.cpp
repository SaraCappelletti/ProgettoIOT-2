#include "CommunicationTask.h"

CommunicationTask::CommunicationTask(Sonar* sonar, ServoMotor* motor, Led* led) : sonar(sonar), motor(motor), led(led) {};

void CommunicationTask::init(const unsigned long period) {
    Task::init(period);
}

void CommunicationTask::tick() {
    this->send();
    if (Scheduler::getState() == State::ALARM && Scheduler::isManual() == true) {
        if (Serial.available() > 0) {
            Scheduler::setRemote(true);
            int val = receive();
            motor->move(val);
        } else {
            Scheduler::setRemote(false);
        }
    }
}

void CommunicationTask::send() {
    float wl = sonar->read();
    String light = led->isOn() ? "Smart light ON" : "Smart light OFF";
    Serial.println(millis()/1000.0 + (String)"," + wl + (String)"," + light + (String)"," + Scheduler::getStateToString());
}

int CommunicationTask::receive() {
    return Serial.read();
}
