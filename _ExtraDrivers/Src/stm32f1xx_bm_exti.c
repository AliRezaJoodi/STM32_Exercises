// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_exti.h>

//**********************************************************
void EXTI_ConfigDefault1(void){	
	BUS_GPIOA_EnableOrDisable(1);
	
	GPIO_SetInputOrOutputMode(GPIOA,0, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOA,0, INPUT_PULL);
	GPIO_InInputModeWithPull_SetPullUpOrPullDown(GPIOA,0, PULL_PULLUP);
	EXTI_SetSource(EXTI_INT0, EXTI_PORTA);
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT0,1);
	EXTI_EventMode_EnableOrDisable(EXTI_INT0,0);
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT0,0);
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT0,1);
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT0,0);
	
	GPIO_SetInputOrOutputMode(GPIOA,6, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOA,6, INPUT_PULL);
	GPIO_InInputModeWithPull_SetPullUpOrPullDown(GPIOA,6, PULL_PULLDOWN);
	EXTI_SetSource(EXTI_INT6, EXTI_PORTA);
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT6,1);
	EXTI_EventMode_EnableOrDisable(EXTI_INT6,0);
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT6,1);
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT6,0);
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT6,0);

	GPIO_SetInputOrOutputMode(GPIOA,11, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOA,11, INPUT_FLOATING);
	EXTI_SetSource(EXTI_INT11, EXTI_PORTA);
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT11,1);
	EXTI_EventMode_EnableOrDisable(EXTI_INT11,0);
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT11,1);
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT11,1);
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT11,0);
}


