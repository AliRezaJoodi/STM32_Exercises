// GitHub Account: GitHub.com/AliRezaJoodi

#include <button.h>

//********************************
 void _Button_EnableBusForGPIO(void){
	#ifdef BUTTON1_PIN
		if(BUTTON1_GPIO == GPIOA){BUS_GPIOA_EnableOrDisable(1);}
			else if(BUTTON1_GPIO ==	GPIOB){BUS_GPIOB_EnableOrDisable(1);}
				else if(BUTTON1_GPIO ==	GPIOC){BUS_GPIOC_EnableOrDisable(1);}
					else if(BUTTON1_GPIO ==	GPIOD){BUS_GPIOD_EnableOrDisable(1);}
	#endif

	#ifdef BUTTON2_PIN
		if(BUTTON2_GPIO == GPIOA){BUS_GPIOA_EnableOrDisable(1);}
			else if(BUTTON2_GPIO ==	GPIOB){BUS_GPIOB_EnableOrDisable(1);}
				else if(BUTTON2_GPIO ==	GPIOC){BUS_GPIOC_EnableOrDisable(1);}
					else if(BUTTON2_GPIO ==	GPIOD){BUS_GPIOD_EnableOrDisable(1);}
	#endif

	#ifdef BUTTON3_PIN
		if(BUTTON3_GPIO == GPIOA){BUS_GPIOA_EnableOrDisable(1);}
			else if(BUTTON3_GPIO ==	GPIOB){BUS_GPIOB_EnableOrDisable(1);}
				else if(BUTTON3_GPIO ==	GPIOC){BUS_GPIOC_EnableOrDisable(1);}
					else if(BUTTON3_GPIO ==	GPIOD){BUS_GPIOD_EnableOrDisable(1);}
	#endif				
}
 
//*************************************************
void Button_Config(void){
	_Button_EnableBusForGPIO();
	
	#ifdef BUTTON1_PIN
		#if BUTTON_PRESSED == 0
			GPIO_ConfigPinForPullUpInputMode(BUTTON1_GPIO,BUTTON1_PIN);   
		#else
			GPIO_ConfigPinForPullDownInputMode(BUTTON1_GPIO,BUTTON1_PIN);
		#endif
	#endif
	
	#ifdef BUTTON2_PIN
		#if BUTTON_PRESSED == 0
			GPIO_ConfigPinForPullUpInputMode(BUTTON2_GPIO,BUTTON2_PIN);   
		#else
			GPIO_ConfigPinForPullDownInputMode(BUTTON2_GPIO,BUTTON2_PIN);
		#endif
	#endif
	
	#ifdef BUTTON3_PIN
		#if BUTTON_PRESSED == 0
			GPIO_ConfigPinForPullUpInputMode(BUTTON3_GPIO,BUTTON3_PIN);  
		#else
			GPIO_ConfigPinForPullDownInputMode(BUTTON3_GPIO,BUTTON3_PIN);		
		#endif
	#endif
}

#ifdef BUTTON1_PIN
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
#endif

#ifdef BUTTON2_PIN
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
#endif


#ifdef BUTTON3_PIN
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
#endif
