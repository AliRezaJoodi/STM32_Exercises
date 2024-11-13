// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_bus.h>

//******************************************************************************
void BUS_GPIOx_EnableOrDisable(GPIO_TypeDef *GPIOx, uint8_t status){		
	if(GPIOx==GPIOA && BUS_GPIOA_GetEnableStatus()==0){
		BUS_GPIOA_EnableOrDisable(status);
	}
	else if(GPIOx==GPIOB && BUS_GPIOB_GetEnableStatus()==0){
		BUS_GPIOB_EnableOrDisable(status);
	}
	else if(GPIOx==GPIOC && BUS_GPIOC_GetEnableStatus()==0){
		BUS_GPIOC_EnableOrDisable(status);
	}
	else if(GPIOx==GPIOD && BUS_GPIOD_GetEnableStatus()==0){
		BUS_GPIOD_EnableOrDisable(status);
	}	
}

//******************************************************************************
void BUS_ADCx_EnableOrDisable(ADC_TypeDef *ADCx, uint8_t status){
	if(ADCx==ADC1 && BUS_ADC1_GetEnableStatus()==0){
		BUS_ADC1_EnableOrDisable(status);
	}
	else if(ADCx==ADC2 && BUS_ADC2_GetEnableStatus()==0){
		BUS_ADC2_EnableOrDisable(status);
	}
}
