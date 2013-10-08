#if !defined(SeeSae__INCLUDED_)
#define SeeSaw__INCLUDED_

#include "Motor.h"
#include "GyroSensor.h"
#include "LineTracer.h"
#include "Straight.h"

typedef struct SeeSaw
{
	GyroSensor *gyroSensor;
	LineTracer *lineTracer;
	Motor	   *rightMotor;
	Motor      *leftMotor;
	Straight   *straight;
	int run_time;
	int phase;
	long angle;
} SeeSaw;



void SeeSaw_init(SeeSaw *this);
BOOL SeeSaw_run(SeeSaw* this);


#endif /*!defined(EA_0311591B_68F8_4d9d_A572_FDE0A82543E8__INCLUDED_)*/
