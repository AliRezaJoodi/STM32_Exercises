// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
	Abbreviations:
	HSE: 		High-Speed External Clock Signal
	HSI: 		High-Speed Internal Clock Signal
	LSI: 		Low-Speed Internal Clock Signal
	LSE: 		Low-Speed External Clock Signal
	EXTCLK:	External Clock Source
*/

#include <stm32f1xx.h>

#include <utility.h>
#include <stm32f1xx_bm_system.h>

#ifndef _STM32F1xx_BM_RCC_INCLUDED
#define _STM32F1xx_BM_RCC_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//******************************************************************
__STATIC_INLINE void RCC_HSI_SetCalibTrimming(uint32_t value){
	RCC->CR= (RCC->CR & ~RCC_CR_HSITRIM) | (value<<RCC_CR_HSITRIM_Pos);
}

__STATIC_INLINE uint32_t _HSI_GetReadyFlag(void){
	return ( GetBit(RCC->CR, RCC_CR_HSIRDY_Pos) );	
}

//******************************************************************
__STATIC_INLINE void RCC_HSI_EnableOrDisable(uint32_t status){
	WriteBit(RCC->CR, RCC_CR_HSION_Pos, status);
	if(status){
		while(!_HSI_GetReadyFlag()){};
	}	
}

__STATIC_INLINE uint32_t _HSE_GetReadyFlag(void){
		return ( GetBit(RCC->CR, RCC_CR_HSERDY_Pos) );
}

__STATIC_INLINE uint32_t _HSE_GetEnableStatus(void){
		return ( GetBit(RCC->CR, RCC_CR_HSEON_Pos) );
}

__STATIC_INLINE void _HSE_EnableOrDisable(uint32_t status){
	WriteBit(RCC->CR, RCC_CR_HSEON_Pos, status);
	
	if(status){
		while(_HSE_GetReadyFlag() != 1){};
	}
	else{
		while(_HSE_GetEnableStatus() != 0){};
	}
}

// The HSEBYP bit can be written only if the HSE oscillator is disabled.
__STATIC_INLINE void _HSE_EnableOrDisableBypass(uint32_t status){
	WriteBit(RCC->CR, RCC_CR_HSEBYP_Pos, status);
}

#define HSE_CLKSOURCE_XTAL      0b00
#define HSE_CLKSOURCE_EXTCLK		0b01
#define HSE_CLKSOURCE_NONE      0b10
//******************************************************************
__STATIC_INLINE void RCC_HSE_SetClockSource(uint32_t mode){
	_HSE_EnableOrDisable(0);
	
	if(mode == HSE_CLKSOURCE_XTAL){
		_HSE_EnableOrDisableBypass(0);
		_HSE_EnableOrDisable(1);
	}
	else if(mode == HSE_CLKSOURCE_EXTCLK){
		_HSE_EnableOrDisableBypass(1);
		_HSE_EnableOrDisable(1);
	}
}

__STATIC_INLINE uint32_t _PLL_GetReadyFlag(void){
  return ( GetBit(RCC->CR, RCC_CR_PLLRDY_Pos) );
}

__STATIC_INLINE uint32_t _PLL_GetEnableStatus(void){
  return ( GetBit(RCC->CR, RCC_CR_PLLON_Pos) );
}

// PLLON: PLL enable
// This bit can not be reset if the PLL clock is used as system clock or is selected to become the system clock.
//******************************************************************
__STATIC_INLINE void RCC_PLL_EnableOrDisable(uint32_t status){
	WriteBit(RCC->CR, RCC_CR_PLLON_Pos, status);
	if(status){
		while(_PLL_GetReadyFlag() != 1){};
	}
	else{
		while(_PLL_GetEnableStatus() != 0){};
	};	
}

__STATIC_INLINE uint32_t _SYSCLK_GetClockSource(void){
		return ( Get2Bit(RCC->CFGR, RCC_CFGR_SWS_Pos) );
}

#define SYSTEM_CLKSOURCE_HSI			0b00
#define SYSTEM_CLKSOURCE_HSE    	0b01
#define SYSTEM_CLKSOURCE_PLL    	0b10
#define SYSTEM_CLKSOURCE_NONE			0b11
//******************************************************************
__STATIC_INLINE void RCC_SYSCLK_SetClockSource(uint32_t mode){
	Write2Bit(RCC->CFGR, RCC_CFGR_SW_Pos, mode);
	while(_SYSCLK_GetClockSource() != mode){};	
}

#define AHB_DIV1   		0b0000
#define AHB_DIV2     	0b1000
#define AHB_DIV4     	0b1001
#define AHB_DIV8     	0b1010
#define AHB_DIV16    	0b1011
#define AHB_DIV64    	0b1100
#define AHB_DIV128		0b1101
#define AHB_DIV256   	0b1110
#define AHB_DIV512		0b1111	
// The AHB clock frequency must be at least 25 MHz when the Ethernet is used.
//******************************************************************
__STATIC_INLINE void RCC_AHB_SetPrescaler(uint32_t value){
		Write4Bit(RCC->CFGR, RCC_CFGR_HPRE_Pos, value);
}
		
#define APB1_DIV1		0b000
#define APB1_DIV2		0b100
#define APB1_DIV4		0b101
#define APB1_DIV8		0b110
#define APB1_DIV16	0b111
// Software must configure these bits ensure that the frequency in this domain does not exceed 36 MHz.
//******************************************************************
__STATIC_INLINE void RCC_APB1_SetPrescaler(uint32_t mode){
		Write3Bit(RCC->CFGR, RCC_CFGR_PPRE1_Pos, mode);
}

#define APB2_DIV1		0b000
#define APB2_DIV2		0b100
#define APB2_DIV4		0b101
#define APB2_DIV8		0b110
#define APB2_DIV16	0b111
// Software must configure these bits ensure that the frequency in this domain does not exceed 72 MHz.
//******************************************************************
__STATIC_INLINE void RCC_APB2_SetPrescaler(uint32_t mode){
	Write3Bit(RCC->CFGR, RCC_CFGR_PPRE2_Pos, mode);
}

__STATIC_INLINE uint32_t _BackupDomain_GetResetStatus(void){
		return ( GetBit(RCC->BDCR, RCC_BDCR_BDRST_Pos) );
}

//******************************************************************
__STATIC_INLINE void RCC_BackupDomain_Reset(void){
	SetBit(RCC->BDCR, RCC_BDCR_BDRST_Pos);
	while(_BackupDomain_GetResetStatus() != 1){};
	ClearBit(RCC->BDCR, RCC_BDCR_BDRST_Pos);
	while(_BackupDomain_GetResetStatus() != 0){};
}

__STATIC_INLINE uint32_t _LSE_GetReadyFlag(void){
		return ( GetBit(RCC->BDCR, RCC_BDCR_LSERDY_Pos) );
}

__STATIC_INLINE uint32_t _LSE_GetEnableStatus(void){
		return ( GetBit(RCC->BDCR, RCC_BDCR_LSEON_Pos) );
}

__STATIC_INLINE void _LSE_EnableOrDisable(uint32_t status){
	WriteBit(RCC->BDCR, RCC_BDCR_LSEON_Pos, status);	
	if(status){
		while(_LSE_GetReadyFlag() != 1){};
	}
	else{
		while(_LSE_GetEnableStatus() != 0){};
	};	
}

// LSEBYP: External low-speed oscillator bypass
// This bit can be written only when the external 32 kHz oscillator is disabled.
__STATIC_INLINE void _LSE_EnableOrDisableBypass(uint32_t status){
	WriteBit(RCC->BDCR, RCC_BDCR_LSEBYP_Pos, status);
}

#define LSE_CLKSOURCE_XTAL			0b00
#define LSE_CLKSOURCE_EXTCLK		0b01
#define LSE_CLKSOURCE_NONE      0b10
//******************************************************************
__STATIC_INLINE void RCC_LSE_SetClockSource(uint32_t mode){
	_LSE_EnableOrDisable(0);
	
	if(mode == LSE_CLKSOURCE_XTAL){
		_LSE_EnableOrDisableBypass(0);
		_LSE_EnableOrDisable(1);
	}
	else if(mode == LSE_CLKSOURCE_EXTCLK){
		_LSE_EnableOrDisableBypass(1);
		_LSE_EnableOrDisable(1);
	}
}


__STATIC_INLINE uint32_t _LSI_GetReadyFlag(void){
		return ( GetBit(RCC->CSR, RCC_CSR_LSIRDY_Pos) );
}

__STATIC_INLINE uint32_t _LSI_GetEnableStatus(void){
		return ( GetBit(RCC->CSR, RCC_CSR_LSION_Pos) );
}

//******************************************************************
__STATIC_INLINE void RCC_LSI_EnableOrDisable(uint32_t status){
	WriteBit(RCC->CSR, RCC_CSR_LSION_Pos, status);
	if(status){
		while(_LSI_GetReadyFlag() != 1){};
	}
	else{
		while(_LSI_GetEnableStatus()  != 0){};
	}
}

__STATIC_INLINE uint32_t _RTC_GetClockSource(void){
		return ( Get2Bit(RCC->BDCR, RCC_BDCR_RTCSEL_Pos) );
}

#define RTC_CLKSOURCE_NONE					0b00
#define RTC_CLKSOURCE_LSE    				0b01
#define RTC_CLKSOURCE_LSI    				0b10
#define RTC_CLKSOURCE_HSE_DIV128		0b11
//******************************************************************
__STATIC_INLINE void RCC_RTC_SetClockSource(uint32_t mode){
	Write2Bit(RCC->BDCR, RCC_BDCR_RTCSEL_Pos, mode);
	while(_RTC_GetClockSource() != mode){};	
}

__STATIC_INLINE uint32_t _RTC_GeEnableStatus(void){
	return ( GetBit(RCC->BDCR, RCC_BDCR_RTCEN_Pos) );
}

//******************************************************************
__STATIC_INLINE void RCC_RTC_EnableOrDisable(uint32_t status){
	WriteBit(RCC->BDCR, RCC_BDCR_RTCEN_Pos, status);
	while(_RTC_GeEnableStatus() != status){};
}

//******************************************************************
void RCC_SystemClock_ConfigDefault1(void);
void RCC_RTCClock_ConfigDefault1(void);

#ifdef __cplusplus
}
#endif
		
#endif	// _STM32F1xx_BM_RCC_INCLUDED
