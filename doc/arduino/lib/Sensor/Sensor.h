#ifndef __SENSOR__
#define __SENSOR__

#include "Component.h"

class Sensor : public Component {
public:
    Sensor(const int pin) : Component(pin) {}
    template <class T>
    T read();
};

#endif
