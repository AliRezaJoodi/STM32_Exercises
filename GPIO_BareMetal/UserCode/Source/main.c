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
#include "STM32F103_RCC_BareMetal.h"
#include "STM32F103_BUS_BareMetal.h"
#include "STM32F103_GPIO_BareMetal.h"
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
  //LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_AFIO);
	EnableOrDisableClockSourceForAlternateFunction(1);
  //LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
	EnableOrDisableClockSourceForPowerInterface(1);

  /* System interrupt init*/
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* SysTick_IRQn interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));

  /** DISABLE: JTAG-DP Disabled and SW-DP Disabled
  */
  //LL_GPIO_AF_DisableRemap_SWJ();
	ConfigureSerialWireDebugPort(JTAG_DISABLED_AND_SWD_DISABLED);

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
	
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	//GPIO_ConfigurePinDirection(GPIOA,14,INPUT_MODE);
	//GPIO_ConfigureInputMode(GPIOA,15,INPUT_WITH_PULLUP_PULLDOWN);
	//GPIO_ConfigurePullUpOrPullDown(GPIOA,15,PULLDOWN);
	//GPIO_SetOutputPinWithODR(GPIOA,0);
	
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	//if(IsEnableClockSourceFromPortA==1){GPIO_SetOutputPin(GPIOB,0);}
			//else if(IsEnableClockSourceFromPortA==0){GPIO_ResetOutputPin(GPIOB,0);}
	//ResetClockSourceFromPortA;
			
  while (1){
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
		GPIO_ToggleOutputPin(GPIOA,0); LL_mDelay(1000);
		//GPIO_WriteOutputPin(GPIOA,0,GPIO_GetInputPin(GPIOA,2));
		if(IsClockStableFromHSI==1){GPIO_SetOutputPin(GPIOB,0);}
			else if(IsClockStableFromHSI==0){GPIO_ResetOutputPin(GPIOB,0);}
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void){
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0){}
  //LL_RCC_HSI_SetCalibTrimming(16);
	SetCalibTrimmingFromHSI(16);
  //LL_RCC_HSI_Enable();
	EnableOrDisableClockFromHSI(1);
   /* Wait till HSI is ready */
  //while(LL_RCC_HSI_IsReady() != 1){}
	WaitTillClockStableFromHSI
		
  //LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
	ConfigurePrescalerForAHB(AHB_DIV1);
  //LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
	ConfigurePrescalerForAPB1(APB1_DIV1);
  //LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
	ConfigurePrescalerForAPB2(APB2_DIV1);
  //LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);
	ConfigureSystemClockSource(SYSCLK_HSI);
   /* Wait till System clock is ready */
  //while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI){}
	//while(GetSystemClockSource != SYSCLK_HSI){}
	WaitTillRightClockSource(SYSCLK_HSI);
		
  LL_Init1msTick(8000000);
  LL_SetSystemCoreClock(8000000);
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void){
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  //LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);
	EnableOrDisableClockSourceFromPortA(1); LL_mDelay(10);
	//DisableClockSourceFromPortA; LL_mDelay(10);
	//EnableOrDisableClockSourceFromPortA(0); LL_mDelay(10);
	//RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPAEN);
	//while(IsEnableClockSourceForPortA){}
  /**/
  //LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_0);
	//GPIOA->BSRR=(0x1UL<<0);
	//GPIOA->BRR=(0x1UL<<0);
	GPIO_SetOutputPin(GPIOA,0);
	GPIO_ConfigurePinDirection(GPIOA,0,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputMode(GPIOA,0,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	
	//GPIO_ResetOutputPin(GPIOA, 0);
	//GPIO_ResetOutputPinWithBSRR(GPIOA,0);
	//GPIO_SetOutputPinWithODR(GPIOA,0);
	//GPIO_ResetOutputPinWithODR(GPIOA,0);
	//GPIO_ToggleOutputPin(GPIOA,0);
	//GPIO_WriteOutputPin(GPIOA,0,0);	
	
	//if(GPIO_GetOutputPin(GPIOA,0)){GPIO_SetOutputPinWithODR(GPIOA,1);}
		//else{GPIO_ResetOutputPinWithODR(GPIOA,1);}
  /**/
  //LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_1);
	//GPIO_SetOutputPin(GPIOA,1);
	//GPIO_ResetOutputPin(GPIOA, 1);
	//GPIO_ResetOutputPinWithBSRR(GPIOA,1);
	//GPIO_SetOutputPinWithODR(GPIOA,1);
	//GPIO_ResetOutputPinWithODR(GPIOA,1);
	
  /**/
/*	
  GPIO_InitStruct.Pin = LL_GPIO_PIN_14;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
*/
  /**/
	/*
  GPIO_InitStruct.Pin = LL_GPIO_PIN_15;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
*/
  /**/
	/*
  GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
*/
  //LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOB);
	EnableOrDisableClockSourceForPortB(ENABLE);
  GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
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

#ifdef  USE_FULL_ASSERT
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
