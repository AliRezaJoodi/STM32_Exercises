// GitHub Account: GitHub.com/AliRezaJoodi

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <delay.h>
#include <display_lcd.h>

#include "_SystemClock.h"

int main(void){
	const char txt1[16]="012345678901234";
	char txt[16]="AliRezaJoodi";

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0)); // SysTick_IRQn interrupt configuration
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWD_ON__JTAG_OFF);

  SystemClock_Config();

	LCD_Config();
	LCD_GoToXY(0,0); LCD_PutString("0123456789012345"); Delay_ms(250);
	LCD_SetOnOff(0); Delay_ms(250);
	LCD_SetOnOff(1); Delay_ms(250);
	LCD_GoToXY(0,1); LCD_PutString(txt); Delay_ms(250);
	LCD_Cursor_SetOnOff(1); Delay_ms(250);
	LCD_ClearDisplay();
	LCD_PutChar(65);
	LCD_BlinkingCursor_SetOnOff(1); Delay_ms(2000);
	LCD_BlinkingCursor_SetOnOff(0); Delay_ms(1000);
	LCD_Cursor_SetOnOff(0); Delay_ms(250);

  while(1){
  }
}




