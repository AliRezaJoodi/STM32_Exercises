// GitHub Account: GitHub.com/AliRezaJoodi

// CRC32 introduction
// Standard:			IEEE 802.3
// Polynomial:		0x04C11DB7
// Default Value:	0xFFFFFFFF 

#include <stm32f1xx.h>

#include <utility.h>
#include <stm32f1xx_bm_bus.h>

#ifndef _STM32F1xx_BM_CRC32_INCLUDED
#define _STM32F1xx_BM_CRC32_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

__STATIC_INLINE void CRC32_ResetValue(void){
	SetBit(CRC->CR, CRC_CR_RESET_Pos);
}

__STATIC_INLINE void CRC32_FeedDataIn32Bits(uint32_t data){
  CRC->DR = data;
}
__STATIC_INLINE void CRC32_FeedDataIn8Bits(uint8_t data){
  CRC->IDR = data;
}

__STATIC_INLINE uint32_t CRC32_ReadValue(void){
	__NOP();
	uint32_t crc = CRC->DR;
  return crc;
}

__STATIC_INLINE uint32_t CRC32_Calculate(uint32_t *data, uint32_t length){	
	BUS_CRC_EnableOrDisable(1);
	CRC32_ResetValue();
	
  for(uint8_t i=0; i<length; ++i){
			CRC32_FeedDataIn32Bits(data[i]);
  }

	uint32_t crc = CRC32_ReadValue();
  return crc;
}


#ifdef __cplusplus
}
#endif

#endif		// _STM32F1xx_BM_CRC32_INCLUDED