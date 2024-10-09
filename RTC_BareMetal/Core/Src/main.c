
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

void write_uart(char data){
	//while(!LL_USART_IsActiveFlag_TXE(USART1));
	//LL_USART_TransmitData8(USART1, (uint8_t)data);
}
	
/* Retargeting stdout_putchar as to use USART_TX for data output */	
int stdout_putchar(int ch){
	write_uart(ch);
	return (ch);
}

struct time_t
{
  uint8_t sec;
  uint8_t min;
  uint8_t hour;
};

struct time_t Time;
struct time_t Alarm;

int main(void){
	char txt[20];

	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
	RCC_SystemClock_ConfigDefault1();
	RCC_RTC_ConfigDefault1();
	RTC_ConfigDefault1();
	USART1_ConfigDefault2_TX();
	USART_PutStringFromFlash(USART1, "USART1 Test");

  //MX_GPIO_Init();
  //MX_USART1_UART_Init();

//  LL_RTC_DisableWriteProtection(RTC);
//  LL_RTC_EnterInitMode(RTC);
//	LL_RTC_EnableIT_ALR(RTC);
//	LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_17);
//	LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_17);
//	
//	LL_RTC_ExitInitMode(RTC);
//	LL_RTC_EnableWriteProtection(RTC);		


//	error= RTC_ConfigTime(23, 59, 55);
//	printf("Error in RTC_ConfigTime: %1d\r\n", error);
//	
//	error= RTC_ConfigAlarm(00, 00, 5);
//	printf("Error in RTC_ConfigAlarm: %1d\r\n", error);
	

	
	//RTC_AlarmInterrupt_EnableOrDisable(1);	
  
	while(1){
		/*if(RTC_AlarmFlag_GetFlag()){
			printf("Alarm Flag = 1\r\n");
		}*/
		RTC_GetTime(&Time.hour, &Time.min, &Time.sec);	
		sprintf(txt, "Time: %.2d:%.2d:%.2d", Time.hour, Time.min, Time.sec);	
		USART_PutString(USART1, txt);
		
		SysTick_Delay_1ms(995);
  }
}

