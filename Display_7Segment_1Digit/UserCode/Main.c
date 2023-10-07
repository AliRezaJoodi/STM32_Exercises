// GitHub Account: GitHub.com/AliRezaJoodi

#include "Utility.h"
#include "STM32F1xx_System_BareMetal.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"

#include "Display_7Segment.h"

char usart1_txt[16]="";
volatile char usart1_task=0;
void ConfigureButtons(void);

int main(void){
	char status=1;
	unsigned char i =0; 
	
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	AFIO_SetSerialWireDebugPort(FULL_SWJ);
  SystemClock_Configuration();
	ConfigureButtons();
	
	SevenSegment_Configuration();
	SevenSegment_SetOnOff(1);
	SevenSegment_DisplayNumber(9);
	
  while(1){
		if(GPIO_GetPin(GPIOB,0)==0 && status==1){
			status=0;
			i++; if(i>9){i=0;}
			SevenSegment_DisplayNumber(i);
		}
		if(GPIO_GetPin(GPIOB,0)){status=1;}
	}
}

//**************************************
void ConfigureButtons(void){
	BUS_GPIOB_EnableOrDisable(1); 
	
	GPIO_SetInputOrOutputMode(GPIOB,0, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOB,0, INPUT_PULLUP);
}





