#if !defined(LOOKUPRUNNER_H_)
#define LOOKUPRUNNER_H_


#include "ecrobot_interface.h"
#include "kernel.h"

#include "Direction.h"

#include "GyroSensor.h"
#include "Motor.h"


// 属性を保持するための構造体の定義
typedef struct LookUpRunner
{
	int forward;
	int turn;
	BOOL isInitialized;
	GyroSensor *gyroSensor;
	Motor *leftMotor;
	Motor *rightMotor;
	Motor *tailMotor;
	int time;//LookUpRunnerが実行された時からの時間
	int tail_angle;
	BOOL flag;
} LookUpRunner;

// 公開操作
void LookUpRunner_init(LookUpRunner* this);
BOOL LookUpRunner_run(LookUpRunner* this, DIRECTION direction);

#endif /*!defined(EA_37548F8E_C7BF_4044_9E50_5C184B895EEE__INCLUDED_)*/

