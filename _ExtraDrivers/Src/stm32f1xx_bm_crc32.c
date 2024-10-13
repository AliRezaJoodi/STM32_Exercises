// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_crc32.h>

uint32_t CRC32_Calculate(uint32_t *data, uint32_t length){	
	BUS_CRC_EnableOrDisable(1);
	CRC32_ResetValue();
	
  for(uint8_t i=0; i<length; i++){
			CRC32_FeedDataIn32Bits(data[i]);
  }
	
	uint32_t crc32 = CRC32_ReadValue();
  return crc32;
}
