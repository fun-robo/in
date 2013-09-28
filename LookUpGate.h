#if !defined(LOOKUPGATE_H_)
#define LOOKUPGATE_H_

#include "ecrobot_interface.h"
#include "kernel.h"

#include "TailRunner.h"
#include "SonarSensor.h"
#include "BalanceRunner.h"

// 属性を保持するための構造体の定義
typedef struct LookUpGate
{
	TailRunner *tailRunner;
	SonarSensor *sonarSensor;
  BalanceRunner *balanceRunner;
  Motor *rightMotor;
  Motor *leftMotor;
	BOOL flag;
  char phase;
  int runtime;
  long rightAngle;
  long leftAngle;
} LookUpGate;

// 公開操作
void LookUpGate_init(LookUpGate* this);
BOOL LookUpGate_run(LookUpGate* this);

#endif
