
#if !defined(CA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_)
#define CA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_

#include "../dev/LightSensor.h"
#include "../dev/TouchSensor.h"
#include "../dev/Motor.h"

typedef struct Ui
{
	int sensor;
	TouchSensor *touchSensor;
	LightSensor *lightSensor;	
	Motor*			 steerMotor;
} Ui;

void Ui_init(Ui* this);
void Ui_start(Ui* this);
unsigned int Ui_calibration(Ui* this);
void Ui_steerAngle_init(Ui* this);


#endif /*!defined(CA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_)*/
