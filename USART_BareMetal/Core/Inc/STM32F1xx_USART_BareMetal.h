// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx.h"
#include "Utility.h"

#ifndef _USART_INCLUDED
	#define _USART_INCLUDED

#ifdef __cplusplus
	extern "C" {
#endif

void USART1_PutChar(char data);
void USART1_PutString(char *str);
void USART1_PutStringFromFlash(const char *str);

void USART1_ConfigureNVIC(void);
void USART1_IRQHandler(void);

#ifdef __cplusplus
	}
#endif

#endif