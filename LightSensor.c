/****************************************************
*  LightSensor.c                                         
*  Created on: 2012/05/05 8:28:55                      
*  Implementation of the Class LightSensor       
*  Original author: hiroyuki.watanabe                     
****************************************************/

#include "LightSensor.h"


void LightSensor_init(LightSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
	this->is_light = true;
}

// 輝度を得る
unsigned int LightSensor_getBrightness(LightSensor* this)
{
	return ecrobot_get_light_sensor(this->inputPort);
}

void LightSensor_switch(LightSensor* this){
	if(!this->is_light){
		ecrobot_set_light_sensor_active(this->inputPort);
		this->is_light = true;
	}else{
		ecrobot_set_light_sensor_inactive(this->inputPort);
		this->is_light = false;
	}
}