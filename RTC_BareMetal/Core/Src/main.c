/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"

#include <utility.h>
#include <stm32f1xx_bm_system.h>
#include <stm32f1xx_bm_pwr.h>
#include <stm32f1xx_bm_rcc.h>
#include <stm32f1xx_bm_bus.h>
#include <stm32f1xx_bm_gpio.h>
#include <stm32f1xx_bm_timer_systick.h>
#include <stm32f1xx_bm_usart.h>
#include <stm32f1xx_bm_rtc.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//uint32_t buffer=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* Function for transmitting 8bit data via USART */
void write_uart(char data){
	while(!LL_USART_IsActiveFlag_TXE(USART1));
	LL_USART_TransmitData8(USART1, (uint8_t)data);
}
	
/* Retargeting stdout_putchar as to use USART_TX for data output */	
int stdout_putchar(int ch){
	write_uart(ch);
	return (ch);
}

struct time_t
{
  uint8_t sec;
  uint8_t min;
  uint8_t hour;
};

struct time_t Time;
struct time_t Alarm;

uint32_t TimeCounter = 0;


void TIME_Update(void);
void TIME_Config(uint8_t, uint8_t, uint8_t);
void ALARM_Config(uint8_t, uint8_t, uint8_t);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  //LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_AFIO);
  //LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
	BUS_PWR_EnableOrDisable(1);
  /* System interrupt init*/
  //NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /** NOJTAG: JTAG-DP Disabled and SW-DP Enabled
  */
	BUS_AFIO_EnableOrDisable(1);
	GPIO_SWJ_SetDebugInterfaces(SWJ_SWD);
  //LL_GPIO_AF_Remap_SWJ_NOJTAG();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  //SystemClock_Config();
	RCC_SystemClock_ConfigDefault1();
	RCC_RTC_ConfigDefault1();
	//SysTick_ConfigDefault1_1ms();
  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  /* configue date, time and alarm and also enabling alarm interrupt */
//  LL_RTC_DisableWriteProtection(RTC);
//  LL_RTC_EnterInitMode(RTC);
//	LL_RTC_EnableIT_ALR(RTC);
//	LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_17);
//	LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_17);
//	
//	LL_RTC_ExitInitMode(RTC);
//	LL_RTC_EnableWriteProtection(RTC);		
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	
	//TIME_Config(23, 58, 57);
	//ALARM_Config(00, 00, 30);
	printf("TEST USART1 \r\n");
	//printf("GetRTCClockSource: %.2d\r\n", buffer);
	
  while(1){
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		/* update and print date and time */
		for(int i=0; i<10; i++){	
		TIME_Update();
		printf("Time: %.2d:%.2d:%.2d\r\n", Time.hour, Time.min, Time.sec);
		SysTick_Delay_1ms(995);
		//LL_mDelay(998);
		}
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
//void SystemClock_Config(void)
//{
//  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
//  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0)
//  {
//  }
//  LL_RCC_HSI_SetCalibTrimming(16);
//  LL_RCC_HSI_Enable();

//   /* Wait till HSI is ready */
//  while(LL_RCC_HSI_IsReady() != 1)
//  {

//  }

////	PWR_BackupDomain_EnableOrDisable(1);
////	
////	//LL_RCC_ForceBackupDomainReset();
////  //LL_RCC_ReleaseBackupDomainReset();
////	//LL_RCC_SetRTCClockSource(LL_RCC_RTC_CLKSOURCE_LSI);
////	//buffer=LL_RCC_GetRTCClockSource();
////	
////  if(_RTC_GetClockSource() != RTC_CLKSOURCE_LSE){
////		RCC_BackupDomain_ResetOrRelease(1);
////		RCC_BackupDomain_ResetOrRelease(0);
////		RCC_RTC_SetClockSource(RTC_CLKSOURCE_LSE);
////  }

////	RCC_LSE_EnableOrDisable(1);
////	RCC_RTC_EnableOrDisable(1);
////  RCC_RTC_ConfigDefault1();
//	
//  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
//  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
//  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
//  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

//   /* Wait till System clock is ready */
//  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
//  {

//  }
//  LL_Init1msTick(8000000);
//  LL_SetSystemCoreClock(8000000);
//}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void){
  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  LL_RTC_InitTypeDef RTC_InitStruct = {0};

  LL_PWR_EnableBkUpAccess();
  /* Enable BKP CLK enable for backup registers */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_BKP);
  /* Peripheral clock enable */
  //LL_RCC_EnableRTC();
	RCC_RTC_EnableOrDisable(1);

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC and set the Time and Date
  */
  RTC_InitStruct.AsynchPrescaler = 0xFFFFFFFFU;
  LL_RTC_Init(RTC, &RTC_InitStruct);
  LL_RTC_SetAsynchPrescaler(RTC, 0xFFFFFFFFU);
  /* USER CODE BEGIN RTC_Init 2 */
  /* set RTC clock prescaler to 32768 (8000-1 hex)*/
  RTC_InitStruct.AsynchPrescaler = 0x00007FFFU;
  LL_RTC_Init(RTC, &RTC_InitStruct);
  LL_RTC_SetAsynchPrescaler(RTC, 0x00007FFFU);
  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  LL_USART_InitTypeDef USART_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);

  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);
  /**USART1 GPIO Configuration
  PA9   ------> USART1_TX
  PA10   ------> USART1_RX
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_9;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_FLOATING;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  USART_InitStruct.BaudRate = 9600;
  USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
  USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
  USART_InitStruct.Parity = LL_USART_PARITY_NONE;
  USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
  USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
  USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
  LL_USART_Init(USART1, &USART_InitStruct);
  LL_USART_ConfigAsyncMode(USART1);
  LL_USART_Enable(USART1);
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOC);
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
//*****************************************************************
void TIME_Update(void)
{
  TimeCounter = LL_RTC_TIME_Get(RTC);
  Time.hour = (TimeCounter/3600) % 24;
  Time.min  = (TimeCounter % 3600) / 60;
  Time.sec  = (TimeCounter % 3600) % 60;
}

//*****************************************************************
void TIME_Config(uint8_t fHour, uint8_t fMin, uint8_t fSec){
  Time.hour = fHour;
  Time.min  = fMin;
  Time.sec  = fSec;

	LL_RTC_DisableWriteProtection(RTC);
  LL_RTC_EnterInitMode(RTC);
  
	LL_RTC_TIME_Set(RTC,((Time.hour * 3600) +
                       (Time.min * 60) +
                        Time.sec));
	
	LL_RTC_ExitInitMode(RTC);
	LL_RTC_EnableWriteProtection(RTC);
}

//*****************************************************************
void ALARM_Config(uint8_t fHour, uint8_t fMin, uint8_t fSec){
  Alarm.hour = fHour;
  Alarm.min  = fMin;
  Alarm.sec  = fSec;

	LL_RTC_DisableWriteProtection(RTC);
  LL_RTC_EnterInitMode(RTC);
	
  LL_RTC_ALARM_Set(RTC,((Alarm.hour * 3600) +
                        (Alarm.min * 60) +
                         Alarm.sec));
	
	LL_RTC_ExitInitMode(RTC);
	LL_RTC_EnableWriteProtection(RTC);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
