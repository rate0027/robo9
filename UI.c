#include <stdlib.h>
#include "ecrobot_interface.h"
#include "kernel.h"
#include "UI.h"

void Ui_init(Ui* this)
{
}

void Ui_start(Ui* this)
{
	while(1)
	{
				
		if(TouchSensor_getpush(this->touchSensor))
		{
			break;
		}
	}
}

unsigned int Ui_calibration(Ui* this)
{	
	while(TouchSensor_getpush(this->touchSensor) == 0){
		this->sensor = LightSensor_getBrightness(this->lightSensor);
	}

	ecrobot_sound_tone(600, 200, 60);
  systick_wait_ms(500);
	return(this->sensor);
} 



void Ui_steerAngle_init(Ui* this)
{
	int i, time = 0, steerAngle[10], rightLimit = 0, leftLimit = 0, zeroAngle = 0;

	while(TouchSensor_getpush(this->touchSensor) == 0)
	{
		systick_wait_ms(4);
	}

	do	/* 右側遊び測定 */
	{
		Motor_rotate(this->steerMotor,10);

		for(i=9; i>=1; i--)
		{
			steerAngle[i] = steerAngle[i-1];
		}

		steerAngle[0] = Motor_getAngle(this->steerMotor);

		systick_wait_ms(4);
	}while(steerAngle[9] != steerAngle[0] || steerAngle[0] == 0);

	ecrobot_sound_tone(640,40,50);
	rightLimit = Motor_getAngle(this->steerMotor);

	for(i=0; i<=9; i++)
	{
		steerAngle[i] = 0;
	}


	do	/* 左側遊び測定*/
	{
		Motor_rotate(this->steerMotor,-10);

		for(i=9; i>=1; i--)
		{
			steerAngle[i] = steerAngle[i-1];
		}

		steerAngle[0] = Motor_getAngle(this->steerMotor);

		systick_wait_ms(4);
	}while(steerAngle[9] != steerAngle[0] || steerAngle[0] >= rightLimit);	
	
	ecrobot_sound_tone(640,40,50);
	leftLimit = Motor_getAngle(this->steerMotor);

	zeroAngle = (rightLimit + leftLimit)/2;
	Motor_moveAngle_set(this->steerMotor, zeroAngle);
	
	while(time <= 500)/* 計算で出した０角度へ */
	{
	Motor_moveAngle_run(this->steerMotor);
	time++;
	systick_wait_ms(4);
	}
	Motor_resetAngle(this->steerMotor);

	this->steerMotor->angleError = (abs(rightLimit) + abs(leftLimit))/2;

	ecrobot_sound_tone(640,20,50);
	systick_wait_ms(50);
	ecrobot_sound_tone(640,20,50);
} 
