#ifndef ADC_Read_H
#define ADC_Read_H

#include <Arduino.h>
#include <Adafruit_ADS1X15.h>

class ADC_Read
{
private:
    int _delay;

public:
    // Include
    Adafruit_ADS1115 ads;

    // Constructor
    ADC_Read(int delay = 10);

    // Setter
    void init();
    void off();

    // Getter

    int getCurrentRead();
    int getVoltageRead();
    int getResistanceRead();

    void Test_Sequence();
    int voltage_measure();
    int current_measure();
};

#endif