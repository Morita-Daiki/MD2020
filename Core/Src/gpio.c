/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, PA2_Pin|PA15_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RA_BK_Pin|LD5_11_Pin|LD4_10_Pin|LD3_9_Pin 
                          |LD2_8_Pin|LD1_7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = PA2_Pin|PA15_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = SW4_Pin|SW3_Pin|SW2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin PBPin */
  GPIO_InitStruct.Pin = RA_BK_Pin|LD5_11_Pin|LD4_10_Pin|LD3_9_Pin 
                          |LD2_8_Pin|LD1_7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
void LED_Go2Go(int x) {
	HAL_GPIO_WritePin(RA_BK_GPIO_Port, RA_BK_Pin, x > 0);
	if (x > 0) {
		HAL_GPIO_WritePin(LD1_7_GPIO_Port, LD1_7_Pin, x < 5);
		HAL_GPIO_WritePin(LD2_8_GPIO_Port, LD2_8_Pin, x < 4);
		HAL_GPIO_WritePin(LD3_9_GPIO_Port, LD3_9_Pin, x < 3);
		HAL_GPIO_WritePin(LD4_10_GPIO_Port, LD4_10_Pin, x < 2);
		HAL_GPIO_WritePin(LD5_11_GPIO_Port, LD5_11_Pin, x < 1);
	} else {
		HAL_GPIO_WritePin(LD1_7_GPIO_Port, LD1_7_Pin, x < 0);
		HAL_GPIO_WritePin(LD2_8_GPIO_Port, LD2_8_Pin, x < -1);
		HAL_GPIO_WritePin(LD3_9_GPIO_Port, LD3_9_Pin, x < -2);
		HAL_GPIO_WritePin(LD4_10_GPIO_Port, LD4_10_Pin, x < -3);
		HAL_GPIO_WritePin(LD5_11_GPIO_Port, LD5_11_Pin, x < -4);
	}
}
int SW_Get_ID() {
	return !HAL_GPIO_ReadPin(SW4_GPIO_Port, SW4_Pin) << 0 | //p1
			!HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin) << 1 | //p2
			!HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin) << 2; //p3
}
/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
