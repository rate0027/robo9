#if !defined(LCURVE_INCLUDED_)
#define LCURVE_INCLUDED_ 

#include "../StopConditions.h"
#include "../run/LineTracer.h"

typedef struct LCurve
{
unsigned int target;
StopConditions* stopConditions;
LineTracer*     lineTracer;
}LCurve;

void LCurve_init(LCurve* this);
void tyokkaku_kari(LCurve* this, unsigned int Target);
void LCurve_run(LCurve* this, unsigned int Target);
#endif
