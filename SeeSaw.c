#include "SeeSaw.h"
#include "BalanceRunner.h"
#include "Motor.h"
#include "GyroSensor.h"
#include "ecrobot_interface.h"

#define OFFSET 585//604
#define ACCEL  605//624
#define BACK   566//585

//初期化する
void SeeSaw_init(SeeSaw* this)
{
	this->run_time = 0;
	this->phase = 0;
	this->angle = 0;
}

//シーソー走行をする
int SeeSaw_run(SeeSaw *this){
	switch(this->phase){
		//ライントレースで段差検知する、検知したら次
	case 0:
		LineTracer_trace(this->lineTracer, 20, 1);
		if(GyroSensor_getAngularVelocity(this->gyroSensor) > 700){	
			ecrobot_sound_tone(261, 100, 100);
			this->run_time = 0;
			this->phase = 1;
		}
		break;
		//ジャイロを狂わせてシーソーに上る、一定時間経ったら次
	case 1:
		Straight_run(this->straight , 30);
		if(this->run_time < 200){
			this->gyroSensor->offset = ACCEL;
		}else{
			this->gyroSensor->offset = OFFSET;
		}

		if(this->run_time > 200){
			ecrobot_sound_tone(261, 100, 100);
			this->run_time = 0;
			this->phase = 2;
			this->angle = Motor_getAngle(this->rightMotor);
			Straight_finish(this->straight);
		}
		break;
		//シーソーをがったんさせる、一定時間経ったら次
	case 2:
		Straight_run(this->straight , 30);
		if((Motor_getAngle(this->rightMotor) - (this->angle)) > 570){
			ecrobot_sound_tone(261, 100, 100);
			this->phase = 3;
			this->run_time = 0;
			this->angle = Motor_getAngle(this->rightMotor);
			Straight_finish(this->straight);
		}
		break;
	case 3://ジャイロを狂わせて後ろに戻る、一定時間で次
		Straight_run(this->straight , -25);
		if(this->run_time < 200){
			this->gyroSensor->offset = BACK;
		}else{
			this->gyroSensor->offset = OFFSET;
		}
		if(this->angle - (Motor_getAngle(this->rightMotor)) > 50){
			ecrobot_sound_tone(261, 100, 100);
			this->phase = 4;
			this->run_time = 0;
			this->angle = Motor_getAngle(this->rightMotor);
			Straight_finish(this->straight);
		}
		break;
		//ジャイロを狂わせて前に進む、一定時間で次
	case 4:
		Straight_run(this->straight , 40);
		if(this->run_time < 400){
			this->gyroSensor->offset = ACCEL;
		}else{
			this->gyroSensor->offset = OFFSET;
		}
		if(this->run_time > 410 && (Motor_getAngle(this->rightMotor) - (this->angle)) > 50){
			ecrobot_sound_tone(261, 100, 100);
			this->phase = 5;
			this->run_time = 0;
			Straight_finish(this->straight);
		}
		break;
		//シーソーから降りる
	case 5:
		Straight_run(this->straight , 50);
		if(this->run_time < 200){
			this->gyroSensor->offset = BACK;
		}else{
			this->gyroSensor->offset = OFFSET;
		}
		

		if(this->run_time > 40000){
			this->phase = 6;
			Straight_finish(this->straight);
		}
		break;
		//未実装、気にしなくて良いよ
	case 6:
		LineTracer_trace(this->lineTracer, 5, 1);
		break;
	}

	this->run_time+=4;
	return this->phase;

}



