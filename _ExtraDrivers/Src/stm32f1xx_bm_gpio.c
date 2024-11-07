// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_gpio.h>

//******************************************************************************
void GPIO_ConfigPinForPushPullOutputMode(GPIO_TypeDef *GPIOx, uint8_t pin){
	GPIO_SetInputOrOutputMode(GPIOx, pin, IO_OUTPUT);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOx, pin, OUTPUT_GP);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOx, pin, OUTPUT_PUSHPULL);
}

//******************************************************************************
void GPIO_ConfigPinForOpenDrainOutputMode(GPIO_TypeDef *GPIOx, uint8_t pin){
	GPIO_SetInputOrOutputMode(GPIOx, pin, IO_OUTPUT);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOx, pin, OUTPUT_GP);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOx, pin, OUTPUT_OPENDRAIN);	
}

//******************************************************************************
void GPIO_ConfigPinForPullUpInputMode(GPIO_TypeDef *GPIOx, uint8_t pin){
	GPIO_SetInputOrOutputMode(GPIOx,pin, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOx,pin, INPUT_PULL);
	GPIO_InInputModeWithPull_SetPullUpOrPullDown(GPIOx,pin, PULL_PULLUP);	
}

//******************************************************************************
void GPIO_ConfigPinForPullDownInputMode(GPIO_TypeDef *GPIOx, uint8_t pin){
	GPIO_SetInputOrOutputMode(GPIOx,pin, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOx,pin, INPUT_PULL);
	GPIO_InInputModeWithPull_SetPullUpOrPullDown(GPIOx,pin, PULL_PULLDOWN);	
}

//******************************************************************************
void GPIO_ConfigPinForFloatingInputMode(GPIO_TypeDef *GPIOx, uint8_t pin){
	GPIO_SetInputOrOutputMode(GPIOx,pin, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOx,pin, INPUT_FLOATING);	
}