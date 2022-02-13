/*
 * motor_read.c
 *
 *  Created on: Aug 2, 2021
 *      Author: Renge
 */

#include "motor.h"
#include "math.h"

#define Tim2Cnt __HAL_TIM_GET_COUNTER(&htim2)
#define Tim4Cnt __HAL_TIM_GET_COUNTER(&htim4)
#define Tim8Cnt __HAL_TIM_GET_COUNTER(&htim8)
#define Tim5Cnt __HAL_TIM_GET_COUNTER(&htim5)



motor_speed_t Motor_Speed = {0,0,0,0};
MotorRevCon__ MotorRevCon = {0,0,0,0};//初始化转数

float Time = 0; //计时
int tf = 0;//计时开始或结束标志位

/*
 * 初始化函数
 */
void motor_encode_init(void)
{
	HAL_TIM_Base_Start_IT(&htim6);//开启计时器中断
	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);// A轮编码器
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);// B轮编码器
	HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_ALL);// C轮编码器
	HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL);// D轮编码器
	__HAL_TIM_SET_COUNTER(&htim5,30000);  // 计数器还原
	__HAL_TIM_SET_COUNTER(&htim8,30000);
	__HAL_TIM_SET_COUNTER(&htim4,30000);
	__HAL_TIM_SET_COUNTER(&htim2,30000);
}

static float limit(float val, int lim, int last_val)//限幅
{
	float limitout;
	if(val > lim) limitout = last_val;
	else limitout = val;
	return limitout;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == (&htim6))//读取其速度
	{
		//获取电机速度并计算，10.4变成r/min的除以系数，(1/每转脉冲)/0.1s 变为转每分钟。
//		Motor_Speed.A = limit((float)((65535-__HAL_TIM_GET_COUNTER(&htim2))/(1820/600)), 200, Motor_Speed.A);//计算速度并限幅
//		Motor_Speed.B = limit((float)((__HAL_TIM_GET_COUNTER(&htim4))/(1820/600)), 200, Motor_Speed.B);
//		Motor_Speed.C = limit((float)((__HAL_TIM_GET_COUNTER(&htim8))/(1820/600)), 200, Motor_Speed.C);
//		Motor_Speed.D = limit((float)((65535-__HAL_TIM_GET_COUNTER(&htim5))/(1820/600)), 200, Motor_Speed.D);

		Motor_Speed.A = limit(((float)abs(Tim2Cnt - 30000))/(1820/600), 200, Motor_Speed.A);//计算速度并限幅
		Motor_Speed.B = limit(((float)abs(Tim4Cnt - 30000))/(1820/600), 200, Motor_Speed.B);
		Motor_Speed.C = limit(((float)abs(Tim8Cnt - 30000))/(1820/600), 200, Motor_Speed.C);
		Motor_Speed.D = limit(((float)abs(Tim5Cnt - 30000))/(1820/600), 200, Motor_Speed.D);

		//*********获取转数*********//
		//轮子没转一周计数器应改变4680
		/*限幅为每100ms最大转十圈，即防止静止时不断计数。因为，A、D轮子为反向脉冲
		 * 初始值为0，0xff - 0 = 0xff即计数错误。
		 */
		MotorRevCon.A += limit(((float)abs(Tim2Cnt - 30000)) /1820, 10, 0);
		MotorRevCon.B += limit(((float)abs(Tim4Cnt - 30000)) /1820, 10, 0);
		MotorRevCon.C += limit(((float)abs(Tim8Cnt - 30000)) /1820, 10, 0);
		MotorRevCon.D += limit(((float)abs(Tim5Cnt - 30000)) /1820, 10, 0);
//
		__HAL_TIM_SET_COUNTER(&htim5,30000);  // 计数器还原
		__HAL_TIM_SET_COUNTER(&htim8,30000);
		__HAL_TIM_SET_COUNTER(&htim4,30000);
		__HAL_TIM_SET_COUNTER(&htim2,30000);

//		__HAL_TIM_SET_COUNTER(&htim5,0);  // 计数器还原
//			__HAL_TIM_SET_COUNTER(&htim8,0);
//			__HAL_TIM_SET_COUNTER(&htim4,0);
//			__HAL_TIM_SET_COUNTER(&htim2,0);
	}

	//计时部分
	if (tf) Time ++ ;//计时判断
	if(Time > 10000) TimeEnd();//溢出中止

}

//=========计时部分=========//
void TimeReset(void)
{
	Time = 0;
	tf = 0;
}
void TimeStart(void)
{
	tf = 1;
}
void TimeEnd(void)
{
	tf = 0;
}

float Get_Time(void)
{
	return Time*0.1;
}
