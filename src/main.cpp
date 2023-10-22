// include opensource lib
// #include <AD9833.h>
// #include <ADS1256.h>
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <ADS1X15.h>
#include <Arduino_FreeRTOS.h>
#include <ArduinoJson.h>
#include <MD_AD9833.h>
// include lib IC_Operation
#include "ADC_Read/ADC_Read.h"
#include "DAC_Bias/DAC_Bias.h"
// include lib BoardOperation
#include "Current_limiter/Current_limiter.h"


Current_Limiter current_limiter(7,6,5,4); //pin digital number

void handleCurrentComplianceTask(void *pvParameters)
{
  Serial.begin(9600);
  current_limiter.init();
  char current_set_from_user = Serial.read();

  switch (current_set_from_user){
    case 'one_mA':
      current_limiter.one_mA();
      Serial.println(current_set_from_user);
      break;
    case 'hundred_uA':
      current_limiter.hundred_uA();
      Serial.println(current_set_from_user);
      break;
    case 'ten_uA':
      current_limiter.ten_uA();
      Serial.println(current_set_from_user);
      break;
    case 'one_uA':
      current_limiter.one_uA();
      Serial.println(current_set_from_user);
      break;
    default:
      Serial.println("Current Compliance selection is needed");
      break;
  }
  // while (1)
  // {
  //   current_limiter.one_mA();
  //   delay(1000);
  //   current_limiter.hundred_uA();
  //   delay(1000);
  //   current_limiter.ten_uA();
  //   delay(1000);
  //   current_limiter.one_uA();
  //   delay(1000);
  // }
}

void handleReadyStatus(void *pvParameters)
{
  Serial.begin(9600);

  while (1)
  {
    Serial.println("Arduino is ready");
    delay(1000);
  }
}

void setup() {
  
  xTaskCreate(handleCurrentComplianceTask, "handle Current Compliance Task", 128, NULL, 1, NULL);
  xTaskCreate(handleReadyStatus, "handleReadyStatus", 128, NULL, 1, NULL);

}

void loop() {}