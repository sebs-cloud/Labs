#include <Arduino.h>
#include <Servo.h>

Servo servoMotor;
void setup() {
  Serial.begin(9600);
  servoMotor.attach(9);

}

void loop() {
  int voltage = analogRead(A0);
  voltage = map(voltage, 0, 1023, 0, 179);
  servoMotor.write(voltage);
  Serial.println(voltage);

  if (voltage > 0 && voltage < 10) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  } else if (voltage >= 170) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
}
