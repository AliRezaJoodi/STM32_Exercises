// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx.h"
#include "Utility.h"

#ifndef _USART_INCLUDED
	#define _USART_INCLUDED

#ifdef __cplusplus
	extern "C" {
#endif

#define MODE_Asyncron		0
#define MODE_Syncron		1
#define USART_SetMode(USARTx, MODE) \
	if(MODE == MODE_Asyncron){\
		ClearBit(USARTx->CR2, USART_CR2_LINEN_Pos);\
		ClearBit(USARTx->CR2, USART_CR2_CLKEN_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_SCEN_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_HDSEL_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_IREN_Pos);}\
	else if(MODE == MODE_Syncron){\
		ClearBit(USARTx->CR2, USART_CR2_LINEN_Pos);\
		SetBit(USARTx->CR2, USART_CR2_CLKEN_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_SCEN_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_HDSEL_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_IREN_Pos);}
#define USART1_SetMode(MODE) \
	USART_SetMode(USART1, MODE);

/*	
#define USART1_SetAsyncMode \
	ClearBit(USART1->CR2, USART_CR2_LINEN_Pos);\
	ClearBit(USART1->CR2, USART_CR2_CLKEN_Pos);\
	ClearBit(USART1->CR3, USART_CR3_SCEN_Pos);\
	ClearBit(USART1->CR3, USART_CR3_HDSEL_Pos);\
	ClearBit(USART1->CR3, USART_CR3_IREN_Pos);
*/
		
/*		
#define USART1_GeEnableStatus \
	GetBit(USART1->CR1, USART_CR1_UE_Pos)
#define USART1_EnableOrDisable(STATUS) \
	WriteBit(USART1->CR1, USART_CR1_UE_Pos, STATUS);\
	while(USART1_GeEnableStatus != STATUS){};
*/
#define USART_GeEnableStatus(USARTx) \
	GetBit(USARTx->CR1, USART_CR1_UE_Pos)
#define USART_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_UE_Pos, STATUS);\
	while(USART_GeEnableStatus(USARTx) != STATUS){};
#define USART1_EnableOrDisable(STATUS) \
	USART_EnableOrDisable(USART1, STATUS);
		
void USART1_PutChar(char data);
void USART1_PutString(char *str);
void USART1_PutStringFromFlash(const char *str);

void USART1_ConfigureNVIC(void);
void USART1_IRQHandler(void);

#ifdef __cplusplus
	}
#endif

#endif