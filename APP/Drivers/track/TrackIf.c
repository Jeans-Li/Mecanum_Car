/*
 * TrackIf.c
 *
 *  Created on: 2021年11月8日
 *      Author: Renge
 */

#include "track.h"

#define PWMH 9000
#define PWMM 6000
#define PWML 2000
#define PWMTurn 3000
#define PWMTo 3000

extern MotorRevCon__ MotorRevCon;

void FindCrossInfrontToRound(int StopFlag, float R, int PWMGo)//循迹到指定距离
{
	while(fabs( (MotorRevCon.A + MotorRevCon.B +MotorRevCon.C+MotorRevCon.D)/4 - R) > 0.1)
	{
		MOTOR_PWM_Out(PWMGo, PWMGo, PWMGo, PWMGo);
		Car_Back();
		if(GrayTrack5 == red && GrayTrack4 == white && GrayTrack3 == white)//右偏
		{
			MOTOR_PWM_Out(PWML, PWMH , PWMH ,PWML);
		}
		if(GrayTrack5 == white && GrayTrack4 == white && GrayTrack3 == red)//左偏
		{
			MOTOR_PWM_Out(PWMH, PWML, PWML, PWMH);
		}
	}
	//		if(GrayTrack2 == red)//右大偏
	//		{
	//			Car_Turn_Left();
	//		}
	//		if(GrayTrack6 == red)//左大偏
	//		{
	//			Car_Turn_Right();
	//		}

	if(StopFlag)
	{
		Car_Go();//反转一下以刹车
		HAL_Delay(20);
		Car_Stop();//停车
		HAL_Delay(150);
	}

}

void FindCrossInfront(int StopFlag)
{
	while(GrayTrack3 == white || GrayTrack4 == white || GrayTrack5 == white)
	{
		MOTOR_PWM_Out(PWMM, PWMM, PWMM, PWMM);
		Car_Back();
		if(GrayTrack5 == red && GrayTrack4 == white && GrayTrack3 == white)//右偏
		{
			MOTOR_PWM_Out(PWML, PWMH , PWMH ,PWML);
		}
		if(GrayTrack5 == white && GrayTrack4 == white && GrayTrack3 == red)//左偏
		{
			MOTOR_PWM_Out(PWMH, PWML, PWML, PWMH);
		}
	}
//	if(GrayTrack2 == red)//右大偏
//	{
//		Car_Turn_Left();
//	}
//	if(GrayTrack6 == red)//左大偏
//	{
//		Car_Turn_Right();
//	}

	if(StopFlag)
	{
		Car_Go();//反转一下以刹车
		HAL_Delay(20);
		Car_Stop();//停车
		HAL_Delay(150);
	}
}

//
//	Car_Back();//到转弯点
//	MOTOR_PWM_Out(PWMTo, PWMTo, PWMTo, PWMTo);
//	HAL_Delay(600);
//	Car_Stop();

void FindCrossBack()
{
	MOTOR_PWM_Out(PWMM, PWMM, PWMM, PWMM);
	Car_Go();
	while(Track2 == white || Track3 == white || Track4 == white)
	{
		MOTOR_PWM_Out(PWMM, PWMM, PWMM, PWMM);
		Car_Go();
		if(Track2 == red && Track3 == white && Track4 == white)  //右偏
		{
			MOTOR_PWM_Out(PWML, PWMH , PWMH ,PWML);
		}
		if(Track2 == white && Track3 == white && Track4 == red)   //左偏
		{
			MOTOR_PWM_Out(PWMH, PWML, PWML, PWMH);
		}
	}

	Car_Back();//反转一下以刹车
	HAL_Delay(20);
	Car_Stop();//停车
	HAL_Delay(150);

	PidWheels_Init();
	ToRound(0, 1.35, 45, 45, 45, 45);//向back开到转向点
	Car_Stop();
}

void FindT5Back(void)//寻找5号病房后的T路口，倒车
{
	MOTOR_PWM_Out(PWMM, PWMM, PWMM, PWMM);
	Car_Go();
	while(Track7 == white || Track2 == white)
	{
		MOTOR_PWM_Out(PWMM, PWMM, PWMM, PWMM);
		Car_Go();
		if(Track2 == red && Track3 == white && Track4 == white)  //右偏
		{
			MOTOR_PWM_Out(PWML, PWMH , PWMH ,PWML);
		}
		if(Track2 == white && Track3 == white && Track4 == red)   //左偏
		{
			MOTOR_PWM_Out(PWMH, PWML, PWML, PWMH);
		}
	}

	Car_Back();//反转一下以刹车
	HAL_Delay(20);
	Car_Stop();//停车
	HAL_Delay(150);

	PidWheels_Init();
	ToRound(0, 1.3, 45, 45, 45, 45);
	Car_Stop();

}

void FindT6Back()
{
	MOTOR_PWM_Out(PWMM, PWMM, PWMM, PWMM);
	Car_Go();
	while(Track3 == white || Track4 == white || Track5 == white)
	{
		MOTOR_PWM_Out(PWMM, PWMM, PWMM, PWMM);
		Car_Go();
		if(Track2 == red && Track3 == white && Track4 == white)  //右偏
		{
			MOTOR_PWM_Out(PWML, PWMH , PWMH ,PWML);
		}
		if(Track2 == white && Track3 == white && Track4 == red)   //左偏
		{
			MOTOR_PWM_Out(PWMH, PWML, PWML, PWMH);
		}
	}

	Car_Back();//反转一下以刹车
	HAL_Delay(20);
	Car_Stop();//停车
	HAL_Delay(150);

	PidWheels_Init();
	ToRound(0, 1.3, 35, 35, 35, 35);
	Car_Stop();
}
void FindT7Back(void)//寻找5号病房后的T路口，倒车
{
	MOTOR_PWM_Out(PWMM, PWMM, PWMM, PWMM);
	Car_Go();
	while(Track3 == white || Track4 == white || Track5 == white)
	{
		MOTOR_PWM_Out(PWMM, PWMM, PWMM, PWMM);
		Car_Go();
		if(Track2 == red && Track3 == white && Track4 == white)  //右偏
		{
			MOTOR_PWM_Out(PWML, PWMH , PWMH ,PWML);
		}
		if(Track2 == white && Track3 == white && Track4 == red)   //左偏
		{
			MOTOR_PWM_Out(PWMH, PWML, PWML, PWMH);
		}
	}

	Car_Back();//反转一下以刹车
	HAL_Delay(20);
	Car_Stop();//停车
	HAL_Delay(150);

	PidWheels_Init();
	ToRound(0, 1.3, 35, 35, 35, 35);
	Car_Stop();

}


void FindT57(void)//寻找57号病房后的T路口
{
	while( GrayTrack2 == white || GrayTrack1 == white)
	{
		MOTOR_PWM_Out(PWMM, PWMM, PWMM, PWMM);
		Car_Back();
		if(GrayTrack5 == red && GrayTrack4 == white && GrayTrack3 == white)//右偏
		{
			MOTOR_PWM_Out(PWML, PWMH , PWMH ,PWML);
		}
		if(GrayTrack5 == white && GrayTrack4 == white && GrayTrack3 == red)//左偏
		{
			MOTOR_PWM_Out(PWMH, PWML, PWML, PWMH);
		}
	}
	Car_Go();//反转一下以刹车
	HAL_Delay(20);
	Car_Stop();//停车
	HAL_Delay(150);


	PidWheels_Init();
	ToRound(1, 1.45, 45, 45, 45, 45);
	Car_Stop();

}



void StopDottedLine(void)
{
	while(GrayTrack1  ==  white && GrayTrack7 == white &&GrayTrack2  ==  white && GrayTrack6 == white )
	{
		MOTOR_PWM_Out(PWMM, PWMM, PWMM, PWMM);
		Car_Back();
		if(GrayTrack5 == red && GrayTrack4 == white && GrayTrack3 == white)//右偏
		{
			MOTOR_PWM_Out(PWML, PWMH , PWMH ,PWML);
		}
		if(GrayTrack5 == white && GrayTrack4 == white && GrayTrack3 == red)//左偏
		{
			MOTOR_PWM_Out(PWMH, PWML, PWML, PWMH);
		}
//		if(GrayTrack5 == white && GrayTrack4 == white && GrayTrack3 == white && GrayTrack2 == red)//右大偏
//		{
//			StopCarInBack();
//			Car_Turn_Right();
//		}
//		if(GrayTrack6 == red&&GrayTrack5 == white && GrayTrack4 == white && GrayTrack3 == white )//左大偏
//		{
//			StopCarInBack();
//			Car_Turn_Left();
//		}
	}
}

void turn_left_90()
{
	MOTOR_PWM_Out(1000, 1000, 1000, 1000);

	PidWheels_Init();
	while(GrayTrack6 == white)
	{
		Car_Turn_Right();
		pid_speed(35, 35,35	,35);

	}
	while(GrayTrack4 == white)
	{
		Car_Turn_Right();
		pid_speed(45, 45,45	,45);
	}
	Car_Stop();
}

//void TurnLeft90InT(void)
//{
//	MOTOR_PWM_Out(1000, 1000, 1000, 1000);
//	PidWheels_Init();
//	while(GrayTrack4 == white)
//	{
//		Car_Turn_Right();
//		pid_speed(45, 45,45	,45);
//	}
//	Car_Stop();
//}
//
//void TurnRight90InT(void)
//{
//	MOTOR_PWM_Out(1000, 1000, 1000, 1000);
//	PidWheels_Init();
//	while(GrayTrack4 == white)
//	{
//		Car_Turn_Left();
//		pid_speed(45, 45,45	,45);
//	}
//	Car_Stop();
//}
void turn_right_90()
{
	MOTOR_PWM_Out(1000, 1000, 1000, 1000);
	PidWheels_Init();
	while(GrayTrack2 == white)
	{
		Car_Turn_Left();
//		MOTOR_PWM_Out(PWMTurn, PWMTurn, PWMTurn, PWMTurn);
		pid_speed(35, 35,35	,35);

	}
	while(GrayTrack4 == white)
	{
		Car_Turn_Left();
//		MOTOR_PWM_Out(PWMTurn, PWMTurn, PWMTurn, PWMTurn);
		pid_speed(35, 35,35	,35);
	}
	Car_Stop();
}

void turn_2_right_90()
{
	MOTOR_PWM_Out(1000, 1000, 1000, 1000);
	PidWheels_Init();
	while(GrayTrack2 == white)
	{
		Car_Turn_Left();
		MOTOR_PWM_Out(PWMTurn, PWMTurn, PWMTurn, PWMTurn);
//		pid_speed(35, 35,35	,35);

	}
	while(GrayTrack4 == white)
	{
		Car_Turn_Left();
		MOTOR_PWM_Out(PWMTurn, PWMTurn, PWMTurn, PWMTurn);
//		pid_speed(45, 45,45	,45);
	}
	Car_Stop();
}

void ToCameraPoint()
{
	//	FindCrossInfront(1);//到十字路口

	InitRev();//循迹到指定距离
	FindCrossInfrontToRound(0,4.3, 6000);
	StopCarInBack();

	//	ToRound(3.2, 45,45,45,45);
	ModifyPosiAtCamera();
	Car_Stop();//到拍照点
}


void ToCameraPoint2(int cmd)
{
	//	FindCrossInfront(1);//到十字路口

	InitRev();//循迹到指定距离
	FindCrossInfrontToRound(0,3.5, 6000);
	StopCarInBack();

	//	ToRound(3.2, 45,45,45,45);
	ModifyPosiAtCamera();
	Car_Stop();//到拍照点
}

void ToCameraPoint1(int cmd)
{
	MotorRevCon.A= 0; MotorRevCon.B  = 0 ;MotorRevCon.C = 0; MotorRevCon.D = 0;
	FindCrossInfront(0);//到十字路口
	HAL_Delay(300);
	FindCrossInfront(0);
	while(fabs( (MotorRevCon.A + MotorRevCon.B +MotorRevCon.C+MotorRevCon.D)/4 - 15)>1);
	StopCarInBack();

}

void StopCarInBack(void)
{
	Car_Go();//反转一下以刹车
	HAL_Delay(20);
	Car_Stop();//停车
	HAL_Delay(150);
}

void ModifyPosiAtDotted(void)
{
	while(Track3 == white)
	{
		MOTOR_PWM_Out(PWMTurn-500, PWMTurn-500, PWMTurn-500, PWMTurn-500);
		if(Track4 == red) Car_Turn_Right();
		if(Track2 == red) Car_Turn_Left();
	}
	Car_Stop();
}

//ToLeftCameraPoint()//v1.00第一版，不循迹无法正对路面《-----------------
//{
//	FindCrossInfront(1);
//	ToRound(1.2, 45, 45,45,45);//到达转弯点
//	turn_left_90();
//	ToRound(2.2, 45,45,45,45);
//	ModifyPosiAtCamera();
//	Car_Stop();//到拍照点
//}

ToLeftCameraPoint()//v2.00加入指定距离慢速循迹
{
	FindCrossInfront(1);
	ToRound(1, 1.3, 45, 45,45,45);//到达转弯点

	turn_left_90();//左转

	InitRev();
	FindCrossInfrontToRound(0,2,3000);

	ModifyPosiAtCamera();
	Car_Stop();//到拍照点
}

ToRightCameraPoint()
{
	FindCrossInfront(1);
	ToRound(1, 1.3, 45, 45,45,45);//到达转弯点
	turn_right_90();

	InitRev();
	FindCrossInfrontToRound(0,2,3000);

	ModifyPosiAtCamera();
	Car_Stop();//到拍照点
}

void ModifyPosiAtCamera(void)
{
	while(GrayTrack4 == white)
	{
		MOTOR_PWM_Out(PWMTurn-500, PWMTurn-500, PWMTurn-500, PWMTurn-500);
		if(GrayTrack5 == red ||GrayTrack6 == red ) Car_Turn_Right();
		if(GrayTrack3 == red || GrayTrack4 == red) Car_Turn_Left();
		if(GrayTrack3 == white &&  GrayTrack4 == white && GrayTrack4 == white) break;
	}
	Car_Stop();
}
