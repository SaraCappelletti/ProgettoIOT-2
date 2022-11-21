#include "Pir.h"

Pir::Pir(const int pin) : Sensor(pin) { Pir::time = millis(); };

bool Pir::read() {
  if (!calibrated) {
    if (millis() - time < CALIBRATION_TIME) {
      return 0.0;
    }
  }
  return digitalRead(pin) == HIGH ? true : false;
}
