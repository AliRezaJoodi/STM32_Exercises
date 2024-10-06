// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
	It's about:
		RCC_APB1RSTR: APB1 peripheral reset register
		RCC_APB1ENR: 	APB1 peripheral clock enable register
		RCC_APB2RSTR: APB2 peripheral reset register 
		RCC_APB2ENR: 	APB2 peripheral clock enable register
*/

#include <stm32f1xx.h>
#include <utility.h>
#include <timeout.h>

#ifndef _STM32F1xx_BM_BUS_INCLUDED
#define _STM32F1xx_BM_BUS_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/*
PWRRST:	Power interface reset
				Set and cleared by software.
				0: No effect
				1: Reset power interface
*/
__STATIC_INLINE uint32_t _PWR_GetResetStatus(void){
	return ( GetBit(RCC->APB1RSTR, RCC_APB1RSTR_PWRRST_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_PWR_ResetOrRelease(uint32_t status){
	WriteBit(RCC->APB1RSTR, RCC_APB1RSTR_PWRRST_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_PWR_GetResetStatus, status) );
	#else
		return 0;
	#endif
}

/*
PWREN:	Power interface clock enable
				Set and cleared by software.
				0: Power interface clock disabled
				1: Power interface clock enable
*/
__STATIC_INLINE uint32_t _PWR_GetEnableStatus(void){
	return ( GetBit(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_PWR_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_PWR_GetEnableStatus, status) );
	#else
		return 0;
	#endif
}

/*
BKPRST:	Backup interface reset
				Set and cleared by software.
				0: No effect
				1: Reset power interface
*/
__STATIC_INLINE uint32_t _BKP_GetResetStatus(void){
	return ( GetBit(RCC->APB1RSTR, RCC_APB1RSTR_BKPRST_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_BKP_ResetOrRelease(uint32_t status){
	WriteBit(RCC->APB1RSTR, RCC_APB1RSTR_BKPRST_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_BKP_GetResetStatus, status) );
	#else
		return 0;
	#endif
}

/*
BKPEN:	Backup interface clock enable
				Set and cleared by software.
				0: Power interface clock disabled
				1: Power interface clock enable
*/
__STATIC_INLINE uint32_t _BKP_GetEnableStatus(void){
	return ( GetBit(RCC->APB1ENR, RCC_APB1ENR_BKPEN_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_BKP_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_BKPEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_BKP_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
AFIORST: 	Alternate function I/O reset
					Set and cleared by software.
					0: No effect
					1: Reset Alternate Function
*/
__STATIC_INLINE uint32_t _AFIO_GetResetStatus(void){
	return ( GetBit(RCC->APB2RSTR, RCC_APB2RSTR_AFIORST_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_AFIO_ResetOrRelease(uint32_t status){
	WriteBit(RCC->APB2RSTR, RCC_APB2RSTR_AFIORST_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_AFIO_GetResetStatus, status) );
	#else
		return 0;
	#endif		
}

/*
AFIOEN: Alternate function IO clock enable
				Set and cleared by software.
				0: Alternate Function IO clock disabled
				1: Alternate Function IO clock enabled
*/
__STATIC_INLINE uint32_t _AFIO_GetEnableStatus(void){
		return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_AFIO_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_AFIO_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
IOPARST: 	I/O port A reset
					Set and cleared by software.
					0: No effect
					1: Reset I/O port A
*/
__STATIC_INLINE uint32_t _GPIOA_GetResetStatus(void){
	return ( GetBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPARST_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_GPIOA_ResetOrRelease(uint32_t status){
	WriteBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPARST_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_GPIOA_GetResetStatus, status) );
	#else
		return 0;
	#endif	
}

/*
IOPAEN: I/O port A clock enable
				Set and cleared by software.
				0: I/O port A clock disabled
				1: I/O port A clock enabled
*/
__STATIC_INLINE uint32_t _GPIOA_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_GPIOA_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_GPIOA_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
IOPBRST: 	I/O port B reset
					Set and cleared by software.
					0: No effect
					1: Reset I/O port B
*/
__STATIC_INLINE uint32_t _GPIOB_GetResetStatus(void){
	return ( GetBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPBRST_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_GPIOB_ResetOrRelease(uint32_t status){
	WriteBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPBRST_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_GPIOB_GetResetStatus, status) );
	#else
		return 0;
	#endif	
}

/*
IOPBEN: I/O port B clock enable
				Set and cleared by software.
				0: I/O port B clock disabled
				1: I/O port B clock enabled
*/
__STATIC_INLINE uint32_t _GPIOB_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_GPIOB_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_GPIOB_GetEnableStatus, status) );
	#else
		return 0;
	#endif
}

/*
IOPCRST: 	I/O port C reset
					Set and cleared by software.
					0: No effect
					1: Reset I/O port C
*/
__STATIC_INLINE uint32_t _GPIOC_GetResetStatus(void){
	return ( GetBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPCRST_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_GPIOC_ResetOrRelease(uint32_t status){
	WriteBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPCRST_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_GPIOC_GetResetStatus, status) );
	#else
		return 0;
	#endif	
}

/*
IOPCEN: I/O port C clock enable
				Set and cleared by software.
				0: I/O port C clock disabled
				1: I/O port C clock enabled
*/
__STATIC_INLINE uint32_t _GPIOC_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_GPIOC_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_GPIOC_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
IOPDRST: 	I/O port D reset
					Set and cleared by software.
					0: No effect
					1: Reset I/O port D
*/
__STATIC_INLINE uint32_t _GPIOD_GetResetStatus(void){
	return ( GetBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPDRST_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_GPIOD_ResetOrRelease(uint32_t status){
	WriteBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPDRST_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_GPIOD_GetResetStatus, status) );
	#else
		return 0;
	#endif	
}

/*
IOPDEN: I/O port D clock enable
				Set and cleared by software.
				0: I/O port D clock disabled
				1: I/O port D clock enabled
*/
__STATIC_INLINE uint32_t _GPIOD_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_GPIOD_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_GPIOD_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
USART1RST:	USART1 reset
						Set and cleared by software.
						0: No effect
						1: Reset USART1
*/
__STATIC_INLINE uint32_t _USART1_GetResetStatus(void){
	return ( GetBit(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_USART1_ResetOrRelease(uint32_t status){
	WriteBit(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_USART1_GetResetStatus, status) );
	#else
		return 0;
	#endif	
}

/*
USART1EN: USART1 clock enable
					Set and cleared by software.
					0: USART1 clock disabled
					1: USART1 clock enabled
*/
__STATIC_INLINE uint32_t _USART1_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_USART1_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_USART1_GetEnableStatus, status) );
	#else
		return 0;
	#endif
}

/*
USART2RST: 	USART 2 reset
						Set and cleared by software.
						0: No effect
						1: Reset USART 2
*/
__STATIC_INLINE uint32_t _USART2_GetResetStatus(void){
	return ( GetBit(RCC->APB1RSTR, RCC_APB1RSTR_USART2RST_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_USART2_ResetOrRelease(uint32_t status){
	WriteBit(RCC->APB1RSTR, RCC_APB1RSTR_USART2RST_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_USART2_GetResetStatus, status) );
	#else
		return 0;
	#endif	
}

/*
USART2EN: USART2 clock enable
					Set and cleared by software.
					0: USART2 clock disabled
					1: USART2 clock enabled
*/
__STATIC_INLINE uint32_t _USART2_GetEnableStatus(void){
	return ( GetBit(RCC->APB1ENR, RCC_APB1ENR_USART2EN_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_USART2_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_USART2EN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_USART2_GetEnableStatus, status) );
	#else
		return 0;
	#endif		
}

/*
USART3RST: 	USART 3 reset
						Set and cleared by software.
						0: No effect
						1: Reset USART 3
*/
__STATIC_INLINE uint32_t _USART3_GetResetStatus(void){
	return ( GetBit(RCC->APB1RSTR, RCC_APB1RSTR_USART3RST_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_USART3_ResetOrRelease(uint32_t status){
	WriteBit(RCC->APB1RSTR, RCC_APB1RSTR_USART3RST_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_USART3_GetResetStatus, status) );
	#else
		return 0;
	#endif	
}

/*
USART3EN: USART3 clock enable
					Set and cleared by software.
					0: USART3 clock disabled
					1: USART3 clock enabled
*/
__STATIC_INLINE uint32_t _USART3_GetEnableStatus(void){
	return ( GetBit(RCC->APB1ENR, RCC_APB1ENR_USART3EN_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_USART3_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_USART3EN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_USART3_GetEnableStatus, status) );
	#else
		return 0;
	#endif
}

/*
CRCEN: 	CRC clock enable
				Set and cleared by software.
				0: CRC clock disabled
				1: CRC clock enabled
*/
__STATIC_INLINE uint32_t _CRC_GetEnableStatus(void){
	return ( GetBit(RCC->AHBENR, RCC_AHBENR_CRCEN_Pos) );
}

//********************************************************************
__STATIC_INLINE uint32_t BUS_CRC_EnableOrDisable(uint32_t status){
	WriteBit(RCC->AHBENR, RCC_AHBENR_CRCEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_CRC_GetEnableStatus, status) );
	#else
		return 0;
	#endif
}

//********************************************************************
void BUS_GPIOx_EnableOrDisableWithAutoSearch(GPIO_TypeDef *GPIOx);


#ifdef __cplusplus
}
#endif
		
#endif	// _STM32F1xx_BM_BUS_INCLUDED
