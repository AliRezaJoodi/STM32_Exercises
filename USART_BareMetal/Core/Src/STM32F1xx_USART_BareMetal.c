// GitHub Account: GitHub.com/AliRezaJoodi

#include "STM32F1xx_USART_BareMetal.h"

//*****************************************
void USART1_ConfigureNVIC(void){
	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(USART1_IRQn);
}

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
		USART1_PutChar(*str);
    ++str;
  }
}

//********************************
void USART1_PutStringFromFlash(const char *str){
  while(*str != 0){
		USART1_PutChar(*str);
		++str;
  }
}

//********************************
/*
void USART2_PutChar(char data){
	USART2_TransmitData(data);
	while(!USART2_TX_GeTransmitStatus){};
}
*/

//********************************
void USART2_PutString(char *str){
  while(*str != 0){
		USART2_PutChar(*str);
    ++str;
  }
}

//********************************
void USART2_PutStringFromFlash(const char *str){
  while(*str != 0){
		USART2_PutChar(*str);
		++str;
  }
}
