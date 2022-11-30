#include "CommunicationTask.h"

CommunicationTask::CommunicationTask(Sonar* sonar, ServoMotor* motor, Led* led) : sonar(sonar), motor(motor), led(led) {};

void CommunicationTask::init(const unsigned long period) {
    Task::init(period);
}

void CommunicationTask::tick() {
    //i messaggi sono da mandare continuamente
    this->send();
    //se sono in allarme e in manuale devo controllare se ho messaggi dalla seriale
    if (Scheduler::getState() == State::ALARM && Scheduler::isManual() == true) {
        if (Serial.available() > 0) {
            //se ho messaggi setto il controllo remoto e muovo il motore
            Scheduler::setRemote(true);
            int val = receive();
            motor->move(val);
        } else {
            //se non ho messaggi non sono in controllo remoto ma solo manuale col potenziometro
            Scheduler::setRemote(false);
        }
    }
}

void CommunicationTask::send() {
    //leggo il livello dell'acqua e lo stato della smart light
    float wl = sonar->read();
    String light = led->isOn() ? "Smart light ON" : "Smart light OFF";
    //mando tutto al grafico
    Serial.println(millis()/1000.0 + (String)"," + wl + (String)"," + light + (String)"," + Scheduler::getStateToString());
}

int CommunicationTask::receive() {
    return Serial.read();
}
