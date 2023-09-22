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
/*
#define FLASH_WaitTillRightLatency(MODE) \
	while(_GetLatency != MODE){}
#define FLASH_ConfigureLatency0 \
	Write3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos, LATENCY0);\
	while(_GetLatency != LATENCY0){};
#define FLASH_ConfigureLatency1 \
	Write3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos, LATENCY1);\
	while(_GetLatency != LATENCY1){};
#define FLASH_ConfigureLatency2 \
	Write3Bit(FLASH->ACR, FLASH_ACR_LATENCY_Pos, LATENCY2);\
	while(_GetLatency != LATENCY2){};
*/
		
// HCLK Clock Frequency		
#define System_SetCoreClockFrequency(HZ) \
	SystemCoreClock = HZ;


#ifdef __cplusplus
	}
#endif

#endif
