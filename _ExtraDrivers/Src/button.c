// GitHub Account: GitHub.com/AliRezaJoodi

#include <button.h>

//********************************
 void _Button_EnableBusForGPIO(void){
	if( BUTTON1_GPIO 			==	GPIOA || \
			BUTTON2_GPIO 			==	GPIOA || \
			BUTTON3_GPIO 			==	GPIOA) 
		{BUS_GPIOA_EnableOrDisable(1);}

	if( BUTTON1_GPIO			==	GPIOB || \
			BUTTON2_GPIO			==	GPIOB || \
			BUTTON3_GPIO			==	GPIOB)
		{BUS_GPIOB_EnableOrDisable(1);}

	if( BUTTON1_GPIO			==	GPIOC || \
			BUTTON2_GPIO			==	GPIOC || \
			BUTTON3_GPIO			==	GPIOC)

	if( BUTTON1_GPIO			==	GPIOD || \
			BUTTON2_GPIO			==	GPIOD || \
			BUTTON3_GPIO			==	GPIOD)
		{BUS_GPIOD_EnableOrDisable(1);}	
}
 
//*************************************************
void Button_Config(void){
	_Button_EnableBusForGPIO();
	
	#ifdef BUTTON1_PIN
		GPIO_SetInputOrOutputMode(BUTTON1_GPIO,BUTTON1_PIN, IO_INPUT);
		#if BUTTON_PRESSED == 0
			GPIO_InputMode_SetInputType(BUTTON1_GPIO,BUTTON1_PIN, INPUT_PULLUP);    
		#else
			GPIO_InputMode_SetInputType(BUTTON1_GPIO,BUTTON1_PIN, INPUT_PULLDOWN);    
		#endif
	#endif
	
	#ifdef BUTTON2_PIN
		GPIO_SetInputOrOutputMode(BUTTON2_GPIO,BUTTON2_PIN, IO_INPUT);
		#if BUTTON_PRESSED == 0
			GPIO_InputMode_SetInputType(BUTTON2_GPIO,BUTTON2_PIN, INPUT_PULLUP);    
		#else
			GPIO_InputMode_SetInputType(BUTTON2_GPIO,BUTTON2_PIN, INPUT_PULLDOWN);    
		#endif
	#endif
	
	#ifdef BUTTON3_PIN
		GPIO_SetInputOrOutputMode(BUTTON3_GPIO,BUTTON3_PIN, IO_INPUT);
		#if BUTTON_PRESSED == 0
			GPIO_InputMode_SetInputType(BUTTON3_GPIO,BUTTON3_PIN, INPUT_PULLUP);    
		#else
			GPIO_InputMode_SetInputType(BUTTON3_GPIO,BUTTON3_PIN, INPUT_PULLDOWN);    
		#endif
	#endif
}

//*************************************************
char Button1_OneStep(void){
    static char last_status=!BUTTON_PRESSED; 
    
    if(GPIO_GetPin(BUTTON1_GPIO,BUTTON1_PIN)==BUTTON_PRESSED && last_status==!BUTTON_PRESSED){
        Delay_ms(BUTTON_LAG1);
        if(GPIO_GetPin(BUTTON1_GPIO,BUTTON1_PIN)==BUTTON_PRESSED){
            last_status=BUTTON_PRESSED;
            return 1; 
        } 
    }
    if(GPIO_GetPin(BUTTON1_GPIO,BUTTON1_PIN)==!BUTTON_PRESSED  && last_status==BUTTON_PRESSED){ 
        Delay_ms(BUTTON_LAG1);
        if(GPIO_GetPin(BUTTON1_GPIO,BUTTON1_PIN)==!BUTTON_PRESSED){last_status=!BUTTON_PRESSED;}
    }
    
    return 0; 
}

//*************************************************
char Button1_Continuous(void){
    static unsigned int i=0;
        
    if(GPIO_GetPin(BUTTON1_GPIO,BUTTON1_PIN)==BUTTON_PRESSED){
        ++i;
        if(i>=BUTTON_LAG2){i=0; return 1;} 
    }
    
    return 0; 
}

//*************************************************
char Button2_OneStep(void){
    static char last_status=!BUTTON_PRESSED; 
    
    if(GPIO_GetPin(BUTTON2_GPIO,BUTTON2_PIN)==BUTTON_PRESSED && last_status==!BUTTON_PRESSED){
        Delay_ms(BUTTON_LAG1);
        if(GPIO_GetPin(BUTTON2_GPIO,BUTTON2_PIN)==BUTTON_PRESSED){
            last_status=BUTTON_PRESSED;
            return 1; 
        } 
    }
    if(GPIO_GetPin(BUTTON2_GPIO,BUTTON2_PIN)==!BUTTON_PRESSED  && last_status==BUTTON_PRESSED){ 
        Delay_ms(BUTTON_LAG1);
        if(GPIO_GetPin(BUTTON2_GPIO,BUTTON2_PIN)==!BUTTON_PRESSED){last_status=!BUTTON_PRESSED;}
    }
    
    return 0; 
}

//*************************************************
char Button2_Continuous(void){
    static unsigned int i=0;
        
    if(GPIO_GetPin(BUTTON2_GPIO,BUTTON2_PIN)==BUTTON_PRESSED){
        ++i;
        if(i>=BUTTON_LAG2){i=0; return 1;} 
    }
    
    return 0; 
}

//*************************************************
char Button3_OneStep(void){
    static char last_status=!BUTTON_PRESSED; 
    
    if(GPIO_GetPin(BUTTON3_GPIO,BUTTON3_PIN)==BUTTON_PRESSED && last_status==!BUTTON_PRESSED){
        Delay_ms(BUTTON_LAG1);
        if(GPIO_GetPin(BUTTON3_GPIO,BUTTON3_PIN)==BUTTON_PRESSED){
            last_status=BUTTON_PRESSED;
            return 1; 
        } 
    }
    if(GPIO_GetPin(BUTTON3_GPIO,BUTTON3_PIN)==!BUTTON_PRESSED  && last_status==BUTTON_PRESSED){ 
        Delay_ms(BUTTON_LAG1);
        if(GPIO_GetPin(BUTTON3_GPIO,BUTTON3_PIN)==!BUTTON_PRESSED){last_status=!BUTTON_PRESSED;}
    }
    
    return 0; 
}

//*************************************************
char Button3_Continuous(void){
    static unsigned int i=0;
        
    if(GPIO_GetPin(BUTTON3_GPIO,BUTTON3_PIN)==BUTTON_PRESSED){
        ++i;
        if(i>=BUTTON_LAG2){i=0; return 1;} 
    }
    
    return 0; 
}