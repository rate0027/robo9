#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "Train.h"

void Train_init(Train* this)
{
}


void Train_run(Train* this, unsigned int Target){
	this->target = Target;


	/* ライン修正 */
	LineTracer_set(this->lineTracer, 40, 0.3);
	while(SC_Distanse(this->stopConditions, 60))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

  /* フィギュアLにぶつけて方向修正 */
	NolineTracer_set(this->nolineTracer, 0, -40, -40);
	while(SC_Time(this->stopConditions, 250))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(4);
	}

	/* 新幹線の前まで移動 */
	LineTracer_set(this->lineTracer, 40, 0.3);
	while(SC_Distanse(this->stopConditions, 100))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}


  /* 新幹線が通過するまで停止 */
	NolineTracer_set(this->nolineTracer, 0, 0, 0);
	while(SC_Sonar(this->stopConditions))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(40);
	}

  /* 通れるようになるまで停止(3秒) */
	NolineTracer_set(this->nolineTracer, 0, 0, 0);
	while(SC_Time(this->stopConditions, 750))
	{
		NolineTracer_run(this->nolineTracer);	
		ecrobot_sound_tone(400, 200, 50);
		systick_wait_ms(4);
	}

	/* 真ん中まで移動 */	
	NolineTracer_set(this->nolineTracer, 0, 60, 60);
	while(SC_Distanse(this->stopConditions, 80))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(4);
	}

	/* 直前まで移動 */
	LineTracer_set(this->lineTracer, 40, 0.3);
	while(SC_Distanse(this->stopConditions, 50))
	{	
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}

  /* 通れるようになるまで停止(4秒) */
	NolineTracer_set(this->nolineTracer, 0, 0, 0);
	while(SC_Time(this->stopConditions, 1000))
	{
		NolineTracer_run(this->nolineTracer);	
		ecrobot_sound_tone(400, 200, 50);
		systick_wait_ms(4);
	}

	/* 通過 */
	NolineTracer_set(this->nolineTracer, 0, 60, 60);
	while(SC_Distanse(this->stopConditions, 150))
	{
		NolineTracer_run(this->nolineTracer);	
		systick_wait_ms(4);
	}
}
