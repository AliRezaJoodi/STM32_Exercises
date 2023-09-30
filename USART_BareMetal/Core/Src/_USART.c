// GitHub Account: GitHub.com/AliRezaJoodi

#include "_USART.h"

//****************************************************
//PA9 -> USART1_TX
//PA10 -> USART1_RX
void USART1_Configure(void){
	BUS_GPIOA_EnableOrDisable(1);
	GPIO_SetInputOrOutputMode(GPIOA,9, MODE_OUTPUT_50MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,9, OUTPUT_AFIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,9, OUTPUT_PUSHPULL);
	GPIO_SetInputOrOutputMode(GPIOA,10, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,10, INPUT_FLOATING);
	
	USART1_ConfigureNVIC();
	BUS_USART1_EnableOrDisable(1);
	
  //LL_USART_InitTypeDef USART_InitStruct = {0};
  //USART_InitStruct.BaudRate = 9600;
  //USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
  //USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
  //USART_InitStruct.Parity = LL_USART_PARITY_NONE;
  //USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
  //USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
  //USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
  //LL_USART_Init(USART1, &USART_InitStruct);

	USART1_SetBaudRate(833);
	USART1_SetMode(MODE_ASYNCRON);
	USART1_SetDataBits(DATABITS_8B);
	USART1_SetParity(PARITY_NONE);
	USART1_SetStopBits(STOPBITS_1);
	USART1_TX_EnableOrDisable(1);
	USART1_TX_INT_EnableOrDisable(0);
	USART1_RX_EnableOrDisable(1);
	USART1_RX_INT_EnableOrDisable(1);
	USART1_CTS_EnableOrDisable(0);
	USART1_CTS_INT_EnableOrDisable(0);
	USART1_RTS_EnableOrDisable(0);	
	USART1_EnableOrDisable(1);
}

//*****************************************
void USART1_IRQHandler(void){
	char c;
	static unsigned char i=0;
	extern char usart1_txt[16];
	extern char usart1_task;
	
	if(USART1_RX_GetReceiveFlag && USART1_RX_INT_GetEnableStatus){		
		c = USART1_ReceiveData_8Bits;
		USART1_TransmitData(c);
		
		if(32<=c && c<127){usart1_txt[i]=c; ++i;}
			else if(c==13){i=0; usart1_task=1;}
	}
}