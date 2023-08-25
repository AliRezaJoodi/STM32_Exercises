### CMSIS/system_stm32f1xx.c
- `#define HSE_VALUE 8000000U`
- `#define HSI_VALUE 8000000U`
- `uint32_t SystemCoreClock = 8000000;`

### CMSIS/stm32f1xx.h
- `#define STM32F103xB`

### STM32F1xx_HAL/stm32f1xx_ll_utils.c
- `LL_Init1msTick(8000000);`
- `LL_SetSystemCoreClock(8000000);`
