
### Define, BM, STM32F1xx
STM32F103xB,HSE_VALUE=8000000,HSI_VALUE=8000000,LSE_VALUE=32768,LSI_VALUE=40000

### Define, LL, STM32F1xx
USE_FULL_LL_DRIVER,HSE_VALUE=8000000,HSE_STARTUP_TIMEOUT=100,LSE_STARTUP_TIMEOUT=5000,LSE_VALUE=32768,HSI_VALUE=8000000,LSI_VALUE=40000,VDD_VALUE=3300,PREFETCH_ENABLE=1,STM32F103xB,HARDWARE_LOCAL

### Define, HAL, STM32F1xx
USE_HAL_DRIVER,STM32F103xB,HARDWARE_LOCAL

### Define, HAL, STM32F4xx
USE_HAL_DRIVER,STM32F407xx,HARDWARE_LOCAL

### Define, HAL and LL, STM32F1xx
USE_FULL_LL_DRIVER,USE_HAL_DRIVER,STM32F103xB,HARDWARE_LOCAL

### Include Paths, STM32F1xx
..\Core\Inc;..\..\_ExtraDrivers\Inc;..\..\_Drivers\CMSIS\Include;..\..\_Drivers\CMSIS\Device\ST\STM32F1xx\Include;..\..\_Drivers\STM32F1xx_HAL_Driver\Inc;..\..\_Drivers\STM32F1xx_HAL_Driver\Inc\Legacy

### Include Paths, STM32F4xx
..\Core\Inc;..\..\_ExtraDrivers\Inc;..\..\_Drivers\CMSIS\Include;..\..\_Drivers\CMSIS\Device\ST\STM32F4xx\Include;..\..\_Drivers\STM32F4xx_HAL_Driver\Inc;..\..\_Drivers\STM32F4xx_HAL_Driver\Inc\Legacy

### Groups
Application/MDK-ARM
Application/User/Core
Drivers/STM32F1xx_HAL_Driver
Drivers/CMSIS
Drivers/ExtraDrivers



