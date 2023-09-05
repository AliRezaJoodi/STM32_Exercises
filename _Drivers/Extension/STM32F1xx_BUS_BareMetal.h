// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx.h"

#ifndef _BUS_INCLUDED
    #define _BUS_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

		
#ifndef ENABLE
	#define ENABLE        															1
#endif

#ifndef DISABLE
	#define DISABLE        															0
#endif

#define BUS_EnableOrDisableClockForPowerInterface(STATUS) \
	RCC->APB1ENR= (RCC->APB1ENR & ~RCC_APB1ENR_PWREN) | ((STATUS&0b1UL)<<RCC_APB1ENR_PWREN_Pos);	
#define BUS_ResetClockForPowerInterface \
	RCC->APB1RSTR= RCC_APB1RSTR_PWRRST;	
#define BUS_IsEnableClockFromPowerInterface \
	((RCC->APB1ENR & RCC_APB1ENR_PWREN) >> RCC_APB1ENR_PWREN_Pos)
#define BUS_WaitTillEnableClockFromPowerInterface \
	while(!BUS_IsEnableClockFromPowerInterface){}
		
#define BUS_EnableOrDisableClockForAlternateFunction(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_AFIOEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_AFIOEN_Pos);
#define BUS_ResetClockForAlternateFunction \
	RCC->APB2RSTR= RCC_APB2RSTR_AFIORST;	
#define BUS_IsEnableClockForAlternateFunction \
	((RCC->APB2ENR & RCC_APB2ENR_AFIOEN) >> RCC_APB2ENR_AFIOEN_Pos)
#define BUS_WaitTillEnableClockForAlternateFunction \
	while(!BUS_IsEnableClockForAlternateFunction){}
		
#define BUS_EnableOrDisableClockForPortA(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPAEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPAEN_Pos);
#define BUS_ResetClockForPortA \
	RCC->APB2RSTR= RCC_APB2RSTR_IOPARST;
#define BUS_IsEnableClockForPortA \
	((RCC->APB2ENR & RCC_APB2ENR_IOPAEN) >> RCC_APB2ENR_IOPAEN_Pos)
#define BUS_WaitTillEnableClockForPortA \
	while(!BUS_IsEnableClockForPortA){}
		
#define BUS_EnableOrDisableClockForPortB(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPBEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPBEN_Pos);
#define BUS_ResetClockForPortB \
	RCC->APB2RSTR= RCC_APB2RSTR_IOPBRST;	
#define BUS_IsEnableClockForPortB \
	((RCC->APB2ENR & RCC_APB2ENR_IOPBEN) >> RCC_APB2ENR_IOPBEN_Pos)
#define BUS_WaitTillEnableClockForPortB \
	while(!BUS_IsEnableClockForPortB){}
		
#define BUS_EnableOrDisableClockForPortC(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPCEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPCEN_Pos);
#define BUS_ResetClockForPortC \
	RCC->APB2RSTR= RCC_APB2RSTR_IOPCRST;
#define BUS_IsEnableClockForPortC \
	((RCC->APB2ENR & RCC_APB2ENR_IOPCEN) >> RCC_APB2ENR_IOPCEN_Pos)
#define BUS_WaitTillEnableClockForPortC \
	while(!BUS_IsEnableClockForPortC){}
		
#define BUS_EnableOrDisableClockForPortD(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPDEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPDEN_Pos);
#define BUS_ResetClockForPortD \
	RCC->APB2RSTR= RCC_APB2RSTR_IOPDRST;
#define BUS_IsEnableClockForPortD \
	((RCC->APB2ENR & RCC_APB2ENR_IOPDEN) >> RCC_APB2ENR_IOPDEN_Pos)
#define BUS_WaitTillEnableClockForPortD \
	while(!BUS_IsEnableClockForPortD){}


#ifdef __cplusplus
}
#endif
		
#endif
