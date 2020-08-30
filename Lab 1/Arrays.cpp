#include <Arduino.h>

boolean toggle = false;

void setup() {
     Serial.begin(9600);
}

void loop() {
    if (toggle) {
              Serial.println("toggle is true");
    } else {
              Serial.println("toggle is false");
    }
toggle = !toggle;
delay(1000);
}
