#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define TIMEBASE_CONFIG
    #define TIMEBASE_REG32_U32

#define BUZZER_HARDWARE
    #define BUZZER_ACTIVE       0U
    #define BUZZER_COUNT1       75U
    #define BUZZER_COUNT2       200U

    #define BUZZER_GPIO         GPIOC
    #define BUZZER_PIN          13U
    #define BUZZER_MASK         (1U << BUZZER_PIN)

#endif
