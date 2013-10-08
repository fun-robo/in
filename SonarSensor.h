#if !defined(SONARSENSOR_H_)
#define SONARSENSOR_H_


#include "ecrobot_interface.h"
#include "kernel.h"


#define SONAR_ALERT_DISTANCE 15 /* 超音波センサによる障害物検知距離[cm] */


// 属性を保持するための構造体の定義
typedef struct SonarSensor
{
	SENSOR_PORT_T inputPort;
} SonarSensor;

// 公開操作
void SonarSensor_init(SonarSensor* this, SENSOR_PORT_T inputPort);
int SonarSensor_sonarAlert(SonarSensor* this, int sonarAlertDistance);

#endif /*!defined(SONARSENSOR_H_)*/
