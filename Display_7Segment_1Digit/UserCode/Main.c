// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdio.h>

#include "Utility.h"
#include "STM32F1xx_System_BareMetal.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "STM32F1xx_USART_BareMetal.h"
#include "Display_7Segment.h"

char usart1_txt[16]= "";
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
  USART1_Configuration();
	ConfigureButtons();
	DisplayOn7Segment_Configuration();
	
	USART1_PutChar('A');USART1_PutNewLine;	
	
	USART1_PutString("Test1\r\n");	
	
	const char txt2[]= "Test2\r\n";
	USART1_PutStringFromFlash(txt2);
	
	char txt3[]= "Test3\r\n";
	USART_ClearString(txt3);
	USART1_PutString(txt3);
	
	sprintf(txt3, "a=%3d", 12);
	USART1_PutString(txt3); USART1_PutNewLine;
	
	sprintf(txt3, "a=%.3f", 12.3456);
	USART1_PutString(txt3); USART1_PutNewLine;
	
	unsigned int a1=0;
	a1=USART1->BRR;
	//a1 = _DIV_SAMPLING16(8000000, 9600);
	sprintf(txt3, "BRR=%d", a1);
	USART1_PutString(txt3); USART1_PutNewLine;
	
	DisplayOn7Segment_Number(0);
	
  while(1){
		if(GPIO_GetPin(GPIOB,0)==0 && status==1){
			status=0;
			i++; if(i>9){i=0;}
			DisplayOn7Segment_Number(i);
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





