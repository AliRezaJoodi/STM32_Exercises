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

/*		
#ifndef ENABLE
	#define ENABLE		1
	#define DISABLE		!ENABLE
#endif
*/

#define BUS_ResetClockForPWR \
	SetBit_NoLastStatus(RCC->APB1RSTR,RCC_APB1RSTR_PWRRST_Pos)
#define BUS_GetClockStatusOfPWR \
	GetBit(RCC->APB1ENR,RCC_APB1RSTR_PWRRST_Pos)
#define BUS_DisableClockForPWR \
	ClearBit(RCC->APB1ENR,RCC_APB1ENR_PWREN_Pos);
#define BUS_EnableClockForPWR \
	SetBit(RCC->APB1ENR,RCC_APB1ENR_PWREN_Pos);\
	while(!BUS_GetClockStatusOfPWR){};
/*
#define BUS_WaitTillEnableClockForPWR \
	while(!BUS_GetClockStatusOfPWR){};
#define BUS_EnableOrDisableClockForPWR(STATUS) \
	WriteBit(RCC->APB1ENR,RCC_APB1ENR_PWREN_Pos,STATUS);
*/
		
#define BUS_ResetClockForAFIO \
	SetBit_NoLastStatus(RCC->APB2RSTR,RCC_APB2RSTR_AFIORST_Pos)	
#define BUS_GetClockStatusOfAFIO \
	GetBit(RCC->APB2ENR,RCC_APB2ENR_AFIOEN_Pos)
#define BUS_DisableClockForAFIO \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_AFIOEN_Pos);
#define BUS_EnableClockForAFIO \
	SetBit(RCC->APB2ENR,RCC_APB2ENR_AFIOEN_Pos);\
	while(!BUS_GetClockStatusOfAFIO){};
/*
#define BUS_WaitTillEnableClockForAFIO \
	while(!BUS_GetClockStatusOfAFIO){};
#define BUS_EnableOrDisableClockForAFIO(STATUS) \
	WriteBit(RCC->APB2ENR,RCC_APB2ENR_AFIOEN_Pos,STATUS);
*/
		
#define BUS_ResetClockForPortA \
	SetBit_NoLastStatus(RCC->APB2RSTR,RCC_APB2RSTR_IOPARST_Pos);
	//RCC->APB2RSTR= RCC_APB2RSTR_IOPARST;
#define BUS_GetClockStatusOfPortA \
	GetBit(RCC->APB2ENR,RCC_APB2ENR_IOPAEN_Pos)
	//((RCC->APB2ENR & RCC_APB2ENR_IOPAEN) >> RCC_APB2ENR_IOPAEN_Pos)
#define BUS_DisableClockForPortA \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_IOPAEN_Pos);
#define BUS_EnableClockForPortA \
	SetBit(RCC->APB2ENR,RCC_APB2ENR_IOPAEN_Pos);\
	while(!BUS_GetClockStatusOfPortA){};
/*
#define BUS_WaitTillEnableClockForPortA \
	while(!BUS_GetClockStatusOfPortA){};
#define BUS_EnableOrDisableClockForPortA(STATUS) \
	WriteBit(RCC->APB2ENR,RCC_APB2ENR_IOPAEN_Pos,STATUS);
	//RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPAEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPAEN_Pos);
*/
		
#define BUS_ResetClockForPortB \
	SetBit_NoLastStatus(RCC->APB2RSTR,RCC_APB2RSTR_IOPBRST_Pos);
	//RCC->APB2RSTR= RCC_APB2RSTR_IOPBRST;	
#define BUS_GetClockStatusOfPortB \
	GetBit(RCC->APB2ENR,RCC_APB2ENR_IOPBEN_Pos)
	//((RCC->APB2ENR & RCC_APB2ENR_IOPBEN) >> RCC_APB2ENR_IOPBEN_Pos)
#define BUS_DisableClockForPortB \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_IOPBEN_Pos);
#define BUS_EnableClockForPortB \
	SetBit(RCC->APB2ENR,RCC_APB2ENR_IOPBEN_Pos);\
	while(!BUS_GetClockStatusOfPortB){};
/*
#define BUS_WaitTillEnableClockForPortB \
	while(!BUS_GetClockStatusOfPortB){};
#define BUS_EnableOrDisableClockForPortB(STATUS) \
	WriteBit(RCC->APB2ENR,RCC_APB2ENR_IOPBEN_Pos,STATUS);
	//RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPBEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPBEN_Pos);
*/
		
#define BUS_ResetClockForPortC \
	SetBit_NoLastStatus(RCC->APB2RSTR,RCC_APB2RSTR_IOPCRST_Pos);
	//RCC->APB2RSTR= RCC_APB2RSTR_IOPCRST;
#define BUS_GetClockStatusOfPortC \
	GetBit(RCC->APB2ENR,RCC_APB2ENR_IOPCEN_Pos)
	//((RCC->APB2ENR & RCC_APB2ENR_IOPCEN) >> RCC_APB2ENR_IOPCEN_Pos)
#define BUS_DisableClockForPortC \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_IOPCEN_Pos);
#define BUS_EnableClockForPortC\
	SetBit(RCC->APB2ENR,RCC_APB2ENR_IOPCEN_Pos);\
	while(!BUS_GetClockStatusOfPortC){};
/*
#define BUS_WaitTillEnableClockForPortC \
	while(!BUS_GetClockStatusOfPortC){};
#define BUS_EnableOrDisableClockForPortC(STATUS) \
	WriteBit(RCC->APB2ENR,RCC_APB2ENR_IOPCEN_Pos,STATUS);
	//RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPCEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPCEN_Pos);
*/
		
#define BUS_ResetClockForPortD \
	SetBit_NoLastStatus(RCC->APB2RSTR,RCC_APB2RSTR_IOPDRST_Pos);
	//RCC->APB2RSTR= RCC_APB2RSTR_IOPDRST;
#define BUS_GetClockStatusOfPortD \
	GetBit(RCC->APB2ENR,RCC_APB2ENR_IOPDEN_Pos)
	//((RCC->APB2ENR & RCC_APB2ENR_IOPDEN) >> RCC_APB2ENR_IOPDEN_Pos)
#define BUS_DisableClockForPortD \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_IOPDEN_Pos);
#define BUS_EnableClockForPortD \
	SetBit(RCC->APB2ENR,RCC_APB2ENR_IOPDEN_Pos);\
	while(!BUS_GetClockStatusOfPortD){};
/*
#define BUS_WaitTillEnableClockForPortD \
	while(!BUS_GetClockStatusOfPortD){};
#define BUS_EnableOrDisableClockForPortD(STATUS) \
	WriteBit(RCC->APB2ENR,RCC_APB2ENR_IOPDEN_Pos,STATUS);
	//RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPDEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPDEN_Pos);
*/
		
#define BUS_ResetClockForUSART1 \
	SetBit_NoLastStatus(RCC->APB2RSTR,RCC_APB2RSTR_USART1RST_Pos)
#define BUS_GetClockStatusOfUSART1 \
	GetBit(RCC->APB2ENR,RCC_APB2ENR_USART1EN_Pos)
#define BUS_DisableClockForUSART1 \
	ClearBit(RCC->APB2ENR,RCC_APB2ENR_USART1EN_Pos);
#define BUS_EnableClockForUSART1 \
	SetBit(RCC->APB2ENR,RCC_APB2ENR_USART1EN_Pos);\
	while(!BUS_GetClockStatusOfUSART1){};
/*
#define BUS_WaitTillEnableClockForUSART1 \
	while(!BUS_GetClockStatusOfUSART1){};
#define BUS_EnableOrDisableClockForUSART1(STATUS) \
	WriteBit(RCC->APB2ENR,RCC_APB2ENR_USART1EN_Pos,STATUS);
*/

#ifdef __cplusplus
}
#endif
		
#endif
