#include <Arduino.h>

void setup() {
     Serial.begin(9600);
}

void loop() {
  long firstNum, secondNum = 0;
  long answer;
  char operation;

  Serial.println("Enter the first number");
  while (Serial.available() == 0) {}
  firstNum = Serial.parseInt();
  Serial.print("you entered: ");
  Serial.println(firstNum);

  Serial.println("Enter the operation");
  while (Serial.available() == 0) {}
  operation = Serial.read();
  Serial.print("you entered: ");
  Serial.println(operation);

  Serial.println("Enter the second number");
  while (Serial.available() == 0) {}
  secondNum = Serial.parseInt();
  Serial.print("you entered: ");
  Serial.println(secondNum);

long beginMicros = micros();

answer = calculate(firstNum, secondNum, operation);

long computeTime = micros() - beginMicros;
Serial.print("The answer is: ");
Serial.println(answer);
Serial.print("The time it took is: ");
Serial.println(computeTime);

}

long calculate(long firstNum, long secondNum, char operation) {
  long answer = 0;
  switch (operation) {
    case '+':
      answer = firstNum + secondNum;
      break;
    case '-':
      answer = firstNum - secondNum;
      break;
    case '*':
      answer = firstNum * secondNum;
      break;
    case '/':
      answer = firstNum / secondNum;
      break;
      return answer;
  }
}
