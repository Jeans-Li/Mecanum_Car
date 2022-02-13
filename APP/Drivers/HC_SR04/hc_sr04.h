/*
 * hc_sr04.h
 *
 *  Created on: 2021年10月29日
 *      Author: Fukami
 */

/*
 * 将float Sr04IN_Callback(TIM_HandleTypeDef *htim);直接放入回调函数中即可使用。
 * 例如：
 *void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	Sr04IN_Callback(htim);//htim已经是一个指针无需取地址
}
此外应在
 */

#ifndef INC_HC_SR04_H_
#define INC_HC_SR04_H_


#include "app_main.h"



#define user_htim_sr04 htim9
#define user_htim_channel_sr04 TIM_CHANNEL_1
#define user_htim_active_channel_sr04 HAL_TIM_ACTIVE_CHANNEL_1


void Sr04IN_Callback(TIM_HandleTypeDef *htim);
float Sr04_Measure(void);
void Sr04_Init(void);

#endif /* INC_HC_SR04_H_ */
