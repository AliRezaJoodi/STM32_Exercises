// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_gpio.h>

//******************************************************************************
void GPIO_OutputWithPushPullMode_ConfigPin(GPIO_TypeDef *GPIOx, uint8_t pin){
	GPIO_OutputOrInputMode_SetMode(GPIOx, pin, GPIO_OUTPUT);
	GPIO_OutputMode_SetOutputType(GPIOx, pin, GPIO_OUTPUT_GP_PUSHPULL);
}

//******************************************************************************
void GPIO_OutputWithOpenDrainMode_ConfigPin(GPIO_TypeDef *GPIOx, uint8_t pin){
	GPIO_OutputOrInputMode_SetMode(GPIOx, pin, GPIO_OUTPUT);
	GPIO_OutputMode_SetOutputType(GPIOx, pin, GPIO_OUTPUT_GP_OPENDRAIN);
}

//******************************************************************************
void GPIO_InputWithPullUpMode_ConfigPin(GPIO_TypeDef *GPIOx, uint8_t pin){
	GPIO_OutputOrInputMode_SetMode(GPIOx,pin, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOx,pin, GPIO_INPUT_PULLUP);
}

//******************************************************************************
void GPIO_InputWithPullDownMode_ConfigPin(GPIO_TypeDef *GPIOx, uint8_t pin){
	GPIO_OutputOrInputMode_SetMode(GPIOx,pin, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOx,pin, GPIO_INPUT_PULLDOWN);	
}

//******************************************************************************
void GPIO_InputWithFloatingMode_ConfigPin(GPIO_TypeDef *GPIOx, uint8_t pin){
	GPIO_OutputOrInputMode_SetMode(GPIOx,pin, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOx,pin, GPIO_INPUT_FLOATING);	
}