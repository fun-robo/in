/****************************************************
 *  BalanceRunner.c                                         
 *  Created on: 2012/05/05 8:34:02                      
 *  Implementation of the Class BalanceRunner       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "BalanceRunner.h"
#include "balancer.h" // 倒立振子制御用ヘッダファイル

#define EXLOW   20 // 低速
#define LOW     30 // 低速
#define NORMAL  50 // 通常
#define HIGH    70 // 高速
#define EXHIGH  100//超高速
#define BATT  8000 // バッテリー電圧



// 初期化する
void BalanceRunner_init(BalanceRunner* this)
{
	this->forward 	    = EXHIGH;
	this->turn          = LOW;
	this->isInitialized = FALSE;
}

// 倒立走行を行う
void BalanceRunner_run(BalanceRunner* this, int turn, int forward)
{
	//int turn;			// 方向を反映した旋回速度
	unsigned int gyro;		// ジャイロセンサ値
	unsigned int gyro_offset;	// ジャイロセンサオフセット値
	long motor_ang_l;		// 左モータ回転角度
	long motor_ang_r;		// 右モータ回転角度
	signed char pwm_l;		// 左モータPWM出力値
	signed char pwm_r;		// 右モータPWM出力値
	//signed spin_count_r;
	//signed spin_count_l;
	
	// 最初だけ、倒立振子制御を初期化とモータエンコーダのリセットを行う
	if(! this->isInitialized)
	{
		balance_init();		// 倒立振子制御初期化
	
		// モータの回転角度をリセットする
		Motor_resetAngle(this->leftMotor);
		Motor_resetAngle(this->rightMotor);
	
		// 初期化済にする
		this->isInitialized = TRUE;
	}
		
	// 指定された方向に合わせた旋回速度を設定する
	/*if(direction == LEFT)
	{
		turn = this->turn * (-1);
	}
	else if(direction == RIGHT)
	{
		turn = this->turn;
	}
	else
	{
		turn = 0;
	}
	*/
	// 倒立振子制御API に渡すパラメータを取得する
	gyro_offset = GyroSensor_getOffset(this->gyroSensor);
	gyro = GyroSensor_getAngularVelocity(this->gyroSensor);
	motor_ang_l = Motor_getAngle(this->leftMotor);
	motor_ang_r = Motor_getAngle(this->rightMotor);
	
	// 倒立振子制御APIを呼び出し、倒立走行するための
	// 左右モータ出力値を得る
	balance_control(
		(float)forward,
		(float)turn,
		(float)gyro, (float)gyro_offset,
		(float)motor_ang_l, (float)motor_ang_r,
		BATT,
		(signed char*)&pwm_l, (signed char*)&pwm_r
	);
	
	//if(turn != 0){
		// 左右モータに回転を指示する
		Motor_rotate(this->leftMotor,pwm_l);
		Motor_rotate(this->rightMotor,pwm_r);
	/*}else{
		
		if(motor_ang_l < motor_ang_r){
			Motor_rotate(this->leftMotor,pwm_l);
			Motor_rotate(this->rightMotor,pwm_r);
		}else if(motor_ang_l > motor_ang_r){
			Motor_rotate(this->leftMotor,pwm_l);
			Motor_rotate(this->rightMotor,pwm_r);
		}else{
			Motor_rotate(this->leftMotor,pwm_l);
			Motor_rotate(this->rightMotor,pwm_r);
		}
		
	}
	*/
}

void NonBalanceRunner_run(BalanceRunner* this, int turn, int forward)
{
	signed char pwm_l;		// 左モータPWM出力値
	signed char pwm_r;		// 右モータPWM出力値


	// 最初だけ、倒立振子制御を初期化とモータエンコーダのリセットを行う
	if(! this->isInitialized)
	{

		// モータの回転角度をリセットする
		Motor_resetAngle(this->leftMotor);
		Motor_resetAngle(this->rightMotor);

		// 初期化済にする
		this->isInitialized = TRUE;
	}

	pwm_l = turn / 2 + forward;
	pwm_r = -1 * turn / 2 + forward;

	Motor_rotate(this->leftMotor,pwm_l);
	Motor_rotate(this->rightMotor,pwm_r);
}
