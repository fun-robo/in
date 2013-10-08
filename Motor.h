/****************************************************
 *  Motor.h                                         
 *  Created on: 2012/05/05 8:35:16                      
 *  Implementation of the Class Motor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_9B5D9C46_B371_4c1c_8F33_BB949D133BB3__INCLUDED_)
#define EA_9B5D9C46_B371_4c1c_8F33_BB949D133BB3__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"

#define P_GAIN             2.5F /* 完全停止用モータ制御比例係数 */
#define PWM_ABS_MAX          60 /* 完全停止用モータ制御PWM絶対最大値 */

// 属性を保持するための構造体の定義
typedef struct Motor
{
	MOTOR_PORT_T outputPort;
} Motor;

// 公開操作
void Motor_init(Motor* this, MOTOR_PORT_T outputPort);
void Motor_resetAngle(Motor* this);
long Motor_getAngle(Motor* this);
void Motor_rotate(Motor* this, int pwm);
void Motor_tailControl(Motor* this, int angle);

#endif /*!defined(EA_9B5D9C46_B371_4c1c_8F33_BB949D133BB3__INCLUDED_)*/

