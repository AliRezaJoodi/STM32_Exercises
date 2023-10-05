
#include "main.h"
#include "Display_LCD.h"

void SystemClock_Config(void);

int main(void){
	const char txt1[16]="012345678901234";
	char txt[16]="012345678901234";

  HAL_Init();
  SystemClock_Config();

	LCD_Configuration();
	LCD_GoToXY(0,0); LCD_PutString("0123456789012345"); HAL_Delay(250);
	LCD_ConfigureDisplayStatus(0); HAL_Delay(250);
	LCD_ConfigureDisplayStatus(1); HAL_Delay(250);
	LCD_GoToXY(0,1); LCD_PutString(txt); HAL_Delay(250);
	LCD_ConfigureCursorStatus(1); HAL_Delay(250);
	LCD_ClearDisplay();
	LCD_PutChar(65);
	LCD_ConfigureBlinkingCursorStatus(1); HAL_Delay(2000);
	LCD_ConfigureBlinkingCursorStatus(0); HAL_Delay(1000);
	LCD_ConfigureCursorStatus(0); HAL_Delay(250);

  while(1){
  }
}


void SystemClock_Config(void){
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

void Error_Handler(void){
  __disable_irq();
  while (1){}
}


