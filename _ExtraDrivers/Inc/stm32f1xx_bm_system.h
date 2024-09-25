// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

#include <stm32f1xx.h>
#include <utility.h>

#ifndef _STM32F1xx_BM_SYSTEM_INCLUDED
#define _STM32F1xx_BM_SYSTEM_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#define LATENCY0	0b000	// Zero wait state, if 0 < SYSCLK <= 24MHz
#define LATENCY1	0b001	// One wait state, if 24MHz < SYSCLK <= 48MHz
#define LATENCY2	0b010	// Two wait states, if 48MHz < SYSCLK <= 72MHz
/*#define _GetLatency \
	Get3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos)*/
__STATIC_INLINE void FLASH_SetLatency(uint32_t MODE){
	Write3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos, MODE);
	while(Get3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos) != MODE){};	
}
/*#define FLASH_SetLatency(MODE) \
	Write3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos, MODE);\
	while(Get3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos) != MODE){};*/
		
// HCLK Clock Frequency		
#define System_SetCoreClockFrequency(HZ) \
	SystemCoreClock = HZ;

__STATIC_INLINE void System_SetSysTick_1ms(uint32_t HCLK_HZ){
  SysTick->LOAD = (uint32_t)((HCLK_HZ / 1000U) - 1UL);
  SysTick->VAL = 0UL;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;	
}
/*#define System_SetSysTick_1ms(HCLK_HZ) \
  SysTick->LOAD = (uint32_t)((HCLK_HZ / 1000U) - 1UL);\
  SysTick->VAL = 0UL;\
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;*/

#ifdef __cplusplus
}
#endif

#endif	// _STM32F1xx_BM_SYSTEM_INCLUDED
