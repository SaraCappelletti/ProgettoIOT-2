#ifndef __MANUALTASK__
#define __MANUALTASK__

#include "Scheduler.h"
#include "Task.h"
#include "Button.h"

class ManualTask : public Task {
  Button* button;

  public:
    ManualTask(Button* button);
    void init(const unsigned long period);
    void tick();
};

#endif
