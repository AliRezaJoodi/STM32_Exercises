## STM32 Programming Exercises
Personal repository for STM32 exercise

## Setup: STM32Cube Firmware Drivers
To keep the repository lightweight, the `Drivers` folder is intentionally ignored in all exercises.  
Each example has a project structure similar to this:   
```
GPIO_F103
|-- HAL
|-- LL
    |-- Core
    |-- Drivers  (ignored in repository)
    |-- MDK-ARM
    |-- main.ioc
```
Before building a project, you need to provide the missing `Drivers` folder manually.  
You can do one of the following:  
- Create a junction link to the official STM32Cube firmware `Drivers` folder.  
- Or temporarily copy the `Drivers` folder from your STM32Cube package into the project path.  

Either method will make the project build successfully.

## Setup: Shared Library (CrossPlatformLibraries)
The following diagram shows the typical folder structure used for bare-metal exercises.  
```
GPIO_F103
|-- HAL
|-- LL
|-- BareMetal
    |-- Core
    |-- CrossPlatformLibraries  (ignored in repository)
    |-- Drivers  (ignored in repository)
    |-- MDK-ARM
    |-- main.ioc
```
bare-metal exercises use my personal cross-platform libraries.  
They are available in the following repository:  
[https://github.com/AliRezaJoodi/CrossPlatformLibraries](https://github.com/AliRezaJoodi/CrossPlatformLibraries)  
Please clone or download this repository.  
To build the exercises, the `CrossPlatformLibraries` folder must be accessible next to the exercise project.  
You can do one of the following:  
- Create a junction link so that the `CrossPlatformLibraries` folder appears beside the exercise project.  
- Or temporarily copy the `CrossPlatformLibraries` folder beside the exercise project.  

Either method will allow the project to build correctly.  

### Useful CMD codes
- `cd /d D:\GitHub\STM32_Exercises\GPIO_F103\BareMetal`
- `mklink /J Drivers D:\SDKs\STM32Cube_FW_F1_V1.8.7\Drivers`
- `mklink /J Drivers D:\SDKs\STM32Cube_FW_F4_V1.28.3\Drivers`
- `mklink /J CrossPlatformLibraries D:\GitHub\CrossPlatformLibraries`
- `rmdir SDK`

### Useful Links
GitHub Profile:  
[GitHub.com/AliRezaJoodi](https://github.com/AliRezaJoodi)   
Download single folder or file from GitHub:  
[https://minhaskamal.github.io/DownGit/#/home](https://minhaskamal.github.io/DownGit/#/home)  

## Abbreviations
- **F103**: STM32F103  
- **F401**: STM32F401  
- **F407**: STM32F407 
 
<!--
### Table of Contents
|Title					|Bare Metal|LL |HAL|
|:--------------------------------------|:--------:|:-:|:-:|
|[AFIO_F103](AFIO_F103)			|Y	   |Y  |-  |
|[GPIO_F103](GPIO_F103)			|Y	   |Y  |Y  |
|[GPIO_F401](GPIO_F401)			|Y	   |Y  |Y  |
|[GPIO_F407](GPIO_F407)			|-	   |-  |Y  |
|[Utility_Bit](Utility_Bit)		|-	   |-  |-  |

-->