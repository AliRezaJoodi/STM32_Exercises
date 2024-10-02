// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include <utility.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_timer_systick.h>
#include <stm32f1xx_bm_usart.h>
#include <stm32f1xx_bm_exti.h>

#ifndef _STM32F1xx_BM_IT_INCLUDED
#define _STM32F1xx_BM_IT_INCLUDED

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

void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);


#ifdef __cplusplus
}
#endif

#endif		// _STM32F1xx_BM_IT_INCLUDED