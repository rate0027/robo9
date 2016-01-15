/*
 * SteerControl.h
 */
#if !defined(STEER_CONTROL_INCLUDED_)
#define STEER_CONTROL_INCLUDED_

#include "../dev/Motor.h"

typedef struct SteerControl
{
	float ex;
	int speed;
	int flg;
	int fixedAngle;
	Motor *steerMotor;
} SteerControl;

void SteerControl_init(SteerControl* this);
void SteerControl_calc(SteerControl* this, int turn);
void SteerControl_setex(SteerControl* this, float EX);
void SteerControl_resetFlag(SteerControl* this);
void SteerControl_runangle(SteerControl* this, int angle);
void SteerControl_runspeed(SteerControl* this);

#endif
