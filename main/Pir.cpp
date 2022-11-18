#include "Pir.h"

Pir::Pir(const int pin) : pin(pin) { Pir::time = millis(); };

float Pir::read() {
  if (!calibrated) {
    if (millis() - time < CALIBRATION_TIME) {
      return 0.0;
    }
  }
  return digitalRead(pin) == HIGH ? 0.0 : 1.0;
}