#include "mbed.h"
#include "Linesensor.h"

Linesensor::Linesensor(PinName pin):
_pin(pin){
}

int Linesensor::direction(){
    int dir;
    double value = _pin.read();
    if(value >= 0.95){//1
        dir = 0;
    }
    else if(value >= 0.85){//0.9
        dir = 45;
    }
    else if(value >= 0.75){//0.8
        dir = 90;
    }
    else if(value >= 0.65){//0.7
        dir = 135;
    }
    else if(value >= 0.55){//0.6
        dir = 180;
    }
    else if(value >= 0.45){//0.5
        dir = 225;
    }
    else if(value >= 0.35){//0.4
        dir = 270;
    }
    else if(value >= 0.25){//0.3
        dir = 315;
    }
    else if(value >= 0.05){//0.1
        dir = 999;
    }
    else{//0
        dir = -999;
    }
    return dir;
}
