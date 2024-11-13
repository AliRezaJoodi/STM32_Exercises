// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef TIMEOUT_INCLUDED
#define TIMEOUT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#ifndef TIMEOUT_VALUE
	#define TIMEOUT_VALUE		1000000
#endif

#define TIMEOUT_SUCCESS		0
#define TIMEOUT_ERROR			1

__STATIC_INLINE uint8_t Timeout_WaitUntil(uint8_t (*condition_func)(void), uint8_t status) {
	uint32_t timeout = TIMEOUT_VALUE;

  while(condition_func() != status){
			if (timeout-- == 0){
				return TIMEOUT_ERROR;
			}
  }
	
  return TIMEOUT_SUCCESS;
}

__STATIC_INLINE uint8_t Timeout_ADC_WaitUntil(uint8_t (*condition_func)(ADC_TypeDef *), ADC_TypeDef *ADCx, uint8_t status){
	uint32_t timeout = TIMEOUT_VALUE;

	while(condition_func(ADCx) != status){
		if(timeout-- == 0){
			return TIMEOUT_ERROR;
		}
	}

	return TIMEOUT_SUCCESS;
}

#ifdef __cplusplus
}
#endif

#endif		// TIMEOUT_INCLUDED