/****************************************************
 *  PID.h                                         
 *  Created on: 2012/05/05 7:35:39                      
 *  Implementation of the Class ColorJudgement       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_DEA59006_B221_4c87_BCC1_054497B43B1E__INCLUDED_)
#define EA_DEA59006_B221_4c87_BCC1_054497B43B1E__INCLUDED_

#include "Color.h"
#include "../dev/LightSensor.h"

// ‘®«‚ğ•Û‚·‚é‚½‚ß‚Ì\‘¢‘Ì‚Ì’è‹`
typedef struct PID
{
	unsigned int threshold;
	int change;
	LightSensor *lightSensor;
} PID;

// ŒöŠJ‘€ì
void PID_init(PID* this);
COLOR PID_judgeColor(PID* this);
int PID_calc(PID* this, unsigned int target_val);
void PID_changeedge(PID* this);


#endif /*!defined(EA_DEA59006_B221_4c87_BCC1_054497B43B1E__INCLUDED_)*/

