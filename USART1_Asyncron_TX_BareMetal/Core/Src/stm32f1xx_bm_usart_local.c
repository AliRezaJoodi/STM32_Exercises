// GitHub Account: GitHub.com/AliRezaJoodi
// It's a local library

#include <stm32f1xx_bm_usart.h>
	
//****************************************************
//PA9 -> USART1_TX
void USART1_ConfigDefault2_TX(void){
	BUS_GPIOA_EnableOrDisable(1);
	GPIO_SetInputOrOutputMode(GPIOA,9, IO_OUTPUT_50MHz);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOA,9, OUTPUT_AF);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOA,9, OUTPUT_PUSHPULL);
	
	BUS_USART1_EnableOrDisable(1);
	USART_SetBaudRate(USART1, 8000000, 9600);
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
//*****************************************
void USART1_IRQHandler(void){
	if(USART_RX_GetReceiveFlag(USART1) && USART_RX_INT_GetEnableStatus(USART1)){
	}
}