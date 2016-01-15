/*
*  RearControl.h
*/

#if !defined(REAR_CONTROL_INCLUDED_)
#define REAR_CONTROL_INCLUDED_

#include "../dev/Motor.h"

typedef struct RearControl
{
	int speedR;
	int speedL;
	int speed;
	Motor* leftMotor;
	Motor* rightMotor;
}RearControl;

void RearControl_init(RearControl* this);
void RearControl_set(RearControl* this, int Speed);
void RearControl_calcLine(RearControl* this, int turn);
void RearControl_calcNoline(RearControl* this, int SpeedR, int SpeedL);
void RearControl_run(RearControl* this);

#endif
