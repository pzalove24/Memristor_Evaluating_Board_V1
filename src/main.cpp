#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <ADS1X15.h>
#include <Current_limiter.h>
#include <ADS1256.h>
#include <MD_AD9833.h>
#include <ADC.h>
#include <AD9833.h>
#include <DAC.h>
#include <ArduinoJson.h>
#include <Arduino_FreeRTOS.h>

void arduinoTask(void *pvParameters)
{
  Serial.begin(9600);

  while (1)
  {
    Serial.println("Arduino is ready");
    delay(1000);
  }
}

void arduinoTask_2(void *pvParameters)
{
  Serial.begin(9600);

  while (1)
  {
    Serial.println("Arduino is prepared");
    delay(100);
  }
}

void setup() {
  
  xTaskCreate(arduinoTask, "RED LED Task", 128, NULL, 1, NULL);
  xTaskCreate(arduinoTask_2, "RED LED Task", 128, NULL, 1, NULL);

}

void loop() {}