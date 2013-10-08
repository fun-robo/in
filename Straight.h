#if !defined(Straight__INCLUDED_)
#define Straight__INCLUDED_

#include "BalanceRunner.h"
#include "Motor.h"
#include "GyroSensor.h"

typedef struct Straight
{
	BalanceRunner *balanceRunner;
	Motor		  *rightMotor;
	Motor		  *leftMotor;
	GyroSensor	  *gyroSensor;
	BOOL		  finish_flag;
	long		  r_motor_angle;
	long		  l_motor_angle;
} Straight;

void Straight_init(Straight *this);
void Straight_run(Straight *this, int forword);
void Straight_finish(Straight *this);

#endif
