// GitHub Account: GitHub.com/AliRezaJoodi

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <delay_nop.h>
#include <display_7segment_4digit_bm.h>

int main(void){
	char status=1;
	unsigned char i =0; 
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
  RCC_SystemClock_ConfigDefault1();
	
	Display7Segment4Digit_Config();
	Display7Segment4Digit_SetOnOff(1);
	
	//Display7Segment4Digit_SetValue_int(-12);
	Display7Segment4Digit_SetValue(-1.234);
	
  while(1){
		Display7Segment4Digit_Refresh();
	}
}






