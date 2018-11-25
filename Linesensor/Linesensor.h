#include "mbed.h"

class Linesensor{
    public:
        Linesensor(PinName pin);
        int direction();
    private:
        AnalogIn _pin;
};