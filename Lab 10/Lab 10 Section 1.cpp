#include <Arduino.h>

/*
      We use Common Anode LED displays, hence common pin is connected to 5V (HIGH)
      That means a segment will illuminate when we ground the corresponding pin
      When using Ardunio, we can do this by writing a LOW (or 0) to corresponding pin

      octalLatchDigitArray holds the LOW/HIGH signal for each LED segment for the Octal Latch
*/
byte octalLatchDigitArray[10][7] = {
  { LOW, LOW, LOW, LOW, LOW, LOW, HIGH}, // = 0
  { HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH}, // = 1
  { LOW, LOW, HIGH, LOW, LOW, HIGH, LOW}, // = 2
  { LOW, LOW, LOW, LOW, HIGH, HIGH, LOW}, // = 3
  { HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW}, // = 4
  { LOW, HIGH, LOW, LOW, HIGH, LOW, LOW}, // = 5
  { LOW, HIGH, LOW, LOW, LOW, LOW, LOW}, // = 6
  { LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH}, // = 7
  { LOW, LOW, LOW, LOW, LOW, LOW, LOW}, // = 8
  { LOW, LOW, LOW, LOW, HIGH, LOW, LOW} // = 9
};

/*
      bcdDriverDigitArray holds the BCD code (4 bit) for input of the BCD to 7 Segment Driver
      Note that array values could be either LOW/HIGH or 0/1. For clarity we use 0/1
*/
byte bcdDriverDigitArray[10][4] = {
 // D, C, B, A
  { 0, 0, 0, 0 }, //    0
  { 0, 0, 0, 1 }, //    1
  { 0, 0, 1, 0 }, //    2
  { 0, 0, 1, 1 }, //    3
  { 0, 1, 0, 0 }, //    4
  { 0, 1, 0, 1 }, //    5
  { 0, 1, 1, 0 }, //    6
  { 0, 1, 1, 1 }, //    7
  { 1, 0, 0, 0 }, //    8
  { 1, 0, 0, 1 } //     9
};

/*
      shiftRegisterDigitArray holds integer values for a byte (8 bits in 0gfedcba format) for illuminating individual segments for each number
      Since a 1 (HIGH) turns off the segment and a 0 (LOW) will turn it on, we will set each bit accordingly
      01000000 (64) for digit 0, 01111001 (121) for digit 1, 00100100 (36) for digit 2, 00110000 (48) for digit 3, 00011001 (25) for digit 4,
      00010010 (18) for digit 5, 00000010 (2) for digit 6, 01111000 (120) for digit 7, 00000000 (0) for digit 8, 00010000 (16) for digit 9
*/
int shiftRegisterDigitArray[] = {64, 121, 36, 48, 25, 18, 2, 120, 0, 16};

/*
      Pin variable declarations for Octal Latch
      Note that Latch Data pins are from pin 6 to pin 12
*/
int octalLatchEnablePin = 2;
int latchD0Pin = 6; //D0=>6, D6=>12

/*
      Pin variable declarations for BCD to 7 Segment Driver

*/
int bcdDriverLatchEnablePin = 3;
int driverAPin = 6;
int driverBPin = 7;
int driverCPin = 8;
int driverDPin = 9;

/*
      Pin variable declarations for Shift Register

*/
int shiftRegisterClockPin = 4;
int storageRegisterClockPin = 5;
int serialInputPin = 6;

/*
    Pins 2 - 5 are used as control signals while Pins 6 - 12 are used as data signals
    These pins are configured as OUTPUT pins
*/
void setup()
{
  Serial.begin(9600);

  for (int i = 2; i <= 12; i++) {
    pinMode(i, OUTPUT);
  }
}

/*
      Main loop function
*/
void loop() {
  testWriteDigitFunctions();

  //testDisplayNumberFunction();
}

/*
      A simple test function
*/
void testWriteDigitFunctions() {
  for (byte count = 0; count <= 9; count++) {
    writeDigitToLatch(count);
    writeDigitToDriver(count);
    writeDigitToRegister(count);

    delay(500);
  }
}

/*
*   A simple test function
*/
void testDisplayNumberFunction() {
  for (int i = 0; i <= 999; i++) {
    displayNumber(i);
    delay(100);
  }
}

/*
      Implement writeDigitToLatch() to write given digit by sending corresponding signals to Octal Latch
*/
void writeDigitToLatch(int digit) {

}

/*
      Implement writeDigitToDriver() to write given digit by sending corresponding BCD signals to Driver
*/
void writeDigitToDriver(byte digit) {

}

/*
      Implement writeDigitToRegister() to write given digit by sending corresponding serial data to Shift Register
*/
void writeDigitToRegister(int digit) {

}

/*
      Implement displayNumber()
      Write to three LED displays using writeDisplay...() functions
      Hint: Use modulo and division operators to seperate unit, tens and hundreds digits
*/
void displayNumber(int digit) {

}
