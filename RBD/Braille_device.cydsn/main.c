/*******************************************************************************
* File Name: main.c  
* Version 1.11
*
* Description:
*  Contains the main.c function.
*
*
*******************************************************************************
* Copyright 2013-2020, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include <project.h>
#include <motor_controller.h>

int main()
{

    CyGlobalIntEnable;  // Enable global interrupts if needed

    // Initialize the LCD
    LCD_init();
    LCD_init_braille();
    LCD_print_string("Hello, year 2026!");
    LCD_set_cursor(1, 0);
    LCD_test_print_braille("Hello, year 2026!");

    MotorController_Init(&Motors);
    MotorController_PrintText(&Motors, "Hello, year 2026!");
}

/* [] END OF FILE */
