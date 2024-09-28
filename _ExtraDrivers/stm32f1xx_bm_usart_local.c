// GitHub Account: GitHub.com/AliRezaJoodi
// It's a local library

#include <stm32f1xx_bm_usart.h>
	
//****************************************************
//PA9 -> USART1_TX
//PA10 -> USART1_RX
void USART1_Config(void){
	BUS_GPIOA_EnableOrDisable(1);
	GPIO_SetInputOrOutputMode(GPIOA,9, IO_OUTPUT_50MHz);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOA,9, OUTPUT_AF);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOA,9, OUTPUT_PUSHPULL);
	GPIO_SetInputOrOutputMode(GPIOA,10, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOA,10, INPUT_FLOATING);
	
	BUS_USART1_EnableOrDisable(1);

	USART_SetBaudRate(USART1, 8000000, 9600);
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
//PA2 -> USART2_TX
//PA3 -> USART2_RX
void USART2_Config(void){
	BUS_GPIOA_EnableOrDisable(1);
	GPIO_SetInputOrOutputMode(GPIOA,2, IO_OUTPUT_50MHz);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOA,2, OUTPUT_AF);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOA,2, OUTPUT_PUSHPULL);
	GPIO_SetInputOrOutputMode(GPIOA,3, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOA,3, INPUT_FLOATING);
	
	BUS_USART2_EnableOrDisable(1);
	USART_SetBaudRate(USART2, 8000000, 9600);
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

//*****************************************
void USART1_IRQHandler(void){
	char c;

	if(USART_RX_GetReceiveFlag(USART1) && USART_RX_INT_GetEnableStatus(USART1)){		
		c = USART1_ReceiveData_8Bits;
		USART1_TransmitData(c);
		
	}
}

//*****************************************
void USART2_IRQHandler(void){
	char c;

	if(USART_RX_GetReceiveFlag(USART2) && USART_RX_INT_GetEnableStatus(USART2)){		
		c = USART_ReceiveData_8Bits(USART2);
		USART_TransmitData_8Bits(USART2, c);
	}
}