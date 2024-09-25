// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_usart.h>

//********************************
void USART_ClearString(char *str){
  while(*str != 0){
		*str=0;
    ++str;
  }
}

//********************************
/*
void USART1_PutChar(char data){
	USART1_TransmitData(data);
	while(!USART1_TX_GeTransmitStatus){};
}
*/

//********************************
/*
void USART2_PutChar(char data){
	USART2_TransmitData(data);
	while(!USART2_TX_GeTransmitStatus){};
}
*/

//********************************
void USART1_PutString(char *str){
  while(*str != 0){
		USART1_PutChar(*str);
    ++str;
  }
	USART1_PutChar('\r');		// 0x0D
	USART1_PutChar('\n');		// 0x0A
}

//********************************
void USART2_PutString(char *str){
  while(*str != 0){
		USART2_PutChar(*str);
    ++str;
  }
	USART1_PutChar('\r');		// 0x0D
	USART1_PutChar('\n');		// 0x0A
}

//********************************
void USART1_PutStringFromFlash(const char *str){
  while(*str != 0){
		USART1_PutChar(*str);
		++str;
  }
	USART1_PutChar('\r');		// 0x0D
	USART1_PutChar('\n');		// 0x0A
}

//********************************
void USART2_PutStringFromFlash(const char *str){
  while(*str != 0){
		USART2_PutChar(*str);
		++str;
  }
	USART1_PutChar('\r');		// 0x0D
	USART1_PutChar('\n');		// 0x0A
}

