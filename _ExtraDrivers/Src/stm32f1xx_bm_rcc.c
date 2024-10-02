// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_rcc.h>

//****************************************************
void RCC_SystemClock_ConfigDefault1(void){
	FLASH_SetLatency(LATENCY0);
	RCC_HSI_SetCalibTrimming(16);
	RCC_HSI_EnableOrDisable(1);
	RCC_SYSCLK_SetClockSource(SYSCLK_HSI);
	RCC_AHB_SetPrescaler(AHB_DIV1);
	RCC_APB1_SetPrescaler(APB1_DIV1);
	RCC_APB2_SetPrescaler(APB2_DIV1);
		
	SystemCoreClockUpdate();	
	System_SetCoreClockFrequency(8000000);
}
