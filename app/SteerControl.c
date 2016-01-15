/*
 * SteerControl.c
 */

#include "SteerControl.h"

int math_limit(int in_val, int min_val, int max_val);

/* 初期化 */
void SteerControl_init(SteerControl* this)
{
  this->ex = 0.4;
  this->speed = 0;
}

/* ライントレース時の前輪の旋回量を計算 */
void SteerControl_calc(SteerControl* this, int turn)
{
#if 0
signed int SteerCalc_run(long Right, long Left)
{
  signed long Right_ms, Left_ms;
	signed int turn;

    Right_ms = (Right * PI / 180.0) * 250;
    Left_ms  = (Left  * PI / 180.0) * 250;
    
    turn = atan((2*B*(Right_ms - Left_ms)) / (A*(Right_ms + Left_ms)));
    
    return turn;	
#endif

	this->speed = (turn * this->ex);	

}


/* 旋回係数を変更 */
void SteerControl_setex(SteerControl* this, float EX)
{
this->ex = EX;
}

/* 前輪フラグの初期化 */
void SteerControl_resetFlag(SteerControl* this)
{
	this->flg = 0;
	this->fixedAngle = 0;	
}

/* 目標角まで前輪制御 */
void SteerControl_runangle(SteerControl* this, int angle)
{
  int steer_count = Motor_getAngle(this->steerMotor);
  int speed_s = angle - steer_count;
  
  /* 現在角の確認 */
  if(-9 <= speed_s && speed_s <= 9 && this->flg == 0)
  {
    this->flg = 2;
  }
  
  /* 前輪の遊びの確認 */
  if(speed_s > 0 && this->flg == 0)
  {
    ecrobot_sound_tone(640,3,49);
    this->fixedAngle = angle + this->steerMotor->angleError;
    this->flg = 1;
  }
  else if(speed_s < 0 && this->flg == 0)
  {
    this->fixedAngle = angle - this->steerMotor->angleError;
    this->flg = 1;
  }
   
  if(this->fixedAngle == steer_count)
  {
    this->flg = 2;
  }


  if(this->flg == 2)
  {
    speed_s = angle - steer_count;
  }
  else if(this->flg == 0 || this->flg == 1)
  {
    speed_s = this->fixedAngle - steer_count;
  }

  speed_s *= 3;

  math_limit(speed_s, -100, 100);

  Motor_rotate(this->steerMotor, speed_s);

}
/* 計算したスピードで前輪制御 */
void SteerControl_runspeed(SteerControl* this)
{
	/*TrikeRunnnerで-されてたからしたけどいらない？*/
	Motor_rotate(this->steerMotor, this->speed * -1 );
}

int math_limit(int in_val, int min_val, int max_val)
{
    if(in_val < min_val)
        in_val = min_val;
    else if(in_val > max_val)
        in_val = max_val;

    return in_val;
}
