#include "RPark.h"

void RPark_run(RPark* this, unsigned int Target)
{
	LineTracer_set(this->lineTracer, 70, 0.2);
	while(SC_Distanse(this->stopConditions, 470))
	{	
		LineTracer_trace(this->lineTracer, Target);
	systick_wait_ms(4);
	}

	NolineTracer_set(this->nolineTracer, -300, 30, 60);
	while(SC_Distanse(this->stopConditions, 100))
	{
	NolineTracer_run(this->nolineTracer);	
	systick_wait_ms(4);
	}

	NolineTracer_set(this->nolineTracer,0, -30, -30);
	while(SC_Distanse(this->stopConditions, -120))
	{
	NolineTracer_run(this->nolineTracer);	
	systick_wait_ms(4);
	}

	NolineTracer_set(this->nolineTracer, -300, -10, -60);
	while(SC_Distanse(this->stopConditions, -130))
	{
	NolineTracer_run(this->nolineTracer);	
	systick_wait_ms(4);
	}

	NolineTracer_set(this->nolineTracer, -300, 0, 0);   /* stop */
	while(SC_Time(this->stopConditions, 1000))
	{
	NolineTracer_run(this->nolineTracer);	
	systick_wait_ms(4);
	}

	NolineTracer_set(this->nolineTracer, -300, 10, 60);
	while(SC_Distanse(this->stopConditions, 130))
	{
	NolineTracer_run(this->nolineTracer);	
	systick_wait_ms(4);
	}

	NolineTracer_set(this->nolineTracer, 0, 30, 30);
	while(SC_Distanse(this->stopConditions, 120))
	{
	NolineTracer_run(this->nolineTracer);	
	systick_wait_ms(4);
	}
}
