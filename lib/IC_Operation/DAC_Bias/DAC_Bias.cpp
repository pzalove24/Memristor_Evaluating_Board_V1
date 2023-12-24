#include "DAC_Bias.h"

void DAC_Bias::init()
{
  // For Adafruit MCP4725A1 the address is 0x62 (default) or 0x63 (ADDR pin tied to VCC)
  // For MCP4725A0 the address is 0x60 or 0x61
  // For MCP4725A2 the address is 0x64 or 0x65
  dac.begin(0x60);
  Serial.println("Generating a triangle wave");
}

void DAC_Bias::off()
{
  dac.setVoltage(0, false);
}

void DAC_Bias::setManualVoltage()
{
}

void DAC_Bias::setPulseVoltage()
{
}

void DAC_Bias::setTransientVoltage()
{
}

void DAC_Bias::Test_Sequence_Triangular_Wave()
{
  uint32_t counter;
  // Run through the full 12-bit scale for a triangle wave
  for (counter = 0; counter < 4095; counter++)
  {
    dac.setVoltage(counter, false);
  }
  for (counter = 4095; counter > 0; counter--)
  {
    dac.setVoltage(counter, false);
  }
}

void DAC_Bias::test_pulse_bias(float PositiveVoltage, float NegativeVoltage, float ReadVoltage = 0.1, int PulseWidth_us = 100, int PositivePulseNumber = 0, int NegativePulseNumber = 0,
                          int DelayRead_us = 50, int DelayTime_us = 100, bool continuoes = false)
{
  uint32_t PositiveVoltage_counter = (PositiveVoltage * 4095) / 5;
  uint32_t NegativeVoltage_counter = (NegativeVoltage * 4095) / 5;
  uint32_t ReadVoltage_counter = (ReadVoltage * 4095) / 5;

  do
  {
    Serial.println("Generate Positive Pulse Number");
    for (int i = 0; i < PositivePulseNumber; i++)
    {
      dac.setVoltage(PositiveVoltage_counter, false); // bias
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0, false);
      delayMicroseconds(DelayRead_us);
      dac.setVoltage(ReadVoltage_counter, false); // read
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0, false);
      delay(DelayTime_us);
    }
    Serial.println("Generate Negative Pulse Number");
    for (int i; i < (PositivePulseNumber + NegativePulseNumber); i++)
    {
      dac.setVoltage(NegativeVoltage_counter, false); // bias
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0, false);
      delayMicroseconds(DelayRead_us);
      dac.setVoltage(ReadVoltage_counter, false); // read
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0, false);
      delay(DelayTime_us);
    }
    Serial.println("Done Generating in this loop");
  } while (continuoes);
}

void DAC_Bias::transient_IV(float voltage_start = 0, float voltage_end = 5, float Vstep = 0.0015, int DelayTime_ms = 1, bool continuoes = false)
{
  uint32_t counter_start = (voltage_start * 4095) / 5;
  uint32_t counter_end = (voltage_end * 4095) / 5;
  uint32_t counter_increase = (Vstep * 4095) / 5;
  // Run through the full 12-bit scale for a triangle wave
  // 0.0012 V = 1 in 4095 resolution as Vstep at 5V
  if (Vstep < 0.0015 || voltage_start > 5 || voltage_end > 5)
  {
    Serial.println("Vstep is exceed DAC resolution or voltage_set is exceed 5V");
  }
  else
  {
    do
    {
      for (counter_start; counter_start < 4095; counter_start = counter_start + counter_increase)
      {
        dac.setVoltage(counter_start, false);
        delay(DelayTime_ms);
      }
      for (counter_end; counter_end > 0; counter_end = counter_end - counter_increase)
      {
        dac.setVoltage(counter_end, false);
        delay(DelayTime_ms);
      }
      // for (int i=0; i<4095;i++ ){
      //   dac.setVoltage((voltage_start*4095)/5, false);
      //   delayMicroseconds(50);
      //   dac.setVoltage((0.1*4095)/5, false);
      //   delay(DelayTime_ms);
      // }
    } while (continuoes);
  }
}

void DAC_Bias::sweep_bias_IV(float positive_voltage = 8, float negative_voltage = -8, float Vstep = 0.0015, int voltage_width_us = 100, int repeat_cycle = 1)
{
  uint32_t counter_start_positive = (0 * 4095) / 8;
  uint32_t counter_end_positive = (positive_voltage * 4095) / 8;
  uint32_t counter_increase_positive = (Vstep * 4095) / 8;

  uint32_t counter_start_negative = (0 * 4095) / 8;
  uint32_t counter_end_negative = (negative_voltage * 4095) / 8;
  uint32_t counter_increase_negative = (Vstep * 4095) / 8;
  // Run through the full 12-bit scale for a triangle wave
  // 0.0012 V = 1 in 4095 resolution as Vstep at 5V
  int current_cycle = 0;
  if (Vstep < 0.0015 || positive_voltage > 8 || negative_voltage < -8)
  {
    Serial.println("Vstep is exceed DAC resolution or voltage_set is exceed +-8V");
  }
  else
  {
    do
    {
      // positive sweep 0 => positive
      for (counter_start_positive; counter_start_positive < 4095; counter_start_positive = counter_start_positive + counter_increase_positive)
      {
        dac.setVoltage(counter_start_positive, false);
        delayMicroseconds(voltage_width_us);
      }
      // positive sweep positive => 0
      for (counter_end_positive; counter_end_positive > 0; counter_end_positive = counter_end_positive - counter_increase_positive)
      {
        dac.setVoltage(counter_end_positive, false);
        delayMicroseconds(voltage_width_us);
      }

      // negative sweep 0 => negative
      for (counter_start_negative; counter_start_negative < -4095; counter_start_negative = counter_start_negative - counter_increase_negative)
      {
        dac.setVoltage(counter_start_negative, false);
        delayMicroseconds(voltage_width_us);
      }
      // negative sweep negative => 0
      for (counter_end_negative; counter_end_negative > 0; counter_end_negative = counter_end_negative + counter_increase_negative)
      {
        dac.setVoltage(counter_end_negative, false);
        delayMicroseconds(voltage_width_us);
      }
      current_cycle++;
    } while (current_cycle < repeat_cycle); // repeat time
  }

//   void DAC_Bias::sweep_bias_IV(float positive_voltage = 8, float negative_voltage = -8, float Vstep = 0.0015, int voltage_width_us = 100, int repeat_cycle = 1)
// {
//   const uint32_t positive_increment = static_cast<uint32_t>((Vstep * 4095) / 8);
//   const uint32_t negative_increment = static_cast<uint32_t>((-Vstep * 4095) / 8);

//   const uint32_t counter_end_positive = static_cast<uint32_t>((positive_voltage * 4095) / 8);
//   const uint32_t counter_end_negative = static_cast<uint32_t>((negative_voltage * 4095) / 8);

//   // Validate input parameters
//   if (Vstep < 0.0015 || positive_voltage > 8 || negative_voltage < -8)
//   {
//     Serial.println("Vstep exceeds DAC resolution or voltage range exceeds +-8V");
//     return;
//   }

//   for (int cycle = 0; cycle < repeat_cycle; ++cycle)
//   {
//     // Positive sweep: 0 => positive
//     for (uint32_t counter = 0; counter < counter_end_positive; counter += positive_increment)
//     {
//       dac.setVoltage(counter, false);
//       delayMicroseconds(voltage_width_us);
//     }

//     // Positive sweep: positive => 0
//     for (uint32_t counter = counter_end_positive; counter > 0; counter -= positive_increment)
//     {
//       dac.setVoltage(counter, false);
//       delayMicroseconds(voltage_width_us);
//     }

//     // Negative sweep: 0 => negative
//     for (uint32_t counter = 0; counter > counter_end_negative; counter += negative_increment)
//     {
//       dac.setVoltage(counter, false);
//       delayMicroseconds(voltage_width_us);
//     }

//     // Negative sweep: negative => 0
//     for (uint32_t counter = counter_end_negative; counter > 0; counter -= negative_increment)
//     {
//       dac.setVoltage(counter, false);
//       delayMicroseconds(voltage_width_us);
//     }
//   }
// }

}

void DAC_Bias::pulse_bias(float PositiveVoltage, float NegativeVoltage, float ReadVoltage = 0.1, int PulseWidth_us = 100, int PositivePulseNumber = 0, int NegativePulseNumber = 0,
                          int DelayRead_us = 50, int DelayTime_us = 100, bool continuoes = false)
{
  uint32_t PositiveVoltage_counter = (PositiveVoltage * 4095) / 5;
  uint32_t NegativeVoltage_counter = (NegativeVoltage * 4095) / 5;
  uint32_t ReadVoltage_counter = (ReadVoltage * 4095) / 5;

  do
  {
    Serial.println("Generate Positive Pulse Number");
    for (int i = 0; i < PositivePulseNumber; i++)
    {
      dac.setVoltage(PositiveVoltage_counter, false); // bias
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0, false);
      delayMicroseconds(DelayRead_us);
      dac.setVoltage(ReadVoltage_counter, false); // read
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0, false);
      delay(DelayTime_us);
    }
    Serial.println("Generate Negative Pulse Number");
    for (int i; i < (PositivePulseNumber + NegativePulseNumber); i++)
    {
      dac.setVoltage(NegativeVoltage_counter, false); // bias
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0, false);
      delayMicroseconds(DelayRead_us);
      dac.setVoltage(ReadVoltage_counter, false); // read
      delayMicroseconds(PulseWidth_us);
      dac.setVoltage(0, false);
      delay(DelayTime_us);
    }
    Serial.println("Done Generating in this loop");
  } while (continuoes);
}