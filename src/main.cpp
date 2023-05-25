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

Current_limiter current_limiter(7,6,5,4); //pin digital number

void handleCurrentComplianceTask(void *pvParameters)
{
  Serial.begin(9600);
  current_limiter.Cl_PinSetup();
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