
#include "Gray.h"


//初期化する
void Gray_init(Gray* this)
{
	int i;
	for(i=0; i<25; i++){
		this->bright[i]=600;
	}
}

//灰色検知する
int Gray_look(Gray *this)
{
	int i;
	int sum = 0;

	this->bright[this->count] = LightSensor_getBrightness(this->lightSensor);

	for(i=0; i<25; i++){
		sum+=this->bright[i];
	}

	this->count++;
	if(this->count == 25)	this->count=0;

	sum = sum/25;
	//if(sum < 400)	return 1;
	return sum;
	
}

