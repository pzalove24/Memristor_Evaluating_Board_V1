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
        void pulse_bias(float PositiveVoltage, float NegativeVoltage, float ReadVoltage = 0.1, float PulseWidth_us = 100, int PositivePulseNumber=10, int NegativePulseNumber=10, float DelayRead_us = 50, float DelayTime_ms = 100, bool continuoes = false);
        void pulse_IV(float voltage_start, float voltage_end, float Vstep, int PositivePulseNumber, int NegativePulseNumber, float DelayTime_ms, bool continuoes = false);
};

#endif