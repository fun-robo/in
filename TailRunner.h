/****************************************************
 *  UI.h                                         
 *  Created on: 2012/05/05 8:28:46                      
 *  Implementation of the Class UI       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(TAIL__INCLUDED_)
#define TAIL__INCLUDED_

#include "Motor.h"
#include "LineTracer.h"
#include "Maimai.h"
#include "GyroSensor.h"
#include "BalanceRunner.h"

#define TAIL_ANGLE 70 /* 移動時の角度[度] */

// 属性を保持するための構造体の定義
typedef struct TailRunner
{
  Motor   *tailMotor;
  LineTracer  *lineTracer;
  GyroSensor *gyroSensor;
  BalanceRunner *balanceRunner;
  int runtime;
  char phase;
  char angle;
} TailRunner;

// 公開操作
void TailRunner_init(TailRunner* this);
void TailRunner_run(TailRunner* this, int forward, int turn);
void TailRunner_run_nonlinetrace(TailRunner* this, int turn, int forward);
void TailRunner_set_tailMotor(TailRunner* this);

#endif /*!defined(TAIL__INCLUDED_)*/

