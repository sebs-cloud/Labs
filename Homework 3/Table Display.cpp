#include <Arduino.h>

void setup() {
     Serial.begin(9600);

     int index = 0;
     int table[10][7];

     for (int i = 0; i < 10; i++) { //row
       for (int j = 0; j < 7; j++) { //column
         table[i][j] = index;
         table[i][j] = table[i][j] + j;
         Serial.print(table[i][j]);
         Serial.print("\t");
       }
       Serial.println();
       index = index + 10;
     }
}

void loop() {

}
