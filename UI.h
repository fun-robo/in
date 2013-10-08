/****************************************************
 *  UI.h                                         
 *  Created on: 2012/05/05 8:28:46                      
 *  Implementation of the Class UI       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_FB3DF40C_CBF0_454a_9BA8_39674A045269__INCLUDED_)
#define EA_FB3DF40C_CBF0_454a_9BA8_39674A045269__INCLUDED_

#include "TouchSensor.h"
#include "Motor.h"
#include "LightSensor.h"
#include "SonarSensor.h"
#include "LineTracer.h"
#include "Maimai.h"


#define TAIL_ANGLE_STAND_UP 110//103/* 完全停止時の角度[度] */
#define TAIL_ANGLE_DRIVE      3 /* バランス走行時の角度[度] */
#define CMD_START            '1'/* リモートスタートコマンド(変更禁止) */

// 属性を保持するための構造体の定義
typedef struct UI
{
	TouchSensor *touchSensor;
	Motor		*tailMotor;
	LightSensor *lightSensor;
	SonarSensor *sonarSensor;
	LineTracer  *lineTracer;
	Maimai		*maimai;
	BOOL run_mode;
	char rx_buf[BT_MAX_RX_BUF_SIZE];
} UI;

// 公開操作
void UI_init(UI* this);
void UI_waitStart(UI* this);
BOOL UI_isEmergency(UI *this);

#endif /*!defined(EA_FB3DF40C_CBF0_454a_9BA8_39674A045269__INCLUDED_)*/

