#include "LookUpRunner.h"
#include "balancer.h" // 倒立振子制御用ヘッダファイル

#define LOW     30 // 低速
#define NORMAL  50 // 通常
#define HIGH    70 // 高速
#define BATT  8000 // バッテリー電圧



// 初期化する
void LookUpRunner_init(LookUpRunner* this)
{
	this->forward 	    = LOW;
	this->turn          = LOW;
	this->isInitialized = FALSE;
	this->time = 0;
	this->tail_angle = 90;
	this->flag = FALSE;
}

// 倒立走行を行う
BOOL LookUpRunner_run(LookUpRunner* this, DIRECTION direction)
{
	int turn;			// 方向を反映した旋回速度
	unsigned int gyro;		// ジャイロセンサ値
	unsigned int gyro_offset;	// ジャイロセンサオフセット値
	long motor_ang_l;		// 左モータ回転角度
	long motor_ang_r;		// 右モータ回転角度
	signed char pwm_l;		// 左モータPWM出力値
	signed char pwm_r;		// 右モータPWM出力値
	
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
	
	if(this->time < 10000/4)
	{
		this->time++;
	}
	
	if(!this->flag)
	{
		Motor_tailControl(this->tailMotor, this->tail_angle);
		
		if(this->time >= 1000/4)
		{
			if(this->time >= 2000/4)
			{
				Motor_rotate(this->leftMotor, 0);
				Motor_rotate(this->rightMotor, 5);
				
				if(this->tail_angle >= 70)
				{
					if(this->time%15 == 0) this->tail_angle--;
				}
				else if(this->tail_angle < 70)
				{
					this->forward = 0;
					this->flag = TRUE;
					this->time = 0;
				}
				return TRUE;
			}
			this->forward = -8;
		}
		else
		{
			this->forward = 0;
		}
	}
	else if(this->flag)
	{
		Motor_tailControl(this->tailMotor, this->tail_angle);
		
		if(this->time <= 5000/4)
		{
			Motor_rotate(this->leftMotor,30);
			Motor_rotate(this->rightMotor,30);
			return TRUE;
		}
		else if(this->time > 5000/4 && this->time <= 5500/4)
		{
			this->tail_angle = 104;
			Motor_rotate(this->leftMotor,-30);
			Motor_rotate(this->rightMotor,-30);
			return TRUE;
		}
		else if(this->time > 5500/4 && this->time <= 7000/4)
		{
			this->tail_angle = 0;
			Motor_tailControl(this->tailMotor, this->tail_angle);
			
			balance_init();		// 倒立振子制御初期化
	
			// モータの回転角度をリセットする
			Motor_resetAngle(this->leftMotor);
			Motor_resetAngle(this->rightMotor);
			
			return FALSE;
		}
	}
		
	// 指定された方向に合わせた旋回速度を設定する
	if(direction == LEFT)
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
	
	// 倒立振子制御API に渡すパラメータを取得する
	gyro_offset = GyroSensor_getOffset(this->gyroSensor);
	gyro = GyroSensor_getAngularVelocity(this->gyroSensor);
	motor_ang_l = Motor_getAngle(this->leftMotor);
	motor_ang_r = Motor_getAngle(this->rightMotor);
	
	// 倒立振子制御APIを呼び出し、倒立走行するための
	// 左右モータ出力値を得る
	balance_control(
		(float)this->forward,
		(float)turn,
		(float)gyro, (float)gyro_offset,
		(float)motor_ang_l, (float)motor_ang_r,
		BATT,
		(signed char*)&pwm_l, (signed char*)&pwm_r
	);
	
	// 左右モータに回転を指示する
	Motor_rotate(this->leftMotor,pwm_l);
	Motor_rotate(this->rightMotor,pwm_r*1.01);
	
	if(!this->flag)	return TRUE;
	else return FALSE;
} 

