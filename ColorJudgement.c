/****************************************************
 *  ColorJudgement.c                                         
 *  Created on: 2012/05/05 13:52:39                      
 *  Implementation of the Class ColorJudgement       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "ColorJudgement.h"
#define LIGHT_BLACK	560	// 黒色の光センサ値


// 初期化する
void ColorJudgement_init(ColorJudgement* this)
{
	this->threshold = LIGHT_BLACK;
}

// 路面の色を判定する
COLOR ColorJudgement_judgeColor(ColorJudgement* this)
{
	// 光センサからの取得値を見て
	// 黒以上であれば「黒」を、
	// そうでなければ「黒以外」を返す
	if(LightSensor_getBrightness(this->lightSensor) >= LIGHT_BLACK)
	{
		return  BLACK;
	}
	else
	{
		return OTHER;
	}
} 

