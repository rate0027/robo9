#if !defined(BRIDGE_INCLUDED_)
#define BRIDGE_INCLUDED_ 

#include "../StopConditions.h"
#include "../run/LineTracer.h"
#include "../run/NolineTracer.h"

typedef struct Bridge
{
unsigned int target;
StopConditions* stopConditions;
LineTracer*     lineTracer;
}Bridge;

void Bridge_init(Bridge* this);
void Bridge_run(Bridge* this, unsigned int Target);
#endif
