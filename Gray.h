#if !defined(Gray__INCLUDED_)
#define Gray__INCLUDED_

#include "BalanceRunner.h"
#include "Motor.h"
#include "GyroSensor.h"
#include "LineTracer.h"
//#include "ScenarioTracer.h"

typedef struct Gray
{
	LightSensor *lightSensor;
	int bright[25];
	short count;
} Gray;

void Gray_init(Gray *this);
int Gray_look(Gray* this);


#endif /*!defined(EA_0311591B_68F8_4d9d_A572_FDE0A82543E8__INCLUDED_)*/
