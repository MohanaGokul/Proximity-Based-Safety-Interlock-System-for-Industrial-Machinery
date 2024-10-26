#include <Servo.h>

const int externalLedPin = 8; // Define the pin where the external LED is connected (you can change this to any pin)
const int inputPin1 = 2;  // Define the input pin
const int inputPin2 = 4;
const int inputPin3 = 6;
int servo1Pin = 10;
int a = 0;
int b = 0;
Servo Servo1;

void setup() {
  pinMode(externalLedPin, OUTPUT);  // Set the external LED pin as an output
  pinMode(inputPin1, INPUT); // Set the input pin as an input
  pinMode(inputPin2, INPUT);
  pinMode(inputPin2, INPUT);
  Servo1.attach(servo1Pin);
}

void loop() {
  int inputState1 = digitalRead(inputPin1);  // Read the state of the input pin (HIGH or LOW)
  int inputState2 = digitalRead(inputPin2);
  int inputState3 = digitalRead(inputPin3);
  
  if (inputState1 == HIGH) {
    a = 1;
  }
  if (inputState2 == HIGH && a == 1){
    b = 1;
  }
  if (inputState3 == HIGH && a == 1 && b == 1){
    digitalWrite(externalLedPin, HIGH);  // Turn on the external LED if the input is HIGH
    Servo1.write(180);
    delay(1000);
    Servo1.write(0);
    delay(1000);
    a = 0;
    b = 0;

  }
}