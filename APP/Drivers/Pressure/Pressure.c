/*
 * Pressure.c
 *
 *  Created on: Nov 4, 2021
 *      Author: Renge
 */


#include "Pressure.h"
int JudgeExistence(void)
{
	return HAL_GPIO_ReadPin(Pressure_GPIO_Port, Pressure_Pin);
}

