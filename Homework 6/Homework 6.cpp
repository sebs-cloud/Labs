#include <Arduino.h>
#include <Bounce2.h>

Button button = Button(); //Creates a button object
bool ledState = LOW; //boolean variable for led state
void setup() {
  button.attach(2, INPUT); //Using external pullup
  button.interval(5);//Sets debounce interval
  button.setPressedState(LOW);//Sets up that the LOW state == physically pressing button
  pinMode(7, OUTPUT);//Assigns pin to output power to LED
  digitalWrite(7, ledState);//Initially sets LED to off
}



void loop() {
  button.update();
  if ( button.pressed() ) {

    // TOGGLE THE LED STATE :
    ledState = !ledState; // SET ledState TO THE OPPOSITE OF ledState
    digitalWrite(7,ledState);
  }
}
