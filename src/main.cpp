#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <ADS1X15.h>
#include <Current_limiter.h>
#include <ADS1256.h>
#include <MD_AD9833.h>

  /* Use this for the 16-bit version */

Current_limiter current_limiter(7,6,5,4);

void setup() {
  Serial.begin(9600);
  current_limiter.Cl_PinSetup();
}

void loop(){
  current_limiter.Test_Sequence();
}
