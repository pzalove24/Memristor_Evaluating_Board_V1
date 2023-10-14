#include "DAC.h"

void DAC_bias::DAC_setup() {
  // For Adafruit MCP4725A1 the address is 0x62 (default) or 0x63 (ADDR pin tied to VCC)
  // For MCP4725A0 the address is 0x60 or 0x61
  // For MCP4725A2 the address is 0x64 or 0x65
  dac.begin(0x60);
  Serial.println("Generating a triangle wave");
}

void DAC_bias::Test_Sequence_Triangular_Wave() {
    uint32_t counter;
    // Run through the full 12-bit scale for a triangle wave
    for (counter = 0; counter < 4095; counter++)
    {
      dac.setVoltage(counter, false);
    }
    for (counter = 4095; counter > 0; counter--)
    {
      dac.setVoltage(counter, false);
    }
}

void DAC_bias::pulse_bias(float PositiveVoltage, float NegativeVoltage, float ReadVoltage = 0.1, int PulseWidth_us = 100,int PositivePulseNumber=0, int NegativePulseNumber=0, 
                          int DelayRead_us = 50, int DelayTime_ms = 100, bool continuoes = false) {
  uint32_t PositiveVoltage_counter = (PositiveVoltage*4095)/5;
  uint32_t NegativeVoltage_counter = (NegativeVoltage*4095)/5;
  uint32_t ReadVoltage_counter     = (ReadVoltage*4095)/5;
  
  do {
    Serial.println("Generate Positive Pulse Number");
    for (int i=0; i<PositivePulseNumber;i++ ){
      dac.setVoltage(PositiveVoltage_counter, false); //bias
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0,false);
      delayMicroseconds(DelayRead_us);
      dac.setVoltage(ReadVoltage_counter, false); //read
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0,false);
      delay(DelayTime_ms);
      }
    Serial.println("Generate Negative Pulse Number");
    for (int i; i<(PositivePulseNumber+NegativePulseNumber);i++){
      dac.setVoltage(NegativeVoltage_counter, false); //bias
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0,false);
      delayMicroseconds(DelayRead_us);
      dac.setVoltage(ReadVoltage_counter, false); //read
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0,false);
      delay(DelayTime_ms);
      }
    Serial.println("Done Generating in this loop");
  }while (continuoes);
}

void DAC_bias::transient_IV(float voltage_start = 0, float voltage_end = 5, float Vstep =0.0015, int DelayTime_ms=1, bool continuoes = false) {
  uint32_t counter_start = (voltage_start*4095)/5;
  uint32_t counter_end = (voltage_end*4095)/5;
  uint32_t counter_increase = (Vstep*4095)/5;
  // Run through the full 12-bit scale for a triangle wave
  // 0.0012 V = 1 in 4095 resolution as Vstep at 5V
  if (Vstep < 0.0015 || voltage_start > 5 || voltage_end > 5) {
    Serial.println("Vstep is exceed DAC resolution or voltage_set is exceed 5V");
  }
  else {
    do {
      for (counter_start; counter_start < 4095; counter_start=counter_start+counter_increase){
        dac.setVoltage(counter_start, false);
        delay(DelayTime_ms);
        }
      for (counter_end; counter_end > 0; counter_end=counter_end-counter_increase){
        dac.setVoltage(counter_end, false);
        delay(DelayTime_ms);
        }
      // for (int i=0; i<4095;i++ ){
      //   dac.setVoltage((voltage_start*4095)/5, false);
      //   delayMicroseconds(50);
      //   dac.setVoltage((0.1*4095)/5, false);
      //   delay(DelayTime_ms);
      // }
    }while (continuoes);
  }
}