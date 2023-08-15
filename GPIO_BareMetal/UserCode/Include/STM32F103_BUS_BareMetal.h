// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _BUS_INCLUDED
    #define _BUS_INCLUDED
		
#ifndef ENABLE
	#define ENABLE        															1
#endif

#ifndef DISABLE
	#define DISABLE        															0
#endif

#define EnableOrDisableClockSourceForPowerInterface(STATUS) \
	RCC->APB1ENR= (RCC->APB1ENR & ~RCC_APB1ENR_PWREN) | ((STATUS&0b1UL)<<RCC_APB1ENR_PWREN_Pos);	
#define ResetClockSourceForPowerInterface \
	RCC->APB1RSTR= RCC_APB1RSTR_PWRRST;	
#define IsEnableClockSourceFromPowerInterface \
	((RCC->APB1ENR & RCC_APB1ENR_PWREN) >> RCC_APB1ENR_PWREN_Pos)
	
#define EnableOrDisableClockSourceForAlternateFunction(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_AFIOEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_AFIOEN_Pos);
#define ResetClockSourceForAlternateFunction \
	RCC->APB2RSTR= RCC_APB2RSTR_AFIORST;	
#define IsEnableClockSourceForAlternateFunction \
	((RCC->APB2ENR & RCC_APB2ENR_AFIOEN) >> RCC_APB2ENR_AFIOEN_Pos)
	
#define EnableOrDisableClockSourceFromPortA(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPAEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPAEN_Pos);
#define ResetClockSourceFromPortA \
	RCC->APB2RSTR= RCC_APB2RSTR_IOPARST;
#define IsEnableClockSourceFromPortA \
	((RCC->APB2ENR & RCC_APB2ENR_IOPAEN) >> RCC_APB2ENR_IOPAEN_Pos)
	
#define EnableOrDisableClockSourceForPortB(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPBEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPBEN_Pos);
#define ResetClockSourceForPortB \
	RCC->APB2RSTR= RCC_APB2RSTR_IOPBRST;	
#define IsEnableClockSourceForPortB \
	((RCC->APB2ENR & RCC_APB2ENR_IOPBEN) >> RCC_APB2ENR_IOPBEN_Pos)
	
#define EnableOrDisableClockSourceForPortC(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPCEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPCEN_Pos);
#define ResetClockSourceForPortC \
	RCC->APB2RSTR= RCC_APB2RSTR_IOPCRST;
#define IsEnableClockSourceForPortC \
	((RCC->APB2ENR & RCC_APB2ENR_IOPCEN) >> RCC_APB2ENR_IOPCEN_Pos)

#define EnableOrDisableClockSourceForPortD(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPDEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPDEN_Pos);
#define ResetClockSourceForPortD \
	RCC->APB2RSTR= RCC_APB2RSTR_IOPDRST;
#define IsEnableClockSourceForPortD \
	((RCC->APB2ENR & RCC_APB2ENR_IOPDEN) >> RCC_APB2ENR_IOPDEN_Pos)
		
#endif
