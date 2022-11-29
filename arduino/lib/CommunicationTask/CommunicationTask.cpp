#include "CommunicationTask.h"

CommunicationTask::CommunicationTask(Sonar* sonar) : Task(), sonar(sonar) {};

void CommunicationTask::init(const unsigned long period) {
    Task::init(period);
};

void CommunicationTask::tick() {
    float wl = sonar->read();
    Serial.println(wl + (String)"," + millis()/1000.0);
};
