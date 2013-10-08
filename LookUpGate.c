#include "LookUpGate.h"
#include "TailRunner.h"
#include "BalanceRunner.h"
#include "Motor.h"

// 初期化する
void LookUpGate_init(LookUpGate* this)
{
	this->flag = FALSE;
	this->phase = 0;
	this->runtime = 0;
	this->turn = 0;
	this->rightAngle = 0;
	this->leftAngle = 0;
}

BOOL LookUpGate_run(LookUpGate* this)
{
	long angleDiffR = Motor_getAngle(this->rightMotor) - this->rightAngle;
	long angleDiffL = Motor_getAngle(this->leftMotor) - this->leftAngle;
	switch(this->phase){
		case 0:
			TailRunner_run(this->tailRunner, 20, 1);
			if(SonarSensor_sonarAlert(this->sonarSensor, 25) == 1){
				this->phase = 1;
				this->rightAngle = Motor_getAngle(this->rightMotor);
				this->leftAngle = Motor_getAngle(this->leftMotor);
				ecrobot_sound_tone(600, 100, 100);
			}
			break;
		case 1:
			TailRunner_run(this->tailRunner, 20, 1);
			if(this->runtime > 6000){
				this->phase = 2;
				this->runtime = 0;
			}
			this->runtime += 4;
			break;
		case 2:
			TailRunner_run(this->tailRunner, 0, 0);
			if(this->runtime > 2000){
				this->phase = 8;
				this->runtime = 0;
				this->turn = (int)(((angleDiffR - angleDiffL) * 20)/ (angleDiffR + angleDiffL));
			}
			this->runtime += 4;
			break;
		/*case 3:
			if(angleDiff*-1 < 226){
				NonBalanceRunner_run(this->balanceRunner, 30, 0);
			}else if(angleDiff*-1 < 256){
				NonBalanceRunner_run(this->balanceRunner, 0, 50);
			}else if(angleDiff*-1 < 480){
				NonBalanceRunner_run(this->balanceRunner, 30, 0);
			}
				else{
				this->phase = 4;
				this->runtime = 0;
			}
			this->runtime += 4;
			break;
		case 4:
			TailRunner_run(this->tailRunner, 20, 1);
			if(this->runtime > 6000){
				this->phase = 5;
				this->runtime = 0;
				this->rightAngle = Motor_getAngle(this->rightMotor);
				this->leftAngle = Motor_getAngle(this->leftMotor);
			}
			this->runtime += 4;
			break;
		case 5:
			if(angleDiff < 450){
				NonBalanceRunner_run(this->balanceRunner, 30, 0);
			}else if(angleDiff < 256){
				NonBalanceRunner_run(this->balanceRunner, 0, 10);
			}else if(angleDiff < 480){
				NonBalanceRunner_run(this->balanceRunner, 30, 0);
			}
				else{
				this->phase = 6;
				this->runtime = 0;
			}
			this->runtime += 4;
			break;
		case 6:
			TailRunner_run(this->tailRunner, 20, 1);
			if(this->runtime > 6000){
				this->phase = 7;
				this->runtime = 0;
			}
			this->runtime += 4;
			this->flag = TRUE;
			break;*/
		case 8:
			TailRunner_run_nonlinetrace(this->tailRunner, this->turn * 2, -20);
			if(angleDiffL < 0 && angleDiffR < 0){
				this->phase = 9;
				this->runtime = 0;
				this->flag = TRUE;
			}
			if(angleDiffR < 0 && angleDiffR > -10){
				ecrobot_sound_tone(300, 100, 100);
			}
			if(angleDiffL < 0 && angleDiffL > -10){
				ecrobot_sound_tone(800, 100, 100);
			}
			this->runtime += 4;
			break;
		default:
			TailRunner_run(this->tailRunner, 0, 0);
			break;

	}

	return this->flag;
}
