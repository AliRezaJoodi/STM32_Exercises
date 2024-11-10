// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_bus.h>

void BUS_GPIOx_EnableOrDisableWithAutoSearch(GPIO_TypeDef *GPIOx){		
	if(GPIOx==GPIOA && BUS_GPIOA_GetEnableStatus()==0){
		BUS_GPIOA_EnableOrDisable(1);
	}
	else if(GPIOx==GPIOB && BUS_GPIOB_GetEnableStatus()==0){
		BUS_GPIOB_EnableOrDisable(1);
	}
	else if(GPIOx==GPIOC && BUS_GPIOC_GetEnableStatus()==0){
		BUS_GPIOC_EnableOrDisable(1);
	}
	else if(GPIOx==GPIOD && BUS_GPIOD_GetEnableStatus()==0){
		BUS_GPIOD_EnableOrDisable(1);
	}	
}