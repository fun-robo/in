#include "Straight.h"

int Calc_angle(Straight *this){
	return ((Motor_getAngle(this->rightMotor) - this->r_motor_angle) - (Motor_getAngle(this->leftMotor) - this->l_motor_angle));
}

void Straight_init(Straight *this){
	this->finish_flag = false;
	this->r_motor_angle = Motor_getAngle(this->rightMotor);
	this->l_motor_angle = Motor_getAngle(this->leftMotor);
}

void Straight_run(Straight *this, int forword){
	if(!this->finish_flag){
		Straight_init(this);
		this->finish_flag = true;
	}

	BalanceRunner_run(this->balanceRunner, Calc_angle(this), forword);
}

void Straight_finish(Straight*this){
	this->finish_flag = false;
}
