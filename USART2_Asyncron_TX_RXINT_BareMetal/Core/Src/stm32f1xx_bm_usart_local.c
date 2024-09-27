// GitHub Account: GitHub.com/AliRezaJoodi
// It's a local library

#include <stm32f1xx_bm_usart.h>
	
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
void USART2_IRQHandler(void){
	extern char usart2_txt[16];
	extern char usart2_task;
	char c;
	static unsigned char i=0;

	if(USART_RX_GetReceiveFlag(USART2) && USART_RX_INT_GetEnableStatus(USART2)){		
		c = USART_ReceiveData_8Bits(USART2);
		USART_TransmitData_8Bits(USART2, c);
		if(32<=c && c<127){usart2_txt[i]=c; ++i;}
			else if(c==13){i=0; usart2_task=1;}
	}
}