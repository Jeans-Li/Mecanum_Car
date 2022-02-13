/*
 * remote.h
 *
 *  Created on: Jul 18, 2021
 *      Author: 李健
 */
#ifndef DRIVERS_REMOTE_REMOTE_H_
#define DRIVERS_REMOTE_REMOTE_H_

#include "main.h"
#include "usart.h"
#include "tim.h"
#include "app_main.h"



#define user_htim_hs0038b htim1
#define user_htim_channel_hs0038b TIM_CHANNEL_1
#define user_htim_active_channel_hs0038b HAL_TIM_ACTIVE_CHANNEL_1

uint8_t Remote_Scan(void);
uint8_t ir_addr_code(void);
void HS0038B_INCallback(TIM_HandleTypeDef *htim);


extern uint32_t upCount;

#endif /* DRIVERS_REMOTE_REMOTE_H_ */
