/*
 * track.h
 *
 *  Created on: 2021年7月24日
 *      Author: 李健
 */

#ifndef DRIVERS_TRACK_TRACK_H_
#define DRIVERS_TRACK_TRACK_H_

#include "app_main.h"

//探测黑线输出低电平，探测白线输出高电平、超出探测为低电平
#define Track1 HAL_GPIO_ReadPin(TRACK1_GPIO_Port,TRACK1_Pin)  //PD4
#define Track2 HAL_GPIO_ReadPin(TRACK2_GPIO_Port,TRACK2_Pin)  //PC10
#define Track3 HAL_GPIO_ReadPin(TRACK3_GPIO_Port,TRACK3_Pin)  //PC11
#define Track4 HAL_GPIO_ReadPin(TRACK4_GPIO_Port,TRACK4_Pin)  //PG11
#define Track5 HAL_GPIO_ReadPin(TRACK5_GPIO_Port,TRACK5_Pin)  //PG13
#define Track6 HAL_GPIO_ReadPin(TRACK6_GPIO_Port,TRACK6_Pin)  //PD3
#define Track7 HAL_GPIO_ReadPin(TRACK7_GPIO_Port,TRACK7_Pin)  //PG15
#define Track8 HAL_GPIO_ReadPin(TRACK8_GPIO_Port,TRACK8_Pin)  //PF6
#define Track9 HAL_GPIO_ReadPin(TRACK9_GPIO_Port,TRACK9_Pin)  //PF7

#define GrayTrack1 HAL_GPIO_ReadPin(GrayTrack1_GPIO_Port,GrayTrack1_Pin)//PG9
#define GrayTrack2 HAL_GPIO_ReadPin(GrayTrack2_GPIO_Port,GrayTrack2_Pin)//PG10
#define GrayTrack3 HAL_GPIO_ReadPin(GrayTrack3_GPIO_Port,GrayTrack3_Pin)//PG12
#define GrayTrack4 HAL_GPIO_ReadPin(GrayTrack4_GPIO_Port,GrayTrack4_Pin)//PB8
#define GrayTrack5 HAL_GPIO_ReadPin(GrayTrack5_GPIO_Port,GrayTrack5_Pin)//PB9
#define GrayTrack6 HAL_GPIO_ReadPin(GrayTrack6_GPIO_Port,GrayTrack6_Pin)//PE0
#define GrayTrack7 HAL_GPIO_ReadPin(GrayTrack7_GPIO_Port,GrayTrack7_Pin)//PE1


#define red 1
#define white 0

#define dark 0
#define light 1

#define go_back 35
#define diff_high 45
#define diff_low 30
#define around_speed 20


/*
 * 循迹函数
 * 在主函数中while结合使用
 */
int track_Scan(void);
void TurnLeftOnTrack(void);
void TurnRightOnTrack(void);
void Clockwise90(void);
void CounterClockwise90(void);
void StopDottedLine(void);
void FindCrossInfront(int StopFlag);
void turn_right_90(void);
void StopDottedLine1(void);
void turn_left_90(void);
void FindCrossBack(void);
void FindCrossInfront1(void);
void StopCarInBack(void);

void _2to5(void);//按照传感器转向
void _5to2(void);
#endif /* DRIVERS_TRACK_TRACK_H_ */
