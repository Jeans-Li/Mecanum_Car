/*
 * RGB.c
 *
 *  Created on: 2021年11月4日
 *      Author: Renge
 */


#include "RGB.h"

void RGB_Init(void)
{
	HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_4);
}

void RGB_Red(void)
{
	HAL_GPIO_WritePin(RGB_B_GPIO_Port, RGB_B_Pin, RESET);
	HAL_GPIO_WritePin(RGB_G_GPIO_Port, RGB_G_Pin, RESET);
	HAL_GPIO_WritePin(RGB_R_GPIO_Port, RGB_R_Pin, SET);
}

void RGB_Green(void)
{
	HAL_GPIO_WritePin(RGB_B_GPIO_Port, RGB_B_Pin, RESET);
	HAL_GPIO_WritePin(RGB_G_GPIO_Port, RGB_G_Pin, SET);
	HAL_GPIO_WritePin(RGB_R_GPIO_Port, RGB_R_Pin, RESET);
}

void RGB_Yellow(void)
{
	HAL_GPIO_WritePin(RGB_B_GPIO_Port, RGB_B_Pin, RESET);
	HAL_GPIO_WritePin(RGB_G_GPIO_Port, RGB_G_Pin, SET);
	HAL_GPIO_WritePin(RGB_R_GPIO_Port, RGB_R_Pin, SET);
}

void RGB_Circle1(void)
{
	void RGB_Red(void);HAL_Delay(1000);
	void RGB_Green(void);HAL_Delay(1000);
	void RGB_Yellow(void);HAL_Delay(1000);
}
