#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP4725.h>

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
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("1Mohm : 1uA");
  digitalWrite(inPin1, HIGH);
  delay(5000);
  Serial.println("Shutdown 1");
  digitalWrite(inPin1, LOW);
  delay(5000);
  Serial.println("100Kohm : 10uA");
  digitalWrite(inPin2, HIGH);
  delay(5000);
  Serial.println("Shutdown 2");
  digitalWrite(inPin2, LOW);
  delay(5000);
  Serial.println("10Kohm : 100uA");
  digitalWrite(inPin3, HIGH);
  delay(5000);
  Serial.println("Shutdown 3");
  digitalWrite(inPin3, LOW);
  delay(5000);
  Serial.println("1Kohm : 1mA");
  digitalWrite(inPin4, HIGH);
  delay(5000);
  Serial.println("Shutdown 4");
  digitalWrite(inPin4, LOW);
  delay(5000);
}