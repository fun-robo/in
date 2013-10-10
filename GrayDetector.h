#if !defined(__GRAY_DETECTOR_H__)
#define __GRAY_DETECTOR_H__

#include "ecrobot_interface.h"
#include "kernel.h"
#include "Maimai.h"
#include "LineTracer.h"
#include "UI.h"

typedef struct GrayDetector {
  LineTracer* lineTracer;
  BOOL detectFlag;
  UI* ui;
} GrayDetector;

void GrayDetector_init(GrayDetector* this);
BOOL GrayDetector_is_detected(GrayDetector* this);


#endif
