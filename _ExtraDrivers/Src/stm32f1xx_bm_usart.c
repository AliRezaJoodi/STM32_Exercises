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

//****************************************************
//PA9 -> USART1_TX
//PA10 -> USART1_RX
void USART1_ConfigDefault1_TX_RXINT(void){
	BUS_GPIOA_EnableOrDisable(1);
	GPIO_SetInputOrOutputMode(GPIOA,9, IO_OUTPUT_50MHz);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOA,9, OUTPUT_AF);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOA,9, OUTPUT_PUSHPULL);
	GPIO_SetInputOrOutputMode(GPIOA,10, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOA,10, INPUT_FLOATING);
	
	BUS_USART1_EnableOrDisable(1);
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

//****************************************************
//PA9 -> USART1_TX
void USART1_ConfigDefault2_TX(void){
	BUS_GPIOA_EnableOrDisable(1);
	GPIO_SetInputOrOutputMode(GPIOA,9, IO_OUTPUT_50MHz);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOA,9, OUTPUT_AF);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOA,9, OUTPUT_PUSHPULL);
	
	BUS_USART1_EnableOrDisable(1);
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

//****************************************************
//PA2 -> USART2_TX
//PA3 -> USART2_RX
void USART2_ConfigDefault1_TX_RXINT(void){
	BUS_GPIOA_EnableOrDisable(1);
	GPIO_SetInputOrOutputMode(GPIOA,2, IO_OUTPUT_50MHz);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOA,2, OUTPUT_AF);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOA,2, OUTPUT_PUSHPULL);
	GPIO_SetInputOrOutputMode(GPIOA,3, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOA,3, INPUT_FLOATING);
	
	BUS_USART2_EnableOrDisable(1);
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

//****************************************************
//PB10 -> USART3_TX
//PB11 -> USART3_RX
void USART3_ConfigDefault1_TX_RXINT(void){
	BUS_GPIOB_EnableOrDisable(1);
	GPIO_SetInputOrOutputMode(GPIOB,10, IO_OUTPUT_50MHz);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOB,10, OUTPUT_AF);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOB,10, OUTPUT_PUSHPULL);
	GPIO_SetInputOrOutputMode(GPIOB,11, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOB,11, INPUT_FLOATING);
	
	BUS_USART3_EnableOrDisable(1);
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

