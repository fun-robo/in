#include "LineReturn.h"


//初期化する
void LineReturn_init(LineReturn* this)
{
	this->run_time = 0;
	this->phase = 0;
}

//ライン復帰をする
int LineReturn_run(LineReturn *this)
{
	//switch(this->phase){
	//	case 0: //倒立
	//		if(this->run_time < 3000){
	//			BalanceRunner_run(this->balanceRunner, 0, 0);
	//		}else{
	//			this->phase = 1;
	//			this->run_time = 0;
	//		}
	//		break;

	//	case 1: //右探索
	//		if(this->run_time < 3000){
	//			BalanceRunner_run(this->balanceRunner, 10, 20);
	//			if(LightSensor_getBrightness(this->lightSensor) > 600){
	//				this->phase = 3;
	//				this->run_time = 0;
	//			}
	//		}else{
	//			this->phase = 2;
	//			this->run_time = 0;
	//		}
	//		break;

	//	case 2: //始点復帰
	//		BalanceRunner_run(this->balanceRunner, -10, -20);
	//		if(this->run_time > 3000){
	//			this->phase = 3;
	//			this->run_time = 0;
	//		}
	//		break;

	//	case 3: //向き修正
	//		if(this->run_time < 1000){
	//			BalanceRunner_run(this->balanceRunner, -5, 5);
	//		}else{
	//			this->phase = 4;
	//		}
	//		break;

	//	case 4: //しっぽ→倒立走行
	//		if(this->run_time < 1000){
	//			LineTracer_trace(this->lineTracer,25);
	//		}else{
	//			this->phase = 5;
	//			this->run_time = 0;
	//			LineTracer_trace(this->lineTracer,25);
	//		}
	//		break;
	//	default:
	//		break;
	//}

	//this->run_time += 4;
	//return this->phase;
	return 0;
}
