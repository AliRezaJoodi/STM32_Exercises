// GitHub Account: GitHub.com/AliRezaJoodi

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

#define BUS_EnableOrDisableClockForPowerInterface(STATUS) \
	WriteBit(RCC->APB1ENR,RCC_APB1ENR_PWREN_Pos,STATUS)
	//RCC->APB1ENR= (RCC->APB1ENR & ~RCC_APB1ENR_PWREN) | ((STATUS&0b1UL)<<RCC_APB1ENR_PWREN_Pos);	
#define BUS_ResetClockForPowerInterface \
	SetBit_NoLastStatus(RCC->APB1RSTR,RCC_APB1RSTR_PWRRST_Pos)
	//RCC->APB1RSTR= RCC_APB1RSTR_PWRRST;	
#define BUS_IsClockEnableForPowerInterface \
	GetBit(RCC->APB1ENR,RCC_APB1RSTR_PWRRST_Pos)
	//((RCC->APB1ENR & RCC_APB1ENR_PWREN) >> RCC_APB1ENR_PWREN_Pos)
#define BUS_WaitTillEnableClockFromPowerInterface \
	while(!BUS_IsClockEnableForPowerInterface){}
		
#define BUS_EnableOrDisableClockForAlternateFunction(STATUS) \
	WriteBit(RCC->APB2ENR,RCC_APB2ENR_AFIOEN_Pos,STATUS)
	//RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_AFIOEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_AFIOEN_Pos);
#define BUS_ResetClockForAlternateFunction \
	SetBit_NoLastStatus(RCC->APB2RSTR,RCC_APB2RSTR_AFIORST_Pos)
	//RCC->APB2RSTR= RCC_APB2RSTR_AFIORST;	
#define BUS_IsClockEnableForAlternateFunction \
	GetBit(RCC->APB2ENR,RCC_APB2ENR_AFIOEN_Pos)
	//((RCC->APB2ENR & RCC_APB2ENR_AFIOEN) >> RCC_APB2ENR_AFIOEN_Pos)
#define BUS_WaitTillEnableClockForAlternateFunction \
	while(!BUS_IsClockEnableForAlternateFunction){}
		
#define BUS_EnableOrDisableClockForPortA(STATUS) \
	WriteBit(RCC->APB2ENR,RCC_APB2ENR_IOPAEN_Pos,STATUS)
	//RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPAEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPAEN_Pos);
#define BUS_ResetClockForPortA \
	SetBit_NoLastStatus(RCC->APB2RSTR,RCC_APB2RSTR_IOPARST_Pos)
	//RCC->APB2RSTR= RCC_APB2RSTR_IOPARST;
#define BUS_IsClockEnableForPortA \
	GetBit(RCC->APB2ENR,RCC_APB2ENR_IOPAEN_Pos)
	//((RCC->APB2ENR & RCC_APB2ENR_IOPAEN) >> RCC_APB2ENR_IOPAEN_Pos)
#define BUS_WaitTillEnableClockForPortA \
	while(!BUS_IsClockEnableForPortA){}
		
#define BUS_EnableOrDisableClockForPortB(STATUS) \
	WriteBit(RCC->APB2ENR,RCC_APB2ENR_IOPBEN_Pos,STATUS)
	//RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPBEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPBEN_Pos);
#define BUS_ResetClockForPortB \
	SetBit_NoLastStatus(RCC->APB2RSTR,RCC_APB2RSTR_IOPBRST_Pos)
	//RCC->APB2RSTR= RCC_APB2RSTR_IOPBRST;	
#define BUS_IsClockEnableForPortB \
	GetBit(RCC->APB2ENR,RCC_APB2ENR_IOPBEN_Pos)
	//((RCC->APB2ENR & RCC_APB2ENR_IOPBEN) >> RCC_APB2ENR_IOPBEN_Pos)
#define BUS_WaitTillEnableClockForPortB \
	while(!BUS_IsClockEnableForPortB){}
		
#define BUS_EnableOrDisableClockForPortC(STATUS) \
	WriteBit(RCC->APB2ENR,RCC_APB2ENR_IOPCEN_Pos,STATUS)
	//RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPCEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPCEN_Pos);
#define BUS_ResetClockForPortC \
	SetBit_NoLastStatus(RCC->APB2RSTR,RCC_APB2RSTR_IOPCRST_Pos)
	//RCC->APB2RSTR= RCC_APB2RSTR_IOPCRST;
#define BUS_IsClockEnableForPortC \
	GetBit(RCC->APB2ENR,RCC_APB2ENR_IOPCEN_Pos)
	//((RCC->APB2ENR & RCC_APB2ENR_IOPCEN) >> RCC_APB2ENR_IOPCEN_Pos)
#define BUS_WaitTillEnableClockForPortC \
	while(!BUS_IsClockEnableForPortC){}
		
#define BUS_EnableOrDisableClockForPortD(STATUS) \
	WriteBit(RCC->APB2ENR,RCC_APB2ENR_IOPDEN_Pos,STATUS)
	//RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPDEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPDEN_Pos);
#define BUS_ResetClockForPortD \
	SetBit_NoLastStatus(RCC->APB2RSTR,RCC_APB2RSTR_IOPDRST_Pos)
	//RCC->APB2RSTR= RCC_APB2RSTR_IOPDRST;
#define BUS_IsClockEnableForPortD \
	GetBit(RCC->APB2ENR,RCC_APB2ENR_IOPDEN_Pos)
	//((RCC->APB2ENR & RCC_APB2ENR_IOPDEN) >> RCC_APB2ENR_IOPDEN_Pos)
#define BUS_WaitTillEnableClockForPortD \
	while(!BUS_IsClockEnableForPortD){}


#ifdef __cplusplus
}
#endif
		
#endif
