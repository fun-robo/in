/****************************************************
 *  LineTracer.h                                         
 *  Created on: 2012/05/05 8:31:07                      
 *  Implementation of the Class LineTracer       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_6FB55B53_C0F0_4250_B6B0_BC28A0A336D7__INCLUDED_)
#define EA_6FB55B53_C0F0_4250_B6B0_BC28A0A336D7__INCLUDED_

#include "ColorJudgement.h"
#include "BalanceRunner.h"
#include "LightSensor.h"
#include "Maimai.h"


// 属性を保持するための構造体の定義
typedef struct LineTracer
{
	ColorJudgement *colorJudgement;
	BalanceRunner *balanceRunner;
	LightSensor *lightSensor;
	Maimai *maimai;
	S32 diff[2];
	F32 integral;

	F32 KP;
	F32 KI;
	F32 KD;
  F32 TARGET;
  F32 TARGET_tail;
  F32 TARGET_tailHalf;
	U16 bright;
} LineTracer;

// 公開操作
void LineTracer_init(LineTracer* this);
void LineTracer_trace(LineTracer* this, int forword, int run_time);
void LineTracer_changePID(LineTracer* this, F32 p, F32 i, F32 d, F32 target);
F32 LineTracer_getTarget(LineTracer* this);
U16 LineTracer_getBright(LineTracer* this);
void LineTracer_trace_nonbalance(LineTracer* this, int forword, int run_time);
F32 get_TARGET_tail(LineTracer *this);

#endif /*!defined(EA_6FB55B53_C0F0_4250_B6B0_BC28A0A336D7__INCLUDED_)*/

