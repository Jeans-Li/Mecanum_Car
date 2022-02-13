/*
 * PID_Firmed_Dis.h
 *
 *  Created on: Oct 29, 2021
 *      Author: Renge
 */

#ifndef DRIVERS_PID_PID_FIRMED_DIS_H_
#define DRIVERS_PID_PID_FIRMED_DIS_H_

#include "main.h"
#include "app_main.h"
//
//
//typedef struct
//{
//	float Target_value;  //目标值
//	float Current_value;  //当前值
//	float PWM;  //PWM
//	float Err;  //目前误差
//	float Last_Err;  //上一次误差
//	float Kp,Ki,Kd;  //比例常数，积分常数，微分常数
//	float output;  //PID输出，通常作为控制执行器的变量
//	float integral;  //积分值
//}PID_TypeDef;
//

void PID_Init();
float PID_operation(float value);


#endif /* DRIVERS_PID_PID_FIRMED_DIS_H_ */
