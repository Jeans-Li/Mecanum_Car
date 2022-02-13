/*
 * Wheel->c
 *
 *  Created on: 2021年10月29日
 *      Author: Fukami
 */


#include "../PID/PID_4Wheels_Syn.h"
#define _KP 30
#define _KI 0
#define _KD 3
#define _IniPWM 1000
#define _MaxPWM 6000




extern motor_speed_t  Motor_Speed;//速度从别的地方读取
PID_TypeDef A, B, C, D;


//初始化PID各项参数
static void PidInit(PID_TypeDef *Wheel)
{
	Wheel->Target_value = 0.0;
	Wheel->Current_value = 0.0;
	Wheel->PWM = _IniPWM;
	Wheel->Err = 0.0;
	Wheel->Last_Err = 0.0;
	Wheel->output = 0.0;
	Wheel->integral = 0.0;
	Wheel->Kp = _KP;
	Wheel->Ki = _KI;
	Wheel->Kd = _KD;     //比例常数，积分常数，微分常数的调整非常重要，这里的参数是经过几次试验得出的经验参数
}

//初始化各轮子
void PidWheels_Init(void)//初始化各轮子Pid参数
{
	PidInit(&A);
	PidInit(&B);
	PidInit(&C);
	PidInit(&D);
}

//获取不同轮子的当前值
static void GetCurrent(PID_TypeDef *wheel)//根据不同的车轮获取相同的速度
{
	if(wheel == &A) wheel->Current_value = Motor_Speed.A;
	if(wheel == &B) wheel->Current_value = Motor_Speed.B;
	if(wheel == &C) wheel->Current_value = Motor_Speed.C;
	if(wheel == &D) wheel->Current_value = Motor_Speed.D;
}



//限幅
static float limit(float val, int lim)
{
	float limitout;
	if(val > lim) limitout = lim;
	else limitout = val;
	return limitout;
}


static void Pid_Operate(PID_TypeDef *Wheel, float target)
{

	Wheel->Target_value = target;  //确定目标值
	GetCurrent(Wheel);
	Wheel->Err = Wheel->Target_value - Wheel->Current_value;  //计算偏差量
	Wheel->integral += Wheel->Err;  //计算和 但是对四轮调速用不到积分项，取消其不断累加防止溢出
	Wheel->output = Wheel->Kp*Wheel->Err + Wheel->Ki*Wheel->integral + Wheel->Kd* (Wheel->Err-Wheel->Last_Err);  //PID运算
	Wheel->Last_Err = Wheel->Err;  //将当前误差值存入上一误差值
	Wheel->PWM = limit(Wheel->output,800) + Wheel->PWM;  //将当前值更新为PID的输出值//输出限幅
	Wheel->PWM = limit(Wheel->PWM, _MaxPWM);
}



void pid_speed(float targetA, float targetB, float targetC, float targetD)
{
		Pid_Operate(&A, targetA);MOTOR_PWM_OUTA(A.PWM);//进行Pid运算后调整PWM
		Pid_Operate(&B, targetB);MOTOR_PWM_OUTB(B.PWM);
		Pid_Operate(&C, targetC);MOTOR_PWM_OUTC(C.PWM);
		Pid_Operate(&D, targetD);MOTOR_PWM_OUTD(D.PWM);
		HAL_Delay(100);
}
