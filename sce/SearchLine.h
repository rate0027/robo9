#if !defined(SEARCHLINE_INCLUDED_)
#define SEARCHLINE_INCLUDED_ 

#include "../StopConditions.h"
#include "../run/LineTracer.h"
#include "../run/NolineTracer.h"
#include "../dev/LightSensor.h"
#include "../dev/Motor.h"

typedef struct SearchLine
{
StopConditions* stopConditions;
LineTracer*     lineTracer;
NolineTracer*		nolineTracer;
LightSensor*		lightSensor;
Motor*			rightMotor;
Motor*			leftMotor;
}SearchLine;

void SearchLine_run(SearchLine* this, unsigned int Target, unsigned int black);
#endif
