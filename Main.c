//////////////////////////////////////////////////////////
//  main.c
///////////////////////////////////////////////////////////

#include "sce_R/Basic_R.h"
#include "sce_R/FigureL.h"
#include "sce_R/RPark.h"
#include "sce_R/Train.h"
#include "sce_L/Basic_L.h"
#include "sce/Stepup.h"
#include "sce/ColorJudgement.h"
#include "sce/SearchLine.h"
#include "run/LineTracer.h"
#include "run/NolineTracer.h"
#include "app/PID.h"
#include "app/SteerControl.h"
#include "app/RearControl.h"
#include "dev/LightSensor.h"
#include "dev/GyroSensor.h"
#include "dev/Motor.h"
#include "StopConditions.h"
#include "UI.h"

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"




// オブジェクトを静的に確保する
RBasic					rbasic;
FigureL					figureL;
RPark						rPark;
Train						train;
LBasic					lbasic;
Stepup					stepup;
ColorJudgement	colorJudgement;
SearchLine			searchLine;
LineTracer			lineTracer;
NolineTracer		nolineTracer;
Ui							ui;
PID							pid;
SteerControl		steerControl;
RearControl			rearControl;
TouchSensor			touchSensor;
LightSensor			lightSensor;
GyroSensor			gyroSensor;
SonarSensor			sonarSensor;
Motor						leftMotor, rightMotor, steerMotor;
StopConditions	stopConditions;

// デバイス初期化用フック関数
// この関数はnxtOSEK起動時に実行されます。
void ecrobot_device_initialize()
{
	// センサ、モータなどの各デバイスの初期化関数を
	// ここで実装することができます
	// ⇒　光センサ赤色LEDをONにする
	ecrobot_init_bt_slave("LEJOS-OSEK");
	ecrobot_set_light_sensor_active(NXT_PORT_S3);
	ecrobot_init_sonar_sensor(NXT_PORT_S4);
}

// デバイス終了用フック関数
// この関数はSTOPまたはEXITボタンが押された時に実行されます。
void ecrobot_device_terminate()
{
	// センサ、モータなどの各デバイスの終了関数を
	// ここで実装することができます。
	// ⇒　光センサ赤色LEDをOFFにする
	ecrobot_set_light_sensor_inactive(NXT_PORT_S3);
	ecrobot_term_sonar_sensor(NXT_PORT_S4);
	ecrobot_term_bt_connection();
}

// 1msec周期割り込み(ISRカテゴリ2)から起動されるユーザー用フック関数
void user_1ms_isr_type2(void)
{
	// 今回は何も行わない
}

TASK(TaskMain)
{
	// オブジェクト間のリンクを構築する
	rbasic.lineTracer						 = &lineTracer;
	rbasic.nolineTracer					 = &nolineTracer;
	rbasic.stopConditions				 = &stopConditions;
	figureL.lineTracer					 = &lineTracer;
	figureL.nolineTracer				 = &nolineTracer;
	figureL.stopConditions			 = &stopConditions;
	figureL.stepup							 = &stepup;
	rPark.lineTracer						 = &lineTracer;
	rPark.nolineTracer					 = &nolineTracer;
	rPark.stopConditions				 = &stopConditions;
	train.lineTracer						 = &lineTracer;
	train.nolineTracer					 = &nolineTracer;
	train.stopConditions				 = &stopConditions;
	lbasic.lineTracer						 = &lineTracer;
	lbasic.stopConditions				 = &stopConditions;
	stepup.lineTracer						 = &lineTracer;
	stepup.nolineTracer					 = &nolineTracer;
	stepup.stopConditions				 = &stopConditions;
	colorJudgement.lightSensor	 = &lightSensor;
	searchLine.lineTracer				 = &lineTracer;
	searchLine.nolineTracer			 = &nolineTracer;
	searchLine.stopConditions		 = &stopConditions;
	searchLine.lightSensor			 = &lightSensor;
	searchLine.rightMotor				 = &rightMotor;
	searchLine.leftMotor				 = &leftMotor;
	lineTracer.pid							 = &pid;
	lineTracer.steerControl      = &steerControl;
	lineTracer.rearControl       = &rearControl;
	nolineTracer.steerControl		 = &steerControl;
	nolineTracer.rearControl		 = &rearControl;
	nolineTracer.steerMotor			 = &steerMotor;
	ui.touchSensor	             = &touchSensor;
	ui.lightSensor               = &lightSensor;
	ui.steerMotor								 = &steerMotor;
	pid.lightSensor              = &lightSensor;
	rearControl.leftMotor        = &leftMotor;
	rearControl.rightMotor       = &rightMotor;
	steerControl.steerMotor      = &steerMotor;
	stopConditions.leftMotor     = &leftMotor;
	stopConditions.rightMotor    = &rightMotor;
	stopConditions.lightSensor   = &lightSensor;
	stopConditions.gyroSensor    = &gyroSensor;
	stopConditions.sonarSensor   = &sonarSensor;

	// 各オブジェクトを初期化する
	LBasic_init(&lbasic);
	RBasic_init(&rbasic);
	Train_init(&train);
	Stepup_init(&stepup);
	ColorJudgement_init(&colorJudgement);
	LineTracer_init(&lineTracer);
	NolineTracer_init(&nolineTracer);
	Ui_init(&ui);
	PID_init(&pid);
	RearControl_init(&rearControl);
	SteerControl_init(&steerControl);
	TouchSensor_init(&touchSensor, NXT_PORT_S2);
	LightSensor_init(&lightSensor, NXT_PORT_S3);
	SonarSensor_init(&sonarSensor, NXT_PORT_S4);
	GyroSensor_init(&gyroSensor, NXT_PORT_S1);
	Motor_init(&leftMotor, NXT_PORT_A);
	Motor_init(&rightMotor, NXT_PORT_B);
	Motor_init(&steerMotor, NXT_PORT_C);
	StopConditions_init(&stopConditions);

	// UIに開始待ちを依頼する
	unsigned int light = LightSensor_getBrightness(&lightSensor);
	unsigned int gyro = GyroSensor_getAngularVelocity(&gyroSensor);

	Ui_steerAngle_init(&ui);

	unsigned int black, white, Target;
	black = Ui_calibration(&ui);
	white = Ui_calibration(&ui);
	Target = (black + white) * 0.48;

	Ui_start(&ui);

	RBasic_2(&rbasic, Target);

//	FigureL_run(&figureL, Target);
//	Train_run(&train, Target);	

#if 0
	LineTracer_set(&lineTracer, 40, 0.3);
	while(SC_Distanse(&stopConditions, 50))
	{	
		LineTracer_trace(&lineTracer, Target);
		systick_wait_ms(4);
	}
	NolineTracer_set(&nolineTracer, -70, 30, 40);
	while(SC_Distanse(&stopConditions, 90))
	{
		NolineTracer_run(&nolineTracer);	
		systick_wait_ms(4);
	}

	PID_changeedge(&pid);
	LineTracer_set(&lineTracer, 40, 0.3);
	while(SC_Distanse(&stopConditions, 50))
	{	
		LineTracer_trace(&lineTracer, Target);
		systick_wait_ms(4);
	}
#endif


	while(1)
	{
	nxt_motor_set_speed(NXT_PORT_A, 0, 1);
	nxt_motor_set_speed(NXT_PORT_B, 0, 1);
	nxt_motor_set_speed(NXT_PORT_C, 0, 1);	
	}
	ecrobot_bt_adc_data_logger(1,2,light,gyro,Target,6);
}

