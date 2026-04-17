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
    
    //MotorController Motors = {0,0};
    /*MotorController_Init(&Motors);*/

    //CyDelay(100);
    // Initialize the LCD
    LCD_init();
    LCD_init_braille();
    LCD_print_string("Hello world!");
    LCD_set_cursor(1, 0);
    LCD_test_print_braille("hello world?");
    //LCD_print_string("just why?");
    
    /*MOTOR_1_DIR_Write(0);
    
    for(int i=0; i<6400; i++){
        MOTOR_1_STEP_Write(1);
        CyDelay(1);
        MOTOR_1_STEP_Write(0);
    }*/
    
    
    
    /*MOTOR_2_DIR_Write(0);
    
    for(int i=0; i<6400; i++){
        MOTOR_2_STEP_Write(1);
        CyDelay(1);
        MOTOR_2_STEP_Write(0);
    }*/
    
    /*MOTOR_1_DIR_Write(1);
    
    for(int j=0; j<4; j++){
        
        for(int i=0; i<6400; i++){
            MOTOR_1_STEP_Write(1);
            CyDelay(1);
            MOTOR_1_STEP_Write(0);
        }
    }*/
    
    
    /*for(;;){
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintString("Hello");
        CyDelay(1000);
        LCD_Char_1_ClearDisplay();
        CyDelay(1000);
    }*/
}

/* [] END OF FILE */
