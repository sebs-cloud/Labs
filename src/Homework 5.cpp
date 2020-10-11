#include <Arduino.h>


boolean powerOn = false;
void setup() {
     Serial.begin(9600);
     pinMode(2, INPUT_PULLUP); //Reading button value
     pinMode(7, OUTPUT); //Output to LED
     pinMode(5, OUTPUT); //Output to MOSFET
}

void pot(boolean powerOn) { //Detects and transmits what the pot is at
  if (powerOn == true) {
    int voltage = analogRead(A0);
    Serial.println(voltage);
    voltage = map(voltage, 0, 1023, 0, 255);
    Serial.println(voltage);
    analogWrite(5, voltage);
  } else {
    analogWrite(5, 0);
  }

}
void LED() { //Turns on LED if button is pressed
  if (digitalRead(2) == LOW){
    powerOn = !powerOn;
    delay(2);
  }
  if (powerOn == true) {
    digitalWrite(7, HIGH);
    pot(powerOn);
  } else {
    digitalWrite(7, LOW);
    pot(powerOn);
  }
  //Serial.println(powerOn);
  delay(1000);
}


void loop() {

  LED();
}
