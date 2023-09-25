// GitHub Account: GitHub.com/AliRezaJoodi

#include "stm32f1xx.h"
#include "Utility.h"

#ifndef _USART_INCLUDED
	#define _USART_INCLUDED

#ifdef __cplusplus
	extern "C" {
#endif

#define MODE_ASYNCRON		0
#define MODE_SYNCRON		1
#define USART_SetMode(USARTx, MODE) \
	if(MODE == MODE_ASYNCRON){\
		ClearBit(USARTx->CR2, USART_CR2_LINEN_Pos);\
		ClearBit(USARTx->CR2, USART_CR2_CLKEN_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_SCEN_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_HDSEL_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_IREN_Pos);}\
	else if(MODE == MODE_SYNCRON){\
		ClearBit(USARTx->CR2, USART_CR2_LINEN_Pos);\
		SetBit(USARTx->CR2, USART_CR2_CLKEN_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_SCEN_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_HDSEL_Pos);\
		ClearBit(USARTx->CR3, USART_CR3_IREN_Pos);}
#define USART1_SetMode(MODE) \
	USART_SetMode(USART1, MODE);
#define USART2_SetMode(MODE) \
	USART_SetMode(USART1, MODE);

/*	
#define USART1_SetAsyncMode \
	ClearBit(USART1->CR2, USART_CR2_LINEN_Pos);\
	ClearBit(USART1->CR2, USART_CR2_CLKEN_Pos);\
	ClearBit(USART1->CR3, USART_CR3_SCEN_Pos);\
	ClearBit(USART1->CR3, USART_CR3_HDSEL_Pos);\
	ClearBit(USART1->CR3, USART_CR3_IREN_Pos);
*/

// Note: The M bit must not be modified during a data transfer (both transmission and reception)
#define DATABITS_8B	0b0
#define DATABITS_9B	0b1
#define USART_SetDataBits(USARTx, MODE) \
	WriteBit(USARTx->CR1, USART_CR1_M_Pos, MODE);
#define USART1_SetDataBits(MODE) \
	USART_SetDataBits(USART1, MODE);
#define USART2_SetDataBits(MODE) \
	USART_SetDataBits(USART2, MODE);

/*	
#define USART_EnableOrDisableParity(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_PCE_Pos, STATUS);
#define USART1_EnableOrDisableParity(STATUS) \
	USART_EnableOrDisableParity(USART1, STATUS);
#define USART2_EnableOrDisableParity(STATUS) \
	USART_EnableOrDisableParity(USART2, STATUS);
*/

#define PARITY_NONE 0b10
#define PARITY_EVEN 0b0
#define PARITY_ODD 	0b1
#define USART_SetParity(USARTx, MODE) \
	if(MODE == PARITY_NONE){\
		ClearBit(USARTx->CR1, USART_CR1_PCE_Pos);}\
	else{\
		SetBit(USARTx->CR1, USART_CR1_PCE_Pos);\
		WriteBit(USARTx->CR1, USART_CR1_PS_Pos, MODE);}
#define USART1_SetParity(MODE) \
	USART_SetParity(USART1, MODE);
#define USART2_SetParity(MODE) \
	USART_SetParity(USART2, MODE);

// The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.
#define STOPBITS_1 		0b00
#define STOPBITS_0_5 	0b01
#define STOPBITS_2 		0b10
#define STOPBITS_1_5 	0b11		
#define USART_SetStopBits(USARTx, MODE) \
	Write2Bit(USARTx->CR2, USART_CR2_STOP_Pos, MODE);
#define USART1_SetStopBits(MODE) \
	USART_SetStopBits(USART1, MODE);
#define USART2_SetStopBits(MODE) \
	USART_SetStopBits(USART2, MODE);

/*
#define DIRECTION_NONE 		0
#define DIRECTION_TX 			1
#define DIRECTION_RX 			2
#define DIRECTION_TX_RX		3
#define USART_SetDirection(USARTx, MODE) \
	if(MODE == DIRECTION_NONE){\
		ClearBit(USARTx->CR1, USART_CR1_TE_Pos);\
		ClearBit(USARTx->CR1, USART_CR1_RE_Pos);}\
	else if(MODE == DIRECTION_TX){\
		SetBit(USARTx->CR1, USART_CR1_TE_Pos);\
		ClearBit(USARTx->CR1, USART_CR1_RE_Pos);}\
	else if(MODE == DIRECTION_RX){\
		ClearBit(USARTx->CR1, USART_CR1_TE_Pos);\
		SetBit(USARTx->CR1, USART_CR1_RE_Pos);}\
	else if(MODE == DIRECTION_TX_RX){\
		SetBit(USARTx->CR1, USART_CR1_TE_Pos);\
		SetBit(USARTx->CR1, USART_CR1_RE_Pos);}
#define USART1_SetDirection(MODE) \
			USART_SetDirection(USART1, MODE)
#define USART2_SetDirection(MODE) \
			USART_SetDirection(USART2, MODE)
*/

#define USART_TX_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_TE_Pos, STATUS);
#define USART1_TX_EnableOrDisable(STATUS) \
	USART_TX_EnableOrDisable(USART1, STATUS);
#define USART2_TX_EnableOrDisable(STATUS) \
	USART_TX_EnableOrDisable(USART2, STATUS);

#define USART_TX_INT_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_TXEIE_Pos, STATUS);
#define USART1_TX_INT_EnableOrDisable(STATUS) \
	USART_TX_INT_EnableOrDisable(USART1, STATUS);
#define USART2_TX_INT_EnableOrDisable(STATUS) \
	USART_TX_INT_EnableOrDisable(USART2, STATUS);

#define USART_RX_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_RE_Pos, STATUS);
#define USART1_RX_EnableOrDisable(STATUS) \
	USART_RX_EnableOrDisable(USART1, STATUS);
#define USART2_RX_EnableOrDisable(STATUS) \
	USART_RX_EnableOrDisable(USART2, STATUS);

#define USART_RX_INT_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_RXNEIE_Pos, STATUS);
#define USART1_RX_INT_EnableOrDisable(STATUS) \
	USART_RX_INT_EnableOrDisable(USART1, STATUS);
#define USART2_RX_INT_EnableOrDisable(STATUS) \
	USART_RX_INT_EnableOrDisable(USART2, STATUS);

#define USART_CTS_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR3, USART_CR3_CTSE_Pos, STATUS);
#define USART1_CTS_EnableOrDisable(STATUS) \
	USART_CTS_EnableOrDisable(USART1, STATUS);
#define USART2_CTS_EnableOrDisable(STATUS) \
	USART_CTS_EnableOrDisable(USART2, STATUS);

#define USART_CTS_INT_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR3, USART_CR3_CTSIE_Pos, STATUS);
#define USART1_CTS_INT_EnableOrDisable(STATUS) \
	USART_CTS_INT_EnableOrDisable(USART1, STATUS);
#define USART2_CTS_INT_EnableOrDisable(STATUS) \
	USART_CTS_INT_EnableOrDisable(USART2, STATUS);

#define USART_RTS_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR3, USART_CR3_RTSE_Pos, STATUS);
#define USART1_RTS_EnableOrDisable(STATUS) \
	USART_RTS_EnableOrDisable(USART1, STATUS);
#define USART2_RTS_EnableOrDisable(STATUS) \
	USART_RTS_EnableOrDisable(USART2, STATUS);

#define _USART_GeEnableStatus(USARTx) \
	GetBit(USARTx->CR1, USART_CR1_UE_Pos)
#define USART_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_UE_Pos, STATUS);\
	while(_USART_GeEnableStatus(USARTx) != STATUS){};
#define USART1_EnableOrDisable(STATUS) \
	USART_EnableOrDisable(USART1, STATUS);
#define USART2_EnableOrDisable(STATUS) \
	USART_EnableOrDisable(USART2, STATUS);

#define USART_TransmitData_8Bits(USARTx, DATA) \
	USARTx->DR = DATA;
#define USART1_TransmitData_8Bits(DATA) \
	USART_TransmitData_8Bits(USART1, DATA)
#define USART2_TransmitData_8Bits(DATA) \
	USART_TransmitData_8Bits(USART2, DATA)

#define USART_TransmitData_9Bits(USARTx, DATA) \
	USARTx->DR = DATA & 0x1FFU;
#define USART1_TransmitData_9Bits(DATA) \
	USART_TransmitData_9Bits(USART1, DATA)
#define USART2_TransmitData_9Bits(DATA) \
	USART_TransmitData_9Bits(USART2, DATA)
		
// Status of transmit data to the shift register
#define USART_TXE_GeFlagStatus(USARTx) \
	GetBit(USARTx->SR, USART_SR_TXE_Pos)
#define USART1_TXE_GeFlagStatus \
	USART_TXE_GeFlagStatus(USART1)
#define USART2_TXE_GeFlagStatus \
	USART_TXE_GeFlagStatus(USART2)

// Transfer completion status
#define USART_TC_GeFlagStatus(USARTx) \
	GetBit(USARTx->SR, USART_SR_TC_Pos)
#define USART1_TC_GeFlagStatus \
	USART_TC_GeFlagStatus(USART1)
#define USART2_TC_GeFlagStatus \
	USART_TC_GeFlagStatus(USART2)


void USART1_PutChar(char data);
void USART1_PutString(char *str);
void USART1_PutStringFromFlash(const char *str);

void USART1_ConfigureNVIC(void);
void USART1_IRQHandler(void);

#ifdef __cplusplus
	}
#endif

#endif