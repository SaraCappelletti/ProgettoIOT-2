#include "Sonar.h"

Sonar::Sonar(const int trigPin, const int echoPin) : Sensor(trigPin), echoPin(echoPin) {}

float Sonar::read() {
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin, LOW);

  float tUS = pulseIn(echoPin, HIGH);
  float t = tUS / 1000.0 / 1000.0 / 2;
  float distance = t*vs;
  return distance;
}