/*
 * motor.c
 *
 *  Created on: Jul 12, 2021
 *      Author: 李健
 */
/*
 *
 *
        	麦克纳姆轮安装方向

                       TIM2  A轮  \\   ------   //  B轮 TIM4
						     \\   ------  //
							      ------
								  ------
								  ------
							  //  ------  \\
			            TIM5 D轮  //   ------   \\  C轮 TIM8

			//四驱底盘及四轮麦克纳姆轮底盘
			//硬件连接说明：
			timer3 控制ABCD四个轮子的PWM
			TIM3_CH1--PA6--A轮 //左前 ---- 电机驱动1-PWMB
			TIM3_CH2--PA7--B轮 //右前 ---- 电机驱动1-PWMA
			TIM3_CH3--PB1--C轮 //右后 ---- 电机驱动2-PWMB
		    TIM3_CH4--PB0--D轮 //左后 ---- 电机驱动2-PWMA

			A轮：PG2 PG3 控制前后运动    PG2----AIN1，PG3----AIN2
			B轮：PG4 PG5 控制前后运动    PG4----BIN1，PG5----BIN2
			C轮：PG8，PD7控制前后运动   PG8 --- BIN1，PD7---BIN1
			D轮：PG7，PG6控制前后运动  PG7 --- AIN1，PG6 ---AIN2
 */
#include "motor.h"
#include "app_main.h"
/*
 * 初始化参数
 */

int car_forward = car_forward_init;
int car_backward = car_backward_init;
int car_leftward = car_leftward_init;
int car_rightward = car_rightward_init;
int car_leftforward = car_leftforward_init;
int car_rightforward = car_rightforward_init;
int car_leftbackward = car_leftbackward_init;
int car_rightbackward = car_rightbackward_init;
int car_clockwise = car_clockwise_init;
int car_counterclockwise = car_counterclockwise_init;
int car_differential_turn_high = car_differential_turn_high_init;
int car_differential_turn_low = car_differential_turn_low_init;

void zkb_init(void)
{
	car_forward = car_forward_init;
	car_backward = car_backward_init;
	car_leftward = car_leftward_init;
	car_rightward = car_rightward_init;
	car_leftforward = car_leftforward_init;
	car_rightforward = car_rightforward_init;
	car_leftbackward = car_leftbackward_init;
	car_rightbackward = car_rightbackward_init;
	car_clockwise = car_clockwise_init;
	car_counterclockwise = car_counterclockwise_init;
	car_differential_turn_high = car_differential_turn_high_init;
	car_differential_turn_low = car_differential_turn_low_init;
}

void zkb_favorite_1(void)
{
	car_forward = 2000;
	car_backward = 2000;
	car_leftward = 2000;
	car_rightward = 2000;
	car_leftforward = 2000;
	car_rightforward = 2000;
	car_leftbackward = 2000;
	car_rightbackward = 2000;
	car_clockwise = 2000;
	car_counterclockwise = 2000;
	car_differential_turn_high = 2000;
	car_differential_turn_low = 0;
}

int change_zkb_flag = 0;//需要引入主函数中。

//*************************四路电机占空比调节***************************//
//数值 0-8400  占空比=设置值/3600
//电机驱动L298N建议设置65%以上占空比
//***************************占空比调节***************************//

void motor_pwm_init()
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);    //�?启pwm输出
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);    //�?启pwm输出
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);    //�?启pwm输出
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);    //�?启pwm输出

	//红外遥控定时�?
	//	HAL_TIM_Base_Start_IT(&htim1);     //定时器更新时、产生中�?
	//	HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);    //启动输入捕获中断
}

void MOTOR_PWM_OUTA(int ZKB_A)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,ZKB_A);
}
void MOTOR_PWM_OUTB(int ZKB_B)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,ZKB_B);
}
void MOTOR_PWM_OUTC(int ZKB_C)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,ZKB_C);
}
void MOTOR_PWM_OUTD(int ZKB_D)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,ZKB_D);
}

/*******************四个轮子占空比调节********************
 *
 */
void MOTOR_PWM_Out(int ZKB_A,int ZKB_B,int ZKB_C,int ZKB_D)
{
	//A轮：左前轮
	MOTOR_PWM_OUTA(ZKB_A);
	//B轮：右前轮
	MOTOR_PWM_OUTB(ZKB_B);
	//C轮：右后轮
	MOTOR_PWM_OUTC(ZKB_C);
	//D轮：左后轮
	MOTOR_PWM_OUTD(ZKB_D);
}

/**************************************************************************
函数功能：单位时间读取编码器计数
入口参数：定时器
返回  值：速度值
 **************************************************************************/
uint16_t Read_Encoder(uint8_t TIMX)
{
	int Encoder_TIM;
	switch(TIMX)
	{
	case 2:
		Encoder_TIM = __HAL_TIM_GET_COUNTER(&htim2);
		__HAL_TIM_SET_COUNTER(&htim2,30000);
		break;
	case 4:
		Encoder_TIM = __HAL_TIM_GET_COUNTER(&htim4);
		__HAL_TIM_SET_COUNTER(&htim4,30000);

		break;
	case 5:
		Encoder_TIM = __HAL_TIM_GET_COUNTER(&htim5);
		__HAL_TIM_SET_COUNTER(&htim5,30000);
		break;
	case 8:
		Encoder_TIM = __HAL_TIM_GET_COUNTER(&htim8);
		__HAL_TIM_SET_COUNTER(&htim8,30000);
		break;
	}
	return Encoder_TIM;
}


//左前A电机
void MOTOR_A(char state)
{
	if(state == GO)//左前电机前进
	{
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3, SET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_2,RESET);
	}
	if(state == BACK)//左前电机后退
	{
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_2, SET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,RESET);
	}
	if(state == STOP)//停转
	{
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,RESET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_2,RESET);
	}
}

//右前B电机
void MOTOR_B(char state)
{
	if(state == GO)//右前电机前进
	{
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_4, SET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_5,RESET);
	}
	if(state == BACK)//右前电机后退
	{
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_4,RESET);

	}
	if(state == STOP)//停转
	{
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_5,RESET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_4,RESET);
	}
}

//左后C电机
void MOTOR_C(char state)
{
	if(state == GO)//右后电机前进
	{
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7, RESET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_8,SET);

	}
	if(state == BACK)//右后电机后退
	{
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_8, RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,SET);
	}
	if(state == STOP)//停转
	{
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,RESET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_8,RESET);
	}
}

//右后D电机
void MOTOR_D(char state)
{
	if(state == GO)//左后电机前进
	{
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_7, SET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_6,RESET);
	}
	if(state == BACK)//左后电机后退
	{
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_6, SET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_7,RESET);
	}
	if(state == STOP)//停转
	{
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_7,RESET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_6,RESET);
	}
}

//***************************前进***************************//
//只要配置INx()的状态就可以改变电机转动方向
void Car_Go(void)
{
	//左前电机 前    //右前电机 前
	MOTOR_A(GO);       MOTOR_B(GO);
	//左后电机 前   //右后电机 前
	MOTOR_D(GO);       MOTOR_C(GO);
}

void Car_Back(void)
{
	//左前电机 后    //右前电机 后
	MOTOR_A(BACK);       MOTOR_B(BACK);
	//左后电机 后   //右后电机 后
	MOTOR_D(BACK);       MOTOR_C(BACK);
}

////***************************原地左转圈***************************//
//void Car_Turn_Left_Around(void)
//{
//	//左前电机 后    //右前电机 前
//	MOTOR_A(BACK);       MOTOR_B(GO);
//	//左后电机 后   //右后电机 前
//	MOTOR_D(BACK);       MOTOR_C(GO);
//}
////***************************原地右转圈***************************//
//void Car_Turn_Right_Around(void)
//{
//	//左前电机 前    //右前电机 后
//	MOTOR_A(GO);       MOTOR_B(BACK);
//	//左后电机 前   //右后电机 后
//	MOTOR_D(GO);       MOTOR_C(BACK);
//}


////***************************右横运动***************************//
//void Car_Right(void)
//{
//	car_rightward = change_zkb(change_zkb_flag,car_rightward);
//	MOTOR_PWM_Out(car_rightward,car_rightward, car_rightward, car_rightward);
//	//左前电机     //右前电机
//	MOTOR_A(GO);       MOTOR_B(BACK);
//	//左后电机    //右后电机
//	MOTOR_D(BACK);       MOTOR_C(GO);
//}
////***************************左横运动***************************//
//void Car_Left(void)
//{
//	car_leftward = change_zkb(change_zkb_flag,car_leftward);
//	MOTOR_PWM_Out(car_leftward,car_leftward, car_leftward, car_leftward);
//	//左前电机     //右前电机
//	MOTOR_A(BACK);       MOTOR_B(GO);
//	//左后电机    //右后电机
//	MOTOR_D(GO);       MOTOR_C(BACK);
//}
////***************************右前45°运动***************************//
//void Car_Right_45Q(void)
//{
//	car_rightforward = change_zkb(change_zkb_flag,car_rightforward);
//	MOTOR_PWM_Out(car_rightforward,car_rightforward, car_rightforward, car_rightforward);
//	//左前电机     //右前电机
//	MOTOR_A(GO);       MOTOR_B(STOP);
//	//左后电机    //右后电机
//	MOTOR_D(STOP);       MOTOR_C(GO);
//}
////***************************右后45°运动***************************//
//void Car_Left_45H(void)
//{
//	car_leftbackward = change_zkb(change_zkb_flag,car_leftbackward);
//	MOTOR_PWM_Out(car_leftbackward,car_leftbackward, car_leftbackward, car_leftbackward);
//	//左前电机     //右前电机
//	MOTOR_A(BACK);       MOTOR_B(STOP);
//	//左后电机    //右后电机
//	MOTOR_D(STOP);       MOTOR_C(BACK);
//}
////***************************左前45运动***************************//
//void Car_Left_45Q(void)
//{
//	car_leftforward = change_zkb(change_zkb_flag,car_leftforward);
//	MOTOR_PWM_Out(car_leftforward,car_leftforward, car_leftforward, car_leftforward);
//	//左前电机     //右前电机
//	MOTOR_A(STOP);       MOTOR_B(GO);
//	//左后电机    //右后电机
//	MOTOR_D(GO);       MOTOR_C(STOP);
//}
////***************************左后45运动***************************//
//void Car_Right_45H(void)
//{
//	car_rightbackward = change_zkb(change_zkb_flag,car_rightbackward);
//	MOTOR_PWM_Out(car_rightbackward,car_rightbackward, car_rightbackward, car_rightbackward);
//	//左前电机     //右前电机
//	MOTOR_A(STOP);       MOTOR_B(BACK);
//	//左后电机    //右后电机
//	MOTOR_D(BACK);       MOTOR_C(STOP);
//}
//***************************停车***************************//
void Car_Stop(void)
{
	//左前电机 停    //右前电机 停
	MOTOR_A(STOP);       MOTOR_B(STOP);
	//左后电机 停   //右后电机 停
	MOTOR_D(STOP);       MOTOR_C(STOP);
}

//***************************前进右转***************************//
void Car_Turn_Right(void)
{
	MOTOR_A(GO);       MOTOR_B(BACK);
	MOTOR_D(GO);       MOTOR_C(BACK);
}
//***************************左转***************************//
void Car_Turn_Left(void)
{
	MOTOR_A(BACK);       MOTOR_B(GO);
	MOTOR_D(BACK);       MOTOR_C(GO);
}



char ch[15];
int change_zkb(int change_zkb_flag,int zkb_now)
{
	if(change_zkb_flag == 1 )
	{
		zkb_now += zkb_step;
		change_zkb_flag = 0;
		sprintf(ch,"zkb_now:%d\n",zkb_now);
		HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 15, 0xFFFF);
	}
	if(change_zkb_flag == 2 )
	{
		zkb_now -= zkb_step;
		change_zkb_flag = 0;
		sprintf(ch,"zkb_now:%d\n",zkb_now);
		HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 15, 0xFFFF);
	}
	if(zkb_now >= 8400)
	{
		zkb_now = change_max;
	}
	if(zkb_now <= 1000)
	{
		zkb_now = change_min;
	}
	return zkb_now;
}
