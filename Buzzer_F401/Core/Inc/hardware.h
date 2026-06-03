#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_32BIT

#define TIMEBASE_CONFIG
    #define TIMEBASE_REG32_U32

#define BUZZER_HARDWARE
    #define BUZZER_ACTIVE       1U
    #define BUZZER_COUNT1       75U
    #define BUZZER_COUNT2       200U

    #define BUZZER_GPIO         GPIOC
    #define BUZZER_PIN          13U
    #define BUZZER_MASK         (1U << BUZZER_PIN)

#endif
