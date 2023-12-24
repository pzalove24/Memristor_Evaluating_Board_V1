#ifndef DAC_Bias_H
#define DAC_Bias_H
#include <Arduino.h>
#include <Adafruit_MCP4725.h>

class DAC_Bias
{
private:
public:
    // Include
    Adafruit_MCP4725 dac;

    // Constructor
    DAC_Bias()
    {
    }

    // Setter
    void init();
    void off();
    void setManualVoltage();
    void setPulseVoltage();
    void setTransientVoltage();
    // Getter

    void Test_Sequence_Triangular_Wave();
    void transient_IV(float voltage_start = 0, float voltage_end = 5, float Vstep = 0.0015, int DelayTime_ms = 1, bool continuoes = false);
    void test_pulse_bias(float PositiveVoltage, float NegativeVoltage, float ReadVoltage = 0.1, int PulseWidth_us = 100, int PositivePulseNumber = 0, int NegativePulseNumber = 0, int DelayRead_us = 50, int DelayTime_ms = 100, bool continuoes = false);
    void pulse_bias(float PositiveVoltage, float NegativeVoltage, float ReadVoltage = 0.1, int PulseWidth_us = 100, int PositivePulseNumber = 0, int NegativePulseNumber = 0, int DelayRead_us = 50, int DelayTime_ms = 100, bool continuoes = false);
    void sweep_bias_IV(float positive_voltage = 8, float negative_voltage = -8, float Vstep = 0.0015, int voltage_width_us = 100, int repeat_cycle = 1);
    void conductancePulse(float positive_voltage, float negative_voltage, float read_voltage = 0.1, int PulseWidth_us = 100, int PositivePulseNumber = 0, int NegativePulseNumber = 0, int DelayRead_us = 50, int DelayTime_ms = 100, bool continuoes = false);
    void enduranceCycle(float positive_voltage, float negative_voltage, float read_voltage = 0.1, int pulseWidth_positive_us = 100, int pulseWidth_negative_us = 100, int pulseWidth_read_us = 100, int interval_us = 50, int repeat = 1);
    void retention_sweep(float positive_voltage, float negative_voltage, float read_voltage = 0.1, int width_positive_us = 100, int width_negative_us = 100, int width_read_us = 100, int interval_us = 50, int repeat = 1);
    void retention_pulse(float positive_voltage, float negative_voltage, float read_voltage = 0.1, int pulseWidth_positive_us = 100, int pulseWidth_negative_us = 100, int pulseWidth_read_us = 100, int wait_us = 50, int repeat = 1);

    // Abstract
    // Friend
    // Static
};

#endif