
#if !defined(Basic__INCLUDED_)
#define Basic__INCLUDED_

#include "GyroSensor.h"
#include "LineTracer.h"
#include "UI.h"

typedef struct Basic
{
	Motor *rightMotor;
	Motor *leftMotor;
	GyroSensor *gyroSensor;
	LineTracer *lineTracer;
	LightSensor *lightSensor;
	UI *ui;
	int run_time, speed;
	int light;
	int ave;
	int light_ave[125];
	int i;
	int j;

	//unsigned int angleR,angleL;

} Basic;

void Basic_init(Basic *this);
void Basic_run_in(Basic *this);
int Basic_GetAVE(Basic *this);
#endif

