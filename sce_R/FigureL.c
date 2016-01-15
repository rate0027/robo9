#include "FigureL.h"



void FigureL_run(FigureL* this, unsigned int Target)
{
	LineTracer_set(this->lineTracer, 50, 0.2);
	while(SC_Gyro(this->stopConditions, 640))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

/*
	/ default -100, -100 /
	NolineTracer_set(this->nolineTracer, 0, -10, -10);
	while(SC_Distanse(this->stopConditions, -30))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(4);
	}

	NolineTracer_set(this->nolineTracer, 0, 0, 0);
	while(SC_Time(this->stopConditions, 250))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(4);
	}
*/
	NolineTracer_set(this->nolineTracer, 0, 85, 90);
	while(SC_Distanse(this->stopConditions, 60))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(4);
	}

/*
	NolineTracer_set(this->nolineTracer, 0, -10, -10);
	while(SC_Time(this->stopConditions, 100))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 60, 0.4);
	while(SC_Time(this->stopConditions, 400))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

	NolineTracer_set(this->nolineTracer, 0, -30, -30);
	while(SC_Distanse(this->stopConditions, -30))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(4);
	}

	NolineTracer_set(this->nolineTracer, -10, 70, 80);
	while(SC_Distanse(this->stopConditions, 60))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 40, 0.2);
	while(SC_Distanse(this->stopConditions, 400))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}
*/

}


void FigureL_run2(FigureL* this, unsigned int Target)
{
	
	LineTracer_set(this->lineTracer, 50, 0.2);
	while(SC_Gyro(this->stopConditions, 640))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

	Stepup_run(this->stepup, Target);

	LineTracer_set(this->lineTracer, 40, 0.3);
	while(SC_Distanse(this->stopConditions, 300))
	{	
		LineTracer_trace(this->lineTracer, Target);
	systick_wait_ms(4);
	}
	
	NolineTracer_set(this->nolineTracer, -250, 10, 50);
	while(SC_Distanse(this->stopConditions, 200))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(4);
	}

	LineTracer_set(this->lineTracer, 40, 0.2);
	while(SC_Distanse(this->stopConditions, 400))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}
	/* ログのためのやーつ */
	unsigned int light = ecrobot_get_light_sensor(NXT_PORT_S3);
	unsigned int gyro = ecrobot_get_gyro_sensor(NXT_PORT_S1);
	ecrobot_bt_adc_data_logger(1,2,light,gyro,Target,6);
}
