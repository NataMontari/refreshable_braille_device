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

    const BrailleCell char_to_braille[128] = {
    ['a'] = {1, 0},
    ['b'] = {3, 0},
    ['c'] = {1, 2},
    ['d'] = {1, 6},
    ['e'] = {1, 4},
    ['f'] = {3, 2},
    ['g'] = {3, 6},
    ['h'] = {3, 4},
    ['i'] = {2, 2},
    ['j'] = {2, 6},

    ['k'] = {5, 0},
    ['l'] = {7, 0},
    ['m'] = {5, 2},
    ['n'] = {5, 6},
    ['o'] = {5, 4},
    ['p'] = {7, 2},
    ['q'] = {7, 6},
    ['r'] = {7, 4},
    ['s'] = {6, 2},
    ['t'] = {6, 6},

    ['u'] = {5, 1},
    ['v'] = {7, 1},
    ['w'] = {2, 7},
    ['x'] = {5, 3},
    ['y'] = {5, 7},
    ['z'] = {5, 5},

    [' '] = {0, 0}
};

    
 

/* [] END OF FILE */
