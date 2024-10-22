// GitHub Account: GitHub.com/AliRezaJoodi

//#include <_hardware.h>

#include <utility.h>
#include <stm32f1xx.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_timer_systick.h>
#include <delay_nop.h>
#include <display_lcd_bm.h>

int main(void){
	const char txt1[16]="012345678901234";
	char txt[16]="AliRezaJoodi";
	
	extern uint8_t char0[8];
	extern uint8_t char1[8];
	extern uint8_t char2[8];
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);

  RCC_SystemClock_ConfigDefault1();

	LCD_Config();
	
	LCD_Cursor_SetXY(0,0); LCD_PutString("0123456789012345"); Delay_ms(1000);
	LCD_Display_SetOnOff(0); Delay_ms(1000);
	LCD_Display_SetOnOff(1); Delay_ms(1000);
	LCD_Cursor_SetXY(0,1); LCD_PutString(txt); Delay_ms(1000);
	LCD_Cursor_SetOnOff(1); Delay_ms(1000);
	LCD_Display_Clear();
	LCD_PutChar(65);
	LCD_Cursor_SetBlinking(1); Delay_ms(1000);
	LCD_Cursor_SetBlinking(0); Delay_ms(1000);
	LCD_Cursor_SetOnOff(0); Delay_ms(1000);
	
	LCD_Cursor_SetXY(8,0); LCD_PutStringFromFlash("Line1");
	//LCD_Cursor_SetXY(8,1); LCD_PutStringFromFlash("Line2");
	
	LCD_DefineChar(char0, 0);
	LCD_DefineChar(char1, 1);
	LCD_DefineChar(char2, 2);
	
	LCD_Cursor_SetXY(0,1); 
	LCD_PutChar(0);
	LCD_PutChar(1);
	LCD_PutChar(2);
	
  while(1){
  }
}




