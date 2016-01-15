/****************************************************
 *  Motor.c                                         
 *  Created on: 2012/05/05 7:35:26                      
 *  Implementation of the Class Motor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "Motor.h"

 int math_limit(int in_val, int min_val, int max_val);

// ‰Šú‰»‚·‚é
void Motor_init(Motor* this, MOTOR_PORT_T outputPort)
{
	this->outputPort = outputPort;
	this->angle      = 0;
}

// ‰ñ“]Šp“x‚ðƒŠƒZƒbƒg‚·‚é
void Motor_resetAngle(Motor* this)
{
	return nxt_motor_set_count(this->outputPort, 0);
}

// ‰ñ“]Šp“x‚ð“¾‚é
long Motor_getAngle(Motor* this)
{
	return -nxt_motor_get_count(this->outputPort);
}

// ‰ñ“]‚³‚¹‚é
void Motor_rotate(Motor* this, int pwm)
{
	nxt_motor_set_speed(this->outputPort, -pwm, 1);
} 

void Motor_moveAngle_set(Motor* this, int Angle)
{
  this->angle = Angle;
}

void Motor_moveAngle_run(Motor* this)
{
  int steer_count = -nxt_motor_get_count(this->outputPort);
  int speed_s = this->angle - steer_count;

  math_limit(speed_s, -100, 100);

  if(steer_count != this->angle)
  {
  nxt_motor_set_speed(this->outputPort, -speed_s, 1);
  }
  else
  {
    nxt_motor_set_speed(this->outputPort, 0, 1);
  }
}
 
 int math_limit(int in_val, int min_val, int max_val)
{
    if(in_val < min_val)
        in_val = min_val;
    else if(in_val > max_val)
        in_val = max_val;

    return in_val;
}
