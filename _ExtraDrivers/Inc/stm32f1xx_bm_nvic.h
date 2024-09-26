// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>

#ifndef _STM32F1xx_BM_NVIC_INCLUDED
    #define _STM32F1xx_BM_NVIC_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NVIC_PRIORITYGROUP_0
	#define NVIC_PRIORITYGROUP_0	((uint32_t)0x00000007)		// 0 bit  for pre-emption priority, 4 bits for subpriority
	#define NVIC_PRIORITYGROUP_1	((uint32_t)0x00000006)		// 1 bit  for pre-emption priority, 3 bits for subpriority
	#define NVIC_PRIORITYGROUP_2	((uint32_t)0x00000005) 		// 2 bits for pre-emption priority, 2 bits for subpriority
	#define NVIC_PRIORITYGROUP_3	((uint32_t)0x00000004) 		// 3 bits for pre-emption priority, 1 bit  for subpriority
	#define NVIC_PRIORITYGROUP_4	((uint32_t)0x00000003) 		// 4 bits for pre-emption priority, 0 bit  for subpriority                                                               0 bit  for subpriority */
#endif

void NVIC_Config(void);

#ifdef __cplusplus
}
#endif

#endif		// _STM32F1xx_BM_NVIC_INCLUDED_INCLUDED

// List:
	//NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	//NVIC_EnableIRQ(USART1_IRQn);
	//NVIC_DisableIRQ(USART1_IRQn);

	//NVIC_SetPriority(USART2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	//NVIC_EnableIRQ(USART2_IRQn);
	//NVIC_DisableIRQ(USART2_IRQn);
	
	//NVIC_SetPriority(EXTI0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  //NVIC_EnableIRQ(EXTI0_IRQn);
	//NVIC_DisableIRQ(EXTI1_IRQn);

	//NVIC_SetPriority(EXTI1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	//NVIC_EnableIRQ(EXTI1_IRQn);
	//NVIC_DisableIRQ(EXTI1_IRQn);	

	//NVIC_SetPriority(EXTI2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  //NVIC_EnableIRQ(EXTI2_IRQn);
	//NVIC_DisableIRQ(EXTI2_IRQn);	

	//NVIC_SetPriority(EXTI3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  //NVIC_EnableIRQ(EXTI3_IRQn);
	//NVIC_DisableIRQ(EXTI3_IRQn);	

	//NVIC_SetPriority(EXTI4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  //NVIC_EnableIRQ(EXTI4_IRQn);
	//NVIC_DisableIRQ(EXTI4_IRQn);	
	
	//NVIC_SetPriority(EXTI9_5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  //NVIC_EnableIRQ(EXTI9_5_IRQn);
	//NVIC_DisableIRQ(EXTI9_5_IRQn);
	
	//NVIC_SetPriority(EXTI15_10_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  //NVIC_EnableIRQ(EXTI15_10_IRQn);	
	//NVIC_DisableIRQ(EXTI15_10_IRQn);	