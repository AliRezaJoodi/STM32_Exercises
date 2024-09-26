// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_nvic.h>

//**********************************************************
void NVIC_EXTI0_Config(void){	
	NVIC_SetPriority(EXTI0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI0_IRQn);
	//NVIC_DisableIRQ(EXTI1_IRQn);
}

//**********************************************************
void NVIC_EXTI1_Config(void){
	NVIC_SetPriority(EXTI1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(EXTI1_IRQn);
	//NVIC_DisableIRQ(EXTI1_IRQn);	
}

//**********************************************************
void NVIC_EXTI2_Config(void){
	NVIC_SetPriority(EXTI2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI2_IRQn);
	//NVIC_DisableIRQ(EXTI2_IRQn);	
}

//**********************************************************
void NVIC_EXTI3_Config(void){
	NVIC_SetPriority(EXTI3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI3_IRQn);
	//NVIC_DisableIRQ(EXTI3_IRQn);	
}

//**********************************************************
void NVIC_EXTI4_Config(void){
	NVIC_SetPriority(EXTI4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI4_IRQn);
	//NVIC_DisableIRQ(EXTI4_IRQn);	
}

//**********************************************************
void NVIC_EXTI9To5_Config(void){		
	NVIC_SetPriority(EXTI9_5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1, 0));
  NVIC_EnableIRQ(EXTI9_5_IRQn);
	//NVIC_DisableIRQ(EXTI9_5_IRQn);
}

//**********************************************************
void NVIC_EXTI15To10_Config(void){		
	NVIC_SetPriority(EXTI15_10_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),2, 0));
  NVIC_EnableIRQ(EXTI15_10_IRQn);	
	//NVIC_DisableIRQ(EXTI15_10_IRQn);	
}

