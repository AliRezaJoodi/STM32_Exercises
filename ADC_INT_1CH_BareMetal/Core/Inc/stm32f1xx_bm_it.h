// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _STM32F1xx_BM_IT_INCLUDED
#define _STM32F1xx_BM_IT_INCLUDED

#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"
#include <utility.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_timer_systick.h>
#include <stm32f1xx_bm_usart.h>
#include <stm32f1xx_bm_exti.h>
#include <stm32f1xx_bm_adc.h>

#ifndef NVIC_PRIORITYGROUP_0
	#define NVIC_PRIORITYGROUP_0	((uint32_t)0x00000007)		// 0 bit  for pre-emption priority, 4 bits for subpriority
	#define NVIC_PRIORITYGROUP_1	((uint32_t)0x00000006)		// 1 bit  for pre-emption priority, 3 bits for subpriority
	#define NVIC_PRIORITYGROUP_2	((uint32_t)0x00000005) 		// 2 bits for pre-emption priority, 2 bits for subpriority
	#define NVIC_PRIORITYGROUP_3	((uint32_t)0x00000004) 		// 3 bits for pre-emption priority, 1 bit  for subpriority
	#define NVIC_PRIORITYGROUP_4	((uint32_t)0x00000003) 		// 4 bits for pre-emption priority, 0 bit  for subpriority                                                               0 bit  for subpriority */
#endif

void NVIC_Config(void);

void ADC1_2_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif		// _STM32F1xx_BM_IT_INCLUDED
