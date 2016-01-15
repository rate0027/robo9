/****************************************************
 *  PID.c                                         
 *  Created on: 2012/05/05 8:54:38                      
 *  Implementation of the Class ColorJudgement       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "PID.h"
#define LIGHT_BLACK	650	// 黒色の光センサ値
#define DELTA_T 0.004
#define KP 1.55   //0.8
#define KI 0.017 //0.012  
#define KD 0.06 //0.076

int math_limit(int in_val, int min_val, int max_val);

static signed int diff[2];
static float integral;


// 初期化する
void PID_init(PID* this)
{
	this->threshold = LIGHT_BLACK;
	this->change = 1; /* 0==右,1==左 */
}

// 路面の色を判定する
COLOR PID_judgeColor(PID* this)
{
	// 光センサからの取得値を見て
	// 黒以上であれば「黒」を、
	// そうでなければ「黒以外」を返す
	if(LightSensor_getBrightness(this->lightSensor) >= this->threshold)
	{
		return  BLACK;
	}
	else
	{
		return NON_BLACK;
	}
} 


int PID_calc(PID* this, unsigned int target_val)
{
    float p, i, d;
    int sensor_val = LightSensor_getBrightness(this->lightSensor);

    diff[0]  =  diff[1];
    if(this->change == 0)
		{
        diff[1]  =  sensor_val - target_val;
    }
    else if(this->change == 1)
		{
        diff[1]  =  target_val - sensor_val;
    }
    integral += (diff[1] + diff[0]) / 2.0 * DELTA_T;
     
    p = KP * diff[1];
    i = KI * integral;
    d = KD * (diff[1] - diff[0]) / DELTA_T;
     
	return math_limit(p+i+d, -100,100);
}

void PID_changeedge(PID* this)
{
	if(this->change == 0)
	{
		this->change =1;
	}
	else if(this->change ==1)
	{
		this->change = 0;
	}

}

int math_limit(int in_val, int min_val, int max_val)
{
    if(in_val < min_val)
        in_val = min_val;
    else if(in_val > max_val)
        in_val = max_val;

    return in_val;
}


