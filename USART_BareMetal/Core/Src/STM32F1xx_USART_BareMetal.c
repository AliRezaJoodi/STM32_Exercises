// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"
#include "STM32F1xx_USART_BareMetal.h"

//********************************
/*
void USART1_PutChar(char data){
	USART1_TransmitData(data);
	while(!USART1_TX_GeTransmitStatus){};
}
*/

//********************************
void USART1_PutString(char *str){
  while(*str != 0){
		//USART1_TransmitData(*str);
		//while(!USART1_TX_GeTransmitStatus){};
		USART1_PutChar(*str);
    ++str;
  }
}

//********************************
void USART1_PutStringFromFlash(const char *str){
  while(*str != 0){
		//USART1_TransmitData(*str);
    //while(!USART1_TX_GeTransmitStatus){};
		USART1_PutChar(*str);
		++str;
  }
}

//*****************************************
/*
void USART1_PutInteger(int number){
	int n=number;
	while(n != 0){
		USART1_PutNumber(n - (n/10));
		n=n/10;
	}
}
*/

//*****************************************
void USART1_ConfigureNVIC(void){
	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(USART1_IRQn);
}

