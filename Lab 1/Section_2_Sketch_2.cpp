#include <Arduino.h>

void setup() {
    Serial.begin(9600);
}

void loop() {

    int count = 0;
    for (int i = 0; i<10; i++) {
                Serial.println(count++);
    }
    delay(1000);
}
