/****************************************************
 *  LightSensor.h                                         
 *  Created on: 2012/05/05 8:28:55                      
 *  Implementation of the Class LightSensor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_02A836BB_DD21_423e_BB0D_ADCE6CCCBCD0__INCLUDED_)
#define EA_02A836BB_DD21_423e_BB0D_ADCE6CCCBCD0__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"


// 属性を保持するための構造体の定義
typedef struct LightSensor
{
	SENSOR_PORT_T inputPort;
	BOOL is_light;
} LightSensor;

// 公開操作
void LightSensor_init(LightSensor* this, SENSOR_PORT_T inputPort);
unsigned int LightSensor_getBrightness(LightSensor* this);
void LightSensor_switch(LightSensor* this);

#endif /*!defined(EA_02A836BB_DD21_423e_BB0D_ADCE6CCCBCD0__INCLUDED_)*/

