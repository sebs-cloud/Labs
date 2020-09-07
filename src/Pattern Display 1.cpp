#include <Arduino.h>

int count = 0;
int total = 10;

void setup() {
     Serial.begin(9600);
}

void loop() {

  if (count == total) {
  count = 1;
  delay(1000);
  } else {
  count = count + 1;
  }

  for (int i = 0; i < count; i++) {
    Serial.print("-");
  }
    Serial.println();

delay(1000);
}
