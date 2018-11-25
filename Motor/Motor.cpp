#include "mbed.h"
#include "Motor.h"

Motor::Motor(PinName p01,PinName p10,PinName p02,PinName p20,PinName p03,PinName p30):
_p01(p01),_p10(p10),_p02(p02),_p20(p20),_p03(p03),_p30(p30)
{
    _p01 = 0;
    _p10 = 0;
    _p02 = 0;
    _p20 = 0;
    _p03 = 0;
    _p30 = 0;
}

/*繝｢繝ｼ繧ｿ繝ｼ蜻ｨ豕｢謨ｰ螟画峩蛻晄悄險ｭ螳�*/
void Motor::setPwmPeriod(float hz){
    _p01.period(hz);
    _p10.period(hz);
    _p02.period(hz);
    _p20.period(hz);
    _p03.period(hz);
    _p30.period(hz);
}

/*繝｢繝ｼ繧ｿ繝ｼ蛻ｶ蠕｡*/
void Motor::setPower(float a,float b,float c){
    
    a = a / 100;
    b = b / 100;
    c = c / 100;
    
    if(a > 0) { //豁｣蝗櫁ｻ｢
        _p01 = a;
        _p10 = 0;
    } else if(a == 0) { //繝悶Ξ繝ｼ繧ｭ
        _p01 = 1;
        _p10 = 1;//0縺�1縺�縺ｨ諤昴≧
    } else { //雋�蝗櫁ｻ｢
        _p01 = 0;
        _p10 = -1*a;
    }
    if(b > 0) {
        _p02 = b;
        _p20 = 0;
    } else if(b == 0) {
        _p02 = 1;
        _p20 = 1;
    } else {
        _p02 = 0;
        _p20 = -1*b;
    }
    if(c > 0) {
        _p03 = c;
        _p30 = 0;
    } else if(c == 0) {
        _p03 = 1;
        _p30 = 1;
    } else {
        _p03 = 0;
        _p30 = -1*c;

    }
}

//*********************************************************************************/////////
///////繝｢繝ｼ繧ｿ繝ｼ蛻ｶ蠕｡ﾎｸ(degree)縺ｫ騾ｲ陦梧婿蜷�,power縺ｫPWM縺ｮ蛟､(0�ｽ�100),菫ｮ豁｣蛟､繧知od縺ｫ莉｣蜈･,蜿ｳ蝗櫁ｻ｢蝓ｺ貅�//////////
//********************************************************************************://///////
/*3霈ｪ逕ｨ*/
void Motor::omniWheels(int degree,int power,int mod){
    float motor[3];//繝｢繝ｼ繧ｿ繝ｼ逕ｨ螟画焚
    float Max[2];//譛�螟ｧ蛟､逕ｨ螟画焚
    
    if(power == 0){//繝代Ρ繝ｼ0縺ｮ縺ｨ縺�
        
        motor[0] = mod; //繝｢繝ｼ繧ｿ繝ｼ蜿ｳ
        motor[1] = mod; //繝｢繝ｼ繧ｿ繝ｼ蠕�
        motor[2] = mod; //繝｢繝ｼ繧ｿ繝ｼ蟾ｦ
    }
    else{ 
    
        motor[0] = sin((degree-60)*Pi/180) + (float)mod * 0.01; //繝｢繝ｼ繧ｿ繝ｼ蜿ｳ
        motor[1] = sin((degree-180)*Pi/180) + (float)mod* 0.01; //繝｢繝ｼ繧ｿ繝ｼ蠕�
        motor[2] = sin((degree-300)*Pi/180) + (float)mod* 0.01; //繝｢繝ｼ繧ｿ繝ｼ蟾ｦ
        
        if(motor[0]>1){
            motor[0] = 1;
        }
        else if(motor[0] < -1){
            motor[0] = -1;
        }
        if(motor[1]>1){
            motor[1] = 1;
        }
        else if(motor[1] < -1){
            motor[1] = -1;
        }
        if(motor[2]>1){
            motor[2] = 1;
        }
        else if(motor[2] < -1){
            motor[2] = -1;
        }
        
    
        if(fabs(motor[0]) >= fabs(motor[1])){ //繝｢繝ｼ繧ｿ繝ｼ繝代Ρ繝ｼ譛�螟ｧ蛟､險育ｮ�
            Max[0] = fabs(motor[0]);
        }
        else{
            Max[0] = fabs(motor[1]);
        }
        if(fabs(motor[2]) >= Max[0]){
            Max[1] = fabs(motor[2]);
        }
        else{
            Max[1] = Max[0];//譛�螟ｧ蛟､
        }
        
    
        motor[0] = (power*(motor[0]/Max[1]));//繝｢繝ｼ繧ｿ繝代Ρ繝ｼ譛�螟ｧ蛟､菫ｮ豁｣
        motor[1] = (power*(motor[1]/Max[1]));
        motor[2] = (power*(motor[2]/Max[1]));
    }
    
    setPower(motor[0],motor[1],motor[2]);
    
}

