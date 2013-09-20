#pragma once

#include "Motor.h"

typedef struct GarageIn
{
	int runtime; //停止するまでの走行時間
	Motor *leftMotor;
	Motor *rightMotor;
	Motor *tailMotor;
} GarageIn;

// 公開操作
void GarageIn_init(GarageIn* this);
void GarageIn_run(GarageIn* this);
