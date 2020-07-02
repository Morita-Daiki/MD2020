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
#include "stm32f0xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ENC_A_Pin GPIO_PIN_0
#define ENC_A_GPIO_Port GPIOA
#define ENC_B_Pin GPIO_PIN_1
#define ENC_B_GPIO_Port GPIOA
#define INA199_REF_Pin GPIO_PIN_3
#define INA199_REF_GPIO_Port GPIOA
#define INA199_OUT_Pin GPIO_PIN_4
#define INA199_OUT_GPIO_Port GPIOA
#define BATT_VOLT_Pin GPIO_PIN_5
#define BATT_VOLT_GPIO_Port GPIOA
#define SW4_Pin GPIO_PIN_8
#define SW4_GPIO_Port GPIOA
#define SW3_Pin GPIO_PIN_9
#define SW3_GPIO_Port GPIOA
#define SW2_Pin GPIO_PIN_10
#define SW2_GPIO_Port GPIOA
#define RA_BK_Pin GPIO_PIN_3
#define RA_BK_GPIO_Port GPIOB
#define LD5_11_Pin GPIO_PIN_4
#define LD5_11_GPIO_Port GPIOB
#define LD4_10_Pin GPIO_PIN_5
#define LD4_10_GPIO_Port GPIOB
#define LD3_9_Pin GPIO_PIN_6
#define LD3_9_GPIO_Port GPIOB
#define LD2_8_Pin GPIO_PIN_7
#define LD2_8_GPIO_Port GPIOB
#define LD1_7_Pin GPIO_PIN_8
#define LD1_7_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/