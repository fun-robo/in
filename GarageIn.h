#if !defined(GARAGEIN_H_)
#define GARAGEIN_H_

#include "TailRunner.h"
#include "GrayDetector.h"
#include "LineTracer.h"
#include "Motor.h"

typedef struct GarageIn
{
  TailRunner* tailRunner;
  GrayDetector* grayDetector;
  LineTracer* lineTracer;
  Motor* rightMotor;
	int runtime; //停止するまでの走行時間
  char phase;
  long rightAngle;
} GarageIn;

// 公開操作
void GarageIn_init(GarageIn* this);
void GarageIn_run(GarageIn* this);

#endif /*!defined(GARAGEIN_H_)*/
