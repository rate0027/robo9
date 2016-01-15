
#include "SonarSensor.h"


void SonarSensor_init(SonarSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
}

unsigned int SonarSensor_getDistanse(SonarSensor* this)
{
	return ecrobot_get_sonar_sensor(this->inputPort);
}


