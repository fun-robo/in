#if !defined(__GRAY_DETECTOR_H__)
#define __GRAY_DETECTOR_H__

#include "ecrobot_interface.h"
#include "kernel.h"

#define QUEUE_SIZE 100

typedef struct GrayDetector {
    SENSOR_PORT_T inputPort;
    int lightSensorValues[QUEUE_SIZE];
	int count,run_time;
} GrayDetector;

void GrayDetector_init(GrayDetector* this, SENSOR_PORT_T inputPort);
int GrayDetector_enqueue(GrayDetector* this);
int GrayDetector_calcAverage(GrayDetector* this);
//int GrayDetector_calcDeviation(GrayDetector* this);

#endif
