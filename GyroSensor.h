/****************************************************
 *  GyroSensor.h                                         
 *  Created on: 2012/05/05 8:29:03                      
 *  Implementation of the Class GyroSensor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_D4AC2211_042D_45c0_A519_246C51749AF9__INCLUDED_)
#define EA_D4AC2211_042D_45c0_A519_246C51749AF9__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"


// 属性を保持するための構造体の定義
typedef struct GyroSensor
{
	unsigned int offset;
	SENSOR_PORT_T inputPort;
} GyroSensor;

// 公開操作
void GyroSensor_init(GyroSensor* this, SENSOR_PORT_T inputPort);
unsigned int GyroSensor_getAngularVelocity(GyroSensor* this);
unsigned int GyroSensor_getOffset(GyroSensor* this);
void GyroSensor_changeOffset(GyroSensor* this, unsigned int offset);

#endif /*!defined(EA_D4AC2211_042D_45c0_A519_246C51749AF9__INCLUDED_)*/

