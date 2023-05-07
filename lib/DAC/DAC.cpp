#include <DAC.h>

void DAC_bias::DAC_setup() {
  // For Adafruit MCP4725A1 the address is 0x62 (default) or 0x63 (ADDR pin tied to VCC)
  // For MCP4725A0 the address is 0x60 or 0x61
  // For MCP4725A2 the address is 0x64 or 0x65
  dac.begin(0x63);
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

void DAC_bias::pulse_bias(float PositiveVoltage, float NegativeVoltage, float ReadVoltage = 0.1, float PulseWidth_us = 100,int PositivePulseNumber=10, int NegativePulseNumber=10, 
                          float DelayRead_us = 50, float DelayTime_ms = 100, bool continuoes = false) {
  do {
    Serial.println("Generate Positive Pulse Number");
    for (int i=0; i<PositivePulseNumber;i++ ){
      dac.setVoltage((PositiveVoltage*4095)/5, false); //bias
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage((0*4095)/5,false);
      delayMicroseconds(DelayRead_us);
      dac.setVoltage((ReadVoltage*4095)/5, false); //read
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage((0*4095)/5,false);
      delay(DelayTime_ms);
      }
    Serial.println("Generate Negative Pulse Number");
    for (int i; i<(PositivePulseNumber+NegativePulseNumber);i++){
      dac.setVoltage((NegativeVoltage*4095)/5, false); //bias
      delayMicroseconds(DelayRead_us);
      dac.setVoltage((ReadVoltage*4095)/5, false); //read
      delay(DelayTime_ms);
      }
    Serial.println("Done Generating in this loop");
  }while (continuoes);
}

void DAC_bias::pulse_IV(float voltage_start, float voltage_end, float Vstep, int PositivePulseNumber, int NegativePulseNumber, float DelayTime_ms, bool continuoes = false) {
  while (continuoes)
  {
    /* code */
  }
  
  
  for (int i=0; i<PositivePulseNumber;i++ ){
    dac.setVoltage((voltage_start*4095)/5, false);
    delayMicroseconds(50);
    dac.setVoltage((0.1*4095)/5, false);
    delay(DelayTime_ms);
  }

}