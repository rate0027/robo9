#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "ColorJudgement.h"

void ColorJudgement_init(ColorJudgement* this)
{
}
void ColorJudgement_run(ColorJudgement* this, unsigned int Target)
{
	if(LightSensor_getBrightness(this->lightSensor) > Target)
	{
		ecrobot_sound_tone(900, 200, 60);
	}
	else
	{
		ecrobot_sound_tone(700, 200, 60);
	}
}


