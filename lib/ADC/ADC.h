#ifndef ADC_h
#define ADC_h

#include <Arduino.h>
#include <Adafruit_ADS1X15.h>

class ADC_measure {
    private:

        int _delay; 

    public: 
    
        ADC_measure(int delay = 10);
        Adafruit_ADS1115 ads;
        void ADC_setup();
        void ADC_init();

};

#endif