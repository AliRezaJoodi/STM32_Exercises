// GitHub Account: GitHub.com/AliRezaJoodi

#include "STM32F1xx_EXTI_BareMetal.h"

//*****************************************
void EXTI_INT0_ConfigureNVIC(void){
  NVIC_SetPriority(EXTI0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI0_IRQn);
	//NVIC_DisableIRQ(EXTI1_IRQn);
}

//*****************************************
void EXTI_INT1_ConfigureNVIC(void){
  NVIC_SetPriority(EXTI1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI1_IRQn);
	//NVIC_DisableIRQ(EXTI1_IRQn);
}

//*****************************************
void EXTI_INT2_ConfigureNVIC(void){
  NVIC_SetPriority(EXTI2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI2_IRQn);
	//NVIC_DisableIRQ(EXTI2_IRQn);
}

//*****************************************
void EXTI_INT3_ConfigureNVIC(void){
  NVIC_SetPriority(EXTI3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI3_IRQn);
	//NVIC_DisableIRQ(EXTI3_IRQn);
}

//*****************************************
void EXTI_INT4_ConfigureNVIC(void){
  NVIC_SetPriority(EXTI4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI4_IRQn);
	//NVIC_DisableIRQ(EXTI4_IRQn);
}

//*****************************************
void EXTI_INT5To9_ConfigureNVIC(void){	
  NVIC_SetPriority(EXTI9_5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1, 0));
  NVIC_EnableIRQ(EXTI9_5_IRQn);
	//NVIC_DisableIRQ(EXTI9_5_IRQn);
}

//*****************************************
void EXTI_INT10To15_ConfigureNVIC(void){	
  NVIC_SetPriority(EXTI15_10_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),2, 0));
  NVIC_EnableIRQ(EXTI15_10_IRQn);	
	//NVIC_DisableIRQ(EXTI15_10_IRQn);
}

