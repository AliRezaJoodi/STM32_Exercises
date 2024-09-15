// GitHub Account: GitHub.com/AliRezaJoodi
// It's a local library

#include "utility.h"
#include "stm32f1xx_bm_system.h"
#include "stm32f1xx_bm_rcc.h"

//****************************************************
void SystemClock_Configuration(void){
	FLASH_SetLatency(LATENCY0);
	RCC_HSI_SetCalibTrimming(16);
	RCC_HSI_EnableOrDisable(1);
	RCC_SYSCLK_SetClockSource(SYSCLK_HSI);
	RCC_AHB_SetPrescaler(AHB_DIV1);
	RCC_APB1_SetPrescaler(APB1_DIV1);
	RCC_APB2_SetPrescaler(APB2_DIV1);
		
	SystemCoreClockUpdate();	
	System_SetSysTick_1ms(8000000);
	System_SetCoreClockFrequency(8000000);
}
