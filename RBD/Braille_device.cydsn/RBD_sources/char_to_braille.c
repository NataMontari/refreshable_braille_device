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


    #include <char_to_braille.h>

    const BrailleCell braille_table[128] = {
    ['a'] = {5, 6},
    ['b'] = {4, 6},
    ['c'] = {5, 5},
    ['d'] = {5, 4},
    ['e'] = {5, 0},
    ['f'] = {4, 5},
    ['g'] = {4, 4},
    ['h'] = {4, 0},
    ['i'] = {0, 5},
    ['j'] = {0, 4},

    ['k'] = {1, 6},
    ['l'] = {3, 6},
    ['m'] = {1, 5},
    ['n'] = {1, 4},
    ['o'] = {1, 0},
    ['p'] = {3, 5},
    ['q'] = {3, 4},
    ['r'] = {3, 0},
    ['s'] = {2, 5},
    ['t'] = {2, 4},

    ['u'] = {1, 7},
    ['v'] = {3, 1},
    ['w'] = {0, 3},
    ['x'] = {1, 1},
    ['y'] = {1, 3},
    ['z'] = {1, 2},

    [' '] = {6, 6},
    
    ['#'] = {7, 3},
    ['1'] = {5, 6},
    ['2'] = {4, 6},
    ['3'] = {5, 5},
    ['4'] = {5, 4},
    ['5'] = {5, 0},
    ['6'] = {4, 5},
    ['7'] = {4, 4},
    ['8'] = {4, 0},
    ['9'] = {0, 5},
    ['0'] = {0, 4},
    ['!'] = {2, 0}
};
    
    const LCD_Braille_Cell dots[8] = {
    {
        0b00000,
        0b00000,
        0b00000,
        0b11000,
        0b11000,
        0b00000,
        0b00000,
        0b00000,
    },
    {   
        0b11000,
        0b11000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b11000,
        0b11000,
    },
    {
        0b00000,
        0b00000,
        0b00000,
        0b11000,
        0b11000,
        0b00000,
        0b11000,
        0b11000,
    },
    {
        0b11000,
        0b11000,
        0b00000,
        0b11000,
        0b11000,
        0b00000,
        0b11000,
        0b11000,
    },
    {
        0b11000,
        0b11000,
        0b00000,
        0b11000,
        0b11000,
        0b00000,
        0b00000,
        0b00000,
    },
    {
        0b11000,
        0b11000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
    },
    {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
    },
    {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b11000,
        0b11000,
    }
};    

    void text_to_lcd_braille(char ch, uint8_t* braille_ch){        
        uint8_t first_row = braille_table[ch].left;
        uint8_t second_row = braille_table[ch].right;
        
        for (int i=0; i<8; i++){
            braille_ch[i] = dots[first_row].glyphs[i] | (dots[second_row].glyphs[i] >> 3);
        }

        
    }
    
    void test_text_to_lcd_braille(uint8_t num, uint8_t* braille_ch){        
        
        for (int i=0; i<8; i++){
            braille_ch[i] = dots[num].glyphs[i];
        }

        
    }
    
 

/* [] END OF FILE */
