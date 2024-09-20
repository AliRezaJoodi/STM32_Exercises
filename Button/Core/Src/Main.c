// GitHub Account: GitHub.com/AliRezaJoodi

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <delay.h>

uint32_t value=3;

#include <button.h>
#include "_SystemClock.h"

void BcdDisplay_Config(void);

int main(void){
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0)); // SysTick_IRQn interrupt configuration
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWD_ON__JTAG_OFF);

  SystemClock_Config();

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
	
	GPIO_SetInputOrOutputMode(GPIOA,3, IO_OUTPUT);
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOA,3, OUTPUT_GP);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,3, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,3);
	
	GPIO_SetInputOrOutputMode(GPIOA,4, IO_OUTPUT);
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOA,4, OUTPUT_GP);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,4, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,4);
	
	GPIO_SetInputOrOutputMode(GPIOA,5, IO_OUTPUT);
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOA,5, OUTPUT_GP);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,5, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,5);
	
	GPIO_SetInputOrOutputMode(GPIOA,6, IO_OUTPUT);
	GPIO_OutputMode_SetGeneralPurposeOrAlternateFunction(GPIOA,6, OUTPUT_GP);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,6, OUTPUT_PUSHPULL);
	GPIO_ResetPin(GPIOA,6);
}

//**********************************************
/*void Button1(void){
		static char status=1;
	
    if(GPIO_GetPin(GPIOA,0)==0 && status==1){
				Delay_ms(30);
				if(GPIO_GetPin(GPIOA,0)==0){
					status=0;
					++value;
				}
		}
    else if(GPIO_GetPin(GPIOA,0)==1 && status==0){
			Delay_ms(30);
			if(GPIO_GetPin(GPIOA,0)==1){
				status=1;
			}	
		}		
}*/

//**********************************************
/*void Button2(void){
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
}*/

//**************************************
/*void Buttons_Config(void){
	BUS_GPIOA_EnableOrDisable(1); 
	
	GPIO_SetInputOrOutputMode(GPIOA,0, IO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,0, INPUT_PULLUP);
	
	GPIO_SetInputOrOutputMode(GPIOA,1, IO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,1,INPUT_PULLUP);
	
	GPIO_SetInputOrOutputMode(GPIOA,2, IO_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,2,INPUT_PULLUP);
}*/


