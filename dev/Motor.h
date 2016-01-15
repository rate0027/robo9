/****************************************************
 *  Motor.h                                         
 *  Created on: 2012/05/05 7:35:26                      
 *  Implementation of the Class Motor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_57AC6181_F8E0_460f_9F59_90029C62B716__INCLUDED_)
#define EA_57AC6181_F8E0_460f_9F59_90029C62B716__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"


// ëÆê´Çï€éùÇ∑ÇÈÇΩÇﬂÇÃç\ë¢ëÃÇÃíËã`
typedef struct Motor
{
	int angle;
	int	angleError;	
	MOTOR_PORT_T outputPort;
}Motor;

// åˆäJëÄçÏ
void Motor_init(Motor* this, MOTOR_PORT_T outputPort);
void Motor_resetAngle(Motor* this);
long Motor_getAngle(Motor* this);
void Motor_rotate(Motor* this, int pwm);
void Motor_moveAngle_set(Motor* this, int Angle);
void Motor_moveAngle_run(Motor* this);
#endif /*!defined(EA_57AC6181_F8E0_460f_9F59_90029C62B716__INCLUDED_)*/

