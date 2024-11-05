// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>

#include <stm32f1xx_bm_timer_systick.h>
#include <delay_nop.h>
#define Delay_us(VALUE)		DelayNop_us(VALUE)
#define Delay_ms(VALUE)		DelayNop_ms(VALUE)

void LED_Config(void);

int main(void){
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
  RCC_SystemClock_ConfigDefault1();
	
	LED_Config();
	
  while(1){	
		//GPIO_TogglePin(GPIOC,13); Delay_ms(1000);
		//if(Refresh()){GPIO_TogglePin(GPIOC,13);}
		GPIO_ResetPin(GPIOC,13); Delay_ms(10);
		GPIO_SetPin(GPIOC,13); Delay_ms(1000); 
		//GPIO_WritePin(GPIOC,13,0); Delay_ms(500);
		//GPIO_WritePin(GPIOC,13,1); Delay_ms(500); 
  }
}

//**************************************
void LED_Config(void){
	BUS_GPIOC_EnableOrDisable(1);
	GPIO_ConfigPinForPushPullOutputMode(GPIOC,13);
	GPIO_SetPin(GPIOC,13);
	
}
