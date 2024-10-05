// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
	Abbreviations:
	PWR_CR: 		Power control register
*/

#include <stm32f1xx.h>
#include <utility.h>

#ifndef _STM32F1xx_BM_PWR_INCLUDED
#define _STM32F1xx_BM_PWR_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


/*
DBP:	Disable backup domain write protection.
			In reset state, the RTC and backup registers are protected against parasitic write access.
			This bit must be set to enable write access to these registers.
			0: Access to RTC and Backup registers disabled
			1: Access to RTC and Backup registers enabled
			Note: If the HSE divided by 128 is used as the RTC clock, this bit must remain set to 1. 
*/

__STATIC_INLINE uint32_t _BackupDomain_GetAccessStatus(void){
		return ( GetBit(PWR->CR, PWR_CR_DBP_Pos) );
}

//******************************************************************
__STATIC_INLINE void PWR_BackupDomain_EnableOrDisable(uint32_t status){
	WriteBit(PWR->CR, PWR_CR_DBP_Pos, status);
	while(_BackupDomain_GetAccessStatus() != status){};
}

#ifdef __cplusplus
}
#endif

#endif		// _STM32F1xx_BM_PWR_INCLUDED