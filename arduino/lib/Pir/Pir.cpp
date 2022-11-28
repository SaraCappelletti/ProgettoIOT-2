#include "Pir.h"

Pir::Pir(const int pin) : Sensor(pin) {
  Pir::time = millis();
}

bool Pir::read() {
  if (!calibrated) {
    if (millis() - time < CALIBRATION_TIME) {
      Serial.println("Calibrating");
      return false;
    } else {
      calibrated = true;
    }
  }
  return digitalRead(pin) == HIGH ? true : false;
}
