# Refreshable Braille Display
This project offers a software implementation for a mechanical prototype that converts text to Braille.

It was designed in PSoC Creator 4.4 for PSoC 4 CY8C4248LQI-BL583 kit.

## Motor Controller Interface
Provides API responsible for motor controllers, that are responsible for text ro Braille conversion

    MotorController Motors = {0 , 0}; - variable that stores current state of the motors
    
    void MotorController_Init(MotorController* motor); - initialize stepper motors to the starting position 
    void MotorController_PrintText(MotorController *motor, char* data); - prints out input text in Braille, accounting for number and capital symbols.
    
## LCD Interface

Provides a debugging visual interface.

Main user API functions:
    void LCD_init(void); - initializes LCD
    void LCD_print_string(char* data); - prints string as is
    void LCD_set_cursor(uint8_t line, uint8_t pos); - sets cursor on one of the selected two lines and cell position. Doesn't print anything
    void LCD_clear(void); - clears LCD
    void LCD_init_braille(void); - necessary set up before using LCD_test_print_braille() function. Stores custom characters to print Braille.
    void LCD_test_print_braille(char* data); - shows input text as Braille on the LCD.
    
