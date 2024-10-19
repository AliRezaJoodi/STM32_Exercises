#include "lcd_ll.h"

// Helper function to send 4 bits to the LCD
static void LCD_Send4Bits(uint8_t data);

// Initialize the LCD in 4-bit mode
void LCD_Init(void) {
    // Enable clock for GPIOA (or appropriate port)
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);

    // Set pins as output
    LL_GPIO_SetPinMode(LCD_GPIO_PORT, LCD_RS_PIN, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinMode(LCD_GPIO_PORT, LCD_EN_PIN, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinMode(LCD_GPIO_PORT, LCD_D4_PIN, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinMode(LCD_GPIO_PORT, LCD_D5_PIN, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinMode(LCD_GPIO_PORT, LCD_D6_PIN, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinMode(LCD_GPIO_PORT, LCD_D7_PIN, LL_GPIO_MODE_OUTPUT);

    // Wait for LCD to power up
    LL_mDelay(50);

    // Initialize LCD in 4-bit mode
    LCD_Send4Bits(0x03);
    LL_mDelay(2);
    LCD_Send4Bits(0x03);
    LL_mDelay(2);
    LCD_Send4Bits(0x03);
		LL_mDelay(2);
    LCD_Send4Bits(0x02);

    // Function set: 2 Line, 4-bit mode, 5x7 dots
    LCD_SendCommand(0x28);

    // Display ON, Cursor OFF
    LCD_SendCommand(0x0C);

    // Entry mode set: Increment cursor
    LCD_SendCommand(0x06);

    // Clear the display
    LCD_Clear();
}

// Clear the LCD display
void LCD_Clear(void) {
    LCD_SendCommand(0x01);
    LL_mDelay(2); // Wait for the clear command to be processed
}

// Set the cursor position on the LCD
void LCD_SetCursor(uint8_t row, uint8_t col) {
    uint8_t address;

    // Row 0 is the first row, Row 1 is the second row
    if (row == 0) {
        address = 0x80 + col;  // 0x80 is the base address for the first row
    } else {
        address = 0xC0 + col;  // 0xC0 is the base address for the second row
    }

    LCD_SendCommand(address);  // Set DDRAM address
}


// Print a string on the LCD
void LCD_Print(char *str) {
    while (*str) {
        LCD_SendData((uint8_t)(*str));
        str++;
    }
}

// Send a command to the LCD
void LCD_SendCommand(uint8_t cmd) {
    LL_GPIO_ResetOutputPin(LCD_GPIO_PORT, LCD_RS_PIN); // RS = 0 for command
    LCD_Send4Bits(cmd >> 4);  // Send upper nibble
    LCD_Send4Bits(cmd & 0x0F); // Send lower nibble
}

// Send data to the LCD
void LCD_SendData(uint8_t data) {
    LL_GPIO_SetOutputPin(LCD_GPIO_PORT, LCD_RS_PIN); // RS = 1 for data
    LCD_Send4Bits(data >> 4);  // Send upper nibble
    LCD_Send4Bits(data & 0x0F); // Send lower nibble
}

// Helper function to send 4 bits to the LCD
static void LCD_Send4Bits(uint8_t data) {
    // Set data pins D4-D7
    if (data & 0x01) {
        LL_GPIO_SetOutputPin(LCD_GPIO_PORT, LCD_D4_PIN);   // Set D4
    } else {
        LL_GPIO_ResetOutputPin(LCD_GPIO_PORT, LCD_D4_PIN); // Reset D4
    }

    if (data & 0x02) {
        LL_GPIO_SetOutputPin(LCD_GPIO_PORT, LCD_D5_PIN);   // Set D5
    } else {
        LL_GPIO_ResetOutputPin(LCD_GPIO_PORT, LCD_D5_PIN); // Reset D5
    }

    if (data & 0x04) {
        LL_GPIO_SetOutputPin(LCD_GPIO_PORT, LCD_D6_PIN);   // Set D6
    } else {
        LL_GPIO_ResetOutputPin(LCD_GPIO_PORT, LCD_D6_PIN); // Reset D6
    }

    if (data & 0x08) {
        LL_GPIO_SetOutputPin(LCD_GPIO_PORT, LCD_D7_PIN);   // Set D7
    } else {
        LL_GPIO_ResetOutputPin(LCD_GPIO_PORT, LCD_D7_PIN); // Reset D7
    }

    // Pulse the enable pin (EN) to latch data
    LL_GPIO_SetOutputPin(LCD_GPIO_PORT, LCD_EN_PIN);       // Set EN
    LL_mDelay(1);                                         // Wait for a short time
    LL_GPIO_ResetOutputPin(LCD_GPIO_PORT, LCD_EN_PIN);     // Reset EN
    LL_mDelay(1);                                         // Wait for a short time
}

