/****************************************************
*  UI.c                                         
*  Created on: 2012/05/05 8:28:46                      
*  Implementation of the Class UI       
*  Original author: hiroyuki.watanabe                     
****************************************************/

#include "UI.h"
#include "Maimai.h"

static int UI_remoteStart(UI* this);

void UI_init(UI* this)
{

}

void UI_waitStart(UI* this)
{
	// タッチセンサが押されるまで、待ち続ける

	char flag_touch = 0;
	int run_time = 0;
	int count = 0;
	U16 white = 0;	
	while(1)
	{
		// 尻尾を立てて完全停止状態にする
		if(flag_touch < 4 && flag_touch > 1)
			Motor_tailControl(this->tailMotor, 80);
		else
			Motor_tailControl(this->tailMotor, TAIL_ANGLE_STAND_UP);
		//点滅の輝度値を格納する
		Maimai_store(this->maimai, run_time);

		if(TouchSensor_isPressed(this->touchSensor))	count++;
		else	count = 0;
		if(count == 5){
			//一度目のボタン押下でキャリブレーション
			if(flag_touch == 0){
				white = Maimai_calc(this->maimai);
				flag_touch = 1;
			}
			//2度目のボタン押下でスタート
			else if(flag_touch == 1){
				this->lineTracer->TARGET = (F32)((white + Maimai_calc(this->maimai)) / 2);
				flag_touch = 2;
			}
			//2度目のボタン押下でスタート
			else if(flag_touch == 2){
				white = Maimai_calc(this->maimai);
				flag_touch = 3;
			}
			//2度目のボタン押下でスタート
			else if(flag_touch == 3){
				this->lineTracer->TARGET_tail = (F32)((white + Maimai_calc(this->maimai)) / 2);
				flag_touch = 4;
			}
			else{
				Motor_tailControl(this->tailMotor, TAIL_ANGLE_DRIVE);
				break;
			}
		}
		
		if(UI_remoteStart(this))
		{
			// タッチセンサが押されたら尻尾を上げる
			Motor_tailControl(this->tailMotor, TAIL_ANGLE_DRIVE);
			break;// タッチセンサが押された
		}

		if(SonarSensor_sonarAlert(this->sonarSensor, 30) == 1){
		}

		display_clear(0);
		display_goto_xy(0,1);
		if(flag_touch == 1){
			display_string("white=");
			display_int(white,1);
		}else if(flag_touch == 2){
			display_string("black=");
			display_int(this->lineTracer->TARGET*2 - white,1);
		}else if(flag_touch == 3){
			display_string("white=");
			display_int(white,1);
		}else if(flag_touch == 4){
			display_string("black=");
			display_int(this->lineTracer->TARGET*2 - white,1);
		}
		display_update();

		systick_wait_ms(4);
		run_time+= 4;
	}

}

static int UI_remoteStart(UI* this)
{
	int i;
	unsigned int rx_len;
	unsigned char start = 0;

	for (i=0; i<BT_MAX_RX_BUF_SIZE; i++)
	{
		this->rx_buf[i] = 0; /* 受信バッファをクリア */
	}

	rx_len = ecrobot_read_bt(this->rx_buf, 0, BT_MAX_RX_BUF_SIZE);
	if (rx_len > 0)
	{
		/* 受信データあり */
		if (this->rx_buf[0] == CMD_START)
		{
			start = 1; /* 走行開始 */
		}
		ecrobot_send_bt(this->rx_buf, 0, rx_len); /* 受信データをエコーバック */
	}

	return start;
}

BOOL UI_isEmergency(UI *this)
{
	if (ecrobot_get_gyro_sensor(NXT_PORT_S1) < 400)
		return true;
	else
		return false;
}
