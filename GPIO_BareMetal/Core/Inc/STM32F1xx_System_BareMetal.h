// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _SYSTEM_INCLUDED
    #define _SYSTEM_INCLUDED

#ifdef __cplusplus
    extern "C" {
#endif


#define FLASH_LATENCY0	0b000U	// Zero wait state, if 0 < SYSCLK <= 24MHz
#define FLASH_LATENCY1	0b001U	// One wait state, if 24MHz < SYSCLK <= 48MHz
#define FLASH_LATENCY2	0b010U	// Two wait states, if 48MHz < SYSCLK <= 72MHz
#define ConfigureLatencyForFLASH(MODE) \
	FLASH->ACR= (FLASH->ACR & ~FLASH_ACR_LATENCY) | ((MODE&0b111U) << FLASH_ACR_LATENCY_Pos);
#define GetLatencyForFLASH \
	((FLASH->ACR & FLASH_ACR_LATENCY) >> FLASH_ACR_LATENCY_Pos)
#define WaitTillRightLatency(MODE) \
	while(GetLatencyForFLASH != MODE){}

// HCLK Clock Frequency		
#define SetDirectlySystemCoreClock(HZ) \
	SystemCoreClock = HZ;


#ifdef __cplusplus
    }
#endif

#endif
