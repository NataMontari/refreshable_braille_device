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

#include <LCD.h>

void LCD_pulse_enable(){
    LCD_E_Write(1);
    CyDelayUs(500);
    LCD_E_Write(0);
    CyDelayUs(500);
}

void LCD_send_nibble(uint8_t data){
    LCD_D4_Write((data >> 0) & 0x01);
    LCD_D5_Write((data >> 1) & 0x01);
    LCD_D6_Write((data >> 2) & 0x01);
    LCD_D7_Write((data >> 3) & 0x01);
    
    LCD_pulse_enable();
}

void LCD_send_byte(uint8_t data, uint8_t mode){
    LCD_RS_Write(mode);
    
    LCD_send_nibble(data >> 4); //send high nibble (first 4 bytes)
    LCD_send_nibble(data & 0x0F); //send low nibble (last 4 bytes) 0x0F=0x1111
    
}

void LCD_clear(){
    LCD_send_byte(0x01, 0); //clear display
}

void LCD_send_command(uint8_t command){
    LCD_send_byte(command, 0); // 0 is command mode for rs
}

void LCD_send_char(char ch){
    LCD_send_byte(ch, 1);
}

void LCD_print_string(char* data){
    if (data == NULL){
        return;
    }
    for (int i=0; data[i] != '\0'; i++){
        LCD_send_char(data[i]);
    }
}

void LCD_set_cursor(uint8_t line, uint8_t pos){
    if (line > 1 || line < 0 || pos > 39 || pos < 0){
        return;
    }
    
    uint8_t addr = (line == 0) ? 0x00 : 0x40;
    addr += pos;
    
    LCD_send_command(0x80 | addr); 
    
    
}

void LCD_print_braille(char* data, uint8_t row, uint8_t col){
    if (data == NULL){
        return;
    }
    for (int i = 0; data[i] != '\0'; i++)
    {
        uint8_t glyph[8];
        text_to_lcd_braille(data[i], glyph);

        uint8_t slot = i % 8;

        // write glyph

        LCD_send_command(0x40 + slot * 8);
        

        for (int j = 0; j < 8; j++){
            /*if (j%2== 0){
                LCD_send_command(0x06);
            }else{
                LCD_send_command(0x04);
            }*/
            LCD_send_char(glyph[j]);
        }

        // go back to display memory
        LCD_set_cursor(row, col+i);

        // print it
        LCD_send_char(slot);
    }
}

void LCD_braille_char(){
    
    uint8_t glyph[8] = {
        0b00000,
        0b00000,
        0b00000,
        0b11000,
        0b11000,
        0b00000,
        0b00000,
        0b00000,
    };
    
    LCD_send_command(0x40);
    for (int j = 0; j < 8; j++){
            LCD_send_char(glyph[j]); //send the glyph
    }
    
    LCD_set_cursor(1, 0);
    LCD_send_char(0);
    LCD_send_char(0);
    
}

void LCD_init_braille(void){
    for (int i = 0; i < 8; i++)
    {
        // write glyph

        LCD_send_command(0x40 + i * 8);
        

        for (int j = 0; j < 8; j++){
            LCD_send_char(dots[i].glyphs[j]);
        }
        LCD_set_cursor(0,0);
    }
}

void LCD_test_print_braille(char* data){
    if (data == NULL){
        return;
    }
    char cur_ch;
    uint8_t character = 0;

    
    for (int i = 0; data[i] != '\0'; i++)
    {
        cur_ch = data[i];
        character = braille_table[cur_ch].left;
        // print left side
        LCD_send_char(character);
        character = braille_table[cur_ch].right;
        LCD_send_char(character);
    }
}
    
void LCD_init(void){
    CyDelay(15); // Wait 15ms after power on
    
    /*Init*/
    LCD_send_nibble(0x03);
    CyDelay(5);
    
    LCD_send_nibble(0x03);
    CyDelayUs(1000);
    
    LCD_send_nibble(0x03);
    
    LCD_send_nibble(0x02); //Enable 4 bit mode
    
    LCD_send_command(0x2C); // function set: 4-bit 2-line
    LCD_send_command(0x08); // turn off the display
    
    LCD_clear(); //clear display
    CyDelay(2);
    
    LCD_send_command(0x06); // Entry mode
    LCD_send_command(0x0F); // turn on display, cursor and blink

}

/* [] END OF FILE */
