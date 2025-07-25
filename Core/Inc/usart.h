/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

/* USER CODE BEGIN Private defines */
extern uint8_t r_data;
extern uint8_t u_buf[256];
#define printf(...)  HAL_UART_Transmit(&huart1, (uint8_t *)u_buf, sprintf((char*)u_buf, __VA_ARGS__), 0xffff)
#define SCREEN_CURRENT_OUTPUT(output)   printf("\xff\xff\xffx0.val=%d\xff\xff\xff", (int)((output)*1000))
#define SCREEN_TARGET_OUTPUT(target)    printf("\xff\xff\xffx3.val=%d\xff\xff\xff", (int)((target)*100))
#define SCREEN_INPUT_FREQ(freq)         printf("\xff\xff\xffx1.val=%d\xff\xff\xff", (int)((freq)*1000))
#define SCREEN_INPUT_VOLTAGE(voltage)   printf("\xff\xff\xffx2.val=%d\xff\xff\xff", (int)((voltage)*1000))
/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

