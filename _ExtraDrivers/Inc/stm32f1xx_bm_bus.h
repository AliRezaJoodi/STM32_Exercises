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

#define BUS_PWR_ResetClock \
	SetBit_NoLastStatus(RCC->APB1RSTR, RCC_APB1RSTR_PWRRST_Pos)
#define _PWR_GeEnableStatus \
	GetBit(RCC->APB1ENR, RCC_APB1RSTR_PWRRST_Pos)
#define BUS_PWR_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos, STATUS);\
	while(_PWR_GeEnableStatus != STATUS){};
	
#define BUS_AFIO_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_AFIORST_Pos)	
#define _AFIO_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos)
#define BUS_AFIO_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_AFIOEN_Pos, STATUS);\
	while(_AFIO_GeEnableStatus != STATUS){};
		
#define BUS_GPIOA_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPARST_Pos);
#define _GPIOA_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos)
#define BUS_GPIOA_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPAEN_Pos, STATUS);\
	while(_GPIOA_GeEnableStatus != STATUS){};
		
#define BUS_GPIOB_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPBRST_Pos);	
#define _GPIOB_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos)
#define BUS_GPIOB_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPBEN_Pos, STATUS);\
	while(_GPIOB_GeEnableStatus != STATUS){};
		
#define BUS_GPIOC_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPCRST_Pos);
#define _GPIOC_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos)
#define BUS_GPIOC_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPCEN_Pos, STATUS);\
	while(_GPIOC_GeEnableStatus != STATUS){};
		
#define BUS_GPIOD_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_IOPDRST_Pos);
#define _GPIOD_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos)
#define BUS_GPIOD_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_IOPDEN_Pos, STATUS);\
	while(_GPIOD_GeEnableStatus != STATUS){};
		
#define BUS_USART1_ResetClock \
	SetBit_NoLastStatus(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST_Pos)
#define _USART1_GeEnableStatus \
	GetBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos)
#define BUS_USART1_EnableOrDisable(STATUS) \
	WriteBit(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos, STATUS);\
	while(_USART1_GeEnableStatus != STATUS){};
		
#ifdef __cplusplus
}
#endif
		
#endif	// _STM32F1xx_BM_BUS_INCLUDED
