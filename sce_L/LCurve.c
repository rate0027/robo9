#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "LCurve.h"

void LCurve_init(LCurve* this){
this->target = 0;
}

void tyokkaku_kari(LCurve* this, unsigned int Target){
  this->target = Target;
 
  int speed = 100;
  TrikeRunner_setspeed(this->trikeRunner, 30); 

  while(SC_Distanse(this->stopConditions, 30))
    LineTracer_trace(this->lineTracer, this->target);
//  run_straight(30, 30);

  while(SC_Gyro(this->stopConditions, 640))
    LineTracer_trace(this->lineTracer, this->target);
//  while(580 <= ecrobot_get_gyro_sensor(GYRO) && ecrobot_get_gyro_sensor(GYRO) <= 620)
//  run_straight_infinit(30);

//  wheelie_start();
  TrikeRunner_setspeed(this->trikeRunner, 40);
  while(SC_Distanse(this->stopConditions, 40))
    TrikeRunner_run(this->trikeRunner, 0);
//  run_straight(40, 30);

  while(SC_Gyro(this->stopConditions, 640))
    TrikeRunner_run(this->trikeRunner, 0);
//   while(580 <= ecrobot_get_gyro_sensor(GYRO) && ecrobot_get_gyro_sensor(GYRO) <= 620)
//  run_straight_infinit(40);
  while(SC_Distanse(this->stopConditions, -40))
    TrikeRunner_run(this->trikeRunner, 0);
//  run_straight(-40, -30);
//  wheelie_end();
  TrikeRunner_setspeed(this->trikeRunner, 50);
  while(SC_Distanse(this->stopConditions, -40))
    TrikeRunner_run(this->trikeRunner, 0);
//  run_straight(50, 200); 

}



void LCurve_run(LCurve* this, unsigned int Target){
  this->target = Target;
  TrikeRunner_setspeed(this->trikeRunner, 30);
  while(SC_Distanse(this->stopConditions, 200))
    LineTracer_trace(this->lineTracer, this->target);
//  run_straight(30, 30);

  while(SC_Gyro(this->stopConditions, 640))
    LineTracer_trace(this->lineTracer, Target);
//  while(580 <= ecrobot_get_gyro_sensor(GYRO) && ecrobot_get_gyro_sensor(GYRO) <= 620)
//  run_straight_infinit(30);

  TrikeRunner_setspeed(this->trikeRunner, 100);
  while(SC_Distanse(this->stopConditions, -30))
  TrikeRunner_run(this->trikeRunner, 0);
//  run_straight(-100,-30);

  while(SC_Distanse(this->stopConditions, 70))
  TrikeRunner_run(this->trikeRunner, 0);
//  run_straight(100,70);

  TrikeRunner_setspeed(this->trikeRunner, 50);
  while(SC_Distanse(this->stopConditions, 100))
  TrikeRunner_run(this->trikeRunner, 0);
//  run_straight(50, 100); 

} 
