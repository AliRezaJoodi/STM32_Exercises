// GitHub Account: GitHub.com/AliRezaJoodi

/*
	Abbreviations:
	HSE: High-Speed External Clock Signal
	HSI: High-Speed Internal Clock Signal
	LSI: Low-Speed Internal Clock Signal
	LSE: Low-Speed External Clock Signal
*/

#include "stm32f1xx.h"
#include "Utility.h"

#ifndef _RCC_INCLUDED
    #define _RCC_INCLUDED

#ifdef __cplusplus
	extern "C" {
#endif


#define RCC_HSI_SetCalibTrimming(VALUE) \
	RCC->CR= (RCC->CR & ~RCC_CR_HSITRIM) | (VALUE<<RCC_CR_HSITRIM_Pos);
#define _HSI_GetClockReadyFlag \
	GetBit(RCC->CR, RCC_CR_HSIRDY_Pos)
#define RCC_HSI_EnableOrDisable(STATUS) \
	WriteBit(RCC->CR, RCC_CR_HSION_Pos, STATUS);\
	if(STATUS){while(!_HSI_GetClockReadyFlag){};}

// The HSEBYP bit can be written only if the HSE oscillator is disabled.
#define XTAL          	0b0
#define EXTERNAL_CLOCK	0b1
#define _HSE_GetClockSource \
	GetBit(RCC->CR, RCC_CR_HSEBYP_Pos)
#define RCC_HSE_SetClockSource(MODE) \
	WriteBit(RCC->CR, RCC_CR_HSEBYP_Pos, MODE);\
	while(_HSE_GetClockSource != MODE){};
#define _HSE_GetClockReadyFlag \
	GetBit(RCC->CR, RCC_CR_HSERDY_Pos)
#define RCC_HSE_EnableOrDisable(STATUS) \
	WriteBit(RCC->CR, RCC_CR_HSEON_Pos, STATUS);\
	if(STATUS){while(!_HSE_GetClockReadyFlag){};};

#define SYSCLK_HSI		0b00
#define SYSCLK_HSE    0b01
#define SYSCLK_PLL    0b10
#define NOT_ALLOWED		0b11
#define _SYSCLK_GetClockSource \
	Get2Bit(RCC->CFGR, RCC_CFGR_SWS_Pos)
#define RCC_SYSCLK_SetClockSource(MODE) \
	Write2Bit(RCC->CFGR, RCC_CFGR_SW_Pos, MODE);\
	while(_SYSCLK_GetClockSource != MODE){};

// The AHB clock frequency must be at least 25 MHz when the Ethernet is used.
#define AHB_DIV1   		0b0000
#define AHB_DIV2     	0b1000
#define AHB_DIV4     	0b1001
#define AHB_DIV8     	0b1010
#define AHB_DIV16    	0b1011
#define AHB_DIV64    	0b1100
#define AHB_DIV128		0b1101
#define AHB_DIV256   	0b1110
#define AHB_DIV512		0b1111		
#define RCC_AHB_SetPrescaler(VALUE) \
	Write4Bit(RCC->CFGR, RCC_CFGR_HPRE_Pos, VALUE);
		
// Software must configure these bits ensure that the frequency in this domain does not exceed 36 MHz.
#define APB1_DIV1		0b000
#define APB1_DIV2		0b100
#define APB1_DIV4		0b101
#define APB1_DIV8		0b110
#define APB1_DIV16	0b111
#define RCC_APB1_SetPrescaler(MODE) \
	Write3Bit(RCC->CFGR, RCC_CFGR_PPRE1_Pos, MODE);

// Software must configure these bits ensure that the frequency in this domain does not exceed 72 MHz.
#define APB2_DIV1		0b000
#define APB2_DIV2		0b100
#define APB2_DIV4		0b101
#define APB2_DIV8		0b110
#define APB2_DIV16	0b111
#define RCC_APB2_SetPrescaler(MODE) \
	Write3Bit(RCC->CFGR, RCC_CFGR_PPRE2_Pos, MODE);

// _SystemClock.h
void SystemClock_Configuration(void);

#ifdef __cplusplus
	}
#endif
		
#endif
