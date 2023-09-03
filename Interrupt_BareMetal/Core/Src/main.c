// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"

void SystemClock_Config(void);
void ConfigureExternalInterrupts(void);
void ConfigureOutputPins(void);
void ConfigureOutputPins2(void);

int main(void){
	EnableOrDisableClockSourceForAlternateFunction(1); WaitTillEnableClockSourceForAlternateFunction;
	EnableOrDisableClockSourceForPowerInterface(1); WaitTillEnableClockSourceFromPowerInterface;
	
  /* System interrupt init*/
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	ConfigureSerialWireDebugPort(FULL_SWJ);
  SystemClock_Config();
	EnableOrDisableClockSourceForPortA(1); WaitTillEnableClockSourceForPortA;
  ConfigureExternalInterrupts();
	ConfigureOutputPins();
	ConfigureOutputPins2();
	
  while(1){
		//GPIOB->ODR= AFIO->EXTICR[0];
		GPIOB->ODR= EXTI->IMR;
  }
}

//***************************************************
void SystemClock_Config(void){
  //LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
	ConfigureLatencyForFLASH(FLASH_LATENCY0);
  //while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0){}
	WaitTillRightLatency(FLASH_LATENCY0);
  //LL_RCC_HSI_SetCalibTrimming(16);
	SetCalibTrimmingFromHSI(16);
  //LL_RCC_HSI_Enable();
	EnableOrDisableClockFromHSI(1);
   /* Wait till HSI is ready */
  //while(LL_RCC_HSI_IsReady() != 1){}
	WaitTillStableClockSourceFromHSI
		
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
	
	SystemCoreClockUpdate();	
  LL_Init1msTick(8000000);
  //LL_SetSystemCoreClock(8000000);
	SetDirectlySystemCoreClock(8000000);
}

//**********************************************************
void ConfigureExternalInterrupts(void){
	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT0);
	ConfigurePinForInputMode(GPIOA,0,FLOATING_INPUT);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT0,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT0,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT0,1);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT0,0);

	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT6);
	ConfigurePinForInputMode(GPIOA,6,FLOATING_INPUT);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT6,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT6,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT6,0);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT6,1);
	
	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT11);
	ConfigurePinForInputMode(GPIOA,11,FLOATING_INPUT);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT11,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT11,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT11,1);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT11,1);
	
	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT12);
	ConfigurePinForInputMode(GPIOA,12,FLOATING_INPUT);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT12,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT12,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT12,1);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT12,0);
	
  /* EXTI interrupt init*/
  NVIC_SetPriority(EXTI0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI0_IRQn);
  NVIC_SetPriority(EXTI9_5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1, 0));
  NVIC_EnableIRQ(EXTI9_5_IRQn);
  NVIC_SetPriority(EXTI15_10_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),2, 0));
  NVIC_EnableIRQ(EXTI15_10_IRQn);
}

//*************************************************
void ConfigureOutputPins(void){
	ConfigurePinForDirection(GPIOA,1,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(GPIOA,1,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(GPIOA,1);
	
	ConfigurePinForDirection(GPIOA,2,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(GPIOA,2,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(GPIOA,2);
	
	ConfigurePinForDirection(GPIOA,3,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(GPIOA,3,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(GPIOA,3);
	
	ConfigurePinForDirection(GPIOA,4,OUTPUT_MODE_2MHz);
	ConfigurePinForOutputMode(GPIOA,4,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	ResetPinFromOutput(GPIOA,4);
}

//*************************************************
void ConfigureOutputPins2(void){
	EnableOrDisableClockSourceForPortB(1); WaitTillEnableClockSourceForPortB;
	GPIOB->CRL=0x22222222UL;
	GPIOB->CRH=0x22222222UL;
	GPIOB->BRR=0xFFFFUL;
/*
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOB);
	
	  LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_0|LL_GPIO_PIN_1|LL_GPIO_PIN_2|LL_GPIO_PIN_10
                          |LL_GPIO_PIN_11|LL_GPIO_PIN_12|LL_GPIO_PIN_13|LL_GPIO_PIN_14
                          |LL_GPIO_PIN_15|LL_GPIO_PIN_3|LL_GPIO_PIN_4|LL_GPIO_PIN_5
                          |LL_GPIO_PIN_6|LL_GPIO_PIN_7|LL_GPIO_PIN_8|LL_GPIO_PIN_9);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_0|LL_GPIO_PIN_1|LL_GPIO_PIN_2|LL_GPIO_PIN_10
                          |LL_GPIO_PIN_11|LL_GPIO_PIN_12|LL_GPIO_PIN_13|LL_GPIO_PIN_14
                          |LL_GPIO_PIN_15|LL_GPIO_PIN_3|LL_GPIO_PIN_4|LL_GPIO_PIN_5
                          |LL_GPIO_PIN_6|LL_GPIO_PIN_7|LL_GPIO_PIN_8|LL_GPIO_PIN_9;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
*/	
}
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
