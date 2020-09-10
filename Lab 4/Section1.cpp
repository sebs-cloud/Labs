#include <Arduino.h>

void setup() {
     Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    int incomingByte = Serial.parseInt();

    Serial.print("I recieved: ");
    char incomingChar = (char)incomingByte;
    Serial.print(incomingChar);

    Serial.print(",");
    Serial.print(incomingByte, DEC);
    Serial.print(",");
    Serial.print(incomingByte, BIN);
    Serial.println();
  }
}
