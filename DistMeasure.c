#include "DistMeasure.h"

void DistMeasure_init(DistMeasure *this)
{
	this->cur_distance = 0;
}

int DistMeasure_getDistance(DistMeasure *this)
{
	this->cur_distance = Motor_getAngle(this->rightMotor);
	return this->cur_distance;
}
