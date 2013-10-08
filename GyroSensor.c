/****************************************************
 *  GyroSensor.c                                         
 *  Created on: 2012/05/05 8:29:03                      
 *  Implementation of the Class GyroSensor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "GyroSensor.h"
#define GYRO_OFFSET  585



// 初期化する
void GyroSensor_init(GyroSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
	this->offset = GYRO_OFFSET;
}

unsigned int GyroSensor_getAngularVelocity(GyroSensor* this)
{
	return ecrobot_get_gyro_sensor(this->inputPort);
}

unsigned int GyroSensor_getOffset(GyroSensor* this)
{
	return this->offset;
} 

void GyroSensor_changeOffset (GyroSensor* this, unsigned int offset){
  this->offset = offset;
}
