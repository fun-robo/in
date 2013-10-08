#if !defined(MAIMAI_H_)
#define MAIMAI_H_

#include "LightSensor.h"

#define NUM 8

// 属性を保持するための構造体の定義
typedef struct Maimai
{
	LightSensor *lightSensor;
	U16 light_value[NUM];
	int index;
} Maimai;

// 公開操作
void Maimai_init(Maimai* this);
void Maimai_store(Maimai* this, int run_time);
U16 Maimai_calc(Maimai* this);

#endif /*!defined(EA_6FB55B53_C0F0_4250_B6B0_BC28A0A336D7__INCLUDED_)*/
