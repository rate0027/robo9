#if !defined(TRAIN_INCLUDED_)
#define TRAIM_INCLUDED_ 

#include "../StopConditions.h"
#include "../run/LineTracer.h"
#include "../run/NolineTracer.h"

typedef struct Train 
{
unsigned int target;
StopConditions* stopConditions;
NolineTracer*		nolineTracer;
LineTracer*     lineTracer;
}Train;

void Train_run(Train* this, unsigned int Target);
void Train_init(Train* this);
#endif
