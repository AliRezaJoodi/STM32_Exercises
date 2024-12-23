// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
It's about:
	RCC_CFGR: Clock configuration register
*/

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

/*
RCC_CR, Bits 7:3
HSITRIM[4:0]:	Internal high-speed clock trimming
							Set and cleared by software
							The default value is 16.
*/

__STATIC_INLINE uint8_t _HSI_GetTrimming(void){
	return ( Get5Bit(RCC->CR, RCC_CR_HSITRIM_Pos) );	
}

__STATIC_INLINE void RCC_HSI_SetTrimming(uint8_t value){
	//RCC->CR= (RCC->CR & ~RCC_CR_HSITRIM) | (value<<RCC_CR_HSITRIM_Pos);
	Write5Bit(RCC->CR, RCC_CR_HSITRIM_Pos, value);
}


/*	
RCC_CR, Bit 1
HSIRDY:	Internal high-speed clock ready flag
				Set by hardware to indicate that internal 8 MHz RC oscillator is stable.
				After the HSION bit is cleared, HSIRDY goes low after 6 internal 8 MHz RC oscillator clock cycles.
				0: internal 8 MHz RC oscillator not ready
				1: internal 8 MHz RC oscillator ready 

RCC_CR, Bit 0
HSION:	Internal high-speed clock enable
				Set and cleared by software.
				Set by hardware to force the internal 8 MHz RC oscillator ON when leaving Stop or Standby
				mode or in case of failure of the external 3-25 MHz oscillator used directly or indirectly as system clock. 
				This bit can not be cleared if the internal 8 MHz RC is used directly or
				indirectly as system clock or is selected to become the system clock.
				0: Internal 8 MHz RC oscillator OFF
				1: Internal 8 MHz RC oscillator ON
*/

__STATIC_INLINE uint8_t _HSI_GetReadyFlag(void){
	return ( GetBit(RCC->CR, RCC_CR_HSIRDY_Pos) );	
}

__STATIC_INLINE uint8_t _HSI_GetEnableStatus(void){
		return ( GetBit(RCC->CR, RCC_CR_HSION_Pos) );
}

__STATIC_INLINE uint8_t RCC_HSI_EnableOrDisable(uint8_t status){
	WriteBit(RCC->CR, RCC_CR_HSION_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_HSI_GetReadyFlag, status) );
	#else
		return 0;
	#endif
}


/*
RCC_CR, Bit 17
HSERDY: External high-speed clock ready flag
				Set by hardware to indicate that the HSE oscillator is stable. 
				This bit needs 6 cycles of the HSE oscillator clock to fall down after HSEON reset.
				0: HSE oscillator not ready
				1: HSE oscillator ready

RCC_CR, Bit 16
HSEON: 	HSE clock enable
				Set and cleared by software.
				Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode.
				This bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock.
				0: HSE oscillator OFF
				1: HSE oscillator ON
*/

__STATIC_INLINE uint8_t _HSE_GetReadyFlag(void){
		return ( GetBit(RCC->CR, RCC_CR_HSERDY_Pos) );
}

__STATIC_INLINE uint8_t _HSE_GetEnableStatus(void){
		return ( GetBit(RCC->CR, RCC_CR_HSEON_Pos) );
}

__STATIC_INLINE uint8_t RCC_HSE_EnableOrDisable(uint8_t status){
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

#define RCC_HSE_CLKSOURCE_XTAL      0b0
#define RCC_HSE_CLKSOURCE_EXTCLK		0b1

__STATIC_INLINE uint8_t RCC_HSE_GetClockSource(void){
  return ( GetBit(RCC->CR, RCC_CR_HSEBYP_Pos) );
}

__STATIC_INLINE void RCC_HSE_SetClockSource(uint8_t mode){
	WriteBit(RCC->CR, RCC_CR_HSEBYP_Pos, mode);
	while(RCC_HSE_GetClockSource() != mode){};	
}


/*
PLLRDY: PLL clock ready flag
				Set by hardware to indicate that the PLL is locked.
				0: PLL unlocked
				1: PLL locked
*/

__STATIC_INLINE uint8_t _PLL_GetReadyFlag(void){
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
__STATIC_INLINE uint8_t _PLL_GetEnableStatus(void){
  return ( GetBit(RCC->CR, RCC_CR_PLLON_Pos) );
}

__STATIC_INLINE uint8_t RCC_PLL_EnableOrDisable(uint8_t status){
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

#define RCC_PLL_CLKSOURCE_HSI_DIV2	0b00
#define RCC_PLL_CLKSOURCE_HSE_DIV1  0b01
#define RCC_PLL_CLKSOURCE_HSE_DIV2	0b10

__STATIC_INLINE void RCC_PLL_SetClockSource(uint8_t mode){
	char e_status= _PLL_GetEnableStatus();

	switch(mode){
		case RCC_PLL_CLKSOURCE_HSI_DIV2:
			ClearBit(RCC->CFGR, RCC_CFGR_PLLSRC_Pos);
			break;
		case RCC_PLL_CLKSOURCE_HSE_DIV1:
			SetBit(RCC->CFGR, RCC_CFGR_PLLSRC_Pos);
			ClearBit(RCC->CFGR, RCC_CFGR_PLLXTPRE_Pos);
			break;
		case RCC_PLL_CLKSOURCE_HSE_DIV2:
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

#define RCC_PLL_MUL2			0b0000
#define RCC_PLL_MUL3			0b0001
#define RCC_PLL_MUL4			0b0010
#define RCC_PLL_MUL5			0b0011
#define RCC_PLL_MUL6			0b0100
#define RCC_PLL_MUL7			0b0101
#define RCC_PLL_MUL8			0b0110
#define RCC_PLL_MUL9			0b0111
#define RCC_PLL_MUL10		0b1000
#define RCC_PLL_MUL11		0b1001
#define RCC_PLL_MUL12		0b1010
#define RCC_PLL_MUL13		0b1011
#define RCC_PLL_MUL14		0b1100
#define RCC_PLL_MUL15		0b1101
#define RCC_PLL_MUL16		0b1110
#define RCC_PLL_MUL16_		0b1111

__STATIC_INLINE void RCC_PLL_SetMultiplicationFactor(uint8_t mode){
	Write4Bit(RCC->CFGR, RCC_CFGR_PLLMULL_Pos, mode);
	while( Get4Bit(RCC->CFGR,RCC_CFGR_PLLMULL_Pos) != mode ){};
}


/*
RCC_CFGR, Bits 3:2
SWS: 	System clock switch status
			Set and cleared by hardware to indicate which clock source is used as system clock.
			00: HSI oscillator used as system clock
			01: HSE oscillator used as system clock
			10: PLL used as system clock
			11: not applicable

RCC_CFGR, Bits 1:0
SW: 	System clock switch
			Set and cleared by software to select SYSCLK source.
			Set by hardware to force HSI selection when leaving Stop and Standby mode or 
			in case of failure of the HSE oscillator used directly or 
			indirectly as system clock (if the Clock Security System is enabled).
			00: HSI selected as system clock
			01: HSE selected as system clock
			10: PLL selected as system clock
			11: not allowed
*/

#define RCC_SYSCLK_CLKSOURCE_HSI			0b00
#define RCC_SYSCLK_CLKSOURCE_HSE    	0b01
#define RCC_SYSCLK_CLKSOURCE_PLL    	0b10
#define RCC_SYSCLK_CLKSOURCE_NONE		0b11

__STATIC_INLINE uint8_t _SeystemClock_GetSource(void){
	return ( Get2Bit(RCC->CFGR, RCC_CFGR_SWS_Pos) );
}

__STATIC_INLINE uint8_t RCC_SeystemClock_SetSource(uint8_t mode){
	Write2Bit(RCC->CFGR, RCC_CFGR_SW_Pos, mode);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_SeystemClock_GetSource, mode) );
	#else
		return 0;
	#endif
}


/*
RCC_CFGR, Bits 7:4
HPRE:	AHB prescaler
			Set and cleared by software to control the division factor of the AHB clock.
			Note: The AHB clock frequency must be at least 25 MHz when the Ethernet is used.
			0xxx: SYSCLK not divided
			1000: SYSCLK divided by 2
			1001: SYSCLK divided by 4
			1010: SYSCLK divided by 8
			1011: SYSCLK divided by 16
			1100: SYSCLK divided by 64
			1101: SYSCLK divided by 128
			1110: SYSCLK divided by 256
			1111: SYSCLK divided by 512
*/

#define RCC_AHB_DIV1   		0b0000
#define RCC_AHB_DIV2     	0b1000
#define RCC_AHB_DIV4     	0b1001
#define RCC_AHB_DIV8     	0b1010
#define RCC_AHB_DIV16    	0b1011
#define RCC_AHB_DIV64    	0b1100
#define RCC_AHB_DIV128			0b1101
#define RCC_AHB_DIV256   	0b1110
#define RCC_AHB_DIV512			0b1111	

__STATIC_INLINE uint8_t _AHB_GetPrescaler(void){
	return( Get4Bit(RCC->CFGR, RCC_CFGR_HPRE_Pos) );
}

__STATIC_INLINE uint8_t RCC_AHB_SetPrescaler(uint8_t mode){
	Write4Bit(RCC->CFGR, RCC_CFGR_HPRE_Pos, mode);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_AHB_GetPrescaler, mode) );
	#else
		return 0;
	#endif
}


/*
RCC_CFGR, Bits 10:8
PPRE1[2:0]: APB Low-speed prescaler (APB1)
						Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
						Note: Software must configure these bits ensure that the frequency in this domain does not exceed 36 MHz.
						0xx: HCLK not divided
						100: HCLK divided by 2
						101: HCLK divided by 4
						110: HCLK divided by 8
						111: HCLK divided by 16
*/

#define RCC_APB1_DIV1		0b000
#define RCC_APB1_DIV2		0b100
#define RCC_APB1_DIV4		0b101
#define RCC_APB1_DIV8		0b110
#define RCC_APB1_DIV16		0b111

__STATIC_INLINE uint8_t _APB1_GetPrescaler(void){
	return( Get3Bit(RCC->CFGR, RCC_CFGR_PPRE1_Pos) );
}

__STATIC_INLINE uint8_t RCC_APB1_SetPrescaler(uint8_t mode){
	Write3Bit(RCC->CFGR, RCC_CFGR_PPRE1_Pos, mode);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_APB1_GetPrescaler, mode) );
	#else
		return 0;
	#endif
}


/*
RCC_CFGR, Bits 13:11
PPRE2[2:0]: APB high-speed prescaler (APB2)
						Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
						Note: Software must configure these bits ensure that the frequency in this domain does not exceed 72 MHz.
						0xx: HCLK not divided
						100: HCLK divided by 2
						101: HCLK divided by 4
						110: HCLK divided by 8
						111: HCLK divided by 16
*/

#define RCC_APB2_DIV1		0b000
#define RCC_APB2_DIV2		0b100
#define RCC_APB2_DIV4		0b101
#define RCC_APB2_DIV8		0b110
#define RCC_APB2_DIV16		0b111

__STATIC_INLINE uint8_t _APB2_GetPrescaler(void){
	return( Get3Bit(RCC->CFGR, RCC_CFGR_PPRE2_Pos) );
}

__STATIC_INLINE uint8_t RCC_APB2_SetPrescaler(uint8_t mode){
	Write3Bit(RCC->CFGR, RCC_CFGR_PPRE2_Pos, mode);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_APB2_GetPrescaler, mode) );
	#else
		return 0;
	#endif
}


/*
RCC_CFGR, Bits 15:14
ADCPRE:	ADC prescaler
				2 Bits, Read/Write by software
				Select the frequency of the clock to the ADCs.
				00: PCLK2 divided by 2
				01: PCLK2 divided by 4
				10: PCLK2 divided by 6
				11: PCLK2 divided by 8
*/

#define RCC_ADC_DIV2		0b00
#define RCC_ADC_DIV4		0b01
#define RCC_ADC_DIV6		0b10
#define RCC_ADC_DIV8		0b11

__STATIC_INLINE uint8_t _ADC_GetPrescaler(void){
	return( Get2Bit(RCC->CFGR, RCC_CFGR_ADCPRE_Pos) );
}

__STATIC_INLINE uint8_t RCC_ADC_SetPrescaler(uint8_t mode){
	Write2Bit(RCC->CFGR, RCC_CFGR_ADCPRE_Pos, mode);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_ADC_GetPrescaler, mode) );
	#else
		return 0;
	#endif
}


/*
RCC_CFGR, Bits 26:24
MCO:	Microcontroller clock output
			Set and cleared by software.
			0xx: No clock
			100: System clock (SYSCLK) selected
			101: HSI clock selected
			110: HSE clock selected
			111: PLL clock divided by 2 selected

			Note: This clock output may have some truncated cycles at startup or during MCO clock source switching.
			Note: When the System Clock is selected to output to the MCO pin,
			make sure that this clock does not exceed 50 MHz (the maximum IO speed).
*/

#define RCC_MCO_SOURCE_NONE					0b000
#define RCC_MCO_SOURCE_SYSCLK				0b100
#define RCC_MCO_SOURCE_HSI					0b101
#define RCC_MCO_SOURCE_HSE					0b110
#define RCC_MCO_SOURCE_PLLCLK_DIV2	0b111

__STATIC_INLINE uint8_t _MCO_GetSource(void){
	return( Get3Bit(RCC->CFGR, RCC_CFGR_MCO_Pos) );
}

__STATIC_INLINE uint8_t RCC_MCO_SetSource(uint8_t mode){
	Write3Bit(RCC->CFGR, RCC_CFGR_MCO_Pos, mode);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_MCO_GetSource, mode) );
	#else
		return 0;
	#endif
}


/*	
BDRST: 	Backup domain software reset
				1 Bit, Read/Write by software
				Note: The RTC_PRL, RTC_ALR, RTC_CNT, and RTC_DIV registers are reset only by a Backup Domain reset.
				0: Reset not activated.
				1: Resets the entire Backup domain. 
*/

__STATIC_INLINE uint8_t _BackupDomain_GetResetStatus(void){
		return ( GetBit(RCC->BDCR, RCC_BDCR_BDRST_Pos) );
}

__STATIC_INLINE uint8_t RCC_BackupDomain_ResetOrRelease(uint8_t status){
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

__STATIC_INLINE uint8_t _LSE_GetReadyFlag(void){
		return ( GetBit(RCC->BDCR, RCC_BDCR_LSERDY_Pos) );
}


/*
LSEON: 	External low-speed oscillator enable
				1 Bit, Read/Write by software
				0: External 32 kHz oscillator OFF
				1: External 32 kHz oscillator ON
*/

__STATIC_INLINE uint8_t _LSE_GetEnableStatus(void){
		return ( GetBit(RCC->BDCR, RCC_BDCR_LSEON_Pos) );
}

__STATIC_INLINE uint8_t RCC_LSE_EnableOrDisable(uint8_t status){
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

#define RCC_LSE_CLKSOURCE_XTAL			0b0
#define RCC_LSE_CLKSOURCE_EXTCLK		0b1

__STATIC_INLINE uint8_t _LSE_GetClockSource(void){
		return ( GetBit(RCC->BDCR, RCC_BDCR_LSEBYP_Pos) );
}

__STATIC_INLINE uint8_t RCC_LSE_SetClockSource(uint8_t mode){
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

__STATIC_INLINE uint8_t _LSI_GetReadyFlag(void){
		return ( GetBit(RCC->CSR, RCC_CSR_LSIRDY_Pos) );
}


/*
LSION: 	Internal low-speed oscillator enable
				1 Bit, Read/Write by software
				0: Internal RC 40 kHz oscillator OFF
				1: Internal RC 40 kHz oscillator ON
*/

__STATIC_INLINE uint8_t _LSI_GetEnableStatus(void){
		return ( GetBit(RCC->CSR, RCC_CSR_LSION_Pos) );
}

__STATIC_INLINE uint8_t RCC_LSI_EnableOrDisable(uint8_t status){
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

#define RCC_RTC_CLKSOURCE_NONE					0b00
#define RCC_RTC_CLKSOURCE_LSE    				0b01
#define RCC_RTC_CLKSOURCE_LSI    				0b10
#define RCC_RTC_CLKSOURCE_HSE_DIV128		0b11

__STATIC_INLINE uint8_t _RTC_GetClockSource(void){
		return ( Get2Bit(RCC->BDCR, RCC_BDCR_RTCSEL_Pos) );
}

__STATIC_INLINE uint8_t RCC_RTC_SetClockSource(uint8_t mode){
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

__STATIC_INLINE uint8_t _RTC_GeEnableStatus(void){
	return ( GetBit(RCC->BDCR, RCC_BDCR_RTCEN_Pos) );
}

__STATIC_INLINE uint8_t RCC_RTC_EnableOrDisable(uint8_t status){
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
