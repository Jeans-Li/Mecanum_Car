//#include "hc_sr04.h"
//#include <math.h>
//
//float dis_fm = 0;
//uint8_t Edge = 0;
//uint16_t HighTime;
//uint16_t RisingTime;
//uint16_t FallingTime;
//
//
//void Sr04IN_Callback(TIM_HandleTypeDef *htim)
//{
//
//	/*防止未使用参数编译警告*/
//	UNUSED(htim);
//
//	if(htim->Instance == user_htim_sr04.Instance)  //TIMER9
//	{
//		if(htim->Channel == user_htim_active_channel_sr04)  //CHANNEL_1
//		{
//			if(Edge == 0)          //捕获上升沿
//			{
//				RisingTime = HAL_TIM_ReadCapturedValue(&user_htim_sr04, user_htim_channel_sr04);    //获取上升沿时间点
//				__HAL_TIM_SET_CAPTUREPOLARITY(&user_htim_sr04, user_htim_channel_sr04, TIM_INPUTCHANNELPOLARITY_FALLING);   //切换捕获极性 下降沿
//				HAL_TIM_IC_Start_IT(&user_htim_sr04, user_htim_channel_sr04);     //切换后重启中断
//
//				Edge = 1;          	 //捕获极性标值换为下降沿
//			}
//			else if(Edge == 1)     //捕获下降沿
//			{
//				FallingTime = HAL_TIM_ReadCapturedValue(&user_htim_sr04, user_htim_channel_sr04);    //获取下降沿时间点
//				__HAL_TIM_SET_CAPTUREPOLARITY(&user_htim_sr04, user_htim_channel_sr04, TIM_INPUTCHANNELPOLARITY_RISING);     //切换捕获极性 上升沿
//				HAL_TIM_IC_Start_IT(&user_htim_sr04, user_htim_channel_sr04);   	 //切换捕获极性后重启中断
//
//				HighTime = FallingTime < RisingTime ? FallingTime + 0xffff - RisingTime + 1 : FallingTime - RisingTime;
//				//高电平时间=下降沿时间 - 上升沿时间(若下降沿时间<上升沿时间FallingTime + 0xffff - RisingTime + 1)
//				dis_fm = ((HighTime * pow(10, -5) * 340) / 2) *  100; //距离计算 [(HighTime* 1us * 340m/s) * 100]   单位cm
//				printf("距离 = %f cm \r\n", dis_fm);
//				Edge = 0;	//一次采集完毕，捕获上升沿标志
//			}
//		}
//	}
//}
//
//
//
//float Sr04_Measure(void)
//{
//HAL_GPIO_WritePin(Trig_GPIO_Port , Trig_Pin , GPIO_PIN_SET);
//	delay_us(20);//延时20微秒
//	HAL_GPIO_WritePin(Trig_GPIO_Port , Trig_Pin, GPIO_PIN_RESET);
//	return dis_fm;
//}
//
//
//void Sr04_Init(void)
//{
//	HAL_TIM_IC_Start_IT(&user_htim_sr04,user_htim_channel_sr04);
//
//	printf("HC-SR04 Ready! \n");
//}
