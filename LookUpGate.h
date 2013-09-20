#if !defined(LOOKUPGATE_H_)
#define LOOKUPGATE_H_

#include "ecrobot_interface.h"
#include "kernel.h"

#include "ColorJudgement.h"
#include "LineTracer.h"
#include "LookUpRunner.h"
#include "SonarSensor.h"

// 属性を保持するための構造体の定義
typedef struct LookUpGate
{
	ColorJudgement *colorJudgement;
	LineTracer *lineTracer;
	LookUpRunner *lookUpRunner;
	SonarSensor *sonarSensor;
	BOOL flag;
} LookUpGate;

// 公開操作
void LookUpGate_init(LookUpGate* this);
BOOL LookUpGate_start(LookUpGate* this);

#endif
