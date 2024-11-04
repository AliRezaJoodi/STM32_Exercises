// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_rcc.h>

//****************************************************
void RCC_SystemClock_ConfigDefault1(void){
	FLASH_SetLatency(LATENCY0);
	
	RCC_ADC_SetPrescaler(RCC_ADC_DIV2);
	RCC_APB2_SetPrescaler(RCC_APB2_DIV1);
	RCC_APB1_SetPrescaler(RCC_APB1_DIV1);
	RCC_AHB_SetPrescaler(RCC_AHB_DIV1);
	RCC_SeystemClock_SetSource(RCC_SYSCLK_CLKSOURCE_HSI);
	RCC_HSI_SetTrimming(16);
	RCC_HSI_EnableOrDisable(1);
}

//****************************************************
void RCC_SystemClock_ConfigDefault2(void){
	FLASH_SetLatency(LATENCY2);
	
	RCC_ADC_SetPrescaler(RCC_ADC_DIV2);
	RCC_APB2_SetPrescaler(RCC_APB2_DIV1);
	RCC_APB1_SetPrescaler(RCC_APB1_DIV2);
	RCC_AHB_SetPrescaler(RCC_AHB_DIV1);
	RCC_SeystemClock_SetSource(RCC_SYSCLK_CLKSOURCE_PLL);
	RCC_PLL_SetMultiplicationFactor(RCC_PLL_MUL9);
	RCC_PLL_SetClockSource(RCC_PLL_CLKSOURCE_HSE_DIV1);
	RCC_HSE_SetClockSource(RCC_HSE_CLKSOURCE_XTAL);
	RCC_PLL_EnableOrDisable(1);
	RCC_HSE_EnableOrDisable(1);
}

//****************************************************
void RCC_RTC_ConfigDefault1(void){
	PWR_BackupDomain_EnableOrDisable(1);
	
	if(_LSE_GetClockSource() != RCC_LSE_CLKSOURCE_XTAL){
		RCC_LSE_EnableOrDisable(0);
		RCC_LSE_SetClockSource(RCC_LSE_CLKSOURCE_XTAL);
	}
	
	if(_RTC_GetClockSource() != RCC_RTC_CLKSOURCE_LSE){
		RCC_BackupDomain_ResetOrRelease(1);
		RCC_BackupDomain_ResetOrRelease(0);
		RCC_RTC_SetClockSource(RCC_RTC_CLKSOURCE_LSE);
	}
	
	RCC_LSE_EnableOrDisable(1);
	RCC_RTC_EnableOrDisable(1);
}
