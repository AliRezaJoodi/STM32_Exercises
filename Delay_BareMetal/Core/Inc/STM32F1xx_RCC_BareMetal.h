// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx.h"

#ifndef _RCC_INCLUDED
    #define _RCC_INCLUDED

#define SetCalibTrimmingFromHSI(VALUE) \
	RCC->CR= (RCC->CR & ~RCC_CR_HSITRIM) | (VALUE<<RCC_CR_HSITRIM_Pos);
#define EnableOrDisableClockFromHSI(STATUS) \
	RCC->CR= (RCC->CR & ~RCC_CR_HSION) | ((STATUS&0b1UL)<<RCC_CR_HSION_Pos);
#define IsClockStableFromHSI \
		((RCC->CR & RCC_CR_HSIRDY) >> RCC_CR_HSIRDY_Pos)
#define WaitTillStableClockSourceFromHSI \
	while(!IsClockStableFromHSI){}

// The HSEBYP bit can be written only if the HSE oscillator is disabled.
#define XTAL          	0b0UL
#define EXTERNAL_CLOCK	0b1UL
#define ConfigureSourceForHSE(MODE) \
	RCC->CR= (RCC->CR & ~RCC_CR_HSEBYP) | ((MODE&0b1UL)<<RCC_CR_HSEBYP_Pos);
	//WriteBit(RCC->CR,RCC_CR_HSEBYP_Pos,MODE);
#define EnableOrDisableClockFromHSE(STATUS) \
	RCC->CR= (RCC->CR & ~RCC_CR_HSEON) | ((STATUS&0b1UL)<<RCC_CR_HSEON_Pos);
#define IsClockStableFromHSE \
		((RCC->CR & RCC_CR_HSERDY) >> RCC_CR_HSERDY_Pos)
#define WaitTillStableClockSourceFromHSE \
	while(!IsClockStableFromHSE){}

// The AHB clock frequency must be at least 25 MHz when the Ethernet is used.
#define AHB_DIV1   		RCC_CFGR_HPRE_DIV1
#define AHB_DIV2     	RCC_CFGR_HPRE_DIV2
#define AHB_DIV4     	RCC_CFGR_HPRE_DIV4
#define AHB_DIV8     	RCC_CFGR_HPRE_DIV8
#define AHB_DIV16    	RCC_CFGR_HPRE_DIV16
#define AHB_DIV64    	RCC_CFGR_HPRE_DIV64
#define AHB_DIV128		RCC_CFGR_HPRE_DIV128
#define AHB_DIV256   	RCC_CFGR_HPRE_DIV256
#define AHB_DIV512		RCC_CFGR_HPRE_DIV512		
#define ConfigurePrescalerForAHB(MODE) \
			RCC->CFGR= (RCC->CFGR & ~RCC_CFGR_HPRE) | MODE;
		
// Software must configure these bits ensure that the frequency in this domain does not exceed 36 MHz.
#define APB1_DIV1			RCC_CFGR_PPRE1_DIV1
#define APB1_DIV2			RCC_CFGR_PPRE1_DIV2
#define APB1_DIV4			RCC_CFGR_PPRE1_DIV4
#define APB1_DIV8			RCC_CFGR_PPRE1_DIV8
#define APB1_DIV16		RCC_CFGR_PPRE1_DIV16
#define ConfigurePrescalerForAPB1(MODE) \
			RCC->CFGR= (RCC->CFGR & ~RCC_CFGR_PPRE1) | MODE;

// Software must configure these bits ensure that the frequency in this domain does not exceed 72 MHz.
#define APB2_DIV1			RCC_CFGR_PPRE2_DIV1
#define APB2_DIV2			RCC_CFGR_PPRE2_DIV2
#define APB2_DIV4			RCC_CFGR_PPRE2_DIV4
#define APB2_DIV8			RCC_CFGR_PPRE2_DIV8
#define APB2_DIV16		RCC_CFGR_PPRE2_DIV16
#define ConfigurePrescalerForAPB2(MODE) \
	RCC->CFGR= (RCC->CFGR & ~RCC_CFGR_PPRE2) | MODE;

#define SYSCLK_HSI		0b00U
#define SYSCLK_HSE    0b01U
#define SYSCLK_PLL    0b10U
#define NOT_ALLOWED		0b11U
#define ConfigureSystemClockSource(MODE) \
	RCC->CFGR= (RCC->CFGR & ~RCC_CFGR_SW) | ((MODE&0b11U) >> RCC_CFGR_SW_Pos);
#define GetSystemClockSource \
	((RCC->CFGR & RCC_CFGR_SWS) >> RCC_CFGR_SWS_Pos)
#define WaitTillRightClockSource(MODE) \
	while(GetSystemClockSource != MODE){}
		
#endif
