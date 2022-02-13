/*
 * app_main.h
 *
 *  Created on: Jul 16, 2021
 *      Author: 李健
 */

#ifndef INC_APP_MAIN_H_
#define INC_APP_MAIN_H_


#include "usart.h"
#include "tim.h"
#include "motor.h"
#include "gui.h"
#include "u8g2.h"
//#include "remote.h"
#include "main.h"
#include "track.h"
#include "hc_sr04.h"
#include "PID_4Wheels_Syn.h"
//=================================//
#include "ssd1306_conf.h"
#include "ssd1306_fonts.h"
#include "ssd1306.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "OLED_Display.h"
#include "UserFuncs.h"
#include "MainControl.h"


#include "jy901.h"
//================================//
#define setSpeed //只要对target赋值就可以设置转速，所以加入空定义以使得可读。

#define Key0Down  !HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin)
#define Key1Down  !HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)
#define Key2Down  !HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)

void app_main_init(void);
void app_main(void);
void display(void);

void cmd_sheet(int cmd );
void do_cmd(int cmd);

void ToPoint34(void);


#endif /* INC_APP_MAIN_H_ */
