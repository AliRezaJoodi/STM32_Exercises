// GitHub Account: GitHub.com/AliRezaJoodi
// It's a local library

#include <stm32f1xx_bm_usart.h>
	
//****************************************************
//PB10 -> USART3_TX
//PB11 -> USART3_RX
void USART3_Config(void){
	BUS_GPIOB_EnableOrDisable(1);
	GPIO_SetInputOrOutputMode(GPIOB,10, IO_OUTPUT_50MHz);
	GPIO_InOutputMode_SetGeneralPurposeOrAlternateFunction(GPIOB,10, OUTPUT_AF);
	GPIO_InOutputMode_SetPushPullOrOpenDrain(GPIOB,10, OUTPUT_PUSHPULL);
	GPIO_SetInputOrOutputMode(GPIOB,11, IO_INPUT);
	GPIO_InInputMode_SetInputType(GPIOB,11, INPUT_FLOATING);
	
	BUS_USART3_EnableOrDisable(1);
	USART_SetBaudRate(USART3, 8000000, 9600);
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

//*****************************************
void USART3_IRQHandler(void){
	extern char usart3_txt[16];
	extern char usart3_task;
	char c;
	static unsigned char i=0;

	if(USART_RX_GetReceiveFlag(USART3) && USART_RX_INT_GetEnableStatus(USART3)){		
		c = USART_ReceiveData_8Bits(USART3);
		USART_TransmitData_8Bits(USART3, c);
		if(32<=c && c<127){usart3_txt[i]=c; ++i;}
			else if(c==13){i=0; usart3_task=1;}
	}
}