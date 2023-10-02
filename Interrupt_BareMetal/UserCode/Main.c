// GitHub Account: GitHub.com/AliRezaJoodi

#include "Utility.h"
#include "STM32F1xx_System_BareMetal.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "STM32F1xx_EXTI_BareMetal.h"

void ConfigureExternalInterrupts(void);
void ConfigureOutputPins(void);
void ConfigureOutputPins2(void);

int main(void){
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	AFIO_SetSerialWireDebugPort(FULL_SWJ);
  
	SystemClock_Configuration();
	
  ConfigureExternalInterrupts();
	ConfigureOutputPins();
	ConfigureOutputPins2();
	
  while(1){
		//GPIOB->ODR= AFIO->EXTICR[0];
		GPIOB->ODR= EXTI->IMR;
  }
}

//**********************************************************
void ConfigureExternalInterrupts(void){	
	EXTI_ConfigureNVIC_EXTI0();
	EXTI_ConfigureNVIC_EXTI5_9();
	EXTI_ConfigureNVIC_EXTI10_15();

	BUS_GPIOA_EnableOrDisable(1);
	
	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT0);
	//GPIO_ConfigureInputTypeForPin(GPIOA,0,FLOATING_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,0, INPUT_FLOATING);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT0,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT0,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT0,1);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT0,0);

	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT6);
	GPIO_InputMode_SetInputType(GPIOA,6,INPUT_FLOATING);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT6,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT6,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT6,0);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT6,1);
	
	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT11);
	GPIO_InputMode_SetInputType(GPIOA,11,INPUT_FLOATING);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT11,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT11,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT11,1);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT11,1);
	
	EXTI_ConfigureSource(EXTI_PORTA,EXTI_INT12);
	GPIO_InputMode_SetInputType(GPIOA,12,INPUT_FLOATING);
	EXTI_EnableOrDisableInterruptMode(EXTI_INT12,1);
	EXTI_EnableOrDisableEventMode(EXTI_INT12,0);
	EXTI_EnableOrDisableRisingTrigger(EXTI_INT12,1);
	EXTI_EnableOrDisableFallingTrigger(EXTI_INT12,0);
}

//*************************************************
void ConfigureOutputPins(void){
	BUS_GPIOA_EnableOrDisable(1);
	
	GPIO_SetInputOrOutputMode(GPIOA,1, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,1, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,1, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,1);
	
	GPIO_SetInputOrOutputMode(GPIOA,2, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,2, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,2, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,2);
	
	GPIO_SetInputOrOutputMode(GPIOA,3, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,3, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,3, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,3);
	
	GPIO_SetInputOrOutputMode(GPIOA,4, MODE_OUTPUT_2MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,4, OUTPUT_GPIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,4, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,4);
}

//*************************************************
void ConfigureOutputPins2(void){
	BUS_GPIOB_EnableOrDisable(1); 
	GPIOB->CRL=0x22222222UL;
	GPIOB->CRH=0x22222222UL;
	GPIOB->BRR=0xFFFFUL;
}
