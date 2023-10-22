// include opensource lib
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <ADS1X15.h>
#include <ArduinoJson.h>
#include <MD_AD9833.h>
// include lib IC_Operation
#include "ADC_Read/ADC_Read.h"
#include "DAC_Bias/DAC_Bias.h"
// include lib BoardOperation
#include "Current_Limiter/Current_Limiter.h"

Current_Limiter current_limiter(7, 6, 5, 4); // pin digital number

void handleCurrentComplianceTask(void *pvParameters)
{
  Serial.begin(9600);
  current_limiter.init();
  char current_set_from_user = Serial.read();

  switch (current_set_from_user)
  {
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

void setup()
{
}

void loop()
{
  char WebsiteCommand = Serial.read();

  switch (WebsiteCommand)
  {
  case 'Manual_Current_Range':
    current_limiter.setCurrentRange('A');
    Serial.println('x');
    break;

  default:
    break;
  }
}