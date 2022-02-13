/*
 * app_main.c
 *
 *  Created on: Jul 16, 2021
 *      Author: 李健
 */
#include "app_main.h"


extern uint8_t recFlag;
extern int btcmd_num ;
int last_btcmd_num;
extern char num[4];
extern int change_zkb_flag;
int cmd_flag = 2;
uint32_t counter = 0;   //定义全局变量
char test[100];
User_USART JY901_data;
float target = 55;


void app_main_init()
{
	motor_pwm_init();    //PWM启动
	motor_encode_init(); //编码器启动
	//	gui_init();     //OLED I2C初始化
	ssd1306_Init(); //OLED SPI初始
	//	beep_start();
	zkb_init();//初始化占空比
	//	HAL_TIM_IC_Start_IT(&htim1,TIM_CHANNEL_1);//红外
	User_USART_Init(&JY901_data);
}
void ToPoint1(void);
void ToPoint2(void);

void app_main()
{
	HAL_GPIO_WritePin(RasBerryReset_GPIO_Port,RasBerryReset_Pin,SET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(RasBerryReset_GPIO_Port, RasBerryReset_Pin, RESET);
	HAL_GPIO_WritePin(RasBerryFlag_GPIO_Port, RasBerryFlag_Pin, SET);  //开启摄像头指令
	int Not12Flay = 1;
	while(!btcmd_num);
	last_btcmd_num = btcmd_num;
	HAL_GPIO_WritePin(RasBerryFlag_GPIO_Port, RasBerryFlag_Pin, RESET);  //关掉摄像头指令
	BeepOn();
	HAL_Delay(1000);
	BeepOff();

	while(!HAL_GPIO_ReadPin(Pressure_GPIO_Port, Pressure_Pin));//判断是否有药

	switch(last_btcmd_num)
	{
	case 1:
		ToPoint1();
		Not12Flay = 0;
		break;
	case 2:
		ToPoint2();
		Not12Flay = 0;
		break;
	}

	btcmd_num = 0;
	if(Not12Flay)
	{
		ToCameraPoint();
		HAL_Delay(1000);
		HAL_GPIO_WritePin(RasBerryFlag_GPIO_Port,RasBerryFlag_Pin, SET);   //讲io口引脚设置为高电平，作为表示提醒树莓派可以开始拍照
		HAL_GPIO_WritePin(LED_BOARD_GPIO_Port,LED_BOARD_Pin, SET);
		while(!btcmd_num);
		last_btcmd_num = btcmd_num;
		HAL_GPIO_WritePin(LED_BOARD_GPIO_Port,LED_BOARD_Pin, RESET);
		HAL_GPIO_WritePin(RasBerryFlag_GPIO_Port,RasBerryFlag_Pin, RESET);
		if(last_btcmd_num != 999) {ToPoint34();  while(1);}//不在此路口判断
//		HAL_GPIO_WritePin(RasBerryReset_GPIO_Port, RasBerryReset_Pin, RESET);   //rashberry引脚置为低电平
		btcmd_num = 0; //在下一个路口寻找
		ToCameraPoint2();
		HAL_Delay(1000);
		ToPoint5768(5);
//		HAL_GPIO_WritePin(RasBerryFlag_GPIO_Port,RasBerryFlag_Pin,SET);
////		HAL_GPIO_WritePin(LED_BOARD_GPIO_Port,LED_BOARD_Pin, SET);
////		while(!btcmd_num);
//		if(btcmd_num == 5 || btcmd_num == 6 ||btcmd_num == 7|| btcmd_num == 8)
//		{
//
//		}
////		last_btcmd_num = btcmd_num;
////		HAL_GPIO_WritePin(RasBerryFlag_GPIO_Port,RasBerryFlag_Pin,RESET);   //rashberry引脚置为低电平
////		HAL_GPIO_WritePin(LED_BOARD_GPIO_Port,LED_BOARD_Pin, RESET);
//		ToPoint5768(last_btcmd_num);
	}

	while(1);
}

void ToPoint1(void)
{
	FindCrossInfront(1);
	ToRound(1, 1.45, 45, 45, 45,45);
	turn_left_90();
	StopDottedLine();
	StopCarInBack();
	ModifyPosiAtDotted();
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);//亮红灯等取药
	while(HAL_GPIO_ReadPin(Pressure_GPIO_Port, Pressure_Pin));
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);//红灯灭
	FindCrossBack();
	turn_left_90();
	StopDottedLine();
	StopCarInBack();
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, RESET);//绿灯亮运行结束
}

void ToPoint2(void)
{
	FindCrossInfront(1);
	ToRound(1, 1.45, 45, 45, 45,45);
	HAL_Delay(200);
	turn_2_right_90();   //防止出现去2病房的时候在十字路口处出现急停现象
	StopDottedLine();
	StopCarInBack();
	ModifyPosiAtDotted();
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);//亮红灯等取药
	while(HAL_GPIO_ReadPin(Pressure_GPIO_Port, Pressure_Pin));
	FindCrossBack();
	turn_right_90();
	StopDottedLine();
	StopCarInBack();
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);//红灯灭
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, RESET);//绿灯亮运行结束
}

void ToPoint34(void)
{
	if(btcmd_num == 3)
	{
		FindCrossInfront(1);
		ToRound(1, 1.35, 45,45,45,45);
		turn_left_90();
		StopDottedLine();
		StopCarInBack();//跳出巡线停车
		ModifyPosiAtDotted();//修正出库角度
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);//亮红灯等取药
		while(HAL_GPIO_ReadPin(Pressure_GPIO_Port, Pressure_Pin));
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);//红灯灭
		FindCrossBack();
		turn_left_90();
		StopDottedLine();
		HAL_Delay(300);//延时以防止两次直接停车
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, RESET);//绿灯亮运行结束
	}

	if(btcmd_num == 4)
	{
		FindCrossInfront(1);
		ToRound(1, 1.4, 45,45,45,45);
		turn_right_90();
		StopDottedLine();
		StopCarInBack();//跳出巡线停车
		ModifyPosiAtDotted();//修正出库角度
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);//亮红灯等取药
		while(HAL_GPIO_ReadPin(Pressure_GPIO_Port, Pressure_Pin));
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);//红灯灭
		FindCrossBack();
		turn_right_90();
		StopDottedLine();
		HAL_Delay(300);//延时以防止两次直接停车
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, RESET);//绿灯亮运行结束
	}
}
void ToPoint5768(int cmd)
{
	if(cmd == 5)
	{
		FindCrossInfront(1);
		ToRound(1, 1.3, 45,45,45,45);
		turn_left_90();
		FindCrossInfront(1);
		ToRound(1, 1.3, 45,45,45,45);
		turn_left_90();
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);//亮红灯等取药
		while(HAL_GPIO_ReadPin(Pressure_GPIO_Port, Pressure_Pin));
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);//红灯灭
		FindT5Back();
		turn_left_90();
		FindT57();
		turn_right_90();
		StopDottedLine();
		HAL_Delay(300);
		StopDottedLine();
		HAL_Delay(300);
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, RESET);//绿灯亮运行结束
	}
	if(cmd == 7)
	{
		ToRound(1, 1.3, 45,45,45,45);
		turn_left_90();   //修改
		FindCrossInfront(1);
		ToRound(1, 1.3, 45,45,45,45);
		turn_right_90();  //修改
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);//亮红灯等取药
		while(HAL_GPIO_ReadPin(Pressure_GPIO_Port, Pressure_Pin));
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);//红灯灭
		FindT5Back();
		turn_right_90();  //修改
		FindT57();
		turn_left_90();   //修改
		StopDottedLine();
		HAL_Delay(300);
		StopDottedLine();
		HAL_Delay(300);
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, RESET);//绿灯亮运行结束
	}
	if(cmd == 6)
	{
		ToRound(1, 1.3, 45,45,45,45);
		turn_right_90();   //修改
		FindCrossInfront(1);
		ToRound(1, 1.3, 45,45,45,45);
		turn_right_90();  //修改
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);//亮红灯等取药
		while(HAL_GPIO_ReadPin(Pressure_GPIO_Port, Pressure_Pin));
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);//红灯灭
		FindT5Back();
		turn_right_90();  //修改
		FindT57();
		turn_right_90();   //修改
		StopDottedLine();
		HAL_Delay(300);
		StopDottedLine();
		HAL_Delay(300);
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, RESET);//绿灯亮运行结束
	}
	if(cmd == 6)
	{
		ToRound(1, 1.3, 45,45,45,45);
		turn_right_90();   //修改
		FindCrossInfront(1);
		ToRound(1, 1.3, 45,45,45,45);
		turn_left_90();  //修改
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);//亮红灯等取药
		while(HAL_GPIO_ReadPin(Pressure_GPIO_Port, Pressure_Pin));
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);//红灯灭
		FindT5Back();
		turn_left_90();  //修改
		FindT57();
		turn_right_90();   //修改
		StopDottedLine();
		HAL_Delay(300);
		StopDottedLine();
		HAL_Delay(300);
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, RESET);//绿灯亮运行结束
	}
}

void ToPoint68(int cmd)
{
	if(cmd == 6)
	{
		FindCrossInfront(1);
		ToRound(1, 1.3, 45, 45, 45, 45);
		turn_right_90();
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);//亮红灯等取药
		while(HAL_GPIO_ReadPin(Pressure_GPIO_Port, Pressure_Pin));
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);//红灯灭
		FindT6Back();
		turn_right_90();
		FindT57();
		turn_left_90();
		StopDottedLine();
		HAL_Delay(300);
		StopDottedLine();
		HAL_Delay(300);
		StopDottedLine();
		StopCarInBack();
		HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,RESET);
	}
}

//void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
//{
//	Sr04IN_Callback(htim);//超声波
//	HS0038B_INCallback(htim);//红外遥控
//}


//void do_cmd(int cmd)
//{
//	switch(cmd)
//	{
//	case 500:
//		change_zkb_flag = 1 ;
//		cmd_sheet(cmd_flag);
//		btcmd_num = cmd_flag;
//		break;
//	case 501:
//		change_zkb_flag = 2 ;
//		cmd_sheet(cmd_flag);
//		btcmd_num = cmd_flag;
//		break;
//	case 503:
//		change_zkb_flag = 0;
//		zkb_init();
//		cmd_sheet(cmd_flag);
//		btcmd_num = cmd_flag;
//		break;
//	case 504:
//		change_zkb_flag = 0;
//		zkb_favorite_1();
//		cmd_sheet(cmd_flag);
//		btcmd_num = cmd_flag;
//		break;
//	default:
//		cmd_sheet(cmd);
//		break;
//	}
//}
//
//
//void cmd_sheet(int cmd)
//{
//	switch(cmd)
//	{
//	case 104:
//		Car_Turn_Left();//差速左转
//		break;
//	case 176:
//		Car_Turn_Right();//差速右转
//		break;
//	case 98:
//		Car_Go();//向前
//		break;
//	case 168:
//		Car_Back();//后退
//		break;
//	case 194:
//		Car_Right();//右移
//		break;
//	case 34:
//		Car_Left();//左移
//		break;
//	case 162:
//		Car_Left_45Q();//左前
//		break;
//	case 226:
//		Car_Right_45Q();//右前
//		break;
//	case 224:
//		Car_Left_45H();//左后
//		break;
//	case 144:
//		Car_Right_45H();//右后
//		break;
//	case 90:
//		Car_Turn_Right_Around();//顺时针
//		break;
//	case 16:
//		Car_Turn_Left_Around();//逆时针
//		break;
//	case 601:
//		TimeStart();
//		while(track_Scan());
//		TimeEnd();
//		break;
//	default:
//		Car_Stop();//停车
//		break;
//	}
//}
