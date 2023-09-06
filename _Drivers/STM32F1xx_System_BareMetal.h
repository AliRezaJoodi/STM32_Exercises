// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx.h"
#include "Utility.h"

#ifndef _SYSTEM_INCLUDED
    #define _SYSTEM_INCLUDED

#ifdef __cplusplus
    extern "C" {
#endif


#define FLASH_LATENCY0	0b000U	// Zero wait state, if 0 < SYSCLK <= 24MHz
#define FLASH_LATENCY1	0b001U	// One wait state, if 24MHz < SYSCLK <= 48MHz
#define FLASH_LATENCY2	0b010U	// Two wait states, if 48MHz < SYSCLK <= 72MHz
#define FLASH_ConfigureLatency(MODE) \
	Write3Bit(FLASH->ACR,FLASH_ACR_LATENCY_Pos,MODE)
	//FLASH->ACR= (FLASH->ACR & ~FLASH_ACR_LATENCY) | ((MODE&0b111U) << FLASH_ACR_LATENCY_Pos);
#define FLASH_GetLatency \
	Get3Bit(FLASH->ACR,FLASH_ACR_LATENCY_Pos)
	//((FLASH->ACR & FLASH_ACR_LATENCY) >> FLASH_ACR_LATENCY_Pos)
#define FLASH_WaitTillRightLatency(MODE) \
	while(FLASH_GetLatency != MODE){}

// HCLK Clock Frequency		
#define SetDirectlySystemCoreClock(HZ) \
	SystemCoreClock= HZ;


#ifdef __cplusplus
    }
#endif

#endif
