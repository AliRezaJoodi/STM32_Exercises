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

#include <display_7segment_1digit_bm.h>

char usart1_txt[16]="";
volatile char usart1_task=0;
void Button_Config(void);

int main(void){
	char status=1;
	unsigned char i =0; 

	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);
  RCC_SystemClock_ConfigDefault1();
	
	Button_Config();
	Display7Segment1Digit_Config();
	Display7Segment1Digit_SetOnOff(1);
	Display7Segment1Digit_DisplayValue(9);
	
  while(1){
		
		if(GPIO_GetPin(GPIOB,0)==0 && status==1){
			Delay_ms(30);
			if(GPIO_GetPin(GPIOB,0)==0 && status==1){
				status=0;
				i++; if(i>9){i=0;}
				Display7Segment1Digit_DisplayValue(i);
			}
		}
		if(GPIO_GetPin(GPIOB,0)==1 && status==0){
			Delay_ms(30);
			if(GPIO_GetPin(GPIOB,0)==1 && status==0){status=1;}
		}
		
	}
}

//**************************************
void Button_Config(void){
	BUS_GPIOB_EnableOrDisable(1); 
	GPIO_InputWithPullUpMode_ConfigPin(GPIOB,0);
}





