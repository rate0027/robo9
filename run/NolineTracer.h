#if !defined(NO_LINE_TRACER_INCLUDED)
#define NO_LINE_TRACER_INCLUDED

#include "../app/RearControl.h"
#include "../app/SteerControl.h"
#include "../dev/Motor.h"

typedef struct NolineTracer
{
	int speed;
	int speedR;
	int speedL;
	int angle;
	int flg;
	RearControl* rearControl;
	SteerControl* steerControl;
	Motor*	      steerMotor;
}NolineTracer;

void NolineTracer_init(NolineTracer* this);
void NolineTracer_set(NolineTracer* this, int S_Angle, int SpeedR, int SpeedL);
void NolineTracer_run(NolineTracer* this);
#endif
