#include "track.h"
#include "app_main.h"

//探测黑线输出低电平，探测白线输出高电平、超出探测为低电平

//
//int track_Scan(void)
//{
//	FindCrossInfront();
//	HAL_Delay(200);
//	turn_left_90();
//	HAL_Delay(200);
//	StopDottedLine();
//	HAL_Delay(200);
//	FindCrossBack();
//	HAL_Delay(200);
//	turn_left_90();
//	HAL_Delay(200);
//	StopDottedLine();
//
//	//		find_cross();
//	//		turn_right_90();
//	//	StopDottedLine();
//
//	return 1;
//
//}
//void FindCrossInfront()
//{
//	PidWheels_Init();
//	while(GrayTrack3 == white || GrayTrack4 == white || GrayTrack5 == white)
//	{
//		Car_Back();
//		pid_speed(go_back, go_back, go_back, go_back);
//		while(GrayTrack5 == white && GrayTrack4 == red && GrayTrack3 == white)  //正中
//		{
//			Car_Back();
//			pid_speed(go_back, go_back , go_back, go_back);
//			if(GrayTrack3 == white || GrayTrack4 == white || GrayTrack5 == white) break;
//		}
//		while(GrayTrack5 == red && GrayTrack4 == white && GrayTrack3 == white) //右偏
//		{
//			Car_Back();
//			pid_speed(diff_low-5, diff_high , diff_high , diff_low-5);
//			if(GrayTrack3 == white || GrayTrack4 == white || GrayTrack5 == white) break;
//		}
//		while(GrayTrack5 == white && GrayTrack4 == white && GrayTrack3 == red)  //左偏
//		{
//			Car_Back();
//			pid_speed(diff_high, diff_low-5 , diff_low-5, diff_high);
//			if(GrayTrack3 == white || GrayTrack4 == white || GrayTrack5 == white) break;
//		}
//	}
//	ToRound(1.5, 25, 25, 25, 25);
//	Car_Stop();
//}

//void FindCrossBack()
//{
//	PidWheels_Init();
//	//	while((Track2  == white || Track4 == white) &&(Track1 == white || Track5 == white )&&(Track7 == white || Track6 == white))
//	while(Track2 == white || Track3 == white || Track4 == white)
//	{
//		Car_Go();
//		pid_speed(go_back, go_back , go_back, go_back);
//		while(Track4 == white && Track5 == red && Track6 == white)  //正中
//		{
//			Car_Go();
//			pid_speed(go_back, go_back , go_back, go_back);
//		}
//		while(Track4 == red && Track5 == white && Track6 == white)  //右偏
//		{
//			Car_Go();
//			pid_speed(diff_high, diff_low-5 , diff_low-5, diff_high);
//		}
//		while(Track4 == white && Track5 == white && Track6 == red)   //左偏
//		{
//			Car_Go();
//			pid_speed(diff_low-5, diff_high , diff_high , diff_low-5);
//		}
//	}
//	ToRound(1.6,25, 25, 25, 25);
//	Car_Stop();
//}

//void turn_right_90()
//{
//	PidWheels_Init();
//	while(GrayTrack6 == white)
//	{
//		Car_Turn_Left();
//		pid_speed(around_speed,around_speed, around_speed, around_speed);
//
//	}
//	while(GrayTrack4 == white)
//	{
//		Car_Turn_Left();
//		pid_speed(around_speed,around_speed, around_speed, around_speed);
//
//	}
//
//	Car_Stop();
//}

//void turn_left_90()
//{
//	PidWheels_Init();
//	while(GrayTrack5 == white)
//	{
//		Car_Turn_Right();
//		pid_speed(around_speed,around_speed, around_speed, around_speed);
//	}
//	while(GrayTrack4 == white)
//	{
//		Car_Turn_Right();
//		pid_speed(around_speed,around_speed, around_speed, around_speed);
//	}
//	Car_Stop();
//}

void _2to5(void)
{
	PidWheels_Init();
	while(GrayTrack2 == white)
	{
		Car_Turn_Right();
		pid_speed(around_speed,around_speed, around_speed, around_speed);
	}
	while(GrayTrack5 == white)
	{
		Car_Turn_Right();
		pid_speed(around_speed,around_speed, around_speed, around_speed);
	}

	Car_Stop();
}

void _5to2(void)
{
	PidWheels_Init();
	while(GrayTrack5 == white)
	{
		Car_Turn_Right();
		pid_speed(around_speed,around_speed, around_speed, around_speed);
	}
	while(GrayTrack3 == white)
	{
		Car_Turn_Right();
		pid_speed(around_speed,around_speed, around_speed, around_speed);
	}
	while(GrayTrack2 == white)
	{
		Car_Turn_Right();
		pid_speed(around_speed,around_speed, around_speed, around_speed);
	}
	Car_Stop();
}



//void StopDottedLine1(void)
//{
//
//	PidWheels_Init();
//	while(Track1  ==  red || Track2 == red && Track3 == red
//			&& Track4 == red && Track5 == red)
//	{
//		Car_Go();
//		pid_speed(go_back, go_back+5, go_back+5, go_back);
//		while(GrayTrack5 == white && GrayTrack4 == red && GrayTrack3 == white)
//		{
//			Car_Go();
//			pid_speed(go_back, go_back+5, go_back+5, go_back);
//		}
//
//		while(GrayTrack3 == red && GrayTrack4 == white && GrayTrack5 == white)
//		{
//			Car_Go();
//			pid_speed(diff_high, diff_low , diff_low -5, diff_high);
//		}
//		while(GrayTrack3 == white && GrayTrack4 == white && GrayTrack5 == red)
//		{
//			Car_Go();
//			pid_speed(diff_low -5 , diff_high, diff_high, diff_low -5);
//		}
//	}
//	Car_Stop();
//}

//void StopDottedLine(void)
//{
//	PidWheels_Init();
//	while(GrayTrack1  ==  white && GrayTrack2 == white && GrayTrack6 == white && GrayTrack7 == white)
//	{
//		Car_Back();
//		pid_speed(go_back, go_back , go_back, go_back);
//		while(GrayTrack5 == white && GrayTrack4 == red && GrayTrack3 == white)  //正中
//		{
//			Car_Back();
//			pid_speed(go_back, go_back , go_back, go_back);
//			if(GrayTrack1  ==  white && GrayTrack2 == white && GrayTrack6 == white && GrayTrack7 == white) break;
//		}
//		while(GrayTrack5 == red && GrayTrack4 == white && GrayTrack3 == white)  //右偏
//		{
//			Car_Back();
//			pid_speed(diff_low-5, diff_high , diff_high , diff_low-5);
//			if(GrayTrack1  ==  white && GrayTrack2 == white && GrayTrack6 == white && GrayTrack7 == white) break;
//		}
//		while(GrayTrack5 == white && GrayTrack4 == white && GrayTrack3 == red)   //左偏
//		{
//			Car_Back();
//			pid_speed(diff_high, diff_low-5 , diff_low-5, diff_high);
//			if(GrayTrack1  ==  white && GrayTrack2 == white && GrayTrack6 == white && GrayTrack7 == white) break;
//		}
//	}
//	Car_Stop();
//}
//		//左大偏
//		while(Track5 == white && Track4 == white && Track3 == white && Track2 == white && Track1 == red)
//		{
//			Car_Go();
//
//			pid_speed(diff_low-5, diff_high+10 , diff_high+10, diff_low-5);
//		}
//		//右大偏
//		while(Track5 == red && Track4 == white && Track3 == white && Track2 == white && Track1 == white)
//		{
//			Car_Go();
//			pid_speed(diff_high+10, diff_low , diff_low , diff_high+10);
//		}


