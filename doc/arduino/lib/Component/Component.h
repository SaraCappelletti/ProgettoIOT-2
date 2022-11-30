#ifndef __COMPONENT__
#define __COMPONENT__

class Component {
protected:
  const int pin;

public:
  Component(const int pin) : pin(pin) {}
};

#endif
