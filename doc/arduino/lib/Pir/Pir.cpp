#include "Pir.h"

Pir::Pir(const int pin) : Sensor(pin) {
  Pir::time = millis();
}

bool Pir::read() {
  //gli lascio del tempo per calibrarsi
  if (!calibrated) {
    if (millis() - time < CALIBRATION_TIME) {
      Serial.println("Calibrating");
      return false;
    } else {
      calibrated = true;
    }
  }
  //quando si è calibrato ritorna se c'è del movimento
  return digitalRead(pin) == HIGH ? true : false;
}
