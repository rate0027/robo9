#if !defined(SPECUNDATE_INCLUDED_)
#define SPECUNDATE_INCLUDED_ 

#include "../StopConditions.h"
#include "../run/LineTracer.h"
#include "../run/NolineTracer.h"

typedef struct SpecUndate
{
	unsigned int target;
	StopConditions* stopConditions;
	LineTracer*     lineTracer;
	NolineTracer		nolineTracer;
}SpecUndate;

void SpecUndate_init(SpecUndate* this);
void SpecUndate_run(SpecUndate* this, unsigned int Target);
#endif
