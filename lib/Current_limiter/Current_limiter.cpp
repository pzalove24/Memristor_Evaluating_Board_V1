#include <Current_limiter.h>

// const int inPin1 = 7;
// const int inPin2 = 6;
// const int inPin3 = 5;
// const int inPin4 = 4;

Current_limiter::Current_limiter(int MohmPin, int HundredKohmPin, int TenKohmPin, int OneKohmPin) {
  _MohmPin = MohmPin;
  _HundredKohmPin = HundredKohmPin;
  _TenKohmPin = TenKohmPin;
  _OneKohmPin = OneKohmPin;  
}

void Current_limiter::Cl_PinSetup() {
  pinMode(_MohmPin, OUTPUT);
  pinMode(_HundredKohmPin, OUTPUT);
  pinMode(_TenKohmPin, OUTPUT);
  pinMode(_OneKohmPin, OUTPUT);
}

void Current_limiter::Test_Sequence() {
  Serial.println("1Mohm : 1uA");
  digitalWrite(_MohmPin, HIGH);
  delay(5000);
  Serial.println("Shutdown 1");
  digitalWrite(_MohmPin, LOW);
  delay(5000);
  Serial.println("100Kohm : 10uA");
  digitalWrite(_HundredKohmPin, HIGH);
  delay(5000);
  Serial.println("Shutdown 2");
  digitalWrite(_HundredKohmPin, LOW);
  delay(5000);
  Serial.println("10Kohm : 100uA");
  digitalWrite(_TenKohmPin, HIGH);
  delay(5000);
  Serial.println("Shutdown 3");
  digitalWrite(_TenKohmPin, LOW);
  delay(5000);
  Serial.println("1Kohm : 1mA");
  digitalWrite(_OneKohmPin, HIGH);
  delay(5000);
  Serial.println("Shutdown 4");
  digitalWrite(_OneKohmPin, LOW);
  delay(5000);
};

void Current_limiter::Gain_R_feedback() {
  
}