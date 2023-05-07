#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <ADS1X15.h>
#include <Current_limiter.h>
#include <ADS1256.h>
#include <MD_AD9833.h>
#include <ADC.h>
#include <AD9833.h>
#include <DAC.h>

  /* Use this for the 16-bit version */

Current_limiter current_limiter(7,6,5,4); //pin digital number
ADC_measure adc_measure(100); //delay
#define FNC_PIN 8 //function generator at digital pin number
AD9833 gen(FNC_PIN);
DAC_bias dac_bias;

void setup() {
  Serial.begin(9600);
  current_limiter.Cl_PinSetup();
  adc_measure.ADC_setup();
  gen.Begin();
  gen.ApplySignal(TRIANGLE_WAVE, REG0,10000);
  dac_bias.DAC_setup();
}

void loop(){
  current_limiter.Test_Sequence();
  adc_measure.Test_Sequence();
  adc_measure.current_measure();
  delay(1000);
  adc_measure.voltage_measure();
  delay(1000);
  dac_bias.Test_Sequence_Triangular_Wave();
  dac_bias.transient_IV(0,5,0.0015,1,false);
  dac_bias.pulse_bias(5,5,0.1,100,10,10,50,100,false);
}

//Return 0
//Return 1