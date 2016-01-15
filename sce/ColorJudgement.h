#if !defined(COLORJUDGEMENT_INCLUDED_)
#define COLORJUDGEMENT_INCLUDED_ 

#include "ecrobot_interface.h"
#include "kernel.h"

#include "../dev/LightSensor.h"

typedef struct ColorJudgement
{
	LightSensor* lightSensor;
}ColorJudgement;

void ColorJudgement_init(ColorJudgement* this);
void ColorJudgement_run(ColorJudgement* this, unsigned int Target);
#endif
