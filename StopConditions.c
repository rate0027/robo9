/****************************************************
 *  StopConditions.c                                         
 *  Created on: 2015/08/20 16:45                  
 *  Implementation of the Class StopConditions       
 *  Original author: daichi.nakamura                     
 ****************************************************/

#include "StopConditions.h"
#define NULL 0;
#define SONAR_ALERT_DISTANCE 30 /* 超音波センサによる障害物検知距離[cm] */


void StopConditions_init(StopConditions* this)
{
	this->Count = NULL;
}


int SC_Distanse(StopConditions* this, int distanse)
{
	long angle;
	angle = Motor_getAngle(this->leftMotor);

	if(angle <= 0 && distanse < 0)
	{
		angle *= -1;
		distanse *= -1;
	}
	else if(angle >= 0 && distanse < 0)
	{
		distanse *= -1;
	}
	else{/* donothig */}

	if(angle >= distanse)
	{
		ecrobot_sound_tone(900, 200, 100);
		Motor_resetAngle(this->leftMotor);
		Motor_resetAngle(this->rightMotor);
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

int SC_Distanse_R(StopConditions* this, int distanse)
{
	long angle;
	angle = Motor_getAngle(this->rightMotor);

	if(angle <= 0 && distanse < 0)
	{
		angle *= -1;
		distanse *= -1;
	}
	else if(angle >= 0 && distanse < 0)
	{
		distanse *= -1;
	}
	else{/* donothig */}

	if(angle >= distanse)
	{
		ecrobot_sound_tone(900, 200, 100);
		Motor_resetAngle(this->leftMotor);
		Motor_resetAngle(this->rightMotor);
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

int SC_Time(StopConditions* this, int Time)
{

	int Count = 0;
	if(Count >= Time)
	{
		Count = 0;
		ecrobot_sound_tone(900, 200, 100);
		return FALSE;
	}
	else
	{
		return TRUE;
		Count++;
	}

}


int SC_Gyro(StopConditions* this, int gyro)
{
	unsigned int velocity;
	velocity = GyroSensor_getAngularVelocity(this->gyroSensor);

	if(velocity >= gyro)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

int SC_Sonar(StopConditions* this)
{
	signed int sonar_distance;
	sonar_distance = SonarSensor_getDistanse(this->sonarSensor);

	if ((sonar_distance <= SONAR_ALERT_DISTANCE) && (sonar_distance > 0))  /* 不等号 */
	{
		return FALSE; /* 障害物を検知 */
	}
	else
	{
		return TRUE; /* 障害物無し */
	}
}

int SC_Grey(StopConditions* this, int target)
{
	int brightness;
	brightness = LightSensor_getBrightness(this->lightSensor);
	

	if(brightness == (target-16) )
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

int SC_Flag(StopConditions* this, int isEnd){

  if(isEnd == TRUE)
  { 
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}


int SC_Cross(StopConditions* this, int target)
{
	int brightness;
	brightness = LightSensor_getBrightness(this->lightSensor);
	

	if(brightness >= (target) )
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

