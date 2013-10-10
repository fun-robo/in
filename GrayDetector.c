#include "GrayDetector.h"

void GrayDetector_init(GrayDetector* this) {
    this->detectFlag = FALSE;
}

//尻尾が85のときのみ
BOOL GrayDetector_is_detected(GrayDetector* this){
    if(LineTracer_getBright(this->lineTracer) < this->ui->blackTailHalf+6){
        this->detectFlag = TRUE;
    }
    return this->detectFlag;
}


