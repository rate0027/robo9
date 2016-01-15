#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "Basic_R.h"

void RBasic_init(RBasic* this){
this->target = 0;
}

void RBasic_1(RBasic* this, unsigned int Target){
  this->target = Target;
	/* 左エッジ*/
	LineTracer_set(this->lineTracer, 100, 0.25);
	while(SC_Distanse(this->stopConditions, 1700))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 50, 0.8);
	while(SC_Distanse(this->stopConditions, 200))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 30, 1.2);
	while(SC_Distanse(this->stopConditions, 900))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 15, 1.4);
	while(SC_Distanse(this->stopConditions, 700))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}
	LineTracer_set(this->lineTracer, 30, 1.0);
	while(SC_Distanse(this->stopConditions, 700))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 30, 1.2);
	while(SC_Distanse(this->stopConditions, 400))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}
#if 0
	/* エッジチェンジ */
	LineTracer_set(this->lineTracer, 40, 0.3);
	while(SC_Distanse(this->stopConditions, 100))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}
	NolineTracer_set(this->nolineTracer, -70, 30, 40);
	while(SC_Distanse(this->stopConditions, 90))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(4);
	}

	LineTracer_pidset(this->lineTracer);
	LineTracer_set(this->lineTracer, 40, 0.3);
	while(SC_Distanse(this->stopConditions, 100))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}
	LineTracer_set(this->lineTracer, 20, 1.3);
	while(SC_Distanse(this->stopConditions, 150))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}
#endif
}



void RBasic_2(RBasic* this, unsigned int Target)
{
	/* 左エッジ */
	LineTracer_set(this->lineTracer, 15, 1.4);
	while(SC_Distanse(this->stopConditions, 700))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 30, 1.2);
	while(SC_Distanse(this->stopConditions, 900))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 50, 0.8);
	while(SC_Distanse(this->stopConditions, 200))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 100, 0.25);
	while(SC_Distanse(this->stopConditions, 1700))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}
} 
