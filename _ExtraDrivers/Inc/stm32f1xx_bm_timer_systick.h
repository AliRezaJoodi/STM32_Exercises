// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

#include <stm32f1xx.h>
///#include <core_cm3.h>
#include <utility.h>
#include <stm32f1xx_bm_gpio.h>

#ifdef HARDWARE_LOCAL
	#include "_hardware.h"
#endif

#ifndef _STM32F1XX_BM_TIMER_SYSTICK_INCLUDED
#define _STM32F1XX_BM_TIMER_SYSTICK_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef STM32F1XX_BM_TIMER_SYSTICK_HARDWARE
#define STM32F1XX_BM_TIMER_SYSTICK_HARDWARE
	#define HCLK_VALUE		8000000
#endif

#define SYSTICK_CLKSOURCE_HCLK_DIV8		0b0UL		// HCLK Frequency/8
#define SYSTICK_CLKSOURCE_HCLK				0b1UL		// HCLK Frequency

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