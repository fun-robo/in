/****************************************************
 *  LineTracer.c                                         
 *  Created on: 2012/05/05 8:31:07                      
 *  Implementation of the Class LineTracer       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "LineTracer.h"
#include "Direction.h"
#include "Color.h"
#include "Maimai.h"

#define LOW     30 // 低速
#define NORMAL  50 // 通常
#define HIGH    70 // 高速

#define DELTA_T 0.004

// 非公開操作
static F32 pid(U16 sensor_val, U16 target_val,LineTracer *this);

// 初期化する
void LineTracer_init(LineTracer* this)
{
	// 何も行わない
	this->diff[0] = 0;
	this->diff[1] = 0;
	this->integral = 0;

	if(this->runMode->run_mode){
		this->KP = 0.6;//試走会0.6;//0.66;//0.6;//0.66;
		this->KI = 0.08;//試走会0.08;//0.07;//0.08;//0.07;
		this->KD = 0.124;//試走会0.12;//0.1;//0.07;
	} else{
		this->KP = 0.8;
		this->KI = 0.07;
		this->KD = 0.06;
	}
	this->TARGET = 120;
	this->MAIMAI_TARGET = 0;
	this->bright = 0;
}

// ライントレースを行う
void LineTracer_trace(LineTracer* this, int forword, int run_time)
{
	int pid_turn;
	if(this->runMode->run_mode){
		this->bright = Maimai_calc(this->maimai);
		pid_turn = run_time * (int)pid(this->bright, this->MAIMAI_TARGET, this);
	}
	else {
		this->bright = LightSensor_getBrightness(this->lightSensor);
		run_time = (-1) * run_time;
		pid_turn = run_time * (int)pid(this->bright, this->TARGET, this);
	}

	//倒立走行を行う
	BalanceRunner_run(this->balanceRunner, pid_turn, forword);
}

//pid係数及びtargetの値を変更する
void LineTracer_changePID(LineTracer* this, F32 p, F32 i, F32 d, F32 target)
{
	this->KD = d; //デフォルト：0.7
	this->KI = i; //デフォルト：0.06
	this->KP = p; //デフォルト：0.05
	this->TARGET = target; //デフォルト：580.0
}

F32 LineTracer_getTarget(LineTracer* this){
	return this->TARGET;
} 

static F32 pid(U16 sensor_val, U16 target_val,LineTracer *this)
{
	F32 p,i,d;

	this->diff[0] = this->diff[1];
	this->diff[1] = sensor_val - target_val;
	this->integral += (this->diff[1] + this->diff[0]) / 2.0 * DELTA_T;

	p = this->KP *this->diff[1];
	i = this->KI *this->integral;
	d = this->KD *(this->diff[1] - this->diff[0]) / DELTA_T;

	if(p+i+d > 80)		return 80;
	if(p+i+d < -80)	return -80;


	return (p + i + d);
}

U16 LineTracer_getBright(LineTracer *this)
{
	return this->bright;
}

F32 get_TARGET_tail(LineTracer *this){
	return this->TARGET_tail;
}

void LineTracer_trace_nonbalance(LineTracer* this, int forword, int run_time)
{
	// 走行体の向きを計算する
	this->bright = Maimai_calc(this->maimai);

	int pid_turn = run_time * (int)pid(this->bright, this->TARGET, this);

	NonBalanceRunner_run(this->balanceRunner, pid_turn, forword);

}

U16 LineTracer_getMaimaiTarget(LineTracer* this)
{
	return this->MAIMAI_TARGET;
}
