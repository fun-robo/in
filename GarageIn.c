#include "GarageIn.h"

// 初期化する
void GarageIn_init(GarageIn* this)
{
	this->runtime = 0; //停止するまでの走行時間(ms)
	this->phase = 0;
	this->rightAngle = 0;
}


//ガレージインを行なう
void GarageIn_run(GarageIn* this)
{
	long angleDiffR = Motor_getAngle(this->rightMotor) - this->rightAngle;
	switch(this->phase){
		case 0:
			TailRunner_run(this->tailRunner, 20, 1);
			if(this->runtime > 15000){
				this->phase = 1;
				this->runtime = 0;
				ecrobot_sound_tone(1000, 100, 100);
				TailRunner_changeTailAngle(this->tailRunner, 85);
			}
			this->runtime += 4;
			break;
		case 1:
			TailRunner_run(this->tailRunner, -20, 0);
			if(this->runtime > 1000){
				this->phase = 2;
				this->runtime = 0;
				LineTracer_changePID(this->lineTracer, 0.67, 0.1, 0.16, this->lineTracer->TARGET_tailHalf);
				this->rightAngle = Motor_getAngle(this->rightMotor);
			}
			this->runtime += 4;
			break;
		case 2:
			TailRunner_run(this->tailRunner, 40, 1);
			if(angleDiffR > 1200){
				this->phase = 3;
				this->runtime = 0;
				ecrobot_sound_tone(1000, 100, 100);
			}
			this->runtime += 4;
			break;
		case 3:
			TailRunner_run(this->tailRunner, 40, 1);
			if(GrayDetector_is_detected(this->grayDetector)){
				ecrobot_sound_tone(1500, 100, 100);
				this->phase = 4;
				this->runtime = 0;
				this->rightAngle = Motor_getAngle(this->rightMotor);
			}
			this->runtime += 4;
			break;
		case 4:
			if(angleDiffR > 200){
				TailRunner_run(this->tailRunner, 0, 0);
			}else{
				TailRunner_run(this->tailRunner, 40, 0);
			}
			this->runtime += 4;
			break;
	}
}
