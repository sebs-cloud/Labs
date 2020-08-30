#include <Arduino.h>

int favNumArray[] = {1, 4, 28, 45, 99};
void setup() {
    Serial.begin(9600);
}

void loop() {
  Serial.println();
  favNumArray[0] = favNumArray[0] + 10;

    for (int i=0; i<5; i++) { Serial.println(favNumArray[i]);
} delay(1000);

}
