// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
	Abbreviations:
*/

#include <stm32f1xx.h>
#include <utility.h>
#include <timeout.h>

#ifdef HARDWARE_LOCAL
	#include "_hardware.h"
#endif

#ifndef _STM32F1xx_BM_RTC_INCLUDED
#define _STM32F1xx_BM_RTC_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RTC_HARDWARE
#define RTC_HARDWARE
#endif

#ifdef __cplusplus
}
#endif

#endif		// _STM32F1xx_BM_RTC_INCLUDED