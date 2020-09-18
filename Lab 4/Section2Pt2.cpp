#include <Arduino.h>

boolean powerOn = false;

void setup() {
     Serial.begin(9600);
     pinMode(2, INPUT_PULLUP);
     pinMode(3, OUTPUT);
}

void loop() {
  if (digitalRead(2) == LOW){
    powerOn = !powerOn;
    delay(2);
  }

  if (powerOn == true) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
}
