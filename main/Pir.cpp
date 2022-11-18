#include "Pir.h"

Pir::Pir(const int pin) : pin(pin) { Pir::time = millis(); };

bool Pir::read() {
  if (!calibrated) {
    if (millis() - time < CALIBRATION_TIME) {
      return false;
    }
  }
  return digitalRead(pin) == HIGH;
}