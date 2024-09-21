### CMSIS/system_stm32f1xx.c
- `#define HSE_VALUE 8000000U`
- `#define HSI_VALUE 8000000U`
- `uint32_t SystemCoreClock = 8000000;`

### CMSIS/stm32f1xx.h
- `#define STM32F103xB`

### STM32F1xx_HAL/stm32f1xx_ll_utils.c
- `LL_Init1msTick(8000000);`
- `LL_SetSystemCoreClock(8000000);`

USE_FULL_LL_DRIVER,USE_HAL_DRIVER,STM32F103xB

### Define, BM
HSE_VALUE=8000000,HSE_STARTUP_TIMEOUT=100,LSE_STARTUP_TIMEOUT=5000,LSE_VALUE=32768,HSI_VALUE=8000000,LSI_VALUE=40000,VDD_VALUE=3300,PREFETCH_ENABLE=1,STM32F103xB,HARDWARE_LOCAL

### Define, LL
USE_FULL_LL_DRIVER,HSE_VALUE=8000000,HSE_STARTUP_TIMEOUT=100,LSE_STARTUP_TIMEOUT=5000,LSE_VALUE=32768,HSI_VALUE=8000000,LSI_VALUE=40000,VDD_VALUE=3300,PREFETCH_ENABLE=1,STM32F103xB,HARDWARE_LOCAL

### Define, HAL
USE_HAL_DRIVER,STM32F103xB,HARDWARE_LOCAL

### Define, HAL and LL
USE_FULL_LL_DRIVER,USE_HAL_DRIVER,STM32F103xB,HARDWARE_LOCAL

### Include Paths
..\Core\Inc;..\..\_ExtraDrivers\Inc;..\..\_Drivers\CMSIS\Include;..\..\_Drivers\CMSIS\Device\ST\STM32F1xx\Include;..\..\_Drivers\STM32F1xx_HAL_Driver\Inc;..\..\_Drivers\STM32F1xx_HAL_Driver\Inc\Legacy

### Groups
Application/MDK-ARM
Application/User/Core
Drivers/STM32F1xx_HAL_Driver
Drivers/CMSIS
Drivers/ExtraDrivers


