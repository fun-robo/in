#if !defined(LineReturn__INCLUDED_)
#define LineReturn__INCLUDED_


#include "BalanceRunner.h"
#include "LineTracer.h"
#include "LightSensor.h"



typedef struct LineReturn
{
	int run_time;
	int phase;
	LightSensor *lightSensor;
	BalanceRunner *balanceRunner;
	LineTracer *lineTracer;
} LineReturn;

void LineReturn_init(LineReturn *this);
int LineReturn_run(LineReturn *this);

#endif /*!defined(EA_0311591B_68F8_4d9d_A572_FDE0A82543E8__INCLUDED_)*/
