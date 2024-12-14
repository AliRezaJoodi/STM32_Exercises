## USART with LL(Low Layer) Drivers, Receiver 2-Byte

Data Format:
Start Byte: 254
Data1: 123 for LED
Data2: 1 for On, 0 for Off
Check Sume: (Data1+Data2)&0xFF
              
MCU:     	STM32F103C8  
System Clock:	8MHz with HSI RC  
USART1:		Asyncron, 9600  
USART1_TX:	Enable
USART1_RX:	Enable
USART1_RX_INT:	Enable    

### Folder and Files Description
It has included:
- `Core` (User Code with C Language)
- `MDK-ARM` (IDE File for Keil uVision5)
- `Simulate` (Simulator File)
- `Code_VB6` (Software with Visual Basic)
- `Main.ioc` (Code Generator with STM32CubeMX)

### Simulate: v1.0
![](Simulate/v1.0.png)

My GitHub Account: [GitHub.com/AliRezaJoodi](https://github.com/AliRezaJoodi)  
**Note**: [You can go here to download a single folder or file from GitHub.com](https://minhaskamal.github.io/DownGit/#/home)
