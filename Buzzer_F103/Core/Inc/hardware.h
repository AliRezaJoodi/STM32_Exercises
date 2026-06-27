#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS     32U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS    32U      /*!< Supported: 8, 16, 32 */

#define AJ_BUZZER_HARDWARE
    #define AJ_BUZZER_ACTIVE       0U
    #define AJ_BUZZER_COUNT1       75U
    #define AJ_BUZZER_COUNT2       200U

    #define AJ_BUZZER_GPIO         GPIOC
    #define AJ_BUZZER_POS          13U
    #define AJ_BUZZER_MASK         (1U << AJ_BUZZER_POS)

#endif
