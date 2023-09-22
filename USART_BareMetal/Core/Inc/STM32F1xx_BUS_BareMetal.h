// GitHub Account: GitHub.com/AliRezaJoodi

/*
	Abbreviations:
	PWR: 		Power Interface
	AFIO: 	Alternate Function I/O
*/

#include "stm32f1xx.h"
#include "Utility.h"

#ifndef _BUS_INCLUDED
	#define _BUS_INCLUDED

#ifdef __cplusplus
	extern "C" {
#endif
		
#ifndef ENABLE
	#define ENABLE		1
	#define DISABLE		!ENABLE
#endif

#define BUS_PWR_ResetClock \
	SetBit_NoLastStatus(RCC->APB1RSTR, RCC_APB1RSTR_PWRRST_Pos)
#define _PWR_GetClockStatus \
	GetBit(RCC->APB1ENR, RCC_APB1RSTR_PWRRST_Pos)
#define BUS_PWR_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos, STATUS);\
	while(_PWR_GetClockStatus != STATUS){};
/*
#define BUS_DisableClockForPWR \
	ClearBit(RCC->APB1ENR,RCC_APB1ENR_PWREN_Pos);
#define BUS_EnableClockForPWR \
	SetBit(RCC->APB1ENR,RCC_APB1ENR_PWREN_Pos);\
	while(!_PWR_GetClockStatus){};
#define BUS_WaitTillEnableClockForPWR \
	while(!_PWR_GetClockStatus){};
*/
	
#define BUS_AFIO_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_AFIORST_Pos)	
#define _AFIO_GetClockStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos)
#define BUS_AFIO_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos, STATUS);\
	while(_AFIO_GetClockStatus != STATUS){};
/*
#define BUS_DisableClockForAFIO \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_AFIOEN_Pos);
#define BUS_EnableClockForAFIO \
	SetBit(RCC->APB2ENR,RCC_APB2ENR_AFIOEN_Pos);\
	while(!_AFIO_GetClockStatus){};
#define BUS_WaitTillEnableClockForAFIO \
	while(!_AFIO_GetClockStatus){};
*/
		
#define BUS_GPIOA_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPARST_Pos);
#define _GPIOA_GetClockStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos)
#define BUS_GPIOA_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos, STATUS);\
	while(_GPIOA_GetClockStatus != STATUS){};
/*
#define BUS_DisableClockForPortA \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_IOPAEN_Pos);
#define BUS_EnableClockForPortA \
	SetBit(RCC->APB2ENR,RCC_APB2ENR_IOPAEN_Pos);\
	while(!_GPIOA_GetClockStatus){};
#define BUS_WaitTillEnableClockForPortA \
	while(!_GPIOA_GetClockStatus){};
*/
		
#define BUS_GPIOB_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPBRST_Pos);	
#define _GPIOB_GetClockStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos)
#define BUS_GPIOB_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos, STATUS);\
	while(_GPIOB_GetClockStatus != STATUS){};
/*
#define BUS_DisableClockForPortB \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_IOPBEN_Pos);
#define BUS_EnableClockForPortB \
	SetBit(RCC->APB2ENR,RCC_APB2ENR_IOPBEN_Pos);\
	while(!_GPIOB_GetClockStatus){};
#define BUS_WaitTillEnableClockForPortB \
	while(!_GPIOB_GetClockStatus){};
*/
		
#define BUS_GPIOC_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPCRST_Pos);
#define _GPIOC_GetClockStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos)
#define BUS_GPIOC_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos, STATUS);\
	while(_GPIOC_GetClockStatus != STATUS){};
/*
#define BUS_DisableClockForPortC \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_IOPCEN_Pos);
#define BUS_EnableClockForPortC\
	SetBit(RCC->APB2ENR,RCC_APB2ENR_IOPCEN_Pos);\
	while(!_GPIOC_GetClockStatus){};
#define BUS_WaitTillEnableClockForPortC \
	while(!_GPIOC_GetClockStatus){};
*/
		
#define BUS_GPIOD_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPDRST_Pos);
#define _GPIOD_GetClockStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos)
#define BUS_GPIOD_EnableOrDisableClock(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos, STATUS);\
	while(_GPIOD_GetClockStatus != STATUS){};
/*
#define BUS_DisableClockForPortD \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_IOPDEN_Pos);
#define BUS_EnableClockForPortD \
	SetBit(RCC->APB2ENR,RCC_APB2ENR_IOPDEN_Pos);\
	while(!_GPIOD_GetClockStatus){};
#define BUS_WaitTillEnableClockForPortD \
	while(!_GPIOD_GetClockStatus){};
*/
		
#define BUS_USART1_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST_Pos)
#define _USART1_GetClockStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos)
#define BUS_USART1_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos, STATUS);\
	while(_USART1_GetClockStatus != STATUS){};
/*
#define BUS_DisableClockForUSART1 \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_USART1EN_Pos);
#define BUS_EnableClockForUSART1 \
	SetBit(RCC->APB2ENR,RCC_APB2ENR_USART1EN_Pos);\
	while(!_USART1_GetClockStatus){};
#define BUS_WaitTillEnableClockForUSART1 \
	while(!_USART1_GetClockStatus){};
*/
		
#ifdef __cplusplus
	}
#endif
		
#endif
