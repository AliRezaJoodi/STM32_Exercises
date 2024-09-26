// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>

#ifndef _STM32F1xx_BM_NVIC_INCLUDED
    #define _STM32F1xx_BM_NVIC_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NVIC_PRIORITYGROUP_0
	#define NVIC_PRIORITYGROUP_0	((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority, 4 bits for subpriority */
	#define NVIC_PRIORITYGROUP_1	((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority, 3 bits for subpriority */
	#define NVIC_PRIORITYGROUP_2	((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority, 2 bits for subpriority */
	#define NVIC_PRIORITYGROUP_3	((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority, 1 bit  for subpriority */
	#define NVIC_PRIORITYGROUP_4	((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,                                                                0 bit  for subpriority */
#endif

__STATIC_INLINE void NVIC_ConfigGroup(uint32_t MODE){
	NVIC_SetPriorityGrouping(MODE); // System interrupt init	
}

void NVIC_USART1_Config(void);
void NVIC_USART2_Config(void);

void NVIC_EXTI0_Config(void);
void NVIC_EXTI1_Config(void);
void NVIC_EXTI2_Config(void);
void NVIC_EXTI3_Config(void);
void NVIC_EXTI4_Config(void);
void NVIC_EXTI9To5_Config(void);
void NVIC_EXTI15To10_Config(void);

#ifdef __cplusplus
}
#endif

#endif		// _STM32F1xx_BM_NVIC_INCLUDED_INCLUDED