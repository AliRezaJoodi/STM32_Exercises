#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED


#define AJ_TARGET_CONFIG
    #define AJ_TARGET_CORE_CLOCK_HZ             16000000U   /*!< Core clock (HCLK) in Hz */

#define AJ_BUZZER_CONFIG
    #define AJ_BUZZER_ACTIVE       1U
    #define AJ_BUZZER_COUNT1       75U
    #define AJ_BUZZER_COUNT2       200U

#define AJ_BUZZER_CONFIG_PLATFORM
    #define AJ_BUZZER_GPIO         GPIOC
    #define AJ_BUZZER_POS          13U
    #define AJ_BUZZER_MASK         (1U << AJ_BUZZER_POS)


#endif
