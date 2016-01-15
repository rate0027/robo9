/****************************************************
 *  GyroSensor.c                                         
 *  Created on: 2012/05/05 7:35:33                      
 *  Implementation of the Class GyroSensor       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "GyroSensor.h"
#define GYRO_OFFSET  610



// ‰Šú‰»‚·‚é
void GyroSensor_init(GyroSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
	this->offset = GYRO_OFFSET;
}

unsigned int GyroSensor_getAngularVelocity(GyroSensor* this)
{
	return ecrobot_get_gyro_sensor(this->inputPort);
}

unsigned int GyroSensor_getOffset(GyroSensor* this)
{
	return this->offset;
} 




