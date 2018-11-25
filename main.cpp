#include "mbed.h"
#include "BNO055.h"
#include "Ping.h"
#include "Motor.h"
#include "Ballsensor.h"
#include "Linesensor.h"

//TerminalDisplay(TeraTerm)
Serial pc(SERIAL_TX, SERIAL_RX);

//UltraSonicSensor
Ping uss_left(PA_0);
Ping uss_right(PB_13);

//BallSensor
Ballsensor ball(A3, A2);

//LineSensor
Linesensor line(A1);

//Motor
Motor motor(PA_10, PB_3, PB_5, PB_4, PB_10, PA_8);

//Timer
Timer time1;

//GyroSensor
I2C i2c(D14, D15);
BNO055 imu(i2c, PC_8);
BNO055_ID_INF_TypeDef bno055_id_inf;
BNO055_EULER_TypeDef euler_angles;

//HoldCheckSensor
DigitalIn hold_check(PC_3);

//ToggleSwitch
DigitalIn sw_start(PD_2); //program start switch
DigitalIn sw_reset(PC_11); //gyro sensor reset switch
DigitalIn swdebug(PC_10); //reserve switch(non connect)
DigitalIn swkick(PC_12); //reserve switch(non connect)

//declear prototype (function list)
const float Pi = 3.1415;
int balldeg(int Deg, int Dis) {
	int ball = Deg;
	int Godeg;
	if (ball >= -45 && ball <= 45) { //ボールが前にあるとき
		return (2 * ball);
	} else if ((ball <= -150) && (ball >= 150)) {
		if (ball >= 0) {
			Godeg = ball + 90;
			return (Godeg);
		} else {
			Godeg = ball - 90;
			return (Godeg);
		}
	} else {
		if (Dis <= 400) { //ボールとの距離が近いとき
			if (ball >= 0) {
				Godeg = ball
						+ (180 - 180 / Pi * asin((float) Dis / (float) 400));
			} else {
				Godeg = ball
						- (180 - 180 / Pi * asin((float) Dis / (float) 400));

			}
		} else {
			if (ball >= 0) {
				Godeg = ball + 180 / Pi * asin((float) 400 / (float) Dis); //数値は半径
			} else {
				Godeg = ball - 180 / Pi * asin((float) 400 / (float) Dis);
			}
		}
		return (Godeg);
	}
}

/*****************************************************************/
/**********************main function******************************/
/*****************************************************************/

int main() {

//**************************************************************//
////////////////////////initialize setting////////////////////////
//**************************************************************//

	/*motor pwm frequency set*/
	motor.setPwmPeriod(0.03);

	/*change Mode IMU,COMPASS,M4G,NDOF_FMC_OFF,NDOF*/
	imu.reset();
	imu.change_fusion_mode(MODE_IMU);
	wait_ms(100);
	imu.get_Euler_Angles(&euler_angles);
	int init_degree = euler_angles.h;
	motor.omniWheels(0, 0, 0);

	while (1) {
//***************************************************************//
////////////////Play mode(you can write this statement)////////////
//***************************************************************//
		while (sw_start == 1) {
			imu.get_Euler_Angles(&euler_angles);
			static int A = 0;
			A = euler_angles.h;
			if (A >= 180) {
				A -= 360;
			}
			if (A >= 50) {
				A = 50;
			} else if (A <= -50) {
				A = -50;
			}

			if (line.direction() != -999) {
				motor.omniWheels(0,0,0);
				wait_ms(200);
				int B = line.direction() - 180;
				for(int i = 1; i<= 200;i++){
					motor.omniWheels(B,50,0);
					wait_ms(1);
				}
			} else {

				if (ball.degree() == -999) {
					motor.omniWheels(0, 0, -0.5*A);
				} else {
					motor.omniWheels(balldeg(ball.degree(), ball.distance()),
							100, -0.5 * A);
				}
			}
		}

//***************************************************************//
////////////////////////Gyro reset mode////////////////////////////
//***************************************************************//
		if (sw_reset == 1) {
			imu.reset();
			wait_ms(100);
			imu.get_Euler_Angles(&euler_angles);
			init_degree = euler_angles.h;
		}
		motor.omniWheels(0, 0, 0);

//***************************************************************//
//////////////////////////debug mode///////////////////////////////
//***************************************************************//
		if (pc.readable() == 1) {
			if (pc.getc() == 'd') {
				//if 'd' is pressed,debug mode will start.
				while (1) {
					if (pc.readable() == 1) {
						if (pc.getc() == 'r') { //if 'r' is pressed,debug mode will be end.
							break;
						}
					}
					imu.get_Euler_Angles(&euler_angles);
					pc.printf("Gyro   degree: %d \r\n", (int) euler_angles.h);
					pc.printf("Ball   degree: %d \r\n", ball.degree());
					pc.printf("Ball distance: %d \r\n", ball.distance());
					pc.printf("Line   sensor: %d \r\n", line.direction());
					pc.printf("Hold   sensor: %d \r\n", hold_check.read());
					uss_left.Send();
					uss_right.Send();
					wait_ms(40);
					pc.printf("USS      left: %d cm\r\n", uss_left.Read_cm());
					pc.printf("USS     right: %d cm\r\n", uss_right.Read_cm());

					wait_ms(40);
					pc.printf("\f");
				}
			}
		}

		/**********************end main function**************************/
	}
	return 0;
}

