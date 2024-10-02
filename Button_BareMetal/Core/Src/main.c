// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_timer_systick.h>
#include <button_bm.h>

uint32_t value=3;

void BcdDisplay_Config(void);

int main(void){
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
  RCC_SystemClock_ConfigDefault1();

	Button_Config();
	BcdDisplay_Config();
	
  while(1){
		if(Button1_OneStep()){++value;}
		if(Button2_Continuous()){++value;} 
		if(Button3_OneStep()){value=0;}
		
		GPIO_Write4Pin(GPIOA,3, value);
  }
}

//**************************************
void BcdDisplay_Config(void){
	BUS_GPIOA_EnableOrDisable(1);
	
	GPIO_ConfigPinForPushPullOutputMode(GPIOA,3);
	GPIO_ConfigPinForPushPullOutputMode(GPIOA,4);
	GPIO_ConfigPinForPushPullOutputMode(GPIOA,5);
	GPIO_ConfigPinForPushPullOutputMode(GPIOA,6);
}





