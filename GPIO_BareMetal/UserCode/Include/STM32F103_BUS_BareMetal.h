// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _BUS_INCLUDED
    #define _BUS_INCLUDED
		
#ifndef ENABLE
	#define ENABLE        															1
#endif

#ifndef DISABLE
	#define DISABLE        															0
#endif

#define EnableClockSourceFromPowerInterface(STATUS) \
	RCC->APB1ENR= (RCC->APB1ENR & ~RCC_APB1ENR_PWREN) | ((STATUS&0b1UL)<<RCC_APB1ENR_PWREN_Pos);	
#define IsEnableClockSourceFromPowerInterface \
	((RCC->APB1ENR & RCC_APB1ENR_PWREN) >> RCC_APB1ENR_PWREN_Pos)
	
#define EnableClockSourceFromAlternateFunction(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_AFIOEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_AFIOEN_Pos);																											
#define IsEnableClockSourceFromAlternateFunction \
	((RCC->APB2ENR & RCC_APB2ENR_AFIOEN) >> RCC_APB2ENR_AFIOEN_Pos)
	
#define EnableClockSourceFromPortA(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPAEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPAEN_Pos);
#define IsEnableClockSourceFromPortA \
	((RCC->APB2ENR & RCC_APB2ENR_IOPAEN) >> RCC_APB2ENR_IOPAEN_Pos)
	
#define EnableClockSourceFromPortB(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPBEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPBEN_Pos);																											
#define IsEnableClockSourceFromPortB \
	((RCC->APB2ENR & RCC_APB2ENR_IOPBEN) >> RCC_APB2ENR_IOPBEN_Pos)
	
#define EnableClockSourceFromPortC(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPCEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPCEN_Pos);
#define IsEnableClockSourceFromPortC \
	((RCC->APB2ENR & RCC_APB2ENR_IOPCEN) >> RCC_APB2ENR_IOPCEN_Pos)

#define EnableClockSourceFromPortD(STATUS) \
	RCC->APB2ENR= (RCC->APB2ENR & ~RCC_APB2ENR_IOPDEN) | ((STATUS&0b1UL)<<RCC_APB2ENR_IOPDEN_Pos);
#define IsEnableClockSourceFromPortD \
	((RCC->APB2ENR & RCC_APB2ENR_IOPDEN) >> RCC_APB2ENR_IOPDEN_Pos)
		
#endif
