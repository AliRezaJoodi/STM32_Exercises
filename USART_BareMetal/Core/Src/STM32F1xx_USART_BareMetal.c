// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"
#include "STM32F1xx_USART_BareMetal.h"

//********************************
void USART1_PutChar(char data){
  //LL_USART_TransmitData8(USART1, data);
	USART1_TransmitData(data);
	//while(!LL_USART_IsActiveFlag_TXE(USART1)){}
	while(!USART1_TX_GeTransmitStatus){};
}

//********************************
void USART1_PutString(char *str){
  while(*str != 0){
		//LL_USART_TransmitData8(USART1, *str);
		USART1_TransmitData(*str);
		//while(!LL_USART_IsActiveFlag_TXE(USART1)){}
		while(!USART1_TX_GeTransmitStatus){};
    str++;
  }
	//LL_USART_TransmitData8(USART1,13);
	//while(!LL_USART_IsActiveFlag_TXE(USART1)){};
}

//********************************
void USART1_PutStringFromFlash(const char *str){
  while(*str != 0){
		//LL_USART_TransmitData8(USART1, *str);
		USART1_TransmitData(*str);
		//while(!LL_USART_IsActiveFlag_TXE(USART1)){}
    while(!USART1_TX_GeTransmitStatus){};
		str++;
  }
	//LL_USART_TransmitData8(USART1,13);
	//while(!LL_USART_IsActiveFlag_TXE(USART1)){};
}

//*****************************************
void USART1_ConfigureNVIC(void){
	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(USART1_IRQn);
}

//*****************************************
void USART1_IRQHandler(void){
	char c;
	static uint8_t i=0;
	//extern uint8_t j;
	extern uint8_t task_usart1;
	extern char txt[16];
	
	//if(LL_USART_IsActiveFlag_RXNE(USART1) && LL_USART_IsEnabledIT_RXNE(USART1)){
	if(USART1_RX_GetReceiveFlag && USART1_RX_INT_GetEnableStatus){
		c=LL_USART_ReceiveData8(USART1);
		//LL_USART_TransmitData8(USART1,c);
		USART1_TransmitData(c);
		//while(!LL_USART_IsActiveFlag_TXE(USART1)){}
	
		if(32<=c && c<127){txt[i]=c; ++i;}
			else if(c==13){i=0; task_usart1=1;}
	}
}
