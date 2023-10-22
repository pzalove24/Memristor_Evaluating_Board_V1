#ifndef Current_Limiter_h
#define Current_Limiter_h
#include <Arduino.h>

class Current_Limiter
{
private:
    byte _MohmPin;
    byte _HundredKohmPin;
    byte _TenKohmPin;
    byte _OneKohmPin;

public:
    // Include

    // Constructor
    Current_Limiter(byte MohmPin, byte HundredKohmPin, byte TenKohmPin, byte OneKohmPin);

    // Setter
    void init();
    void setCurrentRange(char currentRange); // A :1uA, B:10uA, C:100uA, D:1mA
    void one_uA();
    void ten_uA();
    void hundred_uA();
    void one_mA();

    // Getter
    void Test_Sequence();
    void Gain_R_feedback();
};

#endif