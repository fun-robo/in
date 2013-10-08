/****************************************************
 *  BalanceRunner.h                                         
 *  Created on: 2012/05/05 8:34:02                      
 *  Implementation of the Class BalanceRunner       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_37548F8E_C7BF_4044_9E50_5C184B895EEE__INCLUDED_)
#define EA_37548F8E_C7BF_4044_9E50_5C184B895EEE__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"

#include "Direction.h"

#include "GyroSensor.h"
#include "Motor.h"


// 属性を保持するための構造体の定義
typedef struct BalanceRunner
{
	int forward;
	int turn;
	BOOL isInitialized;
	GyroSensor *gyroSensor;
	Motor *leftMotor;
	Motor *rightMotor;
} BalanceRunner;

// 公開操作
void BalanceRunner_init(BalanceRunner* this);
void BalanceRunner_run(BalanceRunner* this, int turn, int forword);
void NonBalanceRunner_run(BalanceRunner* this, int turn, int forword);

#endif /*!defined(EA_37548F8E_C7BF_4044_9E50_5C184B895EEE__INCLUDED_)*/

