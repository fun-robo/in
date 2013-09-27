///////////////////////////////////////////////////////////
//  model_impl.c
///////////////////////////////////////////////////////////

#include "LineTracer.h"
#include "UI.h"
#include "ColorJudgement.h"
#include "BalanceRunner.h"
#include "TouchSensor.h"
#include "LightSensor.h"
#include "GyroSensor.h"
#include "Motor.h"
#include "GarageIn.h"
#include "Basic.h"
#include "LookUpGate.h"
#include "LookUpRunner.h"
#include "LineReturn.h"
#include "Maimai.h"
#include "TailRunner.h"

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

// オブジェクトを静的に確保する
LineTracer 	lineTracer;
UI 		ui;
ColorJudgement 	colorJudgement;
BalanceRunner 	balanceRunner;
TouchSensor 	touchSensor;
LightSensor 	lightSensor;
GyroSensor 	gyroSensor;
Motor 		leftMotor, rightMotor, tailMotor;
GarageIn	garageIn;
Basic		basic;
LookUpGate lookUpGate;
LookUpRunner lookUpRunner;
SonarSensor sonarSensor;
Maimai maimai;
LineReturn	lineReturn;
TailRunner tailRunner;

void ecrobot_device_initialize();
void ecrobot_device_terminate();
void user_1ms_isr_type2(void);
void ecrobot_link();
void ecrobot_init();


TASK(TaskMain)
{
	//変数宣言部
	int run_time = 0;

	//デバイスの初期化
	ecrobot_device_initialize();
	//オブジェクト間のリンク構築
	ecrobot_link();
	//各オブジェクト初期化
	ecrobot_init();
	
	// UIに開始待ちを依頼する
	UI_waitStart(&ui);

	char phase = 0;
	int runtime1 = 0;
	// 4ms周期で、ライントレーサにトレース走行を依頼する
	while(1)
	{
		if(UI_isEmergency(&ui))	break;


		Maimai_store(&maimai, run_time);

		switch(phase){
			case 0:	
				LineTracer_trace(&lineTracer, 50, 1);
				if(runtime1 > 2000){//goalしたら
					ecrobot_sound_tone(349, 100, 100);
					phase = 1;
					runtime1 = 0;
				}
				runtime1 += 4;
				break;
			case 1:	
				TailRunner_run(&tailRunner, 30, 1);
				break;
			case 2:	break;
			case 3:	break;
			case 4:	break;
			default:break;
		}

		run_time+=4;
		systick_wait_ms(4);

		//ディスプレイ
		//gyro = LightSensor_getBrightness(&lightSensor);//ジャイロセンサーの値を代入する	
		//gyro = GyroSensor_getAngularVelocity(&gyroSensor);

		//display_clear(0);
		//display_goto_xy(0,1);
		//display_string("sub=");
		//display_int(suba,1);
		//display_update();
		
		//ロギングする
		ecrobot_bt_data_logger(0, 0);
	}

}

// デバイス初期化用フック関数
// この関数はnxtOSEK起動時に実行されます。
void ecrobot_device_initialize()
{
	// センサ、モータなどの各デバイスの初期化関数を
	// ここで実装することができます
	// ⇒　光センサ赤色LEDをONにする
	ecrobot_set_light_sensor_active(NXT_PORT_S3);
	if(ecrobot_get_bt_status() == BT_NO_INIT){
		ecrobot_set_bt_device_name("ET025");
	}
	ecrobot_init_bt_slave("LEJOS-OSEK");
}

// デバイス終了用フック関数
// この関数はSTOPまたはEXITボタンが押された時に実行されます。
void ecrobot_device_terminate()
{
	// センサ、モータなどの各デバイスの終了関数を
	// ここで実装することができます。
	// ⇒　光センサ赤色LEDをOFFにする
	ecrobot_set_light_sensor_inactive(NXT_PORT_S3);
	ecrobot_term_sonar_sensor(NXT_PORT_S2);
	ecrobot_term_bt_connection();
}

// 1msec周期割り込み(ISRカテゴリ2)から起動されるユーザー用フック関数
void user_1ms_isr_type2(void)
{
	// 今回は何も行わない
}

void ecrobot_link(){
	// オブジェクト間のリンクを構築する
	lineTracer.colorJudgement  = &colorJudgement;
	lineTracer.balanceRunner   = &balanceRunner;
	lineTracer.lightSensor	     = &lightSensor;
	lineTracer.maimai            = &maimai;

	ui.touchSensor		   = &touchSensor;
	ui.tailMotor		   = &tailMotor;
	ui.sonarSensor = &sonarSensor;
	ui.lightSensor = &lightSensor;
	ui.lineTracer = &lineTracer;
	ui.sonarSensor = &sonarSensor;
	ui.maimai	   = &maimai;

	colorJudgement.lightSensor = &lightSensor;

	balanceRunner.gyroSensor   = &gyroSensor;
	balanceRunner.leftMotor    = &leftMotor;
	balanceRunner.rightMotor   = &rightMotor;

	garageIn.leftMotor		  = &leftMotor;
	garageIn.rightMotor		  = &rightMotor;
	garageIn.tailMotor       = &tailMotor;

	basic.leftMotor			  = &leftMotor;
	basic.rightMotor		  = &rightMotor;
	basic.gyroSensor		  = &gyroSensor;
	basic.lineTracer		  = &lineTracer;
	basic.lightSensor         = &lightSensor;
	basic.ui				  = &ui;

	lookUpGate.lineTracer = &lineTracer;
	lookUpGate.lookUpRunner = &lookUpRunner;
	lookUpGate.sonarSensor = &sonarSensor;
	lookUpGate.colorJudgement  = &colorJudgement;

	lookUpRunner.gyroSensor = &gyroSensor;
	lookUpRunner.leftMotor = &leftMotor;
	lookUpRunner.rightMotor = &rightMotor;
	lookUpRunner.tailMotor = &tailMotor;

	lineReturn.lightSensor = &lightSensor;
	lineReturn.balanceRunner = &balanceRunner;
	lineReturn.lineTracer = &lineTracer;

	maimai.lightSensor = &lightSensor;

	tailRunner.tailMotor = &tailMotor;
	tailRunner.lineTracer = &lineTracer;
	tailRunner.gyroSensor = &gyroSensor;
}

void ecrobot_init(){
	// 各オブジェクトを初期化する
	LineTracer_init(&lineTracer);
	UI_init(&ui);
	ColorJudgement_init(&colorJudgement);
	BalanceRunner_init(&balanceRunner);
	TouchSensor_init(&touchSensor, NXT_PORT_S4);
	LightSensor_init(&lightSensor, NXT_PORT_S3);
	GyroSensor_init(&gyroSensor, NXT_PORT_S1);
	Motor_init(&leftMotor, NXT_PORT_C);
	Motor_init(&rightMotor, NXT_PORT_B);
	Motor_init(&tailMotor, NXT_PORT_A);
	Basic_init(&basic);
	SonarSensor_init(&sonarSensor, NXT_PORT_S2);
	LookUpGate_init(&lookUpGate);
	LookUpRunner_init(&lookUpRunner);
	LineReturn_init(&lineReturn);
	Maimai_init(&maimai);
	TailRunner_init(&tailRunner);
}


