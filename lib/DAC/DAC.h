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
        void pulse_bias(float PositiveVoltage, float NegativeVoltage, int PositivePulseNumber, int NegativePulseNumber, float DelayRead_us, float DelayTime_ms, bool continuoes = false);
        void pulse_IV(float voltage_start, float voltage_end, float Vstep, int PositivePulseNumber, int NegativePulseNumber, float DelayTime_ms, bool continuoes = false);
};

#endif