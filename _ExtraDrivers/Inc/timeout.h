// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>

#ifdef HARDWARE_LOCAL
	#include "_hardware.h"
#endif

#ifndef TIMEOUT_INCLUDED
#define TIMEOUT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TIMEOUT_HARDWARE
#define TIMEOUT_HARDWARE
	#define TIMEOUT_DURATION		1000000
#endif

__STATIC_INLINE uint32_t Timeout_WaitUntil(uint32_t (*condition_func)(void), uint32_t status) {
	uint32_t timeout = TIMEOUT_DURATION;

  while (condition_func() != status){
		#if TIMEOUT_DURATION !=0
			if (timeout-- == 0){
				return 1;		// Unsuccessful
			}
		#endif
  }
	
  return 0;		// Successful
}

#ifdef __cplusplus
}
#endif

#endif		// TIMEOUT_INCLUDED