#ifndef Current_Limiter_h
#define Current_Limiter_h
#include <Arduino.h>

class Current_Limiter
{
private:
    int _MohmPin;
    int _HundredKohmPin;
    int _TenKohmPin;
    int _OneKohmPin;

public:
    // Include

    // Constructor
    Current_Limiter(int MohmPin, int HundredKohmPin, int TenKohmPin, int OneKohmPin);

    // Setter
    void init();
    void setCurrentRange(string currentRange)

    // Getter

    void Test_Sequence();
    void Gain_R_feedback();
    void one_uA();
    void ten_uA();
    void hundred_uA();
    void one_mA();
};

#endif