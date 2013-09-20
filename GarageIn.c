
#include "Direction.h"
#include "GarageIn.h"

#define P_GAIN             2.5F /* 完全停止用モータ制御比例係数 */
#define PWM_ABS_MAX          60 /* 完全停止用モータ制御PWM絶対最大値 */
#define	TASK_CYCLE	4	/* タスクの周期（msec）*/
#define TAIL_ANGLE_STAND_UP 90  /* 完全停止時のしっぽ角度*/

// 非公開操作
static void GarageIn_tailcontrol(signed int angle);


// 初期化する
void GarageIn_init(GarageIn* this)
{
	this->runtime = 0; //停止するまでの走行時間(ms)
}


//ガレージインを行なう
void GarageIn_run(GarageIn* this)
{
	//しっぽを接地させる
	Motor_rotate(this->tailMotor, 80);

	//一定時間(runtime)直進後停止
	if(this->runtime < 1500){
		Motor_rotate(this->leftMotor ,-20);
		Motor_rotate(this->rightMotor,-20);
		this->runtime += 4;
	}else if(this->runtime < 3000){
		Motor_rotate(this->leftMotor ,40);
		Motor_rotate(this->rightMotor,40);
	}else{
		Motor_rotate(this->leftMotor , 0);
		Motor_rotate(this->rightMotor, 0);
	}
}


static void GarageIn_tailcontrol(signed int angle)
{
	float pwm = (float)(angle - nxt_motor_get_count(NXT_PORT_A))*P_GAIN; /* 比例制御 */
	/* PWM出力飽和処理 */
	if (pwm > PWM_ABS_MAX)
	{
		pwm = PWM_ABS_MAX;
	}
	else if (pwm < -PWM_ABS_MAX)
	{
		pwm = -PWM_ABS_MAX;
	}

	nxt_motor_set_speed(NXT_PORT_A, (signed char)pwm, 1);
}
