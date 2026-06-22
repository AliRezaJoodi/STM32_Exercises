#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_32BIT

#define AJ_TIMEBASE_CONFIG
    #define AJ_TIMEBASE_REG32_U32

#define AJ_BUZZER_HARDWARE
    #define AJ_BUZZER_ACTIVE       1U
    #define AJ_BUZZER_COUNT1       75U
    #define AJ_BUZZER_COUNT2       200U

    #define AJ_BUZZER_GPIO         GPIOC
    #define AJ_BUZZER_POS          13U
    #define AJ_BUZZER_MASK         (1U << AJ_BUZZER_POS)

#endif
