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
void Buttons_Config(void);
void BcdInput_Config(void);
void BcdDisplay_Config(void);
void Button1(void);
void Button2(void);

int main(void){
	uint32_t value=0;
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugMode(SWJ_SWD);

  RCC_SystemClock_ConfigDefault1();

	Buttons_Config();
	LED_Config();
	BcdInput_Config();
	BcdDisplay_Config();
	
  while(1){
		Button1();
		Button2();
		
		value= GPIO_Get4Pin(GPIOA,4);
		GPIO_Write4Pin(GPIOB,12, value);
  }
}

//**********************************************
void Button1(void){
		static char status=1;
	
    if(GPIO_GetPin(GPIOA,0)==0 && status==1){
				Delay_ms(30);
				if(GPIO_GetPin(GPIOA,0)==0){
					status=0;
					GPIO_TogglePin(GPIOC,13);
				}
		}
    else if(GPIO_GetPin(GPIOA,0)==1 && status==0){
			Delay_ms(30);
			if(GPIO_GetPin(GPIOA,0)==1){
				status=1;
			}	
		}		
}

//**********************************************
void Button2(void){
	static char status=0;

		if(GPIO_GetPin(GPIOA,1)==1 && status==0){
				Delay_ms(30);
				if(GPIO_GetPin(GPIOA,1)==1){
					status=1;
					GPIO_SetPin(GPIOC,13);
				}
		}
		else if(GPIO_GetPin(GPIOA,1)==0 && status==1){
			Delay_ms(30);
			if(GPIO_GetPin(GPIOA,1)==0){
				status=0;
			}	
		}	
}

//**************************************
void BcdInput_Config(void){
	BUS_GPIOA_EnableOrDisable(1);
	
	GPIO_InputWithFloatingMode_ConfigPin(GPIOA,4);
	GPIO_InputWithFloatingMode_ConfigPin(GPIOA,5);
	GPIO_InputWithFloatingMode_ConfigPin(GPIOA,6);
	GPIO_InputWithFloatingMode_ConfigPin(GPIOA,7);
}

//**************************************
void BcdDisplay_Config(void){
	BUS_GPIOB_EnableOrDisable(1);
	
	GPIO_OutputWithPushPullMode_ConfigPin(GPIOB,12);
	GPIO_ResetPin(GPIOB,12);
	
	GPIO_OutputWithPushPullMode_ConfigPin(GPIOB,13);
	GPIO_ResetPin(GPIOB,13);
	
	GPIO_OutputWithPushPullMode_ConfigPin(GPIOB,14);
	GPIO_ResetPin(GPIOB,14);
	
	GPIO_OutputWithPushPullMode_ConfigPin(GPIOB,15);
	GPIO_ResetPin(GPIOB,15);
}

//**************************************
void Buttons_Config(void){
	BUS_GPIOA_EnableOrDisable(1); 
	
	GPIO_InputWithPullUpMode_ConfigPin(GPIOA,0);
	GPIO_InputWithPullDownMode_ConfigPin(GPIOA,1);
}

//**************************************
void LED_Config(void){
	BUS_GPIOC_EnableOrDisable(1);
	
	GPIO_OutputWithPushPullMode_ConfigPin(GPIOC,13);
	GPIO_ResetPin(GPIOC,13);
}

