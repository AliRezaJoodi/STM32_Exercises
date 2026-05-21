## Bare-Metal Exercises Using CMSIS
GPIO is implemented using direct register access through CMSIS definitions.

### Features
- **GPIO Library:** CrossPlatformLibraries that using CMSIS
- **Default Framework:** LL Drivers from STM32Cube_FW_F4_V1.28.3
- **System Clock:** HSI (Internal RC), 16 MHz 
- **Debug Interface:** JTAG (4 Pins)
    
### Folder and Files
- `Core` (User Code with C Language)
- `CrossPlatformLibraries` (ignored in repository)
- `Drivers` (STM32Cube Firmware Drivers – ignored in repository)
- `MDK-ARM` (IDE File for Keil uVision5)
- `Main.ioc` (Code Generator with STM32CubeMX)

Note:  
- The `Drivers` folders are not included in this repository to keep it lightweight. 
- The `CrossPlatformLibraries` folders are not included in this repository to keep it lightweight.  
Please refer to the main repository README for setup instructions. 

