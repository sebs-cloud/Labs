#include <Arduino.h>

char charA = 'a';
char charArray[17] = {'S','t','r','i','n','g',' ','i','s',' ','A','r','r','a','y','!'};
char stringArray[] = "String is Array!";

void setup() {
    Serial.begin(9600);
    //Serial.println(charA);
    /*Serial.println(charArray);*/
    Serial.println(stringArray);

}

void loop() {

}
