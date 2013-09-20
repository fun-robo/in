#include "GrayDetector.h"

void GrayDetector_init(GrayDetector* this, SENSOR_PORT_T inputPort) {
    int i;
	this->count = 0;
	this->run_time= 0;

    this->inputPort = inputPort;
    for (i = 0; i < QUEUE_SIZE; i++) {
        this->lightSensorValues[i] = 600;
    }
}

int GrayDetector_enqueue(GrayDetector* this) {
    int i;
    for (i = QUEUE_SIZE - 1; i > 0; i--) {
        this->lightSensorValues[i] = this->lightSensorValues[i-1];
		if (this->lightSensorValues[i] > 450 && this->lightSensorValues[i] < 600)
				this->count++;
    }
			this->count = 0;

	this->run_time+=4;
    this->lightSensorValues[0] = ecrobot_get_light_sensor(this->inputPort);
	return this->count;
}

int GrayDetector_calcAverage(GrayDetector* this) {
    int i;
    int sum;

    sum = 0;
    for (i = 0; i < QUEUE_SIZE; i++) {
        sum += this->lightSensorValues[i];
    }

    return sum / QUEUE_SIZE;
}

//int GrayDetector_calcDeviation(GrayDetector* this) {
//    return this->lightSensorValues[0] - GrayDetector_calcAverage(this);
//}
