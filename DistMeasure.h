#if !defined(INCLUDED_DISTMEASURE_H_)
#define INCLUDED_DISTMEASURE_H_

#include "Motor.h"

typedef struct DistMeasure
{
	Motor *rightMotor;
	int cur_distance;
}DistMeasure;

void DistMeasure_init(DistMeasure *this);
int DistMeasure_getDistance(DistMeasure *this);
#endif
