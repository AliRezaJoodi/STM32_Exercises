// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
It's about:
	RCC_APB1RSTR: APB1 peripheral reset register
	RCC_APB2RSTR: APB2 peripheral reset register 
	RCC_APB1ENR: 	APB1 peripheral clock enable register
	RCC_APB2ENR: 	APB2 peripheral clock enable register
*/

#ifndef _STM32F1xx_BM_BUS_INCLUDED
#define _STM32F1xx_BM_BUS_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>

#include <utility.h>
#include <timeout.h>

/*
PWRRST:	Power interface reset
				1 Bit, Read/Write by software
				0: No effect
				1: Reset power interface
*/

__STATIC_INLINE uint32_t BUS_PWR_Reset(void){
	SetBit(RCC->APB1RSTR, RCC_APB1RSTR_PWRRST_Pos);
	return 0;
}

/*
PWREN:	Power interface clock enable
				1 Bit, Read/Write by software
				0: Power interface clock disabled
				1: Power interface clock enable
*/

__STATIC_INLINE uint32_t BUS_PWR_GetEnableStatus(void){
	return ( GetBit(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos) );
}

__STATIC_INLINE uint32_t BUS_PWR_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_PWR_GetEnableStatus, status) );
	#else
		return 0;
	#endif
}


/*
BKPRST:	Backup interface reset
				1 Bit, Read/Write by software
				0: No effect
				1: Reset power interface
*/

__STATIC_INLINE uint32_t BUS_BKP_Reset(void){
	SetBit(RCC->APB1RSTR, RCC_APB1RSTR_BKPRST_Pos);
	
	return 0;
}


/*
BKPEN:	Backup interface clock enable
				1 Bit, Read/Write by software
				0: Power interface clock disabled
				1: Power interface clock enable
*/

__STATIC_INLINE uint32_t BUS_BKP_GetEnableStatus(void){
	return ( GetBit(RCC->APB1ENR, RCC_APB1ENR_BKPEN_Pos) );
}

__STATIC_INLINE uint32_t BUS_BKP_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_BKPEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_BKP_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}


/*
RCC_APB2RSTR, Bit 0
AFIORST: 	Alternate function I/O reset
					1 Bit, Read/Write by software
					0: No effect
					1: Reset Alternate Function
*/

__STATIC_INLINE uint32_t BUS_AFIO_Reset(void){
	SetBit(RCC->APB2RSTR, RCC_APB2RSTR_AFIORST_Pos);
	return 0;	
}


/*
AFIOEN: Alternate function IO clock enable
				1 Bit, Read/Write by software
				0: Alternate Function IO clock disabled
				1: Alternate Function IO clock enabled
*/

__STATIC_INLINE uint32_t BUS_AFIO_GetEnableStatus(void){
		return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos) );
}

__STATIC_INLINE uint32_t BUS_AFIO_EnableOrDisable(uint32_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_AFIO_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
RCC_APB2RSTR, Bit 2
IOPARST: 	I/O port A reset
					1 Bit, Read/Write by software
					0: No effect
					1: Reset I/O port A
*/

__STATIC_INLINE void BUS_GPIOA_Reset(void){
	SetBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPARST_Pos);
}

/*
RCC_APB2ENR, Bit 2
IOPAEN: IO port A clock enable
				Set and cleared by software.
				0: IO port A clock disabled
				1: IO port A clock enabled
*/

__STATIC_INLINE uint32_t BUS_GPIOA_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos) );
}

__STATIC_INLINE uint8_t BUS_GPIOA_EnableOrDisable(uint8_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_GPIOA_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
IOPBRST: 	I/O port B reset
					1 Bit, Read/Write by software
					0: No effect
					1: Reset I/O port B
*/

__STATIC_INLINE uint8_t BUS_GPIOB_Reset(void){
	SetBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPBRST_Pos);
	
	return 0;
}


/*
IOPBEN: I/O port B clock enable
				1 Bit, Read/Write by software
				0: I/O port B clock disabled
				1: I/O port B clock enabled
*/
__STATIC_INLINE uint32_t BUS_GPIOB_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos) );
}

__STATIC_INLINE uint8_t BUS_GPIOB_EnableOrDisable(uint8_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_GPIOB_GetEnableStatus, status) );
	#else
		return 0;
	#endif
}

/*
IOPCRST: 	I/O port C reset
					1 Bit, Read/Write by software
					0: No effect
					1: Reset I/O port C
*/

__STATIC_INLINE uint8_t BUS_GPIOC_Reset(void){
	SetBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPCRST_Pos);
	
	return 0;	
}

/*
IOPCEN: I/O port C clock enable
				1 Bit, Read/Write by software
				0: I/O port C clock disabled
				1: I/O port C clock enabled
*/

__STATIC_INLINE uint32_t BUS_GPIOC_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos) );
}

__STATIC_INLINE uint8_t BUS_GPIOC_EnableOrDisable(uint8_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_GPIOC_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
IOPDRST: 	I/O port D reset
					1 Bit, Read/Write by software
					0: No effect
					1: Reset I/O port D
*/

__STATIC_INLINE uint8_t BUS_GPIOD_Reset(void){
	SetBit(RCC->APB2RSTR, RCC_APB2RSTR_IOPDRST_Pos);
	
	return 0;
}

/*
IOPDEN: I/O port D clock enable
				1 Bit, Read/Write by software
				0: I/O port D clock disabled
				1: I/O port D clock enabled
*/

__STATIC_INLINE uint32_t BUS_GPIOD_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos) );
}

__STATIC_INLINE uint8_t BUS_GPIOD_EnableOrDisable(uint8_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_GPIOD_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
USART1RST:	USART1 reset
						1 Bit, Read/Write by software
						0: No effect
						1: Reset USART1
*/

__STATIC_INLINE uint8_t BUS_USART1_Reset(void){
	SetBit(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST_Pos);
	
	return 0;
}

/*
USART1EN: USART1 clock enable
					1 Bit, Read/Write by software
					0: USART1 clock disabled
					1: USART1 clock enabled
*/

__STATIC_INLINE uint32_t BUS_USART1_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos) );
}

__STATIC_INLINE uint8_t BUS_USART1_EnableOrDisable(uint8_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_USART1_GetEnableStatus, status) );
	#else
		return 0;
	#endif
}

/*
USART2RST: 	USART 2 reset
						1 Bit, Read/Write by software
						0: No effect
						1: Reset USART 2
*/

__STATIC_INLINE uint8_t BUS_USART2_Reset(void){
	SetBit(RCC->APB1RSTR, RCC_APB1RSTR_USART2RST_Pos);
	
	return 0;
}


/*
USART2EN: USART2 clock enable
					1 Bit, Read/Write by software
					0: USART2 clock disabled
					1: USART2 clock enabled
*/

__STATIC_INLINE uint32_t BUS_USART2_GetEnableStatus(void){
	return ( GetBit(RCC->APB1ENR, RCC_APB1ENR_USART2EN_Pos) );
}

__STATIC_INLINE uint8_t BUS_USART2_EnableOrDisable(uint8_t status){
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_USART2EN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_USART2_GetEnableStatus, status) );
	#else
		return 0;
	#endif		
}

/*
USART3RST: 	USART 3 reset
						1 Bit, Read/Write by software
						0: No effect
						1: Reset USART 3
*/

__STATIC_INLINE uint8_t BUS_USART3_Reset(void){
	SetBit(RCC->APB1RSTR, RCC_APB1RSTR_USART3RST_Pos);
	
	return 0;
}

/*
USART3EN: USART3 clock enable
					1 Bit, Read/Write by software
					0: USART3 clock disabled
					1: USART3 clock enabled
*/

__STATIC_INLINE uint32_t BUS_USART3_GetEnableStatus(void){
	return ( GetBit(RCC->APB1ENR, RCC_APB1ENR_USART3EN_Pos) );
}

__STATIC_INLINE uint8_t BUS_USART3_EnableOrDisable(uint8_t status){
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_USART3EN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_USART3_GetEnableStatus, status) );
	#else
		return 0;
	#endif
}


/*
RCC_APB2RSTR, Bit 10
ADC2RST: 	ADC 2 interface reset
					Set and cleared by software.
					0: No effect
					1: Reset ADC 2 interface
*/

__STATIC_INLINE uint32_t BUS_ADC2_GetResetStatus(void){
	return ( GetBit(RCC->APB2RSTR, RCC_APB2RSTR_ADC2RST_Pos) );
}

__STATIC_INLINE uint8_t BUS_ADC2_Reset(void){
	SetBit(RCC->APB2RSTR, RCC_APB2RSTR_ADC2RST_Pos);
	
	return 0;
}

/*
RCC_APB2ENR, Bit 10
ADC2EN: ADC 2 interface clock enable
				Set and cleared by software.
				0: ADC 2 interface disabled
				1: ADC 2 interface clock enabled
*/

__STATIC_INLINE uint32_t BUS_ADC2_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_ADC2EN_Pos) );
}

__STATIC_INLINE uint8_t BUS_ADC2_EnableOrDisable(uint8_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_ADC2EN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_ADC2_GetEnableStatus, status) );
	#else
		return 0;
	#endif
}


/*
RCC_APB2RSTR, Bit 9
ADC1RST: 	ADC 1 interface reset
					Set and cleared by software.
					0: No effect
					1: Reset ADC 1 interface
*/

__STATIC_INLINE uint8_t BUS_ADC1_Reset(void){
	SetBit(RCC->APB2RSTR, RCC_APB2RSTR_ADC1RST_Pos);
	
	return 0;
}

/*
RCC_APB2ENR, Bit 9
ADC1EN: ADC 1 interface clock enable
				Set and cleared by software.
				0: ADC 1 interface disabled
				1: ADC 1 interface clock enabled
*/

__STATIC_INLINE uint32_t BUS_ADC1_GetEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_ADC1EN_Pos) );
}

__STATIC_INLINE uint8_t BUS_ADC1_EnableOrDisable(uint8_t status){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_ADC1EN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_ADC1_GetEnableStatus, status) );
	#else
		return 0;
	#endif
}

/*
CRCEN: 	CRC clock enable
				1 Bit, Read/Write by software
				0: CRC clock disabled
				1: CRC clock enabled
*/

__STATIC_INLINE uint32_t BUS_CRC_GetEnableStatus(void){
	return ( GetBit(RCC->AHBENR, RCC_AHBENR_CRCEN_Pos) );
}

__STATIC_INLINE uint8_t BUS_CRC_EnableOrDisable(uint8_t status){
	WriteBit(RCC->AHBENR, RCC_AHBENR_CRCEN_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(BUS_CRC_GetEnableStatus, status) );
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
