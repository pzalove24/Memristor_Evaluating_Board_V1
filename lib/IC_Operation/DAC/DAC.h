#ifndef DAC_h
#define DAC_h
#include <Arduino.h>
#include <Adafruit_MCP4725.h>

class DAC_bias {
    private:

    public:

        Adafruit_MCP4725 dac;
        void DAC_setup();
        void Test_Sequence_Triangular_Wave();
        void pulse_bias(float PositiveVoltage, float NegativeVoltage, float ReadVoltage = 0.1, int PulseWidth_us = 100, int PositivePulseNumber=0, int NegativePulseNumber=0, int DelayRead_us = 50, int DelayTime_ms = 100, bool continuoes = false);
        void transient_IV(float voltage_start = 0, float voltage_end = 5, float Vstep =0.0015, int DelayTime_ms=1, bool continuoes = false);
};

#endif