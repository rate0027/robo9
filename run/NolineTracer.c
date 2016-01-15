/*
* NolineTracer.c
*/

#include "NolineTracer.h"


void NolineTracer_init(NolineTracer* this)
{
	this->speed = 0;
	this->angle = 0;
	this->speedR = 0;
	this->speedL = 0;
}


/* 速度,前輪角度,左右モータの比率を設定 */
void NolineTracer_set(NolineTracer* this, int S_Angle, int SpeedR, int SpeedL)
{
	this->angle = S_Angle;
	this->speedR = SpeedR;
	this->speedL = SpeedL;
	this->flg = 0;
	SteerControl_resetFlag(this->steerControl);
}

/* 計算し，走行 */
void NolineTracer_run(NolineTracer* this)
{
	RearControl_set(this->rearControl, this->speed);
	RearControl_calcNoline(this->rearControl, this->speedR, this->speedL);

/* モデル的にどうなのか。 こうなるとsteerモータの構造体も持たなくてはいけなくなる？ */
	SteerControl_runangle(this->steerControl, this->angle);
	if(this->angle == Motor_getAngle(this->steerMotor) && this->steerControl->flg == 2)
	{
		this->flg = 1;
	}

	if(this->flg == 1)
	{
		RearControl_run(this->rearControl);
	}
	else if(this->flg == 0 )
	{
		ecrobot_sound_tone(640,3,40);
		RearControl_calcNoline(this->rearControl, 0, 0);
		RearControl_run(this->rearControl);
	}

}
