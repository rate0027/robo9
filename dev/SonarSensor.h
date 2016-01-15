
#if !defined(SS_ASDFGHKL_INCLUDE_)
#define SS_ASDFGHJKL_INCLUDE_

#include "ecrobot_interface.h"
#include "kernel.h"

typedef struct SonarSensor
{
	SENSOR_PORT_T inputPort;
} SonarSensor;

void SonarSensor_init(SonarSensor* this, SENSOR_PORT_T inputPort);
unsigned int SonarSensor_getDistanse(SonarSensor* this);

#endif /* !defined(SS_ASDFGHJKL_INCLUDE_) */
