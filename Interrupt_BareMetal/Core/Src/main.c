// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"

void SystemClock_Config(void);
void ConfigureExternalInterrupts(void);
void ConfigureOutputPins(void);
void ConfigureOutputPins2(void);

int main(void){
	BUS_EnableOrDisableClockForPowerInterface(1);
	BUS_WaitTillEnableClockFromPowerInterface;
	
	BUS_EnableOrDisableClockForAlternateFunction(1);
	BUS_WaitTillEnableClockForAlternateFunction;
	
  /* System interrupt init*/
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	AFIO_ConfigureSerialWireDebugPort(FULL_SWJ);
  SystemClock_Config();
	BUS_EnableOrDisableClockForPortA(1); BUS_WaitTillEnableClockForPortA;
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
	FLASH_ConfigureLatency(FLASH_LATENCY0);
	FLASH_WaitTillRightLatency(FLASH_LATENCY0);
	RCC_SetCalibTrimmingFromHSI(16);
	RCC_EnableOrDisableClockFromHSI(1);
	RCC_WaitTillStableClockSourceFromHSI
		
	RCC_ConfigurePrescalerForAHB(AHB_DIV1);
	RCC_ConfigurePrescalerForAPB1(APB1_DIV1);
	RCC_ConfigurePrescalerForAPB2(APB2_DIV1);
	RCC_ConfigureSourceForSYSCLK(SYSCLK_HSI);
	RCC_WaitTillRightSourceForSYSCLK(SYSCLK_HSI);
	
	SystemCoreClockUpdate();	
  LL_Init1msTick(8000000);
	SetDirectlySystemCoreClock(8000000);
}

//**********************************************************
void ConfigureExternalInterrupts(void){
	EXTI_ConfigureNVIC_EXTI0();
	EXTI_ConfigureNVIC_EXTI5_9();
	EXTI_ConfigureNVIC_EXTI10_15();
	
	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT0);
	GPIO_ConfigureInputTypeForPin(GPIOA,0,FLOATING_INPUT);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT0,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT0,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT0,1);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT0,0);

	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT6);
	GPIO_ConfigureInputTypeForPin(GPIOA,6,FLOATING_INPUT);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT6,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT6,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT6,0);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT6,1);
	
	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT11);
	GPIO_ConfigureInputTypeForPin(GPIOA,11,FLOATING_INPUT);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT11,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT11,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT11,1);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT11,1);
	
	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT12);
	GPIO_ConfigureInputTypeForPin(GPIOA,12,FLOATING_INPUT);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT12,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT12,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT12,1);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT12,0);
}

//*************************************************
void ConfigureOutputPins(void){
	GPIO_ConfigurePinDirection(GPIOA,1,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,1,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,1);
	
	GPIO_ConfigurePinDirection(GPIOA,2,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,2,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,2);
	
	GPIO_ConfigurePinDirection(GPIOA,3,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,3,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,3);
	
	GPIO_ConfigurePinDirection(GPIOA,4,OUTPUT_MODE_2MHz);
	GPIO_ConfigureOutputTypeForPin(GPIOA,4,GENERAL_PURPOSE_OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,4);
}

//*************************************************
void ConfigureOutputPins2(void){
	BUS_EnableOrDisableClockForPortB(1); 
	BUS_WaitTillEnableClockForPortB;
	GPIOB->CRL=0x22222222UL;
	GPIOB->CRH=0x22222222UL;
	GPIOB->BRR=0xFFFFUL;
}
