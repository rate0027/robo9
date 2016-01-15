#if !defined(STEPUP_INCLUDED_)
#define STEPUP_INCLUDED_ 

#include "../StopConditions.h"
#include "../run/LineTracer.h"
#include "../run/NolineTracer.h"

typedef struct Stepup
{
unsigned int target;
StopConditions* stopConditions;
LineTracer*     lineTracer;
NolineTracer*		nolineTracer;
}Stepup;

void Stepup_init(Stepup* this);
void Stepup_run(Stepup* this, unsigned int Target);
#endif
