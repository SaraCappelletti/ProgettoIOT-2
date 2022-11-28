#include "ManualTask.h"

ManualTask::ManualTask(Potentiometer* potentiometer, Sonar* sonar, Button* button) : potentiometer(potentiometer), sonar(sonar), button(button) {}

void ManualTask::init(const unsigned long period) {
    Task::init(period);
}

void ManualTask::tick() {
 potentiometer->read();
}
