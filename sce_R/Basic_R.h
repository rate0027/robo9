#if !defined(RBASIC_INCLUDED_)
#define RBASIC_INCLUDED_ 

#include "../StopConditions.h"
#include "../run/LineTracer.h"
#include "../run/NolineTracer.h"

typedef struct RBasic
{
unsigned int target;
StopConditions* stopConditions;
NolineTracer*		nolineTracer;
LineTracer*     lineTracer;
}RBasic;

void RBasic_init(RBasic* this);
void RBasic_1(RBasic* this, unsigned int Target);
void RBasic_2(RBasic* this, unsigned int Target);
#endif
