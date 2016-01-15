/****************************************************
 *  LineTracer.c                                         
 *  Created on: 2012/05/05 7:35:10                      
 *  Implementation of the Class LineTracer       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "LineTracer.h"

#include "ecrobot_interface.h"
#include "kernel.h"



void LineTracer_init(LineTracer* this)
{
	this->turn = 0;
  this->isInitialized = FALSE;
}

void LineTracer_set(LineTracer* this, int Speed, float Ex)
{
	this->speed = Speed;
	SteerControl_setex(this->steerControl, Ex);	
}

void LineTracer_pidset(LineTracer* this)
{
	PID_changeedge(this->pid);
}


void LineTracer_trace(LineTracer* this, unsigned int Target)
{
	if(! this->isInitialized)
	{
	
		// モータエンコーダをリセットする
		nxt_motor_set_count(NXT_PORT_A, 0);
		nxt_motor_set_count(NXT_PORT_B, 0);
		nxt_motor_set_count(NXT_PORT_C, 0);
	
		// 初期化済にする
		this->isInitialized = TRUE;
	}	
	
	this->turn = PID_calc(this->pid, Target);
	RearControl_set(this->rearControl, this->speed);

	/* PID計算値(turn)から前輪と後輪の速度計算 */	
	SteerControl_calc(this->steerControl, this->turn);
	RearControl_calcLine(this->rearControl, this->turn);	

	/* 前輪と後輪を走らす */
	SteerControl_runspeed(this->steerControl);
	RearControl_run(this->rearControl);
}

