// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_rcc.h>

//****************************************************
void RCC_SystemClock_ConfigDefault1(void){
	FLASH_SetLatency(LATENCY0);
	
	RCC_ADC_SetPrescaler(ADC_PCLK2_DIV2);
	RCC_APB2_SetPrescaler(APB2_HCLK_DIV1);
	RCC_APB1_SetPrescaler(APB1_HCLK_DIV1);
	RCC_AHB_SetPrescaler(AHB_SYSCLK_DIV1);
	RCC_SeystemClock_SetSource(SYSCLK_SOURCE_HSI);
	RCC_HSI_SetTrimming(16);
	RCC_HSI_EnableOrDisable(1);
}

//****************************************************
void RCC_SystemClock_ConfigDefault2(void){
	FLASH_SetLatency(LATENCY2);
	
	RCC_ADC_SetPrescaler(ADC_PCLK2_DIV2);
	RCC_APB2_SetPrescaler(APB2_HCLK_DIV1);
	RCC_APB1_SetPrescaler(APB1_HCLK_DIV2);
	RCC_AHB_SetPrescaler(AHB_SYSCLK_DIV1);
	RCC_SeystemClock_SetSource(SYSCLK_SOURCE_PLL);
	RCC_PLL_SetMultiplicationFactor(PLL_MUL_9);
	RCC_PLL_SetClockSource(PLL_CLKSOURCE_HSE_DIV1);
	RCC_HSE_SetClockSource(HSE_CLKSOURCE_XTAL);
	RCC_PLL_EnableOrDisable(1);
	RCC_HSE_EnableOrDisable(1);
}

//****************************************************
void RCC_RTC_ConfigDefault1(void){
	PWR_BackupDomain_EnableOrDisable(1);
	
	if(_LSE_GetClockSource() != LSE_CLKSOURCE_XTAL){
		RCC_LSE_EnableOrDisable(0);
		RCC_LSE_SetClockSource(LSE_CLKSOURCE_XTAL);
	}
	
	if(_RTC_GetClockSource() != RTC_CLKSOURCE_LSE){
		RCC_BackupDomain_ResetOrRelease(1);
		RCC_BackupDomain_ResetOrRelease(0);
		RCC_RTC_SetClockSource(RTC_CLKSOURCE_LSE);
	}
	
	RCC_LSE_EnableOrDisable(1);
	RCC_RTC_EnableOrDisable(1);
}
