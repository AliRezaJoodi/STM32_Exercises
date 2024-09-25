// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_bus.h>

void BUS_GPIOx_EnableOrDisableWithAutoSearch(GPIO_TypeDef *GPIOx){
	static char status=0b0000;
	
	if(GPIOx==GPIOA && GetBit(status,0)==0){
		BUS_GPIOA_EnableOrDisable(1);
		SetBit(status,0);
	}
	else if(GPIOx==GPIOB && GetBit(status,1)==0){
		BUS_GPIOB_EnableOrDisable(1);
		SetBit(status,1);
	}
	else if(GPIOx==GPIOC && GetBit(status,2)==0){
		BUS_GPIOC_EnableOrDisable(1);
		SetBit(status,2);
	}
	else if(GPIOx==GPIOD && GetBit(status,3)==0){
		BUS_GPIOD_EnableOrDisable(1);
		SetBit(status,3);
	}	
}