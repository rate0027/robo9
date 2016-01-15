#if !defined(R_PARK_INCLUDED_)
#define R_PARK_INCLUDED_

#include "LineTracer.h"
#include "NolineTracer.h"
#include "StopConditions.h"

typedef struct RPark
{
	StopConditions* stopConditions;
	NolineTracer* nolineTracer;
	LineTracer* lineTracer;
}RPark;

void RPark_run(RPark* this, unsigned int Target);
#endif
