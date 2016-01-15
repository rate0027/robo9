#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "Stepup.h"

void Stepup_init(Stepup* this){
this->target = 0;
}

void Stepup_run(Stepup* this, unsigned int Target)
{
	int i;
	NolineTracer_set(this->nolineTracer, 0, 20, 20);
	for (i=0; i<250; i++)
  {
		NolineTracer_run(this->nolineTracer);
		systick_wait_ms(4);
  }
  
	NolineTracer_set(this->nolineTracer, 0, 0, 0);
  for (i=0; i<250; i++)
  {
		NolineTracer_run(this->nolineTracer);
		systick_wait_ms(4);
  }

	NolineTracer_set(this->nolineTracer, 0, -100, -100);
  for (i=0; i<30; i++)
  {
    NolineTracer_run(this->nolineTracer);  
		systick_wait_ms(4);
  }

	NolineTracer_set(this->nolineTracer, 0, 0, 0);
  for (i=0; i<15; i++)
  {
    NolineTracer_run(this->nolineTracer);  
		systick_wait_ms(4);
  }
  
	NolineTracer_set(this->nolineTracer, 0, 85, 87);
  for (i=0; i<100; i++)
  {
    NolineTracer_run(this->nolineTracer);  
		systick_wait_ms(4);
  }
  
	NolineTracer_set(this->nolineTracer, 0, 0, 0);
  for (i=0; i<250; i++)
  {
		NolineTracer_run(this->nolineTracer);
		systick_wait_ms(4);
  }

	NolineTracer_set(this->nolineTracer, 0, 20, 20);
  for (i=0; i<350; i++)
  {
		NolineTracer_run(this->nolineTracer);
		systick_wait_ms(4);
  }
  
	NolineTracer_set(this->nolineTracer, 0, 0, 0);
  for (i=0; i<250; i++)
  {
		NolineTracer_run(this->nolineTracer);
		systick_wait_ms(4);
  }
  
	NolineTracer_set(this->nolineTracer, 0, -20, -22);
  for (i=0; i<150; i++)
  {
    NolineTracer_run(this->nolineTracer);  
		systick_wait_ms(4);
  }

	NolineTracer_set(this->nolineTracer, 0, 0, 0);
  for (i=0; i<100; i++)
  {
    NolineTracer_run(this->nolineTracer);  
		systick_wait_ms(4);
  }
  
  LineTracer_set(this->lineTracer, 30, 0.2);
  for (i=0; i<400; i++)
  {
      LineTracer_trace(this->lineTracer, Target);
      systick_wait_ms(4);
  }

	NolineTracer_set(this->nolineTracer, 0, 0, 0);
  for (i=0; i<250; i++)
  {
		NolineTracer_run(this->nolineTracer);
		systick_wait_ms(4);
  }
  
	NolineTracer_set(this->nolineTracer, 0, -30, -30);
  for (i=0; i<75; i++)
  {
    NolineTracer_run(this->nolineTracer);  
		systick_wait_ms(4);
  }
  
	NolineTracer_set(this->nolineTracer, 0, 110, 105);
  for (i=0; i<65; i++)
  {
    NolineTracer_run(this->nolineTracer);  
    systick_wait_ms(4);
  }
  
	NolineTracer_set(this->nolineTracer, 0, 0, 0);
  for (i=0; i<250; i++)
  {
		NolineTracer_run(this->nolineTracer);
		systick_wait_ms(4);
  }
}


