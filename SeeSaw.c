
#include "SeeSaw.h"


//初期化する
void SeeSaw_init(SeeSaw* this)
{
	this->run_time = 0;
	this->phase = 0;
}

//シーソー走行をする
int SeeSaw_run(SeeSaw *this){

	//switch(this->phase){
	//	//段差検知
	//	case 0:	
	//		if(GyroSensor_getAngularVelocity(this->gyroSensor) > 700 && this->run_time > 3000){
	//			this->phase = 1;
	//			this->run_time = 0;
	//		}
	//		LineTracer_trace(this->lineTracer, 25);
	//		break;
	//	//段差を登る
	//	case 1:
	//		if(this->run_time < 1300){
	//			BalanceRunner_run(this->balanceRunner, 0, 30);
	//		}else{
	//			this->phase = 2;
	//			this->run_time = 0;
	//		}
	//		break;
	//	//シーソー上のラインをトレースする
	//	case 2:
	//		if(this->run_time < 4000){
	//			LineTracer_trace(this->lineTracer, 20);
	//		}else{
	//			this->phase = 3;
	//			this->run_time = 0;
	//		}
	//		break;
	//	//直進で降りる
	//	case 3:
	//		if(this->run_time < 2000){
	//			BalanceRunner_run(this->balanceRunner, 0, 40);
	//		}else{
	//			this->phase = 4;
	//			this->run_time = 0;
	//		}
	//		break;
	//	//倒立する
	//	case 4:
	//		if(this->run_time < 500){
	//			BalanceRunner_run(this->balanceRunner, 0, 0);
	//		}else{
	//			this->phase = 5;
	//			this->run_time = 0;
	//		}
	//	default:
	//		break;
	//}

	//this->run_time += 4;
	//return this->phase;
	return 0;
}
