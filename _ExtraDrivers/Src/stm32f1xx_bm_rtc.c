// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx_bm_rtc.h>

/*
Configuring RTC registers:
	To write in the RTC_PRL, RTC_CNT, RTC_ALR registers, the peripheral must enter Configuration mode. 
	This is done by setting the CNF bit in the RTC_CRL register.
	
	In addition, writing to any RTC register is only enabled if the previous write operation is finished. 
	To enable the software to detect this situation, 
	the RTOFF status bit is provided in the RTC_CR register to indicate that an update of the registers is in progress.
	A new value can be written to the RTC registers only when the RTOFF status bit value is ’1’.
	
	Configuration procedure:
		1. Poll RTOFF, wait until its value goes to ‘1’
		2. Set the CNF bit to enter configuration mode
		3. Write to one or more RTC registers
		4. Clear the CNF bit to exit configuration mode
		5. Poll RTOFF, wait until its value goes to ‘1’ to check the end of the write operation.
	The write operation only executes when the CNF bit is cleared; 
	it takes at least three RTCCLK cycles to complete.
*/

//**********************************************************
uint32_t RTC_ConfigPrescalerLoadRegister(uint32_t value){
	char error=0;
	
	error= Timeout_WaitUntil(RTC_LastWriteOperation_GetTerminatedStatus,1);
	if(error ==0){
		error= RTC_ConfigMode_EnableOrDisable(1) | error;
		RTC_PRL_WritePrescalerLoadValue(value);
		error= RTC_ConfigMode_EnableOrDisable(0) | error;
		error= Timeout_WaitUntil(RTC_LastWriteOperation_GetTerminatedStatus,1) | error;
	}

	return error;
}

//**********************************************************
uint32_t RTC_ConfigTime(uint8_t hour, uint8_t min, uint8_t sec){
	char error=0;
	uint32_t value= (hour*3600) + (min*60) + sec;
	
	error= Timeout_WaitUntil(RTC_LastWriteOperation_GetTerminatedStatus,1);
	if(error ==0){
		error= RTC_ConfigMode_EnableOrDisable(1) | error;
		RTC_CNT_WriteCounterValue(value);
		error= RTC_ConfigMode_EnableOrDisable(0) | error;
		error= Timeout_WaitUntil(RTC_LastWriteOperation_GetTerminatedStatus,1) | error;
	}

	return error;
}

//**********************************************************
uint32_t RTC_ConfigAlarm(uint8_t hour, uint8_t min, uint8_t sec){
	char error=0;
	uint32_t value= (hour*3600) + (min*60) + sec;
	
	error= Timeout_WaitUntil(RTC_LastWriteOperation_GetTerminatedStatus,1);
	if(error ==0){
		error= RTC_ConfigMode_EnableOrDisable(1) | error;
		RTC_ALR_WriteAlarmValue(value);
		error= RTC_ConfigMode_EnableOrDisable(0) | error;
		error= Timeout_WaitUntil(RTC_LastWriteOperation_GetTerminatedStatus,1) | error;
	}

	return error;
}

/*
Reading RTC registers:
	Consequently when reading the RTC registers, after having disabled the RTC APB1 interface, 
	the software must first wait for the RSF bit (Register Synchronized Flag) in the RTC_CRL register to be set by hardware.

*/

//**********************************************************
uint32_t RTC_GetTime(uint8_t *hour, uint8_t *min, uint8_t *sec){
	RTC_SynchronizedFlag_ClearFlag();
	char error = Timeout_WaitUntil(RTC_SynchronizedFlag_GetFlag,1);
	if(error == 0){
		uint32_t value = RTC_CNT_GetCounterValue();
		*hour = (value/3600) % 24;
		*min = (value % 3600) / 60;
		*sec = (value % 3600) % 60;
	}
	return error;
}

//**********************************************************
void RTC_ConfigDefault1(void){
	BUS_BKP_EnableOrDisable(1);
	RTC_ConfigPrescalerLoadRegister(0x00007FFFU);	// TR_CLK = 1S
	
	RTC_OverflowInterrupt_EnableOrDisable(1);
	RTC_OverflowFlag_ClearFlag();
	
	RTC_AlarmInterrupt_EnableOrDisable(1);
	RTC_AlarmFlag_ClearFlag();
	
	RTC_SecondInterrupt_EnableOrDisable(1);
	RTC_SecondFlag_ClearFlag();
}