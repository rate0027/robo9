#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "Basic_L.h"

void LBasic_init(LBasic* this){
this->target = 0;
}

void LBasic_1(LBasic* this, unsigned int Target){
  this->target = Target;
	
	/* 直線 */
	LineTracer_set(this->lineTracer, 50, 0.4); /* スピード50,カーブ係数0.2 */
	while(SC_Distanse(this->stopConditions, 200))
	{	
		LineTracer_trace(this->lineTracer, this->target);
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 120, 0.25); /*スピード100,カーブ係数0.25  */
	while(SC_Distanse(this->stopConditions, 1800)) /* 1750 */
	{	
		LineTracer_trace(this->lineTracer, this->target);
		systick_wait_ms(4);
	}

	/* カーブ */
	LineTracer_set(this->lineTracer, 30, 0.48); /* スピード30,カーブ係数1.3 */
	while(SC_Distanse(this->stopConditions, 600))
	{	
		LineTracer_trace(this->lineTracer, this->target);
		systick_wait_ms(4);
	}

#if 0
	/* 直線 */
	LineTracer_set(this->lineTracer, 40, 0.3); /* スピード40, カーブ係数0.5 */
	while(SC_Distanse(this->stopConditions, 200))
	{	
		LineTracer_trace(this->lineTracer, this->target);
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 80, 0.3); /* スピード80, カーブ係数0.3 */
	while(SC_Distanse(this->stopConditions, 700))
	{
		LineTracer_trace(this->lineTracer, this->target);
		systick_wait_ms(4);
	}
#endif
}



void LBasic_2(LBasic* this, unsigned int Target){
  this->target = Target;
} 
