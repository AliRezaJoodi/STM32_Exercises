// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_exti.h>

//**********************************************************
void EXTI_Config(void){	
	/*
	EXTI0_NVIC_Config();
	EXTI9To5_NVIC_Config();
	EXTI15To10_NVIC_Config();

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
	*/
}

//*****************************************
void EXTI0_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT0) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT0);
		//GPIO_TogglePin(GPIOC,13);
  }
}

//*****************************************
void EXTI1_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT1) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT1);
		
  }
}

//*****************************************
void EXTI2_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT2) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT2);
		
  }
}

//*****************************************
void EXTI3_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT3) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT3);
		
  }
}

//*****************************************
void EXTI4_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT4) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT4);
		
  }
}

//*****************************************
void EXTI9_5_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT6) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT6);
		//GPIO_TogglePin(GPIOC,13);
  }
}

//*****************************************
void EXTI15_10_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT11) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT11);
		//GPIO_TogglePin(GPIOC,13);
  }
}


