// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx.h"
#include "Utility.h"

#ifndef _SYSTEM_INCLUDED
    #define _SYSTEM_INCLUDED

#ifdef __cplusplus
	extern "C" {
#endif


#define LATENCY0	0b000	// Zero wait state, if 0 < SYSCLK <= 24MHz
#define LATENCY1	0b001	// One wait state, if 24MHz < SYSCLK <= 48MHz
#define LATENCY2	0b010	// Two wait states, if 48MHz < SYSCLK <= 72MHz
#define _GetLatency \
	Get3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos)
#define FLASH_SetLatency(MODE) \
	Write3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos, MODE);\
	while(_GetLatency != MODE){};
		
// HCLK Clock Frequency		
#define System_SetCoreClockFrequency(HZ) \
	SystemCoreClock = HZ;


#ifdef __cplusplus
	}
#endif

#endif
