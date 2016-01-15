#if !defined(FIGURE_L_INCLUDED_)
#define FIGURE_L_INCLUDED_

#include "LineTracer.h"
#include "NolineTracer.h"
#include "StopConditions.h"
#include "Stepup.h"

typedef struct FigureL
{
	LineTracer* lineTracer;
	NolineTracer* nolineTracer;
	StopConditions* stopConditions;
	Stepup* stepup;
}FigureL;

void FigureL_run(FigureL* this, unsigned int Target);
void FigureL_run2(FigureL* this, unsigned int Target);

#endif
