/****************************************************
 *  LineTracer.h                                         
 *  Created on: 2012/05/05 7:35:10                      
 *  Implementation of the Class LineTracer       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_A4BD4D1A_E40A_4143_A4C5_AC9B36316301__INCLUDED_)
#define EA_A4BD4D1A_E40A_4143_A4C5_AC9B36316301__INCLUDED_

#include "../app/PID.h"
#include "../app/SteerControl.h"
#include "../app/RearControl.h"

// ‘®«‚ğ•Û‚·‚é‚½‚ß‚Ì\‘¢‘Ì‚Ì’è‹`
typedef struct LineTracer
{
	int turn;
	int speed;
	BOOL isInitialized;
	PID *pid;
	SteerControl *steerControl;
	RearControl *rearControl;
} LineTracer;

// ŒöŠJ‘€ì
void LineTracer_init(LineTracer* this);
void LineTracer_set(LineTracer* this, int Speed, float Ex);
void LineTracer_trace(LineTracer* this, unsigned int Target);
void LineTracer_pidset(LineTracer* this);

#endif /*!defined(EA_A4BD4D1A_E40A_4143_A4C5_AC9B36316301__INCLUDED_)*/

