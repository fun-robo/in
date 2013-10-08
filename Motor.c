/****************************************************
 *  Motor.c                                         
 *  Created on: 2012/05/05 8:35:16                      
 *  Implementation of the Class Motor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "Motor.h"


// 初期化する
void Motor_init(Motor* this, MOTOR_PORT_T outputPort)
{
	this->outputPort = outputPort;
}

// 回転角度をリセットする
void Motor_resetAngle(Motor* this)
{
	return nxt_motor_set_count(this->outputPort, 0);
}

// 回転角度を得る
long Motor_getAngle(Motor* this)
{
	return nxt_motor_get_count(this->outputPort);
}

// 回転させる
void Motor_rotate(Motor* this, int pwm)
{
	nxt_motor_set_speed(this->outputPort, pwm, 1);
} 

// 尻尾を動かす
void Motor_tailControl(Motor* this, int angle)
{
	float pwm = (float)(angle - nxt_motor_get_count(this->outputPort))*P_GAIN; /* 比例制御 */
	/* PWM出力飽和処理 */
	if (pwm > PWM_ABS_MAX)
	{
		pwm = PWM_ABS_MAX;
	}
	else if (pwm < -PWM_ABS_MAX)
	{
		pwm = -PWM_ABS_MAX;
	}

	nxt_motor_set_speed(this->outputPort, (signed char)pwm, 1);
}
