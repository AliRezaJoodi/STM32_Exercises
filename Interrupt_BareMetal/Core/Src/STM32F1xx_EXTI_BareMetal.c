
#include "main.h"
#include "STM32F1xx_EXTI_BareMetal.h"

//*****************************************
void EXTI_ConfigureNVIC_EXTI0(void){
  NVIC_SetPriority(EXTI0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI0_IRQn);
	//NVIC_DisableIRQ(EXTI1_IRQn);
}

//*****************************************
void EXTI_ConfigureNVIC_EXTI1(void){
  NVIC_SetPriority(EXTI1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI1_IRQn);
	//NVIC_DisableIRQ(EXTI1_IRQn);
}

//*****************************************
void EXTI_ConfigureNVIC_EXTI2(void){
  NVIC_SetPriority(EXTI2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI2_IRQn);
	//NVIC_DisableIRQ(EXTI2_IRQn);
}

//*****************************************
void EXTI_ConfigureNVIC_EXTI3(void){
  NVIC_SetPriority(EXTI3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI3_IRQn);
	//NVIC_DisableIRQ(EXTI3_IRQn);
}

//*****************************************
void EXTI_ConfigureNVIC_EXTI4(void){
  NVIC_SetPriority(EXTI4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI4_IRQn);
	//NVIC_DisableIRQ(EXTI4_IRQn);
}

//*****************************************
void EXTI_ConfigureNVIC_EXTI5_9(void){	
  NVIC_SetPriority(EXTI9_5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1, 0));
  NVIC_EnableIRQ(EXTI9_5_IRQn);
	//NVIC_DisableIRQ(EXTI9_5_IRQn);
}

//*****************************************
void EXTI_ConfigureNVIC_EXTI10_15(void){	
  NVIC_SetPriority(EXTI15_10_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),2, 0));
  NVIC_EnableIRQ(EXTI15_10_IRQn);	
	//NVIC_DisableIRQ(EXTI15_10_IRQn);
}

//*****************************************
void EXTI0_IRQHandler(void){
	if (EXTI_IsActiveFlag(EXTI_INT0) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT0);
		TogglePinFromOutput(GPIOA,1);
		//while(1){};
  }
}

//*****************************************
void EXTI1_IRQHandler(void){
	if (EXTI_IsActiveFlag(EXTI_INT1) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT1);
		
  }
}

//*****************************************
void EXTI2_IRQHandler(void){
	if (EXTI_IsActiveFlag(EXTI_INT2) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT2);
		
  }
}

//*****************************************
void EXTI3_IRQHandler(void){
	if (EXTI_IsActiveFlag(EXTI_INT3) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT3);
		
  }
}

//*****************************************
void EXTI4_IRQHandler(void){
	if (EXTI_IsActiveFlag(EXTI_INT4) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT4);
		
  }
}

//*****************************************
void EXTI9_5_IRQHandler(void){
	if (EXTI_IsActiveFlag(EXTI_INT6) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT6);
		TogglePinFromOutput(GPIOA,2);
		//while(1){};
  }
}

//*****************************************
void EXTI15_10_IRQHandler(void){
	if (EXTI_IsActiveFlag(EXTI_INT11) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT11);
		TogglePinFromOutput(GPIOA,3);
		//while(1){};
  }
	
	if (EXTI_IsActiveFlag(EXTI_INT12) != RESET){
		EXTI_ClearPendingRegister(EXTI_INT12);
		TogglePinFromOutput(GPIOA,4);
  }
}
