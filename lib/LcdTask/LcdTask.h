#ifndef __LCDTASK__
#define __LCDTASK__

#include "Scheduler.h"
#include "Task.h"
#include "Lcd.h"
#include "Sonar.h"

class LcdTask : public Task {
  Lcd* lcd;
  Sonar* sonar;

  public:
    LcdTask(Lcd* lcd, Sonar* sonar);
    void init(const unsigned long period);
    void tick();
};

#endif
