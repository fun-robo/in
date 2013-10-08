/****************************************************
 *  TouchSensor.h                                         
 *  Created on: 2012/05/05 8:28:43                      
 *  Implementation of the Class TouchSensor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_6012785F_E7A6_4a38_9143_89EE66F593B1__INCLUDED_)
#define EA_6012785F_E7A6_4a38_9143_89EE66F593B1__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"


// 属性を保持するための構造体の定義
typedef struct TouchSensor
{
	SENSOR_PORT_T inputPort;
} TouchSensor;

// 公開操作
void TouchSensor_init(TouchSensor* this, SENSOR_PORT_T inputPort);
BOOL TouchSensor_isPressed(TouchSensor* this);

#endif /*!defined(EA_6012785F_E7A6_4a38_9143_89EE66F593B1__INCLUDED_)*/

