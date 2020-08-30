#include <Arduino.h>

float count = 0;
boolean toggle = false;
int canNotChange = 0;

void setup() {
  count = 1.5;
  Serial.begin(9600);
  Serial.println("This executes only once");
  canNotChange = 1;
}

void loop() {
  Serial.print("This executes repeatedly forever and ever!\t");
  count = count + 1;
  Serial.println(count);
  toggle = !toggle;
  Serial.println(toggle);
  delay(1000);
}
