
#include "TouchSensor.h"



void TouchSensor_init(TouchSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
}

BOOL TouchSensor_getpush(TouchSensor* this)
{
	return ecrobot_get_touch_sensor(this->inputPort);
}
