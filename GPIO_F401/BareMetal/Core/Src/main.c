/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "gpio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  /* System interrupt init*/
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* SysTick_IRQn interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  //MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	//Init Pins for LED
	GPIO_ConfigDirection(GPIOC, GPIO_PIN_13_POS, GPIO_MODE_OUTPUT);
	GPIO_ConfigOutputType(GPIOC, GPIO_PIN_13_POS, GPIO_OUTPUT_PUSHPULL);
	GPIO_ConfigOutputSpeed(GPIOC, GPIO_PIN_13_POS, GPIO_SPEED_2MHZ);
	GPIO_WritePin(GPIOC, GPIO_PIN_13_POS, 1); 

	//Init Pins for Button_On
	GPIO_ConfigDirection(GPIOA, GPIO_PIN_0_POS, GPIO_MODE_INPUT);
	GPIO_ConfigPull(GPIOA, GPIO_PIN_0_POS, GPIO_PULL_UP);

	//Init Pins for Button_Off
	GPIO_ConfigDirection(GPIOA, GPIO_PIN_1_POS, GPIO_MODE_INPUT);
	GPIO_ConfigPull(GPIOA, GPIO_PIN_1_POS, GPIO_PULL_DOWN);

	//Init Pins for 4-channel input
	GPIO_ConfigDirection(GPIOA, GPIO_PIN_4_POS, GPIO_MODE_INPUT);
	GPIO_ConfigPull(GPIOA, GPIO_PIN_4_POS, GPIO_PULL_NONE);
	
	GPIO_ConfigDirection(GPIOA, GPIO_PIN_5_POS, GPIO_MODE_INPUT);
	GPIO_ConfigPull(GPIOA, GPIO_PIN_5_POS, GPIO_PULL_NONE);
	
	GPIO_ConfigDirection(GPIOA, GPIO_PIN_6_POS, GPIO_MODE_INPUT);
	GPIO_ConfigPull(GPIOA, GPIO_PIN_6_POS, GPIO_PULL_NONE);
	
	GPIO_ConfigDirection(GPIOA, GPIO_PIN_7_POS, GPIO_MODE_INPUT);
	GPIO_ConfigPull(GPIOA, GPIO_PIN_7_POS, GPIO_PULL_NONE);

	//Init Pins for 4-pin 7-Segment
	GPIO_ConfigDirection(GPIOB, GPIO_PIN_12_POS, GPIO_MODE_OUTPUT);
	GPIO_ConfigOutputType(GPIOB, GPIO_PIN_12_POS, GPIO_OUTPUT_PUSHPULL);
	GPIO_ConfigOutputSpeed(GPIOB, GPIO_PIN_12_POS, GPIO_SPEED_2MHZ);
	GPIO_WritePin(GPIOB, GPIO_PIN_12_POS, 0); 

	GPIO_ConfigDirection(GPIOB, GPIO_PIN_13_POS, GPIO_MODE_OUTPUT);
	GPIO_ConfigOutputType(GPIOB, GPIO_PIN_13_POS, GPIO_OUTPUT_PUSHPULL);
	GPIO_ConfigOutputSpeed(GPIOB, GPIO_PIN_13_POS, GPIO_SPEED_2MHZ);
	GPIO_WritePin(GPIOB, GPIO_PIN_13_POS, 0); 
	
	GPIO_ConfigDirection(GPIOB, GPIO_PIN_14_POS, GPIO_MODE_OUTPUT);
	GPIO_ConfigOutputType(GPIOB, GPIO_PIN_14_POS, GPIO_OUTPUT_PUSHPULL);
	GPIO_ConfigOutputSpeed(GPIOB, GPIO_PIN_14_POS, GPIO_SPEED_2MHZ);
	GPIO_WritePin(GPIOB, GPIO_PIN_14_POS, 0); 
	
	GPIO_ConfigDirection(GPIOB, GPIO_PIN_15_POS, GPIO_MODE_OUTPUT);
	GPIO_ConfigOutputType(GPIOB, GPIO_PIN_15_POS, GPIO_OUTPUT_PUSHPULL);
	GPIO_ConfigOutputSpeed(GPIOB, GPIO_PIN_15_POS, GPIO_SPEED_2MHZ);
	GPIO_WritePin(GPIOB, GPIO_PIN_15_POS, 0); 
	
  while (1){
    /* USER CODE BEGIN 3 */
		if(GPIO_ReadPin(GPIOA, GPIO_PIN_0_POS) == 0){
			GPIO_ClearPin(GPIOC, GPIO_PIN_13_POS);
		}
		
		if(GPIO_ReadPin(GPIOA, GPIO_PIN_1_POS) == 1){
			GPIO_SetPin(GPIOC, GPIO_PIN_13_POS);
		}
		
		uint32_t value = GPIO_ReadPinField(GPIOA, 0xF0U);
		GPIO_WritePinField(GPIOB, 0xF000U, value);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE2);
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_RCC_HSI_Enable();

   /* Wait till HSI is ready */
  while(LL_RCC_HSI_IsReady() != 1)
  {

  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {

  }
  LL_Init1msTick(16000000);
  LL_SetSystemCoreClock(16000000);
  LL_RCC_SetTIMPrescaler(LL_RCC_TIM_PRESCALER_TWICE);
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

  /**/
  LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_13);

  /**/
  LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_0);

  /**/
  LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_12|LL_GPIO_PIN_13|LL_GPIO_PIN_14|LL_GPIO_PIN_15);

  /**/
  GPIO_InitStruct.Pin = LL_GPIO_PIN_13|LL_GPIO_PIN_0;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /**/
  GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /**/
  GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_DOWN;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /**/
  GPIO_InitStruct.Pin = LL_GPIO_PIN_4|LL_GPIO_PIN_5|LL_GPIO_PIN_6|LL_GPIO_PIN_7;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /**/
  GPIO_InitStruct.Pin = LL_GPIO_PIN_12|LL_GPIO_PIN_13|LL_GPIO_PIN_14|LL_GPIO_PIN_15;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
