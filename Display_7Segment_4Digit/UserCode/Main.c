// GitHub Account: GitHub.com/AliRezaJoodi

#include "Utility.h"
#include "STM32F1xx_System_BareMetal.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "Display_7Segment.h"

int main(void){
	char status=1;
	unsigned char i =0; 
	
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // System interrupt init
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	AFIO_SetSerialWireDebugPort(FULL_SWJ);
  SystemClock_Configuration();
	SevenSegment_4Digit_Configuration();

	//SevenSegment_4Digit_UpdateNumbers_uint(1234);
	SevenSegment_4Digit_UpdateNumbers_float(1.2345);
	
  while(1){
		SevenSegment_4Digit_Refresh(1);
	}
}






