#if !defined(LCURVE_INCLUDED_)
#define LCURVE_INCLUDED_ 

#include "../app/TrikeRunner.h"
#include "../StopConditions.h"
#include "../run/LineTracer.h"

typedef struct LCurve
{
unsigned int target;
TrikeRunner*    trikeRunner;
StopConditions* stopConditions;
LineTracer*     lineTracer;

}LCurve;

void LCurve_init(LCurve* this);
void LCurve_run(LCurve* this, unsigned int Target);
void tyokkaku_kari(LCurve* this, unsigned int Target);
#endif
