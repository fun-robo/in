#include "Basic.h"
#include<stdlib.h>

void Basic_init(Basic *this)
{
	this->run_time = 0;
	this->speed = 100;
	this->light = LightSensor_getBrightness(this->lightSensor);
	this->i = 0;
	this->ave = 0;
	this->j = 0;
	for(this->i=0 ; this->i<125; this->i++){
		this->light_ave[this->i] = 0;//ジャイロセンサーの値の平均を取るための250の配列（1秒分）
	}
}

int Basic_GetAVE(Basic *this)
{
	int sum = 0;
	if(LightSensor_getBrightness(this->lightSensor) > 150)
		this->light_ave[this->i] = LightSensor_getBrightness(this->lightSensor);
	for(this->j = 0; this->j < 125; this->j++)	sum += this->light_ave[this->j];
	
	if(this->i == 125)	this->i = 0;
	else			this->i++;
	
	return sum/125;
}

void Basic_run_in(Basic *this)
{
	////this->ave = Basic_GetAVE(this);
	//if(this->run_time == 14000){
	//	LineTracer_changePID(this->lineTracer, 0.8, 0.065, 0.085, this->ui->target[1]);
	//}
	//if(this->run_time > 22000){
	//	LineTracer_changePID(this->lineTracer, 0.8, 0.065, 0.085, this->ui->target[0]);
	//}
	//LineTracer_trace(this->lineTracer, this->speed);

	//this->run_time+=4;
}
