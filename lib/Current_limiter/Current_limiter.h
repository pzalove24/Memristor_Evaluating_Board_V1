#ifndef Current_limiter_h
#define Current_limiter_h
#include <Arduino.h>

class Current_limiter {
    private:
        
        int _MohmPin;
        int _HundredKohmPin;
        int _TenKohmPin;
        int _OneKohmPin;

    public:
        
        Current_limiter(int MohmPin, int HundredKohmPin, int TenKohmPin, int OneKohmPin);
        void Cl_PinSetup();
        void Test_Sequence();
        void Gain_R_feedback();
        void one_uA();
        void ten_uA();
        void hundred_uA();
        void one_mA();
        
};

#endif