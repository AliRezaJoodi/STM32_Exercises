// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_rcc.h>

//****************************************************
void RCC_SystemClock_ConfigDefault1(void){
	FLASH_SetLatency(LATENCY0);
	
	RCC_HSI_EnableOrDisable(0);
	RCC_HSI_SetCalibTrimming(16);
	
	RCC_AHB_SetPrescaler(AHB_DIV1);
	RCC_APB1_SetPrescaler(APB1_DIV1);
	RCC_APB2_SetPrescaler(APB2_DIV1);
	RCC_SYSCLK_SetClockSource(SYSTEM_CLKSOURCE_HSI);
	
	RCC_HSI_EnableOrDisable(1);
	///SystemCoreClockUpdate();	
	///System_SetCoreClockFrequency(8000000);
}

//****************************************************
void RCC_SystemClock_ConfigDefault2(void){
	FLASH_SetLatency(LATENCY2);
	
	RCC_HSE_EnableOrDisable(0);
	RCC_HSE_SetClockSource(HSE_CLKSOURCE_XTAL);
	RCC_HSE_EnableOrDisable(1);
	
	RCC_PLL_EnableOrDisable(0);
	RCC_PLL_SetClockSource(PLL_CLKSOURCE_HSE_DIV1);
	RCC_PLL_SetMultiplicationFactor(PLL_MUL_9);
	RCC_PLL_EnableOrDisable(1);
	
	RCC_AHB_SetPrescaler(AHB_DIV1);
	RCC_APB1_SetPrescaler(APB1_DIV2);
	RCC_APB2_SetPrescaler(APB2_DIV1);
	RCC_SYSCLK_SetClockSource(SYSTEM_CLKSOURCE_PLL);
}

//****************************************************
void RCC_RTC_ConfigDefault1(void){
	PWR_BackupDomain_EnableOrDisable(1);
	
	RCC_LSE_EnableOrDisable(0);
	RCC_LSE_SetClockSource(LSE_CLKSOURCE_XTAL);
	
	RCC_BackupDomain_Reset();
	RCC_RTC_SetClockSource(RTC_CLKSOURCE_LSE);
	
	RCC_LSE_EnableOrDisable(1);
	//RCC_LSI_EnableOrDisable(0);
	RCC_RTC_EnableOrDisable(1);
}
