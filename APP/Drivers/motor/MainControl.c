/*
 * MainControl.c
 *
 *  Created on: Nov 4, 2021
 *      Author: Renge
 */

#include "MainControl.h"
#define YArg JY901_data.angle.angle[0];

extern MotorRevCon__ MotorRevCon;
extern User_USART  JY901;


int ToRoundFlag = 1;
float TargetVal;


void ToRound(int direction ,float r, float A,float B ,float C ,float D)
{
	MotorRevCon.A = 0; MotorRevCon.B = 0; MotorRevCon.C = 0; MotorRevCon.D = 0;

	if(direction){
		Car_Back();
	}
	else
	{
		Car_Go();
	}
	PidWheels_Init();
	while(fabs( (MotorRevCon.A + MotorRevCon.B +MotorRevCon.C+MotorRevCon.D)/4 - r)>1)
	{
		pid_speed(A, B, C, D);
	}
	Car_Stop();
}


void InitRev(void)//归零计数
{
	MotorRevCon.A = 0; MotorRevCon.B = 0; MotorRevCon.C = 0; MotorRevCon.D = 0;
}
int RoundLim(float R)
{
	return fabs((MotorRevCon.A + MotorRevCon.B +MotorRevCon.C+MotorRevCon.D) / 4 - R) < 1;
}

void TurnLeftRound(float r)
{
	Car_Turn_Left_Around();
	while(fabs((MotorRevCon.C + MotorRevCon.D)/2 - r) > 1);
	MotorRevCon.A = 0; MotorRevCon.B = 0; MotorRevCon.C = 0; MotorRevCon.D = 0;
	Car_Stop();
}

void ToArg0(void)
{
//	if(fabs(YArg) < 3) pid(20, 20, 20, 20);
//	if(fabs(YArg) > 3)

}


