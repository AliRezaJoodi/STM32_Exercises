// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_nvic.h>

//**********************************************************
void NVIC_USART1_Config(void){	
	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(USART1_IRQn);
	//NVIC_DisableIRQ(USART1_IRQn);
}

//**********************************************************
void NVIC_USART2_Config(void){	
	NVIC_SetPriority(USART2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(USART2_IRQn);
	//NVIC_DisableIRQ(USART1_IRQn);
}
