// GitHub Account: GitHub.com/AliRezaJoodi

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <delay.h>

#include "_SystemClock.h"
void LED_Config(void);
void Buttons_Config(void);
void BcdInput_Config(void);
void BcdDisplay_Config(void);
void Button1(void);
void Button2(void);

int main(void){
	uint32_t value=0;
	
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0)); // SysTick_IRQn interrupt configuration
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWD_ON__JTAG_OFF);

  SystemClock_Config();

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
	
    if(!GPIO_GetPin(GPIOA,0) && status==1){
				Delay_ms(30);
				if(!GPIO_GetPin(GPIOA,0)){
					status=0;
					GPIO_TogglePin(GPIOC,13);
				}
		}
    else if(GPIO_GetPin(GPIOA,0) && status==0){
			Delay_ms(30);
			if(GPIO_GetPin(GPIOA,0)){
				status=1;
			}	
		}		
}

//**********************************************
void Button2(void){
	static char status=0;

		if(GPIO_GetPin(GPIOA,1) && status==0){
				Delay_ms(30);
				if(GPIO_GetPin(GPIOA,1)){
					status=1;
					GPIO_SetPin(GPIOC,13);
				}
		}
		else if(!GPIO_GetPin(GPIOA,1) && status==1){
			Delay_ms(30);
			if(!GPIO_GetPin(GPIOA,1)){
				status=0;
			}	
		}	
}

//**************************************
void BcdInput_Config(void){
	BUS_GPIOA_EnableOrDisable(1);
	
	GPIO_SetInputOrOutputMode(GPIOA,4, IO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,4, INPUT_FLOATING);
	
	GPIO_SetInputOrOutputMode(GPIOA,5, IO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,5, INPUT_FLOATING);
	
	GPIO_SetInputOrOutputMode(GPIOA,6, IO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,6, INPUT_FLOATING);
	
	GPIO_SetInputOrOutputMode(GPIOA,7, IO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,7	, INPUT_FLOATING);
}

//**************************************
void BcdDisplay_Config(void){
	BUS_GPIOB_EnableOrDisable(1);
	
	GPIO_SetInputOrOutputMode(GPIOB,12, IO_OUTPUT);
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOB,12, OUTPUT_GP);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOB,12, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOB,12);
	
	GPIO_SetInputOrOutputMode(GPIOB,13, IO_OUTPUT);
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOB,13, OUTPUT_GP);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOB,13, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOB,13);
	
	GPIO_SetInputOrOutputMode(GPIOB,14, IO_OUTPUT);
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOB,14, OUTPUT_GP);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOB,14, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOB,14);
	
	GPIO_SetInputOrOutputMode(GPIOB,15, IO_OUTPUT);
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOB,15, OUTPUT_GP);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOB,15, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOB,15);
}

//**************************************
void Buttons_Config(void){
	BUS_GPIOA_EnableOrDisable(1); 
	
	GPIO_SetInputOrOutputMode(GPIOA,0, IO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,0, INPUT_PULLUP);
	
	GPIO_SetInputOrOutputMode(GPIOA,1, IO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,1,INPUT_PULLDOWN);
}

//**************************************
void LED_Config(void){
	BUS_GPIOC_EnableOrDisable(1);
	
	GPIO_SetInputOrOutputMode(GPIOC,13, IO_OUTPUT);
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOC,13, OUTPUT_GP);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOC,13, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOC,13);
}

