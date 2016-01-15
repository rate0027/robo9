/*
* RearControl.c
*/

#include "RearControl.h"

void RearControl_init(RearControl* this)
{
	this->speedR = 0;
	this->speedL = 0;
	this->speed  = 0;
}


void RearControl_set(RearControl* this, int Speed)
{
	this->speed = Speed;
}


void RearControl_calcLine(RearControl* this, int turn)
{			/* input power of both motor */
	if(turn<0){
		this->speedR = (this->speed + (turn * (-1) )) * 0.7;
		this->speedL = (this->speed - (turn * (-1) )) * 0.48;
	}
	else{
		this->speedR = (this->speed - turn) * 0.48;
		this->speedL = (this->speed + turn) * 0.7;
	}
}

void RearControl_calcNoline(RearControl* this, int SpeedR, int SpeedL)
{
	this->speedR = SpeedR;
	this->speedL = SpeedL;
}

void RearControl_run(RearControl* this)
{
	Motor_rotate(this->rightMotor, this->speedR);
	Motor_rotate(this->leftMotor, this->speedL);
}

