// GitHub Account: GitHub.com/AliRezaJoodi

#include "STM32F1xx_EXTI_BareMetal.h"

//*****************************************
void EXTI0_NVIC_Configuration(void){
  NVIC_SetPriority(EXTI0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI0_IRQn);
	//NVIC_DisableIRQ(EXTI1_IRQn);
}

//*****************************************
void EXTI1_NVIC_Configuration(void){
  NVIC_SetPriority(EXTI1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI1_IRQn);
	//NVIC_DisableIRQ(EXTI1_IRQn);
}

//*****************************************
void EXTI2_NVIC_Configuration(void){
  NVIC_SetPriority(EXTI2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI2_IRQn);
	//NVIC_DisableIRQ(EXTI2_IRQn);
}

//*****************************************
void EXTI3_NVIC_Configuration(void){
  NVIC_SetPriority(EXTI3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI3_IRQn);
	//NVIC_DisableIRQ(EXTI3_IRQn);
}

//*****************************************
void EXTI4_NVIC_Configuration(void){
  NVIC_SetPriority(EXTI4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI4_IRQn);
	//NVIC_DisableIRQ(EXTI4_IRQn);
}

//*****************************************
void EXTI5To9_NVIC_Configuration(void){	
  NVIC_SetPriority(EXTI9_5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1, 0));
  NVIC_EnableIRQ(EXTI9_5_IRQn);
	//NVIC_DisableIRQ(EXTI9_5_IRQn);
}

//*****************************************
void EXTI10To15_NVIC_Configuration(void){	
  NVIC_SetPriority(EXTI15_10_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),2, 0));
  NVIC_EnableIRQ(EXTI15_10_IRQn);	
	//NVIC_DisableIRQ(EXTI15_10_IRQn);
}

