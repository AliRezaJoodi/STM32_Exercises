// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

#include <stm32f1xx.h>
#include <utility.h>

#ifndef _STM32F1xx_BM_SYSTEM_INCLUDED
    #define _STM32F1xx_BM_SYSTEM_INCLUDED

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

#define LATENCY0	0b000	// Zero wait state, if 0 < SYSCLK <= 24MHz
#define LATENCY1	0b001	// One wait state, if 24MHz < SYSCLK <= 48MHz
#define LATENCY2	0b010	// Two wait states, if 48MHz < SYSCLK <= 72MHz
#define _GetLatency \
	Get3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos)
#define FLASH_SetLatency(MODE) \
	Write3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos, MODE);\
	while(_GetLatency != MODE){};
		
// HCLK Clock Frequency		
#define System_SetCoreClockFrequency(HZ) \
	SystemCoreClock = HZ;

#define System_SetSysTick_1ms(HCLK_HZ) \
  SysTick->LOAD = (uint32_t)((HCLK_HZ / 1000U) - 1UL);\
  SysTick->VAL = 0UL;\
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

#ifdef __cplusplus
	}
#endif

#endif
