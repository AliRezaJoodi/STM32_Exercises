// GitHub Account: GitHub.com/AliRezaJoodi
// Bare Metal Programming

/*
Abbreviations:
	RTC: Real Time Clock
*/

/*
It's about:
	RTC_CRH 	/ RTC_CRL: 		RTC control register
	RTC_PRLH	/ RTC_PRLL:		RTC prescaler load register
	RTC_DIVH	/ RTC_DIVL: 	RTC prescaler divider register
	RTC_CNTH 	/ RTC_CNTL: 	RTC counter register
	RTC_ALRH 	/ RTC_ALRL: 	RTC alarm register
*/

/*
Resetting RTC registers:
	All system registers are asynchronously reset by a System Reset or Power Reset, 
	except for RTC_PRL, RTC_ALR, RTC_CNT, and RTC_DIV.
		
	The RTC_PRL, RTC_ALR, RTC_CNT, and RTC_DIV registers are reset only by a Backup Domain reset.
*/

#include <stm32f1xx.h>
#include <utility.h>
#include <timeout.h>
#include <stm32f1xx_bm_bus.h>

#ifdef HARDWARE_LOCAL
	#include "_hardware.h"
#endif

#ifndef _STM32F1xx_BM_RTC_INCLUDED
#define _STM32F1xx_BM_RTC_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/*
OWIE: Overflow interrupt enable
			1 Bit, Read/Write by software
			0: Overflow interrupt is masked.
			1: Overflow interrupt is enabled.
*/

__STATIC_INLINE uint32_t _OverflowInterrupt_GetEnableStatus(void){
		return ( GetBit(RTC->CRH, RTC_CRH_OWIE_Pos) );
}

__STATIC_INLINE uint32_t RTC_OverflowInterrupt_EnableOrDisable(uint32_t status){
	WriteBit(RTC->CRH, RTC_CRH_OWIE_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_OverflowInterrupt_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
ALRIE: Alarm interrupt enable
			1 Bit, Read/Write by software
			0: Overflow interrupt is masked.
			1: Overflow interrupt is enabled.
*/

__STATIC_INLINE uint32_t _AlarmInterrupt_GetEnableStatus(void){
		return ( GetBit(RTC->CRH, RTC_CRH_ALRIE_Pos) );
}

__STATIC_INLINE uint32_t RTC_AlarmInterrupt_EnableOrDisable(uint32_t status){
	WriteBit(RTC->CRH, RTC_CRH_ALRIE_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_AlarmInterrupt_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
SECIE: Second interrupt enable
			1 Bit, Read/Write by software
			0: Overflow interrupt is masked.
			1: Overflow interrupt is enabled.
*/

__STATIC_INLINE uint32_t _SecondInterrupt_GetEnableStatus(void){
		return ( GetBit(RTC->CRH, RTC_CRH_SECIE_Pos) );
}

__STATIC_INLINE uint32_t RTC_SecondInterrupt_EnableOrDisable(uint32_t status){
	WriteBit(RTC->CRH, RTC_CRH_SECIE_Pos, status);
	
	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_SecondInterrupt_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
RTOFF: 	RTC operation OFF
				1 Bit, Read only
				With this bit the RTC reports the status of the last write operation performed on its registers, 
				indicating if it has been completed or not.
				If its value is ‘0’ then it is not possible to write to any of the RTC registers. 
				0: Last write operation on RTC registers is still ongoing.
				1: Last write operation on RTC registers terminated.
*/

__STATIC_INLINE uint32_t RTC_LastWriteOperation_GetTerminatedStatus(void){
		return ( GetBit(RTC->CRL, RTC_CRL_RTOFF_Pos) );
}

/*
CNF: 	Configuration flag
			1 Bit, Read/Write by software
			This bit must be set by software to enter in configuration mode_
			so as to allow new values to be written in the RTC_CNT, RTC_ALR or RTC_PRL registers. 
			The write operation is only executed when the CNF bit is reset by software after has been set.
			0: Exit configuration mode (start update of RTC registers).
			1: Enter configuration mode.
*/

__STATIC_INLINE uint32_t _ConfigMode_GetEnableStatus(void){
	return ( GetBit(RTC->CRL, RTC_CRL_CNF_Pos) );
}

__STATIC_INLINE uint32_t RTC_ConfigMode_EnableOrDisable(uint32_t status){
	WriteBit(RTC->CRL, RTC_CRL_CNF_Pos, status);

	#ifdef TIMEOUT_INCLUDED
		return ( Timeout_WaitUntil(_ConfigMode_GetEnableStatus, status) );
	#else
		return 0;
	#endif	
}

/*
RSF: 	Registers synchronized flag
			1 Bit, set by hardware, cleared only by software
			This bit is set by hardware at each time the RTC_CNT and RTC_DIV registers are updated and cleared by software.
			Before any read operation after an APB1 reset or an APB1 clock stop, this bit must be cleared by software, 
			and the user application must wait until it is set to be sure_
			that the RTC_CNT, RTC_ALR or RTC_PRL registers are synchronized.
			0: Registers not yet synchronized.
			1: Registers synchronized.
*/

__STATIC_INLINE uint32_t RTC_SynchronizedFlag_GetFlag(void){
	return ( GetBit(RTC->CRL, RTC_CRL_RSF_Pos) );
}

__STATIC_INLINE void RTC_SynchronizedFlag_ClearFlag(void){
	ClearBit(RTC->CRL, RTC_CRL_RSF_Pos);
}

/*
OWF: 	Overflow flag
			1 Bit, set by hardware, cleared only by software
			This bit is set by hardware when the 32-bit programmable counter overflows. 
			An interrupt is generated if OWIE=1 in the RTC_CRH register. 
			0: Overflow not detected
			1: 32-bit programmable counter overflow occurred.
*/

__STATIC_INLINE uint32_t RTC_OverflowFlag_GetFlag(void){
	return ( GetBit(RTC->CRL, RTC_CRL_OWF_Pos) );
}

__STATIC_INLINE void RTC_OverflowFlag_ClearFlag(void){
	ClearBit(RTC->CRL, RTC_CRL_OWF_Pos);
}

/*
ALRF: Alarm flag
			1 Bit, set by hardware, cleared only by software
			This bit is set by hardware when the 32-bit programmable counter reaches the threshold set in the RTC_ALR register.
			An interrupt is generated if ALRIE=1 in the RTC_CRH register. 
			0: Alarm not detected
			1: Alarm detected
*/

__STATIC_INLINE uint32_t RTC_AlarmFlag_GetFlag(void){
	return ( GetBit(RTC->CRL, RTC_CRL_ALRF_Pos) );
}

__STATIC_INLINE void RTC_AlarmFlag_ClearFlag(void){
	ClearBit(RTC->CRL, RTC_CRL_ALRF_Pos);
}

/*
SECF: Second flag
			1 Bit, set by hardware, cleared only by software
			This bit is set by hardware when the 32-bit programmable prescaler overflows, thus incrementing the RTC counter. 
			Hence this flag provides a periodic signal with a period corresponding_
			to the resolution programmed for the RTC counter (usually one second).
			An interrupt is generated if SECIE=1 in the RTC_CRH register.
			0: Second flag condition not met.
			1: Second flag condition met.
*/

__STATIC_INLINE uint32_t RTC_SecondFlag_GetFlag(void){
	return ( GetBit(RTC->CRL, RTC_CRL_SECF_Pos) );
}

__STATIC_INLINE void RTC_SecondFlag_ClearFlag(void){
	ClearBit(RTC->CRL, RTC_CRL_SECF_Pos);
}

/*
RTC_PRLH:	RTC prescaler load register high
					4 Bits Included PRL[19:16], Write only
RTC_PRLL:	RTC prescaler load register low
					16 Bits Included PRL[15:0], Write only
					
					The Prescaler Load registers keep the period counting value of the RTC prescaler. 
					They are write-protected by the RTOFF bit in the RTC_CR register, and a write operation is allowed if the RTOFF value is ‘1’.

					These bits are used to define the counter clock frequency according to the following formula:
					F(TR_CLK) = F(RTC_CLK) / (PRL[19:0]+1)
					
					Note: The zero value is not recommended. RTC interrupts and flags cannot be asserted correctly.
					Note: If the input clock frequency is 32.768KHz, write 7FFFh in this register to get a signal period of 1 second.
*/

__STATIC_INLINE void RTC_PRL_WritePrescalerLoadValue(uint32_t value){
	RTC->PRLH = 0xF & (value >> 16);
  RTC->PRLL = 0xFFFF & value;
}

/*
RTC_DIVH: RTC prescaler divider register high
					16 Bits, Read Only, Included RTC_DIV[19:16]
RTC_DIVL: RTC prescaler divider register low
					16 Bits, Read Only, Included RTC_DIV[15:0]

					During each period of TR_CLK, the counter inside the RTC prescaler is reloaded with the value stored in the RTC_PRL register.
					To get an accurate time measurement it is possible to read the current value of the prescaler counter, 
					stored in the RTC_DIV register, without stopping it. 
					This register is read-only and it is reloaded by hardware after any change in the RTC_PRL or RTC_CNT registers.
*/

__STATIC_INLINE uint32_t RTC_DIV_GetDividerValue(void){
	uint32_t high= (RTC->DIVH) & 0xF;
	uint32_t low= (RTC->DIVL) & 0xFFFF;
	uint32_t out= (high<<16) | low;
	return out;
}

/*
RTC_CNTH: RTC counter register high
					16-bit, Read/Write by software and hardware
RTC_CNTL: RTC counter register low
					16-bit, Read/Write by software and hardware

					Note: For write to this register it is necessary to enter configuration mode.
*/

__STATIC_INLINE uint32_t RTC_CNT_GetCounterValue(void){
	uint32_t high= (RTC->CNTH) & 0xFFFF;
	uint32_t low= (RTC->CNTL) & 0xFFFF;
	uint32_t value= (high<<16) | low;
	return value;	
}

__STATIC_INLINE void RTC_CNT_WriteCounterValue(uint32_t value){
	RTC->CNTH = (value>>16) & 0xFFFF;
	RTC->CNTL = value & 0xFFFF;
}

/*
RTC_ALRH: RTC alarm register high
					16-bit, Write only by software
RTC_ALRL: RTC alarm register low
					16-bit, Write only by software

					Note: For write to this register it is necessary to enter configuration mode.
*/

__STATIC_INLINE void RTC_ALR_WriteAlarmValue(uint32_t value){
	RTC->ALRH = (value>>16) & 0xFFFF;
	RTC->ALRL = value & 0xFFFF;
}

//**********************************************************
uint32_t RTC_ConfigPrescalerLoadRegister(uint32_t value);
uint32_t RTC_ConfigTime(uint8_t hour, uint8_t min, uint8_t sec);
uint32_t RTC_ConfigAlarm(uint8_t hour, uint8_t min, uint8_t sec);

void RTC_ConfigDefault1(void);
uint32_t RTC_GetTime(uint8_t *hour, uint8_t *min, uint8_t *sec);

#ifdef __cplusplus
}
#endif

#endif		// _STM32F1xx_BM_RTC_INCLUDED