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
        
};

#endif