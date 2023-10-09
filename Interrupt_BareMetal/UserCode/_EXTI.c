// GitHub Account: GitHub.com/AliRezaJoodi

#include "Utility.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "STM32F1xx_EXTI_BareMetal.h"

//**********************************************************
void EXTI_Configuration(void){	
	EXTI0_NVIC_Configuration();
	EXTI5To9_NVIC_Configuration();
	EXTI10To15_NVIC_Configuration();

	BUS_GPIOA_EnableOrDisable(1);
	
	GPIO_SetInputOrOutputMode(GPIOA,0, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,0, INPUT_FLOATING);
	EXTI_SetSource(EXTI_PORTA, EXTI_INT0);
	EXTI0_InterruptMode_EnableOrDisable(1);
	EXTI0_EventMode_EnableOrDisable(0);
	EXTI0_RisingTrigger_EnableOrDisable(1);
	EXTI0_FallingTrigger_EnableOrDisable(0);
	EXTI0_SoftwareInterrupt_EnableOrDisable(0);
	
	GPIO_SetInputOrOutputMode(GPIOA,6, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,6, INPUT_FLOATING);
	EXTI_SetSource(EXTI_PORTA, EXTI_INT6);
	EXTI6_InterruptMode_EnableOrDisable(1);
	EXTI6_EventMode_EnableOrDisable(0);
	EXTI6_RisingTrigger_EnableOrDisable(0);
	EXTI6_FallingTrigger_EnableOrDisable(1);
	EXTI6_SoftwareInterrupt_EnableOrDisable(0);
	
	GPIO_SetInputOrOutputMode(GPIOA,11, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,11, INPUT_FLOATING);
	EXTI_SetSource(EXTI_PORTA, EXTI_INT11);
	EXTI11_InterruptMode_EnableOrDisable(1);
	EXTI11_EventMode_EnableOrDisable(0);
	EXTI11_RisingTrigger_EnableOrDisable(1);
	EXTI11_FallingTrigger_EnableOrDisable(1);
	EXTI11_SoftwareInterrupt_EnableOrDisable(0);

	GPIO_SetInputOrOutputMode(GPIOA,12, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,12, INPUT_FLOATING);
	EXTI_SetSource(EXTI_PORTA, EXTI_INT12);
	EXTI12_InterruptMode_EnableOrDisable(1);
	EXTI12_EventMode_EnableOrDisable(0);
	EXTI12_RisingTrigger_EnableOrDisable(1);
	EXTI12_FallingTrigger_EnableOrDisable(0);
	EXTI12_SoftwareInterrupt_EnableOrDisable(0);
}

//*****************************************
void EXTI0_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT0) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT0);
		GPIO_TogglePin(GPIOA,1);
		//while(1){};
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
		GPIO_TogglePin(GPIOA,2);
		//while(1){};
  }
}

//*****************************************
void EXTI15_10_IRQHandler(void){
	if (EXTI_GetActiveFlag(EXTI_INT11) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT11);
		GPIO_TogglePin(GPIOA,3);
		//while(1){};
  }
	
	if (EXTI_GetActiveFlag(EXTI_INT12) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT12);
		GPIO_TogglePin(GPIOA,4);
  }
}


