// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
	Abbreviations:
	RCC_CR:	Clock control register
	HSE: 		High-Speed External Clock Signal
	HSI: 		High-Speed Internal Clock Signal
	LSI: 		Low-Speed Internal Clock Signal
	LSE: 		Low-Speed External Clock Signal
	EXTCLK:	External Clock Source
*/

#ifndef _STM32F1xx_BM_RCC_INCLUDED
#define _STM32F1xx_BM_RCC_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>

#include <utility.h>
#include <timeout.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_pwr.h>

__STATIC_INLINE void RCC_HSI_SetCalibTrimming(uint32_t value){
	RCC->CR= (RCC->CR & ~RCC_CR_HSITRIM) | (value<<RCC_CR_HSITRIM_Pos);
}

/*	
HSIRDY:	Internal high-speed clock ready flag
				Set by hardware to indicate that internal 8 MHz RC oscillator is stable.
				After the HSION bit is cleared, HSIRDY goes low after 6 internal 8 MHz RC oscillator clock cycles.
				0: internal 8 MHz RC oscillator not ready
				1: internal 8 MHz RC oscillator ready 
*/
__STATIC_INLINE uint32_t _HSI_GetReadyFlag(void){
	return ( GetBit(RCC->CR, RCC_CR_HSIRDY_Pos) );	
}

//******************************************************************
__STATIC_INLINE uint32_t RCC_HSI_EnableOrDisable(uint32_t status){
	WriteBit(RCC->CR, RCC_CR_HSION_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_HSI_GetReadyFlag, status) );
	#else
		return 0;
	#endif
}

__STATIC_INLINE uint32_t _HSE_GetReadyFlag(void){
		return ( GetBit(RCC->CR, RCC_CR_HSERDY_Pos) );
}

__STATIC_INLINE uint32_t _HSE_GetEnableStatus(void){
		return ( GetBit(RCC->CR, RCC_CR_HSEON_Pos) );
}

__STATIC_INLINE uint32_t RCC_HSE_EnableOrDisable(uint32_t status){
	WriteBit(RCC->CR, RCC_CR_HSEON_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_HSE_GetReadyFlag, status) );
	#else
		return 0;
	#endif
}

/* 	
HSEBYP: External high-speed clock bypass
				The HSEBYP bit can be written only if the HSE oscillator is disabled.
				0: external 3-25 MHz oscillator not bypassed
				1: external 3-25 MHz oscillator bypassed with external clock
*/

__STATIC_INLINE uint32_t RCC_HSE_GetClockSource(void){
  return ( GetBit(RCC->CR, RCC_CR_HSEBYP_Pos) );
}

#define HSE_CLKSOURCE_XTAL      0b0
#define HSE_CLKSOURCE_EXTCLK		0b1

__STATIC_INLINE void RCC_HSE_SetClockSource(uint32_t mode){
	WriteBit(RCC->CR, RCC_CR_HSEBYP_Pos, mode);
	while(RCC_HSE_GetClockSource() != mode){};	
}

/*
PLLRDY: PLL clock ready flag
				Set by hardware to indicate that the PLL is locked.
				0: PLL unlocked
				1: PLL locked
*/
__STATIC_INLINE uint32_t _PLL_GetReadyFlag(void){
  return ( GetBit(RCC->CR, RCC_CR_PLLRDY_Pos) );
}

/*
PLLON: 	PLL enable
				Set and cleared by software to enable PLL.
				Cleared by hardware when entering Stop or Standby mode. 
				This bit can not be reset if the PLL clock is used as system clock or is selected to become the system clock.
				0: PLL OFF
				1: PLL ON
*/
__STATIC_INLINE uint32_t _PLL_GetEnableStatus(void){
  return ( GetBit(RCC->CR, RCC_CR_PLLON_Pos) );
}

__STATIC_INLINE uint32_t RCC_PLL_EnableOrDisable(uint32_t status){
	WriteBit(RCC->CR, RCC_CR_PLLON_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_PLL_GetReadyFlag, status) );
	#else
		return 0;
	#endif	
}

/* 	
PLLSRC:		PLL entry clock source
					This bit can be written only when PLL is disabled.
					0: HSI oscillator clock /2 selected as PLL input clock
					1: HSE oscillator clock selected as PLL input clock 
PLLXTPRE: HSE divider for PLL entry
					This bit can be written only when PLL is disabled.
					0: HSE clock not divided
					1: HSE clock divided by 2
*/

#define PLL_CLKSOURCE_HSI_DIV2	0b00
#define PLL_CLKSOURCE_HSE_DIV1  0b01
#define PLL_CLKSOURCE_HSE_DIV2	0b10

__STATIC_INLINE void RCC_PLL_SetClockSource(uint32_t mode){
	char e_status= _PLL_GetEnableStatus();

	switch(mode){
		case PLL_CLKSOURCE_HSI_DIV2:
			ClearBit(RCC->CFGR, RCC_CFGR_PLLSRC_Pos);
			break;
		case PLL_CLKSOURCE_HSE_DIV1:
			SetBit(RCC->CFGR, RCC_CFGR_PLLSRC_Pos);
			ClearBit(RCC->CFGR, RCC_CFGR_PLLXTPRE_Pos);
			break;
		case PLL_CLKSOURCE_HSE_DIV2:
			SetBit(RCC->CFGR, RCC_CFGR_PLLSRC_Pos);
			SetBit(RCC->CFGR, RCC_CFGR_PLLXTPRE_Pos);
			break;
		default:
			break;
	}
}

/*	
PLLMUL:	PLL multiplication factor
				These bits can be written only when PLL is disabled.
				Caution: The PLL output frequency must not exceed 72 MHz.
*/

#define PLL_MUL_2			0b0000
#define PLL_MUL_3			0b0001
#define PLL_MUL_4			0b0010
#define PLL_MUL_5			0b0011
#define PLL_MUL_6			0b0100
#define PLL_MUL_7			0b0101
#define PLL_MUL_8			0b0110
#define PLL_MUL_9			0b0111
#define PLL_MUL_10		0b1000
#define PLL_MUL_11		0b1001
#define PLL_MUL_12		0b1010
#define PLL_MUL_13		0b1011
#define PLL_MUL_14		0b1100
#define PLL_MUL_15		0b1101
#define PLL_MUL_16		0b1110
#define PLL_MUL_16_		0b1111

__STATIC_INLINE void RCC_PLL_SetMultiplicationFactor(uint32_t mode){
	Write4Bit(RCC->CFGR, RCC_CFGR_PLLMULL_Pos, mode);
	while( Get4Bit(RCC->CFGR,RCC_CFGR_PLLMULL_Pos) != mode ){};
}

/*
SW:		System clock switch
			Set and cleared by hardware to indicate which clock source is used as system clock.
			00: HSI oscillator used as system clock
			01: HSE oscillator used as system clock
			10: PLL used as system clock
			11: not applicable
*/

#define SYSTEM_CLKSOURCE_HSI			0b00
#define SYSTEM_CLKSOURCE_HSE    	0b01
#define SYSTEM_CLKSOURCE_PLL    	0b10
#define SYSTEM_CLKSOURCE_NONE			0b11

__STATIC_INLINE uint32_t _SYSCLK_GetClockSource(void){
		return ( Get2Bit(RCC->CFGR, RCC_CFGR_SWS_Pos) );
}

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
__STATIC_INLINE void RCC_AHB_SetPrescaler(uint32_t value){
		Write4Bit(RCC->CFGR, RCC_CFGR_HPRE_Pos, value);
}

/*
PPRE1[2:0]: APB Low-speed prescaler (APB1)
						Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
						0xx: HCLK not divided
						100: HCLK divided by 2
						101: HCLK divided by 4
						110: HCLK divided by 8
						111: HCLK divided by 16
						Note: Software must configure these bits ensure that the frequency in this domain does not exceed 36 MHz.
*/

#define APB1_DIV1		0b000
#define APB1_DIV2		0b100
#define APB1_DIV4		0b101
#define APB1_DIV8		0b110
#define APB1_DIV16	0b111

__STATIC_INLINE uint32_t _APB1_GetPrescaler(void){
		return( Get3Bit(RCC->CFGR, RCC_CFGR_PPRE1_Pos) );
}

__STATIC_INLINE void RCC_APB1_SetPrescaler(uint32_t mode){
		Write3Bit(RCC->CFGR, RCC_CFGR_PPRE1_Pos, mode);
}

/*
PPRE2[2:0]: APB high-speed prescaler (APB2)
						Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
						0xx: HCLK not divided
						100: HCLK divided by 2
						101: HCLK divided by 4
						110: HCLK divided by 8
						111: HCLK divided by 16
						Note: Software must configure these bits ensure that the frequency in this domain does not exceed 72 MHz.
*/

#define APB2_DIV1		0b000
#define APB2_DIV2		0b100
#define APB2_DIV4		0b101
#define APB2_DIV8		0b110
#define APB2_DIV16	0b111

__STATIC_INLINE uint32_t _APB2_GetPrescaler(void){
		return( Get3Bit(RCC->CFGR, RCC_CFGR_PPRE2_Pos) );
}

__STATIC_INLINE void RCC_APB2_SetPrescaler(uint32_t mode){
	Write3Bit(RCC->CFGR, RCC_CFGR_PPRE2_Pos, mode);
}

/*	
BDRST: 	Backup domain software reset
				1 Bit, Read/Write by software
				Note: The RTC_PRL, RTC_ALR, RTC_CNT, and RTC_DIV registers are reset only by a Backup Domain reset.
				0: Reset not activated.
				1: Resets the entire Backup domain. 
*/

__STATIC_INLINE uint32_t _BackupDomain_GetResetStatus(void){
		return ( GetBit(RCC->BDCR, RCC_BDCR_BDRST_Pos) );
}

__STATIC_INLINE uint32_t RCC_BackupDomain_ResetOrRelease(uint32_t status){
	WriteBit(RCC->BDCR, RCC_BDCR_BDRST_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_BackupDomain_GetResetStatus, status) );
	#else
		return 0;
	#endif
}

/*
LSERDY: External low-speed oscillator ready
				1 Bit, Read by software, Write by hardware
				Set and cleared by hardware to indicate when the external 32 kHz oscillator is stable. After
				the LSEON bit is cleared, LSERDY goes low after 6 external low-speed oscillator clock cycles.
				0: External 32 kHz oscillator not ready
				1: External 32 kHz oscillator ready
*/

__STATIC_INLINE uint32_t _LSE_GetReadyFlag(void){
		return ( GetBit(RCC->BDCR, RCC_BDCR_LSERDY_Pos) );
}

/*
LSEON: 	External low-speed oscillator enable
				1 Bit, Read/Write by software
				0: External 32 kHz oscillator OFF
				1: External 32 kHz oscillator ON
*/

__STATIC_INLINE uint32_t _LSE_GetEnableStatus(void){
		return ( GetBit(RCC->BDCR, RCC_BDCR_LSEON_Pos) );
}

__STATIC_INLINE uint32_t RCC_LSE_EnableOrDisable(uint32_t status){
	WriteBit(RCC->BDCR, RCC_BDCR_LSEON_Pos, status);	
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_LSE_GetReadyFlag, status) );
	#else
		return 0;
	#endif	
}
	
/*	
LSEBYP: External low-speed oscillator bypass
				1 Bit, Read/Write by software
				Set and cleared by software to bypass oscillator in debug mode.
				This bit can be written only when the external 32 kHz oscillator is disabled.
				0: LSE oscillator not bypassed
				1: LSE oscillator bypassed 
*/

#define LSE_CLKSOURCE_XTAL			0b0
#define LSE_CLKSOURCE_EXTCLK		0b1

__STATIC_INLINE uint32_t _LSE_GetClockSource(void){
		return ( GetBit(RCC->BDCR, RCC_BDCR_LSEBYP_Pos) );
}

__STATIC_INLINE uint32_t RCC_LSE_SetClockSource(uint32_t mode){
	WriteBit(RCC->BDCR, RCC_BDCR_LSEBYP_Pos, mode);

	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_LSE_GetClockSource, mode) );
	#else
		return 0;
	#endif
}

/*
LSIRDY: Internal low-speed oscillator ready
				1 Bit, Read by software, Write by hardware
				Set and cleared by hardware to indicate when the internal RC 40 kHz oscillator is stable.
				After the LSION bit is cleared, LSIRDY goes low after 3 internal RC 40kHz oscillator clock cycles.
				0: Internal RC 40 kHz oscillator not ready
				1: Internal RC 40 kHz oscillator ready
*/

__STATIC_INLINE uint32_t _LSI_GetReadyFlag(void){
		return ( GetBit(RCC->CSR, RCC_CSR_LSIRDY_Pos) );
}

/*
LSION: 	Internal low-speed oscillator enable
				1 Bit, Read/Write by software
				0: Internal RC 40 kHz oscillator OFF
				1: Internal RC 40 kHz oscillator ON
*/

__STATIC_INLINE uint32_t _LSI_GetEnableStatus(void){
		return ( GetBit(RCC->CSR, RCC_CSR_LSION_Pos) );
}

__STATIC_INLINE uint32_t RCC_LSI_EnableOrDisable(uint32_t status){
	WriteBit(RCC->CSR, RCC_CSR_LSION_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_LSI_GetReadyFlag, status) );
	#else
		return 0;
	#endif	
}

/*	
RTCSEL[1:0]: 	RTC clock source selection
							Set by software to select the clock source for the RTC.
							Once the RTC clock source has been selected, it cannot be changed anymore unless the Backup domain is reset. 
							The BDRST bit can be used to reset them. 
							00: No clock
							01: LSE oscillator clock used as RTC clock
							10: LSI oscillator clock used as RTC clock
							11: HSE oscillator clock divided by 128 used as RTC clock
*/

#define RTC_CLKSOURCE_NONE					0b00
#define RTC_CLKSOURCE_LSE    				0b01
#define RTC_CLKSOURCE_LSI    				0b10
#define RTC_CLKSOURCE_HSE_DIV128		0b11

__STATIC_INLINE uint32_t _RTC_GetClockSource(void){
		return ( Get2Bit(RCC->BDCR, RCC_BDCR_RTCSEL_Pos) );
}

__STATIC_INLINE uint32_t RCC_RTC_SetClockSource(uint32_t mode){
	Write2Bit(RCC->BDCR, RCC_BDCR_RTCSEL_Pos, mode);

	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_RTC_GetClockSource, mode) );
	#else
		return 0;
	#endif		
}

/*	
RTCEN: 	RTC clock enable
				1 Bit, Read/Write by software
				0: RTC clock disabled
				1: RTC clock enabled 
*/

__STATIC_INLINE uint32_t _RTC_GeEnableStatus(void){
	return ( GetBit(RCC->BDCR, RCC_BDCR_RTCEN_Pos) );
}

__STATIC_INLINE uint32_t RCC_RTC_EnableOrDisable(uint32_t status){
	WriteBit(RCC->BDCR, RCC_BDCR_RTCEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_RTC_GeEnableStatus, status) );
	#else
		return 0;
	#endif
}

//******************************************************************
void RCC_SystemClock_ConfigDefault1(void);
void RCC_SystemClock_ConfigDefault2(void);
void RCC_RTC_ConfigDefault1(void);

#ifdef __cplusplus
}
#endif
		
#endif	// _STM32F1xx_BM_RCC_INCLUDED
