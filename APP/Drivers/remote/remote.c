/*
 * remote.c
 *
 *  Created on: Jul 18, 2021
 *      Author: 李健
 */

#include "remote.h"


uint32_t upCount = 0;   //向上计数
uint16_t valueUp = 0;   //高电平计数
uint16_t valueDown = 0;   //低电平计数
uint8_t isUpCompare = 1;      //是否为上升沿捕获标记
uint16_t width;           //脉宽
uint16_t buffer[128] = {0};    //接收缓冲区
uint16_t bufferId = 0;        //接收缓冲区数组下标
uint8_t recFlag = 0;    //接收完成标志位
char num[4] = {0};


void HS0038B_INCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == user_htim_hs0038b.Instance)  //TIMER1
	{
		if(htim->Channel == user_htim_active_channel_hs0038b)
		{//CHANNEL_1
			if(isUpCompare)   //如果是上升沿捕获
			{
				valueUp = HAL_TIM_ReadCapturedValue(htim, user_htim_channel_hs0038b);
				isUpCompare = 0;
				__HAL_TIM_SET_CAPTUREPOLARITY(htim,user_htim_channel_hs0038b,TIM_ICPOLARITY_FALLING);   //设置为下降沿捕获
				upCount = 0;
			}
			else
			{
				valueDown = HAL_TIM_ReadCapturedValue(htim, user_htim_channel_hs0038b);
				isUpCompare = 1;
				__HAL_TIM_SET_CAPTUREPOLARITY(htim,user_htim_channel_hs0038b,TIM_ICPOLARITY_RISING);   //设置为上升沿捕获
				width = valueDown + upCount*65536 - valueUp;
				if(width > 4400 && width < 4600)    //判断同步码
				{
					bufferId = 0;
					buffer[bufferId++] = width;
				}
				else if(bufferId > 0)
				{
					buffer[bufferId++] = width;
					if(bufferId > 32)   //所有码一共32位已经全部收到
					{
						recFlag = 1;
						bufferId = 0;
					}

				}
			}
			for(int i=0;i<4;i++)
			{
				num[i] = 0;
			}

			for(int i =0;i < 32; i++)
			{
				if(buffer[i+1]<1000)
				{
					num[i/8] = num[i/8]<<1;
				}
				else
				{
					num[i/8] = num[i/8]<<1;
					num[i/8] |= 0x01;
				}
			}
		}
	}
	Remote_Scan();
}


uint8_t Remote_Scan(void)
{
	if(recFlag)
	{

		recFlag = 0;    //防止if语句重复成立
		printf("遥控键盘码值：");
		printf("%d  \r\n",num[2]);
		return num[2];

	}

	return 5555;   //出错
}
