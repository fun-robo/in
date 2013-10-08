#if !defined(INCLUDED_BASIC_H_)
#define INCLUDED_BASIC_H_

#include "LineTracer.h"
#include "DistMeasure.h"

typedef enum Basic_gate {
		BASIC_START, SLOPE_TOP, GATE_ONE, GATE_TWO, GATE_THREE, GATE_FOUR, BASIC_GOAL,
} Basic_gate;

typedef struct Basic
{
	LineTracer *lineTracer;
	DistMeasure *distMeasure;
	int run_time;
	int speed;
	int cur_phase;
	
} Basic;

void Basic_init(Basic *this);
void Basic_run(Basic *this);
int Basic_getCurPhase(Basic *this);
#endif
