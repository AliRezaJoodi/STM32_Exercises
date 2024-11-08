// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_usart.h>

//******************************************************************
void USART_ClearString(char *str){
  while(*str != 0){
		*str=0;
    ++str;
  }
}

//******************************************************************
void USART_PutChar(USART_TypeDef *USARTx, uint16_t data){
	while(!USART_TX_GetEmptyFlag(USARTx)){};	
	USART_TransmitData_8Bits(USARTx, data);
	while(!USART_TX_GeCompleteFlag(USARTx)){};
}

//******************************************************************
void USART_PutString(USART_TypeDef *USARTx, char *str){
  while(*str != 0){
		while(!USART_TX_GetEmptyFlag(USARTx)){};
		USART_TransmitData_8Bits(USARTx, *str);	
    ++str;
  }
	
	while(!USART_TX_GetEmptyFlag(USARTx)){};
	USART_TransmitData_8Bits(USARTx, '\r');	
	while(!USART_TX_GetEmptyFlag(USARTx)){};
	USART_TransmitData_8Bits(USARTx, '\n');
		
	while(!USART_TX_GeCompleteFlag(USARTx)){};
}

//******************************************************************
void USART_PutStringFromFlash(USART_TypeDef *USARTx, const char *str){
  while(*str != 0){
		while(!USART_TX_GetEmptyFlag(USARTx)){};
		USART_TransmitData_8Bits(USARTx, *str);
    ++str;
  }
	
	while(!USART_TX_GetEmptyFlag(USARTx)){};
	USART_TransmitData_8Bits(USARTx, '\r');	
	while(!USART_TX_GetEmptyFlag(USARTx)){};
	USART_TransmitData_8Bits(USARTx, '\n');
		
	while(!USART_TX_GeCompleteFlag(USARTx)){};
}


/*
USART1
	TX Pin:	PA9
	RX Pin: PA10
	RX INT:	Enable
	Baud Rate: 9600
*/
//****************************************************
void USART1_ConfigDefault1(void){
	BUS_USART1_EnableOrDisable(1);
	
	BUS_GPIOA_EnableOrDisable(1);	
	GPIO_OutputOrInputMode_SetMode(GPIOA,9, GPIO_OUTPUT_50MHz);
	GPIO_OutputMode_SetOutputType(GPIOA,9, GPIO_OUTPUT_AF_PUSHPULL);
	GPIO_OutputOrInputMode_SetMode(GPIOA,10, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,10, GPIO_INPUT_FLOATING);
	
	USART_SetBaudRate(USART1, PCLK2_VALUE, 9600);
	USART_SetMode(USART1, MODE_ASYNCRON);
	USART_SetDataBits(USART1, DATABITS_8BITS);
	USART_SetParity(USART1, PARITY_NONE);
	USART_SetStopBits(USART1, STOPBITS_1);
	USART_TX_EnableOrDisable(USART1, 1);
	USART_TX_INT_EnableOrDisable(USART1, 0);
	USART_RX_EnableOrDisable(USART1, 1);
	USART_RX_INT_EnableOrDisable(USART1, 1);
	USART_CTS_EnableOrDisable(USART1, 0);
	USART_CTS_INT_EnableOrDisable(USART1, 0);
	USART_RTS_EnableOrDisable(USART1, 0);
	USART_EnableOrDisable(USART1, 1);
}


/*
USART1
	TX Pin:	PA9
	Baud Rate: 9600
*/
//****************************************************
void USART1_ConfigDefault2(void){
	BUS_USART1_EnableOrDisable(1);
	
	BUS_GPIOA_EnableOrDisable(1);
	GPIO_OutputOrInputMode_SetMode(GPIOA,9, GPIO_OUTPUT_50MHz);
	GPIO_OutputMode_SetOutputType(GPIOA,9, GPIO_OUTPUT_AF_PUSHPULL);
	
	USART_SetBaudRate(USART1, PCLK2_VALUE, 9600);
	USART_SetMode(USART1, MODE_ASYNCRON);
	USART_SetDataBits(USART1, DATABITS_8BITS);
	USART_SetParity(USART1, PARITY_NONE);
	USART_SetStopBits(USART1, STOPBITS_1);
	USART_TX_EnableOrDisable(USART1, 1);
	USART_TX_INT_EnableOrDisable(USART1, 0);
	USART_RX_EnableOrDisable(USART1, 0);
	USART_RX_INT_EnableOrDisable(USART1, 0);
	USART_CTS_EnableOrDisable(USART1, 0);
	USART_CTS_INT_EnableOrDisable(USART1, 0);
	USART_RTS_EnableOrDisable(USART1, 0);
	USART_EnableOrDisable(USART1, 1);
}


/*
USART2
	TX Pin:	PA2
	RX Pin: PA3
	RX INT:	Enable
	Baud Rate: 9600
*/
//****************************************************
void USART2_ConfigDefault1(void){
	BUS_USART2_EnableOrDisable(1);
	
	BUS_GPIOA_EnableOrDisable(1);
	GPIO_OutputOrInputMode_SetMode(GPIOA,2, GPIO_OUTPUT_50MHz);
	GPIO_OutputMode_SetOutputType(GPIOA,2, GPIO_OUTPUT_AF_PUSHPULL);
	GPIO_OutputOrInputMode_SetMode(GPIOA,3, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,3, GPIO_INPUT_FLOATING);
	
	USART_SetBaudRate(USART2, PCLK1_VALUE, 9600);
	USART_SetMode(USART2, MODE_ASYNCRON);
	USART_SetDataBits(USART2, DATABITS_8BITS);
	USART_SetParity(USART2, PARITY_NONE);
	USART_SetStopBits(USART2, STOPBITS_1);
	USART_TX_EnableOrDisable(USART2, 1);
	USART_TX_INT_EnableOrDisable(USART2, 0);
	USART_RX_EnableOrDisable(USART2, 1);
	USART_RX_INT_EnableOrDisable(USART2, 1);
	USART_CTS_EnableOrDisable(USART2, 0);
	USART_CTS_INT_EnableOrDisable(USART2, 0);
	USART_RTS_EnableOrDisable(USART2, 0);
	USART_EnableOrDisable(USART2, 1);
}


/*
USART3
	TX Pin:	PB10
	RX Pin: PB11
	RX INT:	Enable
	Baud Rate: 9600
*/
//****************************************************
void USART3_ConfigDefault1(void){
	BUS_USART3_EnableOrDisable(1);
	
	BUS_GPIOB_EnableOrDisable(1);
	GPIO_OutputOrInputMode_SetMode(GPIOB,10, GPIO_OUTPUT_50MHz);
	GPIO_OutputMode_SetOutputType(GPIOB,10, GPIO_OUTPUT_AF_PUSHPULL);
	GPIO_OutputOrInputMode_SetMode(GPIOB,11, GPIO_INPUT);
	GPIO_InputMode_SetInputType(GPIOB,11, GPIO_INPUT_FLOATING);
	
	USART_SetBaudRate(USART3, PCLK1_VALUE, 9600);
	USART_SetMode(USART3, MODE_ASYNCRON);
	USART_SetDataBits(USART3, DATABITS_8BITS);
	USART_SetParity(USART3, PARITY_NONE);
	USART_SetStopBits(USART3, STOPBITS_1);
	USART_TX_EnableOrDisable(USART3, 1);
	USART_TX_INT_EnableOrDisable(USART3, 0);
	USART_RX_EnableOrDisable(USART3, 1);
	USART_RX_INT_EnableOrDisable(USART3, 1);
	USART_CTS_EnableOrDisable(USART3, 0);
	USART_CTS_INT_EnableOrDisable(USART3, 0);
	USART_RTS_EnableOrDisable(USART3, 0);
	USART_EnableOrDisable(USART3, 1);
}

