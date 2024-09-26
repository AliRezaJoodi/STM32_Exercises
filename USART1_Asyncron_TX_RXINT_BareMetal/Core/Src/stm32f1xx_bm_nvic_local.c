// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_nvic.h>

//**********************************************************
void NVIC_Config(void){	
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	
	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(USART1_IRQn);
}
