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
#ifndef CHAR_TO_BRAILLE_H
#define CHAR_TO_BRAILLE_H
    
    #include <stdint.h>
    
    typedef struct {
        uint8_t left;
        uint8_t right;
    } BrailleCell;
        
    extern const BrailleCell braille_table[128];
    
    typedef struct{
        uint8_t glyphs[8];
    } LCD_Braille_Cell;
    
    extern const LCD_Braille_Cell dots[8];
    
    void test_text_to_lcd_braille(uint8_t num, uint8_t* braille_ch);
    
#endif /* CHAR_TO_BRAILLE_H */ 
/* [] END OF FILE */
