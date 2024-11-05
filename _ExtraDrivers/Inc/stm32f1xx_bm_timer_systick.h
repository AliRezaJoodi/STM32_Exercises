// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

#ifndef _STM32F1XX_BM_TIMER_SYSTICK_INCLUDED
#define _STM32F1XX_BM_TIMER_SYSTICK_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include <utility.h>

#ifndef SYSTICK_HCLK_VALUE
	#define SYSTICK_HCLK_VALUE		8000000
#endif


//**************************************************
__STATIC_INLINE void SysTick_SetClockSource(uint32_t MODE){
	WriteBit(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Pos, MODE);
}

//**************************************************
__STATIC_INLINE void SysTick_SetLoadValue(uint32_t value){
	SysTick->LOAD = value;
}

//**************************************************
__STATIC_INLINE void SysTick_ResetCounter(void){
	SysTick->VAL = 0UL;
}

#define SYSTICK_DISABLE		0b0UL
#define SYSTICK_ENABLE		0b1UL

//**************************************************
__STATIC_INLINE void SysTick_EnableOrDisable(uint32_t STATUS){
	WriteBit(SysTick->CTRL, SysTick_CTRL_ENABLE_Pos, STATUS);
}

#define SYSTICK_INT_DISABLE		0b0UL
#define SYSTICK_INT_ENABLE		0b1UL

//**************************************************
__STATIC_INLINE void SysTick_INT_EnableOrDisable(uint32_t STATUS){
	WriteBit(SysTick->CTRL, SysTick_CTRL_TICKINT_Pos, STATUS);
}

//**************************************************
void SysTick_Delay_1us(uint32_t us);
void SysTick_Delay_1ms(uint32_t ms);	
void SysTick_ConfigDefault1_1ms(void);
void SysTick_ConfigDefault2_INT(void);

#ifdef __cplusplus
}
#endif

#endif		// _STM32F1XX_BM_TIMER_SYSTICK_INCLUDED