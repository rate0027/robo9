
#if !defined(TS_ASDFGHKLA_INCLUDE_)
#define TS_ASDFGHJKLA_INCLUDE_

#include "ecrobot_interface.h"
#include "kernel.h"

typedef struct TouchSensor
{
	SENSOR_PORT_T inputPort;
} TouchSensor;


void TouchSensor_init(TouchSensor* this, SENSOR_PORT_T inputPort);
BOOL TouchSensor_getpush(TouchSensor* this);

#endif /* !defined(TS_ASDFGHJKLA_INCLUDE_) */
