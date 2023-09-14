/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void pwm_on(uint16_t pwmD[], uint32_t idX);
void pwm_off(void);
void DWT_Delay(uint32_t us);
void buzzer(unsigned long t);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define enax_Pin GPIO_PIN_5
#define enax_GPIO_Port GPIOB
#define lsx1_Pin GPIO_PIN_4
#define lsx1_GPIO_Port GPIOB
#define dirx_Pin GPIO_PIN_15
#define dirx_GPIO_Port GPIOA
#define MCU_ACTIVE_Pin GPIO_PIN_12
#define MCU_ACTIVE_GPIO_Port GPIOG
#define pulx_Pin GPIO_PIN_13
#define pulx_GPIO_Port GPIOC
#define lsy0_Pin GPIO_PIN_7
#define lsy0_GPIO_Port GPIOC
#define lsy1_Pin GPIO_PIN_6
#define lsy1_GPIO_Port GPIOC
#define enay_Pin GPIO_PIN_13
#define enay_GPIO_Port GPIOB
#define diry_Pin GPIO_PIN_12
#define diry_GPIO_Port GPIOB
#define puly_Pin GPIO_PIN_1
#define puly_GPIO_Port GPIOC
#define FRAME_RATE_Pin GPIO_PIN_1
#define FRAME_RATE_GPIO_Port GPIOA
#define camf_Pin GPIO_PIN_4
#define camf_GPIO_Port GPIOA
#define VSYNC_FREQ_Pin GPIO_PIN_2
#define VSYNC_FREQ_GPIO_Port GPIOA
#define RENDER_TIME_Pin GPIO_PIN_6
#define RENDER_TIME_GPIO_Port GPIOA
#define lsx0_Pin GPIO_PIN_5
#define lsx0_GPIO_Port GPIOA
#define camp_Pin GPIO_PIN_5
#define camp_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
