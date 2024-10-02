// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
	Abbreviations:
	PWR: 		Power Interface
	AFIO: 	Alternate Function I/O
*/

#include <stm32f1xx.h>
#include <utility.h>

#ifndef _STM32F1xx_BM_BUS_INCLUDED
#define _STM32F1xx_BM_BUS_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/*
#ifndef ENABLE
	#define ENABLE		1
	#define DISABLE		!ENABLE
#endif
*/

__STATIC_INLINE void BUS_PWR_ResetClock(void){
	SetBit_NoLastStatus(RCC->APB1RSTR, RCC_APB1RSTR_PWRRST_Pos)
}
__STATIC_INLINE uint32_t _PWR_GeEnableStatus(void){
		return ( GetBit(RCC->APB1ENR, RCC_APB1RSTR_PWRRST_Pos) );
}
__STATIC_INLINE void BUS_PWR_EnableOrDisable(uint32_t STATUS){
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos, STATUS);
	while(_PWR_GeEnableStatus() != STATUS){};	
}
/*#define BUS_PWR_ResetClock \
	SetBit_NoLastStatus(RCC->APB1RSTR, RCC_APB1RSTR_PWRRST_Pos)
#define _PWR_GeEnableStatus \
	GetBit(RCC->APB1ENR, RCC_APB1RSTR_PWRRST_Pos)
#define BUS_PWR_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos, STATUS);\
	while(_PWR_GeEnableStatus() != STATUS){};*/

__STATIC_INLINE void BUS_AFIO_ResetClock(void){
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_AFIORST_Pos)
}	
__STATIC_INLINE uint32_t _AFIO_GeEnableStatus(void){
		return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos) );
}
__STATIC_INLINE void BUS_AFIO_EnableOrDisable(uint32_t STATUS){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos, STATUS);
	while(_AFIO_GeEnableStatus() != STATUS){};
}
/*#define BUS_AFIO_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_AFIORST_Pos)
#define _AFIO_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos)
#define BUS_AFIO_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos, STATUS);\
	while(_AFIO_GeEnableStatus() != STATUS){};*/

__STATIC_INLINE void BUS_GPIOA_ResetClock(void){
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPARST_Pos);	
}
__STATIC_INLINE uint32_t _GPIOA_GeEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos) );
}
__STATIC_INLINE void BUS_GPIOA_EnableOrDisable(uint32_t STATUS){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos, STATUS);
	while(_GPIOA_GeEnableStatus() != STATUS){};
}
/*#define BUS_GPIOA_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPARST_Pos);
#define _GPIOA_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos)
#define BUS_GPIOA_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos, STATUS);\
	while(_GPIOA_GeEnableStatus() != STATUS){};*/
	
__STATIC_INLINE void BUS_GPIOB_ResetClock(void){
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPBRST_Pos);	
}
__STATIC_INLINE uint32_t _GPIOB_GeEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos) );
}
__STATIC_INLINE void BUS_GPIOB_EnableOrDisable(uint32_t STATUS){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos, STATUS);
	while(_GPIOB_GeEnableStatus() != STATUS){};
}

/*#define BUS_GPIOB_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPBRST_Pos);	
#define _GPIOB_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos)
#define BUS_GPIOB_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos, STATUS);\
	while(_GPIOB_GeEnableStatus != STATUS){};*/

__STATIC_INLINE void BUS_GPIOC_ResetClock(void){
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPCRST_Pos);	
}
__STATIC_INLINE uint32_t _GPIOC_GeEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos) );
}
__STATIC_INLINE void BUS_GPIOC_EnableOrDisable(uint32_t STATUS){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos, STATUS);
	while(_GPIOC_GeEnableStatus() != STATUS){};
}
/*#define BUS_GPIOC_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPCRST_Pos);
#define _GPIOC_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos)
#define BUS_GPIOC_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos, STATUS);\
	while(_GPIOC_GeEnableStatus != STATUS){};*/

__STATIC_INLINE void BUS_GPIOD_ResetClock(void){
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPDRST_Pos);	
}
__STATIC_INLINE uint32_t _GPIOD_GeEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos) );
}
__STATIC_INLINE void BUS_GPIOD_EnableOrDisable(uint32_t STATUS){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos, STATUS);
	while(_GPIOD_GeEnableStatus() != STATUS){};
}
/*#define BUS_GPIOD_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPDRST_Pos);
#define _GPIOD_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos)
#define BUS_GPIOD_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos, STATUS);\
	while(_GPIOD_GeEnableStatus != STATUS){};*/

/*#define BUS_GPIOx_EnableOrDisableWithAutoSearch(GPIOx); \
	if(GPIOx == GPIOA){BUS_GPIOA_EnableOrDisable(1);}\
		else if(GPIOx ==	GPIOB){BUS_GPIOB_EnableOrDisable(1);}\
			else if(GPIOx ==	GPIOC){BUS_GPIOC_EnableOrDisable(1);}\
				else if(GPIOx ==	GPIOD){BUS_GPIOD_EnableOrDisable(1);}*/

__STATIC_INLINE void BUS_USART1_ResetClock(void){
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST_Pos);
}	
__STATIC_INLINE uint32_t _USART1_GeEnableStatus(void){
	return ( GetBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos) );
}
__STATIC_INLINE void BUS_USART1_EnableOrDisable(uint32_t STATUS){
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos, STATUS);
	while(_USART1_GeEnableStatus() != STATUS){};	
}
/*
#define BUS_USART1_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST_Pos)
#define _USART1_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos)
#define BUS_USART1_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos, STATUS);\
	while(_USART1_GeEnableStatus != STATUS){};*/

__STATIC_INLINE void BUS_USART2_ResetClock(void){
	SetBit_NoLastStatus(RCC->APB1RSTR, RCC_APB1RSTR_USART2RST_Pos);
}	
__STATIC_INLINE uint32_t _USART2_GeEnableStatus(void){
	return ( GetBit(RCC->APB1ENR, RCC_APB1ENR_USART2EN_Pos) );
}
__STATIC_INLINE void BUS_USART2_EnableOrDisable(uint32_t STATUS){
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_USART2EN_Pos, STATUS);
	while(_USART2_GeEnableStatus() != STATUS){};	
}

__STATIC_INLINE void BUS_USART3_ResetClock(void){
	SetBit_NoLastStatus(RCC->APB1RSTR, RCC_APB1RSTR_USART3RST_Pos);
}	
__STATIC_INLINE uint32_t _USART3_GeEnableStatus(void){
	return ( GetBit(RCC->APB1ENR, RCC_APB1ENR_USART3EN_Pos) );
}
__STATIC_INLINE void BUS_USART3_EnableOrDisable(uint32_t STATUS){
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_USART3EN_Pos, STATUS);
	while(_USART3_GeEnableStatus() != STATUS){};	
}


__STATIC_INLINE uint32_t _CRC_GeEnableStatus(void){
	return ( GetBit(RCC->AHBENR, RCC_AHBENR_CRCEN_Pos) );
}
__STATIC_INLINE void BUS_CRC_EnableOrDisable(uint32_t STATUS){
	WriteBit(RCC->AHBENR, RCC_AHBENR_CRCEN_Pos, STATUS);
	while(_CRC_GeEnableStatus() != STATUS){};
}

void BUS_GPIOx_EnableOrDisableWithAutoSearch(GPIO_TypeDef *GPIOx);


#ifdef __cplusplus
}
#endif
		
#endif	// _STM32F1xx_BM_BUS_INCLUDED
