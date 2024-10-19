// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

#ifndef _STM32F1xx_BM_USART_INCLUDED
#define _STM32F1xx_BM_USART_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>
#include <utility.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>

#define _DIV_INTEGER_SAMPLING16(PERIPHCLK, BAUDRATE) \
	( ((PERIPHCLK)*25) / (4*(BAUDRATE)) )
#define _DIV_MANTISSA_SAMPLING16(PERIPHCLK, BAUDRATE) \
	(_DIV_INTEGER_SAMPLING16((PERIPHCLK), (BAUDRATE)) / 100)
#define _DIV_FRACTION_SAMPLING16(PERIPHCLK, BAUDRATE) \
	((((_DIV_INTEGER_SAMPLING16((PERIPHCLK), (BAUDRATE)) - (_DIV_MANTISSA_SAMPLING16((PERIPHCLK), (BAUDRATE))*100) ) * 16) + 50) / 100)
#define _DIV_SAMPLING16(PERIPHCLK, BAUDRATE) \
	(((_DIV_MANTISSA_SAMPLING16((PERIPHCLK), (BAUDRATE)) << 4) + \
	(_DIV_FRACTION_SAMPLING16((PERIPHCLK), (BAUDRATE)) & 0xF0)) + \
	(_DIV_FRACTION_SAMPLING16((PERIPHCLK), (BAUDRATE)) & 0x0F))

__STATIC_INLINE void USART_SetBaudRate(USART_TypeDef *USARTx, uint32_t PERIPHCLK, uint32_t BAUDRATE){
		USARTx->BRR = _DIV_SAMPLING16(PERIPHCLK, BAUDRATE);
}
/*#define USART_SetBaudRate(USARTx, PERIPHCLK, BAUDRATE) \
	USARTx->BRR = _DIV_SAMPLING16(PERIPHCLK, BAUDRATE);*/
/*#define USART1_SetBaudRate(PERIPHCLK, BAUDRATE) \
	USART_SetBaudRate(USART1, PERIPHCLK, BAUDRATE);
#define USART2_SetBaudRate(PERIPHCLK, BAUDRATE) \
	USART_SetBaudRate(USART2, PERIPHCLK, BAUDRATE);*/
	
#define MODE_ASYNCRON		0
#define MODE_SYNCRON		1
__STATIC_INLINE void USART_SetMode(USART_TypeDef *USARTx, uint32_t MODE){
	if(MODE == MODE_ASYNCRON){
		ClearBit(USARTx->CR2, USART_CR2_LINEN_Pos);
		ClearBit(USARTx->CR2, USART_CR2_CLKEN_Pos);
		ClearBit(USARTx->CR3, USART_CR3_SCEN_Pos);
		ClearBit(USARTx->CR3, USART_CR3_HDSEL_Pos);
		ClearBit(USARTx->CR3, USART_CR3_IREN_Pos);
	}
	else if(MODE == MODE_SYNCRON){
		ClearBit(USARTx->CR2, USART_CR2_LINEN_Pos);
		SetBit(USARTx->CR2, USART_CR2_CLKEN_Pos);
		ClearBit(USARTx->CR3, USART_CR3_SCEN_Pos);
		ClearBit(USARTx->CR3, USART_CR3_HDSEL_Pos);
		ClearBit(USARTx->CR3, USART_CR3_IREN_Pos);
	}	
}
/*#define USART_SetMode(USARTx, MODE) \
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
		ClearBit(USARTx->CR3, USART_CR3_IREN_Pos);}*/
/*#define USART1_SetMode(MODE) \
	USART_SetMode(USART1, MODE);
#define USART2_SetMode(MODE) \
	USART_SetMode(USART1, MODE);*/

/*	
#define USART1_SetAsyncMode \
	ClearBit(USART1->CR2, USART_CR2_LINEN_Pos);\
	ClearBit(USART1->CR2, USART_CR2_CLKEN_Pos);\
	ClearBit(USART1->CR3, USART_CR3_SCEN_Pos);\
	ClearBit(USART1->CR3, USART_CR3_HDSEL_Pos);\
	ClearBit(USART1->CR3, USART_CR3_IREN_Pos);
*/

// Note: The M bit must not be modified during a data transfer (both transmission and reception)
#define DATABITS_8BITS	0b0
#define DATABITS_9BITS	0b1
__STATIC_INLINE uint32_t USART_GeDataBits(USART_TypeDef *USARTx){
		return ( GetBit(USARTx->CR1, USART_CR1_M_Pos) );
}
__STATIC_INLINE void USART_SetDataBits(USART_TypeDef *USARTx, uint32_t MODE){
		WriteBit(USARTx->CR1, USART_CR1_M_Pos, MODE);
}
/*#define USART_GeDataBits(USARTx) \
	GetBit(USARTx->CR1, USART_CR1_M_Pos)
#define USART_SetDataBits(USARTx, MODE) \
	WriteBit(USARTx->CR1, USART_CR1_M_Pos, MODE);*/
/*#define USART1_SetDataBits(MODE) \
	USART_SetDataBits(USART1, MODE);
#define USART2_SetDataBits(MODE) \
	USART_SetDataBits(USART2, MODE);*/

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
__STATIC_INLINE void USART_SetParity(USART_TypeDef *USARTx, uint32_t MODE){
	if(MODE == PARITY_NONE){
		ClearBit(USARTx->CR1, USART_CR1_PCE_Pos);}
	else{
		SetBit(USARTx->CR1, USART_CR1_PCE_Pos);
		WriteBit(USARTx->CR1, USART_CR1_PS_Pos, MODE);}	
}
/*#define USART_SetParity(USARTx, MODE) \
	if(MODE == PARITY_NONE){\
		ClearBit(USARTx->CR1, USART_CR1_PCE_Pos);}\
	else{\
		SetBit(USARTx->CR1, USART_CR1_PCE_Pos);\
		WriteBit(USARTx->CR1, USART_CR1_PS_Pos, MODE);}*/
/*#define USART1_SetParity(MODE) \
	USART_SetParity(USART1, MODE);
#define USART2_SetParity(MODE) \
	USART_SetParity(USART2, MODE);*/

// The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.
#define STOPBITS_1 		0b00
#define STOPBITS_0_5 	0b01
#define STOPBITS_2 		0b10
#define STOPBITS_1_5 	0b11	
__STATIC_INLINE void USART_SetStopBits(USART_TypeDef *USARTx, uint32_t MODE){
	Write2Bit(USARTx->CR2, USART_CR2_STOP_Pos, MODE);
}
/*#define USART_SetStopBits(USARTx, MODE) \
	Write2Bit(USARTx->CR2, USART_CR2_STOP_Pos, MODE);*/
/*#define USART1_SetStopBits(MODE) \
	USART_SetStopBits(USART1, MODE);
#define USART2_SetStopBits(MODE) \
	USART_SetStopBits(USART2, MODE);*/

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

__STATIC_INLINE void USART_TX_EnableOrDisable(USART_TypeDef *USARTx, uint32_t STATUS){
	WriteBit(USARTx->CR1, USART_CR1_TE_Pos, STATUS);
}
/*#define USART_TX_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_TE_Pos, STATUS);*/
/*#define USART1_TX_EnableOrDisable(STATUS) \
	USART_TX_EnableOrDisable(USART1, STATUS);
#define USART2_TX_EnableOrDisable(STATUS) \
	USART_TX_EnableOrDisable(USART2, STATUS);*/

__STATIC_INLINE void USART_TX_INT_EnableOrDisable(USART_TypeDef *USARTx, uint32_t STATUS){
	WriteBit(USARTx->CR1, USART_CR1_TXEIE_Pos, STATUS);
}
/*#define USART_TX_INT_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_TXEIE_Pos, STATUS);*/
/*#define USART1_TX_INT_EnableOrDisable(STATUS) \
	USART_TX_INT_EnableOrDisable(USART1, STATUS);
#define USART2_TX_INT_EnableOrDisable(STATUS) \
	USART_TX_INT_EnableOrDisable(USART2, STATUS);*/

__STATIC_INLINE void USART_RX_EnableOrDisable(USART_TypeDef *USARTx, uint32_t STATUS){
	WriteBit(USARTx->CR1, USART_CR1_RE_Pos, STATUS);
}
/*#define USART_RX_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_RE_Pos, STATUS);*/
/*#define USART1_RX_EnableOrDisable(STATUS) \
	USART_RX_EnableOrDisable(USART1, STATUS);
#define USART2_RX_EnableOrDisable(STATUS) \
	USART_RX_EnableOrDisable(USART2, STATUS);*/

__STATIC_INLINE void USART_RX_INT_EnableOrDisable(USART_TypeDef *USARTx, uint32_t STATUS){
	WriteBit(USARTx->CR1, USART_CR1_RXNEIE_Pos, STATUS);
}
/*#define USART_RX_INT_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_RXNEIE_Pos, STATUS);*/
/*#define USART1_RX_INT_EnableOrDisable(STATUS) \
	USART_RX_INT_EnableOrDisable(USART1, STATUS);
#define USART2_RX_INT_EnableOrDisable(STATUS) \
	USART_RX_INT_EnableOrDisable(USART2, STATUS);*/

__STATIC_INLINE void USART_CTS_EnableOrDisable(USART_TypeDef *USARTx, uint32_t STATUS){
	WriteBit(USARTx->CR3, USART_CR3_CTSE_Pos, STATUS);
}
/*#define USART_CTS_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR3, USART_CR3_CTSE_Pos, STATUS);
#define USART1_CTS_EnableOrDisable(STATUS) \
	USART_CTS_EnableOrDisable(USART1, STATUS);
#define USART2_CTS_EnableOrDisable(STATUS) \
	USART_CTS_EnableOrDisable(USART2, STATUS);*/

__STATIC_INLINE void USART_CTS_INT_EnableOrDisable(USART_TypeDef *USARTx, uint32_t STATUS){
	WriteBit(USARTx->CR3, USART_CR3_CTSIE_Pos, STATUS);
}
/*#define USART_CTS_INT_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR3, USART_CR3_CTSIE_Pos, STATUS);*/
/*#define USART1_CTS_INT_EnableOrDisable(STATUS) \
	USART_CTS_INT_EnableOrDisable(USART1, STATUS);
#define USART2_CTS_INT_EnableOrDisable(STATUS) \
	USART_CTS_INT_EnableOrDisable(USART2, STATUS);*/

__STATIC_INLINE void USART_RTS_EnableOrDisable(USART_TypeDef *USARTx, uint32_t STATUS){
	WriteBit(USARTx->CR3, USART_CR3_RTSE_Pos, STATUS);	
}
/*#define USART_RTS_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR3, USART_CR3_RTSE_Pos, STATUS);*/
/*#define USART1_RTS_EnableOrDisable(STATUS) \
	USART_RTS_EnableOrDisable(USART1, STATUS);
#define USART2_RTS_EnableOrDisable(STATUS) \
	USART_RTS_EnableOrDisable(USART2, STATUS);*/

__STATIC_INLINE uint32_t _USART_GeEnableStatus(USART_TypeDef *USARTx){
 return ( GetBit(USARTx->CR1, USART_CR1_UE_Pos) );	
}
__STATIC_INLINE void USART_EnableOrDisable(USART_TypeDef *USARTx, uint32_t STATUS){
	WriteBit(USARTx->CR1, USART_CR1_UE_Pos, STATUS);
	while(_USART_GeEnableStatus(USARTx) != STATUS){};	
}
/*#define _USART_GeEnableStatus(USARTx) \
	GetBit(USARTx->CR1, USART_CR1_UE_Pos)
#define USART_EnableOrDisable(USARTx, STATUS) \
	WriteBit(USARTx->CR1, USART_CR1_UE_Pos, STATUS);\
	while(_USART_GeEnableStatus(USARTx) != STATUS){};*/
/*#define USART1_EnableOrDisable(STATUS) \
	USART_EnableOrDisable(USART1, STATUS);
#define USART2_EnableOrDisable(STATUS) \
	USART_EnableOrDisable(USART2, STATUS);*/

__STATIC_INLINE uint8_t USART_ReceiveData_8Bits(USART_TypeDef *USARTx){
	return (USARTx->DR & 0xFFU);
}
/*#define USART_ReceiveData_8Bits(USARTx) \
	(USARTx->DR & 0xFFU)*/
/*#define USART1_ReceiveData_8Bits \
	USART_ReceiveData_8Bits(USART1)
#define USART2_ReceiveData_8Bits \
	USART_ReceiveData_8Bits(USART2)*/

__STATIC_INLINE uint16_t USART_ReceiveData_9Bits(USART_TypeDef *USARTx){
	return (USARTx->DR & 0x1FFU);
}
/*#define USART_ReceiveData_9Bits(USARTx) \
	(USARTx->DR & 0x1FFU)*/
/*#define USART1_ReceiveData_9Bits \
	USART_ReceiveData_9Bits(USART1)
#define USART2_ReceiveData_9Bits \
	USART_ReceiveData_9Bits(USART2)*/
/*
#define USART_ReceiveData(USARTx, DATA) \
	if(USART_GeDataBits(USARTx)==DATABITS_8BITS){DATA=USART_ReceiveData_8Bits(USARTx);}\
		else{DATA=USART_ReceiveData_9Bits(USARTx);}
#define USART1_ReceiveData(DATA) \
	USART_ReceiveData(USART1, DATA)
#define USART2_ReceiveData(DATA) \
	USART_ReceiveData(USART2, DATA)
*/

__STATIC_INLINE uint32_t USART_RX_GetReceiveFlag(USART_TypeDef *USARTx){
	return( GetBit(USARTx->SR, USART_SR_RXNE_Pos) );
}
/*#define USART_RX_GetReceiveFlag(USARTx) \
	GetBit(USARTx->SR, USART_SR_RXNE_Pos)*/
/*#define USART1_RX_GetReceiveFlag \
	USART_RX_GetReceiveFlag(USART1)
#define USART2_RX_GetReceiveFlag \
	USART_RX_GetReceiveFlag(USART2)*/

__STATIC_INLINE uint32_t USART_RX_INT_GetEnableStatus(USART_TypeDef *USARTx){
	return( GetBit(USARTx->CR1, USART_CR1_RXNEIE_Pos) );
}
/*#define USART_RX_INT_GetEnableStatus(USARTx) \
	GetBit(USARTx->CR1, USART_CR1_RXNEIE_Pos)*/
/*#define USART1_RX_INT_GetEnableStatus \
	USART_RX_INT_GetEnableStatus(USART1)
#define USART2_RX_INT_GetEnableStatus \
	USART_RX_INT_GetEnableStatus(USART2)*/

__STATIC_INLINE void USART_TransmitData_8Bits(USART_TypeDef *USARTx, uint8_t data){
	USARTx->DR = (data & 0xFFU);
}
/*#define USART_TransmitData_8Bits(USARTx, DATA) \
	USARTx->DR = DATA & 0xFFU;*/
/*#define USART1_TransmitData_8Bits(DATA) \
	USART_TransmitData_8Bits(USART1, DATA)
#define USART2_TransmitData_8Bits(DATA) \
	USART_TransmitData_8Bits(USART2, DATA)*/

__STATIC_INLINE void USART_TransmitData_9Bits(USART_TypeDef *USARTx, uint16_t data){
	USARTx->DR = (data & 0x1FFU);
}
/*#define USART_TransmitData_9Bits(USARTx, DATA) \
	USARTx->DR = DATA & 0x1FFU;*/
/*#define USART1_TransmitData_9Bits(DATA) \
	USART_TransmitData_9Bits(USART1, DATA);
#define USART2_TransmitData_9Bits(DATA) \
	USART_TransmitData_9Bits(USART2, DATA);*/

__STATIC_INLINE void USART_TransmitData(USART_TypeDef *USARTx, uint16_t data){
	if(USART_GeDataBits(USARTx)==DATABITS_8BITS){
		USART_TransmitData_8Bits(USARTx, data);
	}
	else{
		USART_TransmitData_9Bits(USARTx, data);
	}	
}
/*#define USART_TransmitData(USARTx, DATA) \
	if(USART_GeDataBits(USARTx)==DATABITS_8BITS){USART_TransmitData_8Bits(USARTx, DATA);}\
		else{USART_TransmitData_9Bits(USARTx, DATA);}*/
/*#define USART1_TransmitData(DATA) \
	USART_TransmitData(USART1, DATA)
#define USART2_TransmitData(DATA) \
	USART_TransmitData(USART2, DATA)*/

// Transmit Data Register Empty
__STATIC_INLINE uint32_t USART_TX_GetEmptyFlag(USART_TypeDef *USARTx){
	return ( GetBit(USARTx->SR, USART_SR_TXE_Pos) );
}
/*#define USART_TX_GetEmptyFlag(USARTx) \
	GetBit(USARTx->SR, USART_SR_TXE_Pos)*/
/*#define USART1_TX_GeTransmitStatus \
	USART_TX_GetEmptyFlag(USART1)
#define USART2_TX_GeTransmitStatus \
	USART_TX_GetEmptyFlag(USART2)*/

// Transmission Complete
__STATIC_INLINE uint32_t USART_TX_GeCompleteFlag(USART_TypeDef *USARTx){
	return ( GetBit(USARTx->SR, USART_SR_TC_Pos) );
}
/*#define USART_TX_GeCompleteFlag(USARTx) \
	GetBit(USARTx->SR, USART_SR_TC_Pos)*/
/*#define USART1_TX_GeTransferCompletionStatus \
	USART_TX_GeCompleteFlag(USART1)
#define USART2_TX_GeTransferCompletionStatus \
	USART_TX_GeCompleteFlag(USART2)*/


/*#define USART_PutChar(USARTx, DATA)\
	USART_TransmitData(USARTx, DATA);\
	while(!USART_TX_GetEmptyFlag(USARTx)){};*/
/*#define USART1_PutChar(DATA)\
	USART_PutChar(USART1, DATA);
#define USART2_PutChar(DATA)\
	USART_PutChar(USART2, DATA);*/	

/*#define USART_PutNewLine(USARTx)\
	USART_TransmitData(USARTx, '\r');\
	while(!USART_TX_GetEmptyFlag(USARTx)){};\
	USART_TransmitData(USARTx, '\n');\
	while(!USART_TX_GetEmptyFlag(USARTx)){};
#define USART1_PutNewLine\
	USART_PutNewLine(USART1);
#define USART2_PutNewLine\
	USART_PutNewLine(USART2);*/

///void USART1_NVIC_Configuration(void);		
//void USART2_NVIC_Configuration(void);
//void USART_ClearString(char *str);
//void USART1_PutChar(char data);
//void USART2_PutChar(char data);
/*void USART1_PutString(char *str);
void USART2_PutString(char *str);
void USART1_PutStringFromFlash(const char *str);
void USART2_PutStringFromFlash(const char *str);*/

void USART_PutChar(USART_TypeDef *USARTx, uint16_t data);
void USART_PutString(USART_TypeDef *USARTx, char *str);
void USART_PutStringFromFlash(USART_TypeDef *USARTx, const char *str);
void USART_ClearString(char *str);

void USART1_ConfigDefault1_TX_RXINT(void);
void USART1_ConfigDefault2_TX(void);
void USART2_ConfigDefault1_TX_RXINT(void);
void USART3_ConfigDefault1_TX_RXINT(void);
		
#ifdef __cplusplus
}
#endif

#endif	// _STM32F1xx_BM_USART_INCLUDED