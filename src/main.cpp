#include <Arduino.h>

const int inPin1 = 7;
const int inPin2 = 6;
const int inPin3 = 5;
const int inPin4 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(inPin1, OUTPUT);
  pinMode(inPin2, OUTPUT);
  pinMode(inPin3, OUTPUT);
  pinMode(inPin4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(inPin1, HIGH);
  delay(5000);
  digitalWrite(inPin1, LOW);
  delay(5000);
  digitalWrite(inPin2, HIGH);
  delay(5000);
  digitalWrite(inPin2, LOW);
  delay(5000);
  digitalWrite(inPin3, HIGH);
  delay(5000);
  digitalWrite(inPin3, LOW);
  delay(5000);
  digitalWrite(inPin4, HIGH);
  delay(5000);
  digitalWrite(inPin4, LOW);
  delay(5000);
}