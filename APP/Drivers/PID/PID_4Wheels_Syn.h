/*
 * pid.h
 *
 *  Created on: Jul 21, 2021
 *      Author: 李健
 */

#ifndef PID_PID_H_
#define PID_PID_H_

#include "main.h"
#include "app_main.h"
#include "math.h"


void pid_speed(float targetA, float targetB, float targetC, float targetD);//进行pid到指定转速
void PidWheels_Init(void);

typedef struct
{
	float Target_value;  //目标值
	float Current_value;  //当前值
	float PWM;  //PWM
	float Err;  //目前误差
	float Last_Err;  //上一次误差
	float Kp,Ki,Kd;  //比例常数，积分常数，微分常数
	float output;  //PID输出，通常作为控制执行器的变量
	float integral;  //积分值
}PID_TypeDef;

#endif /* PID_PID_H_ */
