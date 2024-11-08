// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_exti.h>

//**********************************************************
void EXTI_ConfigDefault1(void){	
	BUS_GPIOA_EnableOrDisable(1);
	
	GPIO_OutputOrInputMode_SetMode(GPIOA,0, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,0, GPIO_INPUT_PULLUP);

	EXTI_SetSource(EXTI_INT0, EXTI_PORTA);
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT0,1);
	EXTI_EventMode_EnableOrDisable(EXTI_INT0,0);
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT0,0);
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT0,1);
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT0,0);
	
	GPIO_OutputOrInputMode_SetMode(GPIOA,6, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,6, GPIO_INPUT_PULLDOWN);

	EXTI_SetSource(EXTI_INT6, EXTI_PORTA);
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT6,1);
	EXTI_EventMode_EnableOrDisable(EXTI_INT6,0);
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT6,1);
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT6,0);
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT6,0);

	GPIO_OutputOrInputMode_SetMode(GPIOA,11, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,11, GPIO_INPUT_FLOATING);
	
	EXTI_SetSource(EXTI_INT11, EXTI_PORTA);
	EXTI_InterruptMode_EnableOrDisable(EXTI_INT11,1);
	EXTI_EventMode_EnableOrDisable(EXTI_INT11,0);
	EXTI_RisingTrigger_EnableOrDisable(EXTI_INT11,1);
	EXTI_FallingTrigger_EnableOrDisable(EXTI_INT11,1);
	EXTI_SoftwareInterrupt_EnableOrDisable(EXTI_INT11,0);
}


