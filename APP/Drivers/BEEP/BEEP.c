/*
 * BEEP.c
 *
 *  Created on: Nov 4, 2021
 *      Author: Renge
 */


#include "BEEP.h"

void BeepOn(void)
{
	HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, SET);
}

void BeepOff(void)
{
	HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, RESET);
}

void BeepFunc1(int Times, int Delay)
{
	for(int i = 0; i < Times; i++)
	{
		BeepOff();
		HAL_Delay(Delay);
		BeepOn();
		HAL_Delay(Delay);
	}
}
