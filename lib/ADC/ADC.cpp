#include <ADC.h>

ADC_measure::ADC_measure(int delay = 10) {
    _delay = delay;
}

void ADC_measure::ADC_setup() {
    Serial.println("Getting differential reading from AIN0 (P) and AIN1 (N), AIN2 (P) and AIN3 (N)");
    Serial.println("ADC Range: +/- 6.144V (1 bit = 0.1875mV/ADS1115)");
    ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)

    if (!ads.begin()) {
        Serial.println("Failed to initialize ADS.");
        while (1);
    }
}

void ADC_measure::ADC_init() {
    int16_t voltage;
    int16_t current;
    /* Be sure to update this value based on the IC and the gain settings! */
    float multiplier = 0.1875F; /* ADS1115  @ +/- 6.144V gain (16-bit results) */
    voltage = ads.readADC_Differential_0_1();
    current = ads.readADC_Differential_2_3();
    Serial.print("Differential: "); Serial.print(voltage); Serial.print("("); Serial.print(voltage * multiplier); Serial.println("mV)");
    Serial.print("Differential: "); Serial.print(current); Serial.print("("); Serial.print(current * multiplier); Serial.println("mV)");
    delay(_delay);
}