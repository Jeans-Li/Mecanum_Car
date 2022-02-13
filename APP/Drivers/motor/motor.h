/*
 * motor.h
 *
 *  Created on: Jul 12, 2021
 *      Author: 李健
 */

#ifndef DRIVERS_MOTOR_MOTOR_H_
#define DRIVERS_MOTOR_MOTOR_H_

#include "main.h"
#include "tim.h"
#include "time.h"


//定义电机状态
#define GO    0// 前进
#define BACK  1//后退
#define STOP  2//停车

/*车速控制
 *
 */
#define car_forward_init 10000
#define car_backward_init 5000
#define car_leftward_init 5000
#define car_rightward_init 5000
#define car_leftforward_init 5000
#define car_rightforward_init 5000
#define car_leftbackward_init 5000
#define car_rightbackward_init 5000
#define car_clockwise_init 2500
#define car_counterclockwise_init 2500
#define car_differential_turn_high_init 2000
#define car_differential_turn_low_init 1000


uint16_t Read_Encoder(uint8_t TIMX);

void zkb_init(void);

void MOTOR_PWM_OUTA(int ZKB_A);

void MOTOR_PWM_OUTB(int ZKB_B);

void MOTOR_PWM_OUTC(int ZKB_C);

void MOTOR_PWM_OUTD(int ZKB_D);

void MOTOR_PWM_Out(int ZKB_A,int ZKB_B,int ZKB_C,int ZKB_D);

void MOTOR_A(char state);
void MOTOR_B(char state);
void MOTOR_C(char state);
void MOTOR_D(char state);

void Car_Go(void);
void Car_Back(void);
void Car_Turn_Right(void);
void Car_Turn_Left(void);
void Car_Stop(void);
//void Car_Right_45Q(void);
//void Car_Right_45H(void);
//void Car_Left_45Q(void);
//void Car_Left_45H(void);
//void Car_Forward_Left(void);
//void Car_Forward_Right(void);

void motor_encode_init(void);

//=============计时==============//
void TimeEnd(void);
void TimeStart(void);//计时开始
float Get_Time(void);//计时结束并返回时间
/*
 * 加减速度
 */
#define zkb_step 1000
#define change_max 8400
#define change_min 1000//变速上下限制
int change_zkb(int change_zkb_flag, int zkb_now);

typedef struct
{//ABCD的转速
	float A;
	float B;
	float C;
	float D;
} motor_speed_t;

typedef struct
{//ABCD共转圈数
	float A;
	float B;
	float C;
	float D;
}MotorRevCon__;

#endif /* DRIVERS_MOTOR_MOTOR_H_ */
