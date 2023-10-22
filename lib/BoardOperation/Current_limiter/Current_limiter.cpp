#include "Current_Limiter.h"

// const int inPin1 = 7;
// const int inPin2 = 6;
// const int inPin3 = 5;
// const int inPin4 = 4;

Current_Limiter::Current_Limiter(int MohmPin, int HundredKohmPin, int TenKohmPin, int OneKohmPin)
{
  _MohmPin = MohmPin;
  _HundredKohmPin = HundredKohmPin;
  _TenKohmPin = TenKohmPin;
  _OneKohmPin = OneKohmPin;
}

void Current_Limiter::init()
{
  pinMode(_MohmPin, OUTPUT);
  pinMode(_HundredKohmPin, OUTPUT);
  pinMode(_TenKohmPin, OUTPUT);
  pinMode(_OneKohmPin, OUTPUT);
}

void Current_Limiter::setCurrentRange(string currentRange) {

  string selectCurrentRange = currentRange;
  switch (selectCurrentRange)
  {
  case /* constant-expression */:
    /* code */
    break;
  
  default:
    break;
  }
}

void Current_Limiter::Test_Sequence()
{
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

void Current_Limiter::one_uA()
{
  digitalWrite(_MohmPin, HIGH);
  digitalWrite(_HundredKohmPin, LOW);
  digitalWrite(_TenKohmPin, LOW);
  digitalWrite(_OneKohmPin, LOW);
}

void Current_Limiter::ten_uA()
{
  digitalWrite(_MohmPin, LOW);
  digitalWrite(_HundredKohmPin, HIGH);
  digitalWrite(_TenKohmPin, LOW);
  digitalWrite(_OneKohmPin, LOW);
}

void Current_Limiter::hundred_uA()
{
  digitalWrite(_MohmPin, LOW);
  digitalWrite(_HundredKohmPin, LOW);
  digitalWrite(_TenKohmPin, HIGH);
  digitalWrite(_OneKohmPin, LOW);
}

void Current_Limiter::one_mA()
{
  digitalWrite(_MohmPin, LOW);
  digitalWrite(_HundredKohmPin, LOW);
  digitalWrite(_TenKohmPin, LOW);
  digitalWrite(_OneKohmPin, HIGH);
}

void Current_Limiter::Gain_R_feedback()
{
}