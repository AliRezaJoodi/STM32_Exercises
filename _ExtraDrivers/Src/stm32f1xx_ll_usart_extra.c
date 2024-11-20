// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_ll_usart_extra.h>

//********************************
void LL_USART_PutChar(USART_TypeDef *USARTx, char data){
	while(LL_USART_IsActiveFlag_TXE(USARTx) != 1){}		 // Transmit Data Register Empty 
	LL_USART_TransmitData8(USARTx,data);
	while(LL_USART_IsActiveFlag_TC(USARTx) != 1){}	// Transmission Complete 
}

//********************************
void LL_USART_PutString(USART_TypeDef *USARTx, char *str){
  while(*str != 0){
		LL_USART_PutChar(USARTx,*str);
    str++;
  }
	LL_USART_PutChar(USARTx, '\r');		// 0x0D
	LL_USART_PutChar(USARTx, '\n');		// 0x0A
}

//********************************
void LL_USART_PutStringFromFlash(USART_TypeDef *USARTx, const char *str){
  while(*str != 0){
		LL_USART_PutChar(USARTx, *str);
    str++;
  }
	LL_USART_PutChar(USARTx, '\r');		// 0x0D
	LL_USART_PutChar(USARTx, '\n');		// 0x0A
}
