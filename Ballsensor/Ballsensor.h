#include "mbed.h"

class Ballsensor
{
public:
    Ballsensor(PinName p1,PinName p2);
    int degree();
    int distance();

private:
    AnalogIn _p1;
    AnalogIn _p2;
};