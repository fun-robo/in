#include "LookUpGate.h"
#include "Direction.h"
#include "Color.h"

// 初期化する
void LookUpGate_init(LookUpGate* this)
{
	this->flag = FALSE;
}

BOOL LookUpGate_start(LookUpGate* this)
{
	if(SonarSensor_sonarAlert(this->sonarSensor, 30) == 1){

	}
	//BOOL returnFlag = TRUE;
	//
	//if(this->flag || SonarSensor_sonarAlert(this->sonarSensor, 15) == 1)
	//{
	//	this->flag = LookUpRunner_run(this->lookUpRunner, STRAIGHT);
	//	returnFlag = this->flag;
	//}
	//else
	//{
	//	LineTracer_trace(this->lineTracer, 30);
	//}
	//return returnFlag;
	return false;
}
