// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _STM32F1xx_LL_USART_PUT_INCLUDED
#define _STM32F1xx_LL_USART_PUT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>
#include "stm32f1xx_ll_usart.h"

//********************************
void USART_PutChar(USART_TypeDef *USARTx, char data){
	while(LL_USART_IsActiveFlag_TXE(USARTx) != 1){}		 // Transmit Data Register Empty 
	LL_USART_TransmitData8(USARTx,data);
	while(LL_USART_IsActiveFlag_TC(USARTx) != 1){}	// Transmission Complete 
}

//********************************
void USART_PutString(USART_TypeDef *USARTx, char *str){
  while(*str != 0){
		USART_PutChar(USARTx,*str);
    str++;
  }
	USART_PutChar(USARTx, '\r');		// 0x0D
	USART_PutChar(USARTx, '\n');		// 0x0A
}

//********************************
void USART_PutStringFromFlash(USART_TypeDef *USARTx, const char *str){
  while(*str != 0){
		USART_PutChar(USARTx, *str);
    str++;
  }
	USART_PutChar(USARTx, '\r');		// 0x0D
	USART_PutChar(USARTx, '\n');		// 0x0A
}

#ifdef __cplusplus
}
#endif

#endif		// _STM32F1xx_LL_USART_PUT_INCLUDED