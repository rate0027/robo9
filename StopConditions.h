
#if !defined(SC_ASDFGHJKLA_INCLUDE_)
#define SC_ASDFGHJKLA_INCLUDE_


#include "ecrobot_interface.h"
#include "kernel.h"

#include "./dev/Motor.h"
#include "./dev/GyroSensor.h"
#include "./dev/SonarSensor.h"
#include "./dev/LightSensor.h"

typedef struct StopConditions
{
	int Count;

	Motor *leftMotor;
	Motor *rightMotor;
	GyroSensor *gyroSensor;
	SonarSensor *sonarSensor;
	LightSensor *lightSensor;
} StopConditions;


void StopConditions_init(StopConditions* this);

int SC_Distanse(StopConditions* this, int distanse);
int SC_Distanse_R(StopConditions* this, int distanse);
int SC_Time(StopConditions* this, int Time);
int SC_Gyro(StopConditions* this, int gyro);
int SC_Sonar(StopConditions* this);
int SC_Grey(StopConditions* this, int target);
int SC_Flag(StopConditions* this, int isend);
int SC_Cross(StopConditions* this, int target);

#endif /*!defined(SC_ASDFGHJKLA_INCLUDE_)*/
