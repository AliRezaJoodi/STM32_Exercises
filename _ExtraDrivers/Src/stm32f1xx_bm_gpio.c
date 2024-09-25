// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_gpio.h>

//******************************************************************************
void GPIO_ConfigPinForPushPullOutputMode(GPIO_TypeDef *GPIOx, uint32_t PIN){
	GPIO_SetInputOrOutputMode(GPIOx, PIN, IO_OUTPUT);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOx, PIN, OUTPUT_GP);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOx, PIN, OUTPUT_PUSHPULL);
}

//******************************************************************************
void GPIO_ConfigPinForOpenDrainOutputMode(GPIO_TypeDef *GPIOx, uint32_t PIN){
	GPIO_SetInputOrOutputMode(GPIOx, PIN, IO_OUTPUT);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOx, PIN, OUTPUT_GP);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOx, PIN, OUTPUT_OPENDRAIN);	
}

//******************************************************************************
void GPIO_ConfigPinForPullUpInputMode(GPIO_TypeDef *GPIOx, uint32_t PIN){
	GPIO_SetInputOrOutputMode(GPIOx,PIN, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOx,PIN, INPUT_PULL);
	GPIO_InInputModeWithPull_SetPullUpOrPullDown(GPIOx,PIN, PULL_PULLUP);	
}

//******************************************************************************
void GPIO_ConfigPinForPullDownInputMode(GPIO_TypeDef *GPIOx, uint32_t PIN){
	GPIO_SetInputOrOutputMode(GPIOx,PIN, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOx,PIN, INPUT_PULL);
	GPIO_InInputModeWithPull_SetPullUpOrPullDown(GPIOx,PIN, PULL_PULLDOWN);	
}

//******************************************************************************
void GPIO_ConfigPinForFloatingInputMode(GPIO_TypeDef *GPIOx, uint32_t PIN){
	GPIO_SetInputOrOutputMode(GPIOx,PIN, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOx,PIN, INPUT_FLOATING);	
}