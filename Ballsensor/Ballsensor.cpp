#include "mbed.h"
#include "Ballsensor.h"

Ballsensor::Ballsensor(PinName p1,PinName p2):
_p1(p1),_p2(p2){
}

int Ballsensor::degree(){
    int value;
    if(_p2.read() >= 0.95 ){
        value = -999;
    }
    else{
        value = (int)(_p1.read()*360 - 180);
    }
    return value;
}

int Ballsensor::distance(){
    int value;
    value = (int)(_p2.read() * 1024);
    return value;
}