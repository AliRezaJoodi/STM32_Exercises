/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
static inline void Delay_us(uint32_t us){
	while(us--){
			/* 8 MHz -> 1 cycle = 125 ns
				 8 cycles ˜ 1 us */
			__NOP();
			__NOP();
			__NOP();
			__NOP();
			__NOP();
			__NOP();
			__NOP();
			__NOP();
	}
}

static inline void Delay_ms(uint32_t ms){
    while(ms--){
        Delay_us(1000);
    }
}
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
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_AFIO);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  /* System interrupt init*/
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* SysTick_IRQn interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));

  /** NONJTRST: Full SWJ (JTAG-DP + SW-DP) but without NJTRST
  */
  LL_GPIO_AF_Remap_SWJ_NONJTRST();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  //MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	  /* GPIO Ports Clock Enable */
		LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOC);
		LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);
		LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOB);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//	GPIO_ConfigDirection(GPIOC, 13, GPIO_MODE_INPUT);
//	GPIO_ConfigInputType(GPIOC, 13, GPIO_INPUT_FLOATING);
//	
//	GPIO_LockPinMask(GPIOC, (0x01U << 13U));

//	GPIO_ConfigDirection(GPIOC, 13, GPIO_MODE_OUTPUT_2MHz);
//	GPIO_ConfigOutputType(GPIOC, 13, GPIO_OUTPUT_GP_PUSHPULL);
//	GPIO_WritePin(GPIOC, 13, 0);
//	while (1){}
	
	GPIO_ConfigDirection(GPIOC, 13, GPIO_MODE_OUTPUT_2MHz);
	GPIO_ConfigOutputType(GPIOC, 13, GPIO_OUTPUT_GP_PUSHPULL);
	GPIO_WritePin(GPIOC, 13, 1); 
	
	GPIO_ConfigDirection(GPIOA, 0, GPIO_MODE_INPUT);
	GPIO_ConfigInputType(GPIOA, 0, GPIO_INPUT_PULL);
	GPIO_ConfigPull(GPIOA, 0, GPIO_PULL_UP);

	GPIO_ConfigDirection(GPIOA, 1, GPIO_MODE_INPUT);
	GPIO_ConfigInputType(GPIOA, 1, GPIO_INPUT_PULL);
	GPIO_ConfigPull(GPIOA, 1, GPIO_PULL_DOWN);

	GPIO_ConfigDirection(GPIOA, 4, GPIO_MODE_INPUT);
	GPIO_ConfigInputType(GPIOA, 4, GPIO_INPUT_FLOATING);
	GPIO_ConfigDirection(GPIOA, 5, GPIO_MODE_INPUT);
	GPIO_ConfigInputType(GPIOA, 5, GPIO_INPUT_FLOATING);
	GPIO_ConfigDirection(GPIOA, 6, GPIO_MODE_INPUT);
	GPIO_ConfigInputType(GPIOA, 6, GPIO_INPUT_FLOATING);
	GPIO_ConfigDirection(GPIOA, 7, GPIO_MODE_INPUT);
	GPIO_ConfigInputType(GPIOA, 7, GPIO_INPUT_FLOATING);

	GPIO_ConfigDirection(GPIOB, 12, GPIO_MODE_OUTPUT_2MHz);
	GPIO_ConfigOutputType(GPIOB, 12, GPIO_OUTPUT_GP_PUSHPULL);
	GPIO_ResetPin(GPIOB, 12);
	GPIO_ConfigDirection(GPIOB, 13, GPIO_MODE_OUTPUT_2MHz);
	GPIO_ConfigOutputType(GPIOB, 13, GPIO_OUTPUT_GP_PUSHPULL);
	GPIO_ResetPin(GPIOB, 13); 	
	GPIO_ConfigDirection(GPIOB, 14, GPIO_MODE_OUTPUT_2MHz);
	GPIO_ConfigOutputType(GPIOB, 14, GPIO_OUTPUT_GP_PUSHPULL);
	GPIO_ResetPin(GPIOB, 14); 
	GPIO_ConfigDirection(GPIOB, 15, GPIO_MODE_OUTPUT_2MHz);
	GPIO_ConfigOutputType(GPIOB, 15, GPIO_OUTPUT_GP_PUSHPULL);
	GPIO_ResetPin(GPIOB, 15); 
	
  while (1){
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		if(GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0){
			GPIO_ResetPin(GPIOC, GPIO_PIN_13);
		}
		
		if(GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 1){
			GPIO_SetPin(GPIOC, GPIO_PIN_13);
		}
				
		uint32_t value = GPIO_ReadPinField(GPIOA, 0xF0U);
		//uint32_t value = GPIO_Read4Pin(GPIOA, 4U);
				
		GPIO_WritePinField(GPIOB, 0xF000U, value);
		//GPIO_Write4Pin(GPIOB, GPIO_PIN_12, value);
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
  LL_Init1msTick(8000000);
  LL_SetSystemCoreClock(8000000);
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
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOC);
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOB);

  /**/
  LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_13);

  /**/
  LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_12|LL_GPIO_PIN_13|LL_GPIO_PIN_14|LL_GPIO_PIN_15);

  /**/
  GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
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
  GPIO_InitStruct.Mode = LL_GPIO_MODE_FLOATING;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /**/
  GPIO_InitStruct.Pin = LL_GPIO_PIN_12|LL_GPIO_PIN_13|LL_GPIO_PIN_14|LL_GPIO_PIN_15;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
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
