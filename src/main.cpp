#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <ADS1X15.h>
#include <Current_limiter.h>
#include <Adafruit_ADS1X15.h>
#include <ADS1256.h>
#include <MD_AD9833.h>

#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Getting differential reading from AIN0 (P) and AIN1 (N), AIN2 (P) and AIN3 (N)");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 0.1875mV/ADS1115)");
  ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)

  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }}


void loop(void)
{
  int16_t results1;
  int16_t results2;

  /* Be sure to update this value based on the IC and the gain settings! */
  float multiplier = 0.1875F; /* ADS1115  @ +/- 6.144V gain (16-bit results) */

  results1 = ads.readADC_Differential_0_1();
  results2 = ads.readADC_Differential_2_3();

  Serial.print("Differential: "); Serial.print(results1); Serial.print("("); Serial.print(results1 * multiplier); Serial.println("mV)");
  Serial.print("Differential: "); Serial.print(results2); Serial.print("("); Serial.print(results2 * multiplier); Serial.println("mV)");

  delay(1000);
}