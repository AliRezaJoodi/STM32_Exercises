// GitHub Account: GitHub.com/AliRezaJoodi

#include "main.h"

#include "Utility.h"
#include "STM32F1xx_System_BareMetal.h"
#include "STM32F1xx_RCC_BareMetal.h"
#include "STM32F1xx_BUS_BareMetal.h"
#include "STM32F1xx_GPIO_BareMetal.h"
#include "STM32F1xx_USART_BareMetal.h"

uint8_t j=0;
volatile char usart1_task=0;
char txt[16]= "";

void ConfigureSystemClock(void);
static void ConfigureUSART1(void);
void USART1_IRQHandler(void);

int main(void){
  /* System interrupt init*/
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	
	BUS_PWR_EnableOrDisable(1);
	BUS_AFIO_EnableOrDisable(1);
	AFIO_SetSerialWireDebugPort(FULL_SWJ);

  ConfigureSystemClock();
  ConfigureUSART1();
	//LL_mDelay(500);

	USART1_PutChar('A'); USART1_PutNewLine;
	//USART1_PutNumber(9); USART1_PutNewLine;
	
	USART1_PutString("Test1\r\n");
	
	const char txt2[]= "Test2\r\n";
	USART1_PutStringFromFlash(txt2);
	
	char txt3[]= "Test3\r\n";
	USART1_PutString(txt3);
	
	//USART1_PutInteger(123);
	
  while(1){
		if(usart1_task==1){
			usart1_task=0;
			USART1_PutString(txt); USART1_PutNewLine;
		}	
  }
}

//*****************************************
void USART1_IRQHandler(void){
	static char c;
	static unsigned char i=0;
	
	if(USART1_RX_GetReceiveFlag && USART1_RX_INT_GetEnableStatus){
		if(c==13){
			do{--i; txt[i]=0;} while(i);
		}
				
		c = USART1_ReceiveData_8Bits;
		USART1_TransmitData(c);
		
		if(32<=c && c<127){txt[i]=c; ++i;}
			else if(c==13){i=0; usart1_task=1;}
	}
}

//****************************************************
void ConfigureSystemClock(void){
	FLASH_SetLatency(LATENCY0);
	RCC_HSI_SetCalibTrimming(16);
	RCC_HSI_EnableOrDisable(1);
	RCC_SYSCLK_SetClockSource(SYSCLK_HSI);
	RCC_AHB_SetPrescaler(AHB_DIV1);
	RCC_APB1_SetPrescaler(APB1_DIV1);
	RCC_APB2_SetPrescaler(APB2_DIV1);
		
	SystemCoreClockUpdate();	
  LL_Init1msTick(8000000);
	System_SetCoreClockFrequency(8000000);
}

//****************************************************
//PA9 -> USART1_TX
//PA10 -> USART1_RX
static void ConfigureUSART1(void){
	BUS_GPIOA_EnableOrDisable(1);
	GPIO_SetInputOrOutputMode(GPIOA,9, MODE_OUTPUT_50MHz);
	GPIO_OutputMode_SetGeneralOrAlternateOutput(GPIOA,9, OUTPUT_AFIO);
	GPIO_OutputMode_SetPushPullOrOpenDrain(GPIOA,9, OUTPUT_PUSHPULL);
	GPIO_SetInputOrOutputMode(GPIOA,10, MODE_INPUT);
	GPIO_InputMode_SetInputType(GPIOA,10, INPUT_FLOATING);
	
	USART1_ConfigureNVIC();
	BUS_USART1_EnableOrDisable(1);
	
  LL_USART_InitTypeDef USART_InitStruct = {0};
  USART_InitStruct.BaudRate = 9600;
  //USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
  //USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
  //USART_InitStruct.Parity = LL_USART_PARITY_NONE;
  //USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
  //USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
  USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
  LL_USART_Init(USART1, &USART_InitStruct);

	USART1_SetMode(MODE_ASYNCRON);
	USART1_SetDataBits(DATABITS_8B);
	USART1_SetParity(PARITY_NONE);
	USART1_SetStopBits(STOPBITS_1);
	USART1_TX_EnableOrDisable(1);
	USART1_TX_INT_EnableOrDisable(0);
	USART1_RX_EnableOrDisable(1);
	USART1_RX_INT_EnableOrDisable(1);
	USART1_CTS_EnableOrDisable(0);
	USART1_CTS_INT_EnableOrDisable(0);
	USART1_RTS_EnableOrDisable(0);	
	USART1_EnableOrDisable(1);
}

