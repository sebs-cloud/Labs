#include <Arduino.h>

int count = 1;
int total = 10;
boolean inc = true;

void setup() {
     Serial.begin(9600);
}

void loop() {

  for (int i = 0; i < count; i++) {
    Serial.print("-");
  }
    Serial.println();

  if (inc == true) {
  count = count + 1;
  } else {
  count = count - 1;
  }

  if (count == total) {
    inc = false;
  } else if (count == 1) {
    inc = true;
  delay(1000);
  }

//delay(1000);
}
