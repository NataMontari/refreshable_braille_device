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
    
    extern const BrailleCell char_to_braille[128];
    
    
#endif /* CHAR_TO_BRAILLE_H */ 
/* [] END OF FILE */
