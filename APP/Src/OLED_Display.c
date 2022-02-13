/*
 * OLED_Display.c
 *
 *  Created on: Nov 1, 2021
 *      Author: Renge
 */
//用于小车的显示内容
#include "OLED_Display.h"
#include "app_main.h"

extern MotorRevCon__ MotorRevCon;
extern User_USART JY901_data;

//void OLED_Display1(void)
//{
//	uint32_t EncoderNum;
//	char EncoderNum_str[10];
//
//	EncoderNum = __HAL_TIM_GET_COUNTER(&htim4);
//	ssd1306_SetCursor(0, 0);
//	ssd1306_WriteString("Speed:", Font_7x10, White);     //显示提示字：Speed
//	ssd1306_SetCursor(80,0);
//	ssd1306_WriteString("m/min", Font_7x10, White);
//
//	sprintf(EncoderNum_str,"%d",EncoderNum);
//	ssd1306_SetCursor(0,15);//文字显示位置
//	ssd1306_WriteString("A:      B:      ", Font_7x10, White);
//	ssd1306_SetCursor(0,30);//文字显示位
//	ssd1306_WriteString("C:      D:      ", Font_7x10, White);
//	ssd1306_SetCursor(0, 45);
//	ssd1306_WriteString("P:   I:   D:", Font_7x10, White);
//	ssd1306_SetCursor(20,15);//文字显示位置
//	//	ssd1306_WriteString(EncoderNum_str, Font_7x10, White);
//
//
//	ssd1306_SetCursor(20, 15);
//	ssd1306_WriteString(showRPM(1), Font_7x10,White);     //A轮实际减速箱输出转速  单位RPM
//
//	ssd1306_SetCursor(80, 15);
//	ssd1306_WriteString(showRPM(2), Font_7x10,White);     //B轮实际减速箱输出转速  单位RPM
//
//	ssd1306_SetCursor(20, 30);
//	ssd1306_WriteString(showRPM(3), Font_7x10,White);     //C轮实际减速箱输出转速  单位RPM
//
//	ssd1306_SetCursor(80, 30);
//	ssd1306_WriteString(showRPM(4), Font_7x10,White);    //D轮实际减速箱输出转速  单位RPM
//
//	ssd1306_UpdateScreen();
//	ssd1306_Fill(Black);	//清屏
//}


void OLED_Display2(void)
{
	float Time;
	char TimeStr[10];
	char RevNumStr[10];

	//***********时间显示***********//
	Time = Get_Time();
	ssd1306_SetCursor(0, 0);
	ssd1306_WriteString("Time:", Font_7x10, White);
	ssd1306_SetCursor(70,0);
	ssd1306_WriteString("s", Font_7x10, White);
	sprintf(TimeStr,"%.2f",Time);
	ssd1306_SetCursor(20,0);
	ssd1306_WriteString(TimeStr, Font_7x10, White);

	//**********转数显示***********//
	ssd1306_SetCursor(0, 10);
	ssd1306_WriteString("Rev:", Font_7x10, White);
	ssd1306_SetCursor(100,10);
	ssd1306_WriteString("r", Font_7x10, White);
	sprintf(RevNumStr,"%.1f ",MotorRevCon.A);
	ssd1306_SetCursor(0,20);
	ssd1306_WriteString(RevNumStr, Font_7x10, White);
	sprintf(RevNumStr,"%.1f ",MotorRevCon.B);
	ssd1306_SetCursor(30,20);
	ssd1306_WriteString(RevNumStr, Font_7x10, White);
	sprintf(RevNumStr,"%.1f ",MotorRevCon.C);
	ssd1306_SetCursor(0,30);
	ssd1306_WriteString(RevNumStr, Font_7x10, White);
	sprintf(RevNumStr,"%.1f ",MotorRevCon.D);
	ssd1306_SetCursor(30,30);
	ssd1306_WriteString(RevNumStr, Font_7x10, White);

	uint8_t Buffer[32];
//	print("\r\nKalmanAngleX:%.2f\r\nKalmanAngleY:%.2f\r\n", MPU6050.KalmanAngleX, MPU6050.KalmanAngleY);
	ssd1306_SetCursor(0,40);
	sprintf((char*)Buffer, "X:%7.2f", JY901_data.angle.angle[1]);
	ssd1306_WriteString((char*)Buffer, Font_7x10, White);

	ssd1306_SetCursor(0,50);
	sprintf((char*)Buffer, "Y:%7.2f", JY901_data.angle.angle[0]);
	ssd1306_WriteString((char*)Buffer, Font_7x10, White);

	ssd1306_SetCursor(50,50);
		sprintf((char*)Buffer, "Z:%7.2f", JY901_data.angle.angle[2]);
		ssd1306_WriteString((char*)Buffer, Font_7x10, White);

	//**********清屏输出***********//
	ssd1306_UpdateScreen();
	ssd1306_Fill(Black);	//清屏
}

