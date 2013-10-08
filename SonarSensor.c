#include "SonarSensor.h"


void SonarSensor_init(SonarSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
}

int SonarSensor_sonarAlert(SonarSensor* this, int sonarAlertDistance)
{
	static unsigned int counter = 0;
	static int alert = 0;
	
	signed int distance = 0;

	if (++counter == 40/4) /* 約40msec周期毎に障害物検知  */
	{
		/*
		 * 超音波センサによる距離測定周期は、超音波の減衰特性に依存します。
		 * NXTの場合は、40msec周期程度が経験上の最短測定周期です。
		 */
		distance = ecrobot_get_sonar_sensor(this->inputPort);
		if ((distance <= sonarAlertDistance) && (distance >= 0))
		{
			alert = 1; /* 障害物を検知 */
			
		}
		else
		{
			alert = 0; /* 障害物無し */
		}
		counter = 0;
	}

	return alert;
}
