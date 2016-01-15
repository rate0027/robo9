#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "SearchLine.h"

void SearchLine_run(SearchLine* this, unsigned int Target, unsigned int black)
{
	
int oldR = -Motor_getAngle(this->rightMotor);
int oldL = -Motor_getAngle(this->leftMotor);
int nowR = -Motor_getAngle(this->rightMotor);
int nowL = -Motor_getAngle(this->leftMotor);
int tyokkaku = 650;
int RorL = 1; //右側：1 左側:0
int flg = 0;
int target = Target;
int seach_range = 80;
int speed = 40;
int shani = 30;
U16 ir = 0;

NolineTracer_set(this->nolineTracer, tyokkaku, -speed, 0);
if(RorL ==1){/*r = 0; 引数が右側走行だったら */
		while(nowR - oldR <= seach_range){
			nowR = -Motor_getAngle(this->rightMotor);
			NolineTracer_run(this->nolineTracer);/* 右向け */
			ir = LightSensor_getBrightness(this->lightSensor);
			if(ir <= (black+shani) && ir >= (black-shani)){
				flg = 1;
				Motor_rotate(this->rightMotor, speed);/* 左向け */
				break;}
			systick_wait_ms(4);
		}

	oldR = -Motor_getAngle(this->rightMotor);

NolineTracer_set(this->nolineTracer, tyokkaku, speed, 0);
		while(nowR - oldR >= -(seach_range*2)){
		nowR = -Motor_getAngle(this->rightMotor);
NolineTracer_run(this->nolineTracer);/* 左向け */
		ir = LightSensor_getBrightness(this->lightSensor);
		if((ir <= (black+shani) && ir >= (black-shani)) || flg == 1){
		flg = 1;
		Motor_rotate(this->rightMotor, -speed);/* 右向け */
		break;}
		systick_wait_ms(4);
		}

	oldR = -Motor_getAngle(this->rightMotor);

NolineTracer_set(this->nolineTracer, tyokkaku, -speed, 0);
		while(nowR - oldR <= seach_range){
		nowR = -Motor_getAngle(this->rightMotor);
NolineTracer_run(this->nolineTracer);/* 右向け */
		ir = LightSensor_getBrightness(this->lightSensor);
		if((ir <= (black+shani) && ir >= (black-shani)) || flg == 1){
		flg = 1;
		Motor_rotate(this->rightMotor, speed);/* 左向け */
		break;}
		systick_wait_ms(4);
		}

	}else{/* 引数が左側走行だったら */

NolineTracer_set(this->nolineTracer, tyokkaku, speed, 0);
		while(((nowL - oldL)-(nowR - oldR)) <= seach_range){
		nowR = -Motor_getAngle(this->rightMotor);
		nowL = -Motor_getAngle(this->leftMotor);
NolineTracer_run(this->nolineTracer);/* 左向け */
		ir = LightSensor_getBrightness(this->lightSensor);
		if(ir <= (black+shani) && ir >= (black-shani)){
		flg = 1;
		Motor_rotate(this->rightMotor, -speed);/* 右向け */
		break;}
		systick_wait_ms(4);
		}

	oldR = -Motor_getAngle(this->rightMotor);
	oldL = -Motor_getAngle(this->leftMotor);

NolineTracer_set(this->nolineTracer, tyokkaku, -speed, 0);
		while((nowR - oldR)-(nowL - oldL) <= (seach_range*2)){
		nowR = -Motor_getAngle(this->rightMotor);
		nowL = -Motor_getAngle(this->leftMotor);
NolineTracer_run(this->nolineTracer);/* 右向け */
		ir = LightSensor_getBrightness(this->lightSensor);
		if((ir <= (black+shani) && ir >= (black-shani)) || flg == 1){
		flg = 1;
		Motor_rotate(this->rightMotor, speed);/* 左向け */
		break;}
		systick_wait_ms(4);
		}

NolineTracer_set(this->nolineTracer, tyokkaku, speed, 0);
		while(((nowL - oldL)-(nowR - oldR)) <= seach_range){
		nowR = -Motor_getAngle(this->rightMotor);
		nowL = -Motor_getAngle(this->leftMotor);
NolineTracer_run(this->nolineTracer);/* 左向け */
		ir = LightSensor_getBrightness(this->lightSensor);
		if((ir <= (black+shani) && ir >= (black-shani)) || flg == 1){
		flg = 1;
		Motor_rotate(this->rightMotor, -speed);/* 右向け */
		break;}
		systick_wait_ms(4);
		}

	}


	if(RorL == 1){/* 引数が右側走行だったら */
NolineTracer_set(this->nolineTracer, tyokkaku, -speed, 0);
		while(ir >= target){/* targetより黒寄りの間繰り返す */
NolineTracer_run(this->nolineTracer);/* 右向け */
		ir = LightSensor_getBrightness(this->lightSensor);
		}
	}else if(RorL == 2){
NolineTracer_set(this->nolineTracer, tyokkaku, speed, 0);
		while(ir >= target){/* targetより黒寄り */
NolineTracer_run(this->nolineTracer);/* 右向け */
		ir = LightSensor_getBrightness(this->lightSensor);
		}
	}





	NolineTracer_set(this->nolineTracer, 0, 0, 0);
	while(SC_Time(this->stopConditions, 750))
	{
		NolineTracer_run(this->nolineTracer);
		systick_wait_ms(4);
	}



	LineTracer_set(this->lineTracer, 20, 0.3);
	while(SC_Distanse(this->stopConditions, 300))
	{
		LineTracer_trace(this->lineTracer, Target);
		systick_wait_ms(4);
	}


}


