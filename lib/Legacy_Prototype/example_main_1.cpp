  /* Use this for the 16-bit version */


Current_limiter current_limiter(7,6,5,4); //pin digital number
ADC_measure adc_measure(100); //delay
#define FNC_PIN 8 //function generator at digital pin number
AD9833 gen(FNC_PIN);
DAC_bias dac_bias;

void setup() {
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
  //current_limiter.Cl_PinSetup();
  //adc_measure.ADC_setup();
  //gen.Begin();
  //gen.ApplySignal(TRIANGLE_WAVE, REG0,10000);
  //dac_bias.DAC_setup();
}

void loop(){
  // current_limiter.Test_Sequence();
  // current_limiter.one_mA();
  // delay(1000);
  // current_limiter.hundred_uA();
  // delay(1000);
  // current_limiter.ten_uA();
  // delay(1000);
  // current_limiter.one_uA();
  // delay(1000);
  // adc_measure.Test_Sequence();
  // adc_measure.current_measure();
  // delay(1000);
  // adc_measure.voltage_measure();
  // delay(1000);
  // dac_bias.Test_Sequence_Triangular_Wave();
  // dac_bias.transient_IV(0,5,0.0015,1,false);
  //dac_bias.pulse_bias(4,4,0.1,100,10,10,50,100,false);
  //dac_bias.pulse_bias(4,4,0.1,100,10,0,50,1000,false);
}
//Return 0
//Return 1