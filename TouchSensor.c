/****************************************************
 *  TouchSensor.c                                         
 *  Created on: 2012/05/05 8:28:43                      
 *  Implementation of the Class TouchSensor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "TouchSensor.h"


// 初期化する
void TouchSensor_init(TouchSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
}

// 押下状態を得る
BOOL TouchSensor_isPressed(TouchSensor* this)
{
	return ecrobot_get_touch_sensor(this->inputPort);
} 

