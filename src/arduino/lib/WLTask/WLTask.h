#ifndef __WLTASK__
#define __WLTASK__

#include "Scheduler.h"
#include "Task.h"
#include "Sonar.h"
#include "Const.h"

class WLTask : public Task {
  Sonar* sonar;

  public:
    WLTask(Sonar* sonar);
    void init(const unsigned long period);
    void tick();
};

#endif
