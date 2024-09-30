// GitHub Account: GitHub.com/AliRezaJoodi

#include <button_bm.h>
 
//*************************************************
void Button_Config(void){
	#ifdef BUTTON1_PIN
		BUS_GPIOx_EnableOrDisableWithAutoSearch(BUTTON1_GPIO);
		#if BUTTON_PRESSED == 0
			GPIO_ConfigPinForPullUpInputMode(BUTTON1_GPIO,BUTTON1_PIN);   
		#else
			GPIO_ConfigPinForPullDownInputMode(BUTTON1_GPIO,BUTTON1_PIN);
		#endif
	#endif
	
	#ifdef BUTTON2_PIN
		BUS_GPIOx_EnableOrDisableWithAutoSearch(BUTTON2_GPIO);
		#if BUTTON_PRESSED == 0
			GPIO_ConfigPinForPullUpInputMode(BUTTON2_GPIO,BUTTON2_PIN);   
		#else
			GPIO_ConfigPinForPullDownInputMode(BUTTON2_GPIO,BUTTON2_PIN);
		#endif
	#endif
	
	#ifdef BUTTON3_PIN
		BUS_GPIOx_EnableOrDisableWithAutoSearch(BUTTON3_GPIO);
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
        SysTick_Delay_1ms(BUTTON_LAG1);
        if(GPIO_GetPin(BUTTON1_GPIO,BUTTON1_PIN)==BUTTON_PRESSED){
            last_status=BUTTON_PRESSED;
            return 1; 
        } 
    }
    if(GPIO_GetPin(BUTTON1_GPIO,BUTTON1_PIN)==!BUTTON_PRESSED  && last_status==BUTTON_PRESSED){ 
        SysTick_Delay_1ms(BUTTON_LAG1);
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
        SysTick_Delay_1ms(BUTTON_LAG1);
        if(GPIO_GetPin(BUTTON2_GPIO,BUTTON2_PIN)==BUTTON_PRESSED){
            last_status=BUTTON_PRESSED;
            return 1; 
        } 
    }
    if(GPIO_GetPin(BUTTON2_GPIO,BUTTON2_PIN)==!BUTTON_PRESSED  && last_status==BUTTON_PRESSED){ 
        SysTick_Delay_1ms(BUTTON_LAG1);
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
        SysTick_Delay_1ms(BUTTON_LAG1);
        if(GPIO_GetPin(BUTTON3_GPIO,BUTTON3_PIN)==BUTTON_PRESSED){
            last_status=BUTTON_PRESSED;
            return 1; 
        } 
    }
    if(GPIO_GetPin(BUTTON3_GPIO,BUTTON3_PIN)==!BUTTON_PRESSED  && last_status==BUTTON_PRESSED){ 
        SysTick_Delay_1ms(BUTTON_LAG1);
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
