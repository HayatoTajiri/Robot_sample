#include "mbed.h"

class Motor
{
public:

    Motor(PinName p01,PinName p10,PinName p02,PinName p20,PinName p03,PinName p30);
    
    /*******************************************/
    /*初期設定(1周期を引数に取る)*/
    /******************************************/
    void setPwmPeriod(float hz);
    
    /****************************************************/
    /*モーターを動かす*/
    /****************************************************/
    void setPower(float a,float b, float c);
    
    //*********************************************************************************//
    ///////モーター制御θ(degree)に進行方向,powerにPWMの値(0～100),修正値をmodに代入,右回転基準////
    //********************************************************************************://
    void omniWheels(int degree,int power,int mod);

private:
    PwmOut _p01;
    PwmOut _p10;
    PwmOut _p02; 
    PwmOut _p20;
    PwmOut _p03;
    PwmOut _p30;
    const double Pi = 3.14159265; 
};