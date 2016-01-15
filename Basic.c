#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "Basic.h"

void Basic_init(Basic* this){
this->target = 0;
}

void Basic_1(Basic* this, unsigned int Target){
  this->target = Target;

	LineTracer_set(this->lineTracer, 50, 0.3); /* original 100 0.25 */
	while(SC_Distanse(this->stopConditions, 1900)) /* original is 2150 */
	{	
		LineTracer_trace(this->lineTracer, this->target);
		systick_wait_ms(4);
	}

	NolineTracer_set(this->nolineTracer, 0, 0, 0);
	while(SC_Time(this->stopConditions, 500))
	{
		NolineTracer_run(this->nolineTracer);
		systick_wait_ms(4);
	}
	

	LineTracer_set(this->lineTracer, 30, 1.3); /* original 30, 1.3 */
	while(SC_Distanse(this->stopConditions, 900))
	{	
		LineTracer_trace(this->lineTracer, this->target);
		systick_wait_ms(4);
	}

	NolineTracer_set(this->nolineTracer, 0, 0, 0);
	while(SC_Time(this->stopConditions, 500))
	{
		NolineTracer_run(this->nolineTracer);
		systick_wait_ms(4);
	}


	LineTracer_set(this->lineTracer, 50, 0.3);
	while(SC_Distanse(this->stopConditions, 650))
	{	
		LineTracer_trace(this->lineTracer, this->target);
		systick_wait_ms(4);
	}

}



void Basic_2(Basic* this, unsigned int Target){
  this->target = Target;
} 
