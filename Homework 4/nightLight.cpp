#include <Arduino.h>

boolean powerOn = false;

void setup() {
     Serial.begin(9600);
     pinMode(2, INPUT_PULLUP);
     pinMode(3, OUTPUT);
}

void loop() {

    if (digitalRead(2) == LOW) {
      powerOn = !powerOn;
      delay(30);
    }

    if (powerOn == true) {

      //  reading values from photocell & printing data
      int dataIn = analogRead(A0);
      Serial.print("System is on, light value is: ");
      Serial.println(dataIn);
      delay(1000);

      //  turning on the light if its dark
      if (dataIn > 250) {
        digitalWrite(3, LOW);
      } else {
        digitalWrite(3, HIGH);
      }
      //  turning off light & informing
    } else {
      digitalWrite(3, LOW);
      Serial.println("System is off");
      delay(1000);
    }


}
