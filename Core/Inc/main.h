/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#ifdef DEBUG
//#define print(format, ...) printf( format "\r\n",##__VA_ARGS__)
#define print(format, ...) printf("[%04d: %s ][ %10s ]:" format "\r\n",__LINE__,__FILE__,__func__, ##__VA_ARGS__)
#define debug(format, ...) printf("[%04d: %s ][ %10s ]:" format "\r\n",__LINE__,__FILE__,__func__, ##__VA_ARGS__)
#else
//#define print(format, ...)
#define print(format, ...) printf( format "\r\n",##__VA_ARGS__)
#define debug(format, ...)
#endif
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY0_Pin GPIO_PIN_2
#define KEY0_GPIO_Port GPIOE
#define KEY1_Pin GPIO_PIN_3
#define KEY1_GPIO_Port GPIOE
#define KEY2_Pin GPIO_PIN_4
#define KEY2_GPIO_Port GPIOE
#define RGB_R_Pin GPIO_PIN_5
#define RGB_R_GPIO_Port GPIOE
#define RGB_B_Pin GPIO_PIN_6
#define RGB_B_GPIO_Port GPIOE
#define TRACK8_Pin GPIO_PIN_6
#define TRACK8_GPIO_Port GPIOF
#define TRACK9_Pin GPIO_PIN_7
#define TRACK9_GPIO_Port GPIOF
#define BEEP_Pin GPIO_PIN_8
#define BEEP_GPIO_Port GPIOF
#define LED0_Pin GPIO_PIN_9
#define LED0_GPIO_Port GPIOF
#define LED1_Pin GPIO_PIN_10
#define LED1_GPIO_Port GPIOF
#define RGB_G_Pin GPIO_PIN_0
#define RGB_G_GPIO_Port GPIOC
#define Pressure_Pin GPIO_PIN_1
#define Pressure_GPIO_Port GPIOC
#define RasBerryFlag_Pin GPIO_PIN_11
#define RasBerryFlag_GPIO_Port GPIOF
#define RasBerryReset_Pin GPIO_PIN_12
#define RasBerryReset_GPIO_Port GPIOF
#define OLED_CS_Pin GPIO_PIN_13
#define OLED_CS_GPIO_Port GPIOF
#define A_AIN1_Pin GPIO_PIN_2
#define A_AIN1_GPIO_Port GPIOG
#define A_AIN2_Pin GPIO_PIN_3
#define A_AIN2_GPIO_Port GPIOG
#define B_BIN1_Pin GPIO_PIN_4
#define B_BIN1_GPIO_Port GPIOG
#define B_BIN2_Pin GPIO_PIN_5
#define B_BIN2_GPIO_Port GPIOG
#define D_AIN2_Pin GPIO_PIN_6
#define D_AIN2_GPIO_Port GPIOG
#define D_AIN1_Pin GPIO_PIN_7
#define D_AIN1_GPIO_Port GPIOG
#define C_BIN1_Pin GPIO_PIN_8
#define C_BIN1_GPIO_Port GPIOG
#define TRACK2_Pin GPIO_PIN_10
#define TRACK2_GPIO_Port GPIOC
#define TRACK3_Pin GPIO_PIN_11
#define TRACK3_GPIO_Port GPIOC
#define TRACK6_Pin GPIO_PIN_3
#define TRACK6_GPIO_Port GPIOD
#define TRACK1_Pin GPIO_PIN_4
#define TRACK1_GPIO_Port GPIOD
#define C_BIN2_Pin GPIO_PIN_7
#define C_BIN2_GPIO_Port GPIOD
#define GrayTrack1_Pin GPIO_PIN_9
#define GrayTrack1_GPIO_Port GPIOG
#define GrayTrack2_Pin GPIO_PIN_10
#define GrayTrack2_GPIO_Port GPIOG
#define TRACK4_Pin GPIO_PIN_11
#define TRACK4_GPIO_Port GPIOG
#define GrayTrack3_Pin GPIO_PIN_12
#define GrayTrack3_GPIO_Port GPIOG
#define TRACK5_Pin GPIO_PIN_13
#define TRACK5_GPIO_Port GPIOG
#define LED_BOARD_Pin GPIO_PIN_14
#define LED_BOARD_GPIO_Port GPIOG
#define TRACK7_Pin GPIO_PIN_15
#define TRACK7_GPIO_Port GPIOG
#define GrayTrack4_Pin GPIO_PIN_8
#define GrayTrack4_GPIO_Port GPIOB
#define GrayTrack5_Pin GPIO_PIN_9
#define GrayTrack5_GPIO_Port GPIOB
#define GrayTrack6_Pin GPIO_PIN_0
#define GrayTrack6_GPIO_Port GPIOE
#define GrayTrack7_Pin GPIO_PIN_1
#define GrayTrack7_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */


void delay_us(uint32_t duration);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void beep_start(void);


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
