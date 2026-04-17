/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#ifndef LCD_H
#define LCD_H
    
    #include <stdint.h>
    #include <stdio.h>
    #include <char_to_braille.h>
    
    /*User API functions*/
    void LCD_init(void);
    void LCD_print_string(char* data);
    void LCD_set_cursor(uint8_t line, uint8_t pos);
    void LCD_print_braille(char* data, uint8_t row, uint8_t col);
    void LCD_clear(void);
    void LCD_send_char(char ch);
    void LCD_test_print_braille(char* data);
    void LCD_init_braille(void);
    
    
    /*Library functions*/
    void LCD_send_nibble(uint8_t data);
    void LCD_send_byte(uint8_t data, uint8_t mode);
    void LCD_pulse_enable(void);
    


#endif /*LCD_H*/
/* [] END OF FILE */
