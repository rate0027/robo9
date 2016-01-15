#if !defined(BASIC_INCLUDED_)
#define BASIC_INCLUDED_ 

#include "../StopConditions.h"
#include "../run/LineTracer.h"

typedef struct LBasic
{
unsigned int target;
StopConditions* stopConditions;
LineTracer*     lineTracer;
}LBasic;

void LBasic_init(LBasic* this);
void LBasic_1(LBasic* this, unsigned int Target);
void LBasic_2(LBasic* this, unsigned int Target);
#endif
