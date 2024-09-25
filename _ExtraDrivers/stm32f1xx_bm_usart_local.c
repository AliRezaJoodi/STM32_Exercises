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
	
	//USART1_SetBaudRate(8000000, 9600);
	//USART1_SetMode(MODE_ASYNCRON);
	//USART1_SetDataBits(DATABITS_8BITS);
	//USART1_SetParity(PARITY_NONE);
	//USART1_SetStopBits(STOPBITS_1);
	//USART1_TX_EnableOrDisable(1);
	//USART1_TX_INT_EnableOrDisable(0);
	//USART1_RX_EnableOrDisable(1);
	//USART1_RX_INT_EnableOrDisable(1);
	//USART1_CTS_EnableOrDisable(0);
	//USART1_CTS_INT_EnableOrDisable(0);
	//USART1_RTS_EnableOrDisable(0);	
	//USART1_EnableOrDisable(1);
	
	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  //NVIC_DisableIRQ(USART1_IRQn);
	NVIC_EnableIRQ(USART1_IRQn);
}

//*****************************************
void USART1_IRQHandler(void){
	extern char usart1_txt[16];
	extern char usart1_task;
	char c;
	static unsigned char i=0;

	if(USART_RX_GetReceiveFlag(USART1) && USART_RX_INT_GetEnableStatus(USART1)){		
		c = USART1_ReceiveData_8Bits;
		USART1_TransmitData(c);
		
		if(32<=c && c<127){usart1_txt[i]=c; ++i;}
			else if(c==13){i=0; usart1_task=1;}
	}
}