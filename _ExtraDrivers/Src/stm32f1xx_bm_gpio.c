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

//******************************************************************************
void GPIO_ADC_ConfigCh(uint8_t ch){
	switch(ch){
		case 0:
			if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOA, 0, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOA, 0, GPIO_INPUT_ANALOG);
			break;
		case 1:
			if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOA, 1, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOA, 1, GPIO_INPUT_ANALOG);
			break;
    case 2:
			if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOA, 2, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOA, 2, GPIO_INPUT_ANALOG);
			break;
		case 3:
			if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOA, 3, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOA, 3, GPIO_INPUT_ANALOG);
			break;
		case 4:
			if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOA, 4, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOA, 4, GPIO_INPUT_ANALOG);
			break;
		case 5:
			if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOA, 5, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOA, 5, GPIO_INPUT_ANALOG);
			break;
		case 6:
			if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOA, 6, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOA, 6, GPIO_INPUT_ANALOG);
			break;
		case 7:
			if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOA, 7, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOA, 7, GPIO_INPUT_ANALOG);
			break;
		case 8:
			if(BUS_GPIOB_GetEnableStatus() == 0){BUS_GPIOB_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOB, 0, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOB, 0, GPIO_INPUT_ANALOG);
			break;
		case 9:
			if(BUS_GPIOB_GetEnableStatus() == 0){BUS_GPIOB_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOB, 1, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOB, 1, GPIO_INPUT_ANALOG);
			break;
		case 10:
			if(BUS_GPIOC_GetEnableStatus() == 0){BUS_GPIOC_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOC, 0, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOC, 0, GPIO_INPUT_ANALOG);
			break;
		case 11:
			if(BUS_GPIOC_GetEnableStatus() == 0){BUS_GPIOC_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOC, 1, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOC, 1, GPIO_INPUT_ANALOG);
			break;
		case 12:
			if(BUS_GPIOC_GetEnableStatus() == 0){BUS_GPIOC_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOC, 2, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOC, 2, GPIO_INPUT_ANALOG);
			break;
		case 13:
			if(BUS_GPIOC_GetEnableStatus() == 0){BUS_GPIOC_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOC, 3, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOC, 3, GPIO_INPUT_ANALOG);
			break;
		case 14:
			if(BUS_GPIOC_GetEnableStatus() == 0){BUS_GPIOC_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOC, 4, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOC, 4, GPIO_INPUT_ANALOG);
			break;
		case 15:
			if(BUS_GPIOC_GetEnableStatus() == 0){BUS_GPIOC_EnableOrDisable(1);}
			GPIO_OutputOrInputMode_SetMode(GPIOC, 5, GPIO_INPUT);
			GPIO_InputMode_SetInputType(GPIOC, 5, GPIO_INPUT_ANALOG);
			break;
		default:
			break;
  }
}

//******************************************************************************
void GPIO_USART1_ConfigTxPin(void){
	if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
	GPIO_OutputOrInputMode_SetMode(GPIOA,9, GPIO_OUTPUT_50MHz);
	GPIO_OutputMode_SetOutputType(GPIOA,9, GPIO_OUTPUT_AF_PUSHPULL);	
}

//******************************************************************************
void GPIO_USART1_ConfigRxPin(void){
	if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
	GPIO_OutputOrInputMode_SetMode(GPIOA,10, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,10, GPIO_INPUT_FLOATING);	
}

//******************************************************************************
void GPIO_USART2_ConfigTxPin(void){
	if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
	GPIO_OutputOrInputMode_SetMode(GPIOA,2, GPIO_OUTPUT_50MHz);
	GPIO_OutputMode_SetOutputType(GPIOA,2, GPIO_OUTPUT_AF_PUSHPULL);
}

//******************************************************************************
void GPIO_USART2_ConfigRxPin(void){
	if(BUS_GPIOA_GetEnableStatus() == 0){BUS_GPIOA_EnableOrDisable(1);}
	GPIO_OutputOrInputMode_SetMode(GPIOA,3, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,3, GPIO_INPUT_FLOATING);
}

//******************************************************************************
void GPIO_USART3_ConfigTxPin(void){
	if(BUS_GPIOB_GetEnableStatus() == 0){BUS_GPIOB_EnableOrDisable(1);}
	GPIO_OutputOrInputMode_SetMode(GPIOB,10, GPIO_OUTPUT_50MHz);
	GPIO_OutputMode_SetOutputType(GPIOB,10, GPIO_OUTPUT_AF_PUSHPULL);
}

//******************************************************************************
void GPIO_USART3_ConfigRxPin(void){
	if(BUS_GPIOB_GetEnableStatus() == 0){BUS_GPIOB_EnableOrDisable(1);}
	GPIO_OutputOrInputMode_SetMode(GPIOB,11, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOB,11, GPIO_INPUT_FLOATING);
}