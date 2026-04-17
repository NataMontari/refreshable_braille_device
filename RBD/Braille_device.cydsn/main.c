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

int main()
{

    CyGlobalIntEnable;  // Enable global interrupts if needed

    //CyDelay(100);
    // Initialize the LCD
LCD_Char_1_Start();

    // Wait until LCD is ready (poll internally)
    //RED_LED_Write(1);  // Turn on LED (assuming active-high)
    //LCD_Char_1_IsReady();

    //CyDelay(100);
    // Indicate LCD is ready using LED
    //RED_LED_Write(0);  // Turn on LED (assuming active-high)
    //BLUE_LED_Write(1);  // Turn on LED (assuming active-high)
    // Or, if you have RGB LED: 
    // RED_LED_Write(1);   // turn red on
    // GREEN_LED_Write(0); // turn green off, etc.


    // Print "Hello World" to the screen
    //LCD_Char_1_PrintString("Hello World");

    /*LCD_Char_1_Start();
    LCD_Char_1_Init();
    
    LCD_Char_1_DisplayOn();
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_Position(0,0);
    LCD_Char_1_PrintString("Hello World");*/
    
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
    
    
    for(;;){
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintString("Hello");
        CyDelay(1000);
        LCD_Char_1_ClearDisplay();
        CyDelay(1000);
    }
}

/* [] END OF FILE */
