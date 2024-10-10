
#include <stm32f1xx.h>
#include <stdio.h>

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_pwr.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_timer_systick.h>
#include <stm32f1xx_bm_usart.h>
#include <stm32f1xx_bm_rtc.h>
#include <stm32f1xx_bm_it.h>

//void write_uart(char data){
//	//while(!LL_USART_IsActiveFlag_TXE(USART1));
//	//LL_USART_TransmitData8(USART1, (uint8_t)data);
//}
	
/* Retargeting stdout_putchar as to use USART_TX for data output */	
int stdout_putchar(int ch){
	//write_uart(ch);
	return (ch);
}

struct time_t
{
  uint8_t sec;
  uint8_t min;
  uint8_t hour;
};
struct time_t time;
struct time_t alarm;

int main(void){
	char txt[50];
	char error=0;
	char buffer=0;
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
	RCC_SystemClock_ConfigDefault1();
	RCC_RTC_ConfigDefault1();
	RTC_ConfigDefault1();
	USART1_ConfigDefault2_TX();
	USART_PutStringFromFlash(USART1, "USART1 Test");
	NVIC_Config();

//	error= RTC_ConfigTime(23, 59, 55);
//	sprintf(txt, "%.1d: Error in RTC_ConfigTime", error);	
//	USART_PutString(USART1, txt);
//	
//	error= RTC_ConfigAlarm(00, 00, 5);
//	sprintf(txt, "%.1d: Error in RTC_ConfigAlarm", error);	
//	USART_PutString(USART1, txt);

//	buffer= _AlarmInterrupt_GetEnableStatus();
//	sprintf(txt, "%.1d: Status in AlarmInterrupt", buffer);	
//	USART_PutString(USART1, txt);
//	
//	buffer= _OverflowInterrupt_GetEnableStatus();
//	sprintf(txt, "%.1d: Status in OverflowInterrupt", buffer);	
//	USART_PutString(USART1, txt);
//	
//	buffer= _SecondInterrupt_GetEnableStatus();
//	sprintf(txt, "%.1d: Status in SecondInterrupt", buffer);	
//	USART_PutString(USART1, txt);

	while(1){
		//if(RTC_AlarmFlag_GetFlag()){ USART_PutStringFromFlash(USART1, "AlarmFlag: 1"); }
		//if(RTC_OverflowFlag_GetFlag()){ USART_PutStringFromFlash(USART1, "OverflowFlag: 1"); }
		if(rtc_second_task){
			rtc_second_task=0;
			RTC_GetTime(&time.hour, &time.min, &time.sec);	
			sprintf(txt, "%.2d:%.2d:%.2d", time.hour, time.min, time.sec);	
			USART_PutString(USART1, txt);	
		}
  }
}

