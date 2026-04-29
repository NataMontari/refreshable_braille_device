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
#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

    #include <stdint.h>
    #include <math.h>
    #include <char_to_braille.h>
    
    #define MOTOR_STEP 320;
    #define MOTOR_1_LEFT 0;
    #define MOTOR_1_RIGHT 0;
    
    /*Define functions and variables to work with the stepper motors */
    
    typedef struct MotorController MotorController; /*a structure to track the current position of the motors*/
    
    struct MotorController {
        uint8_t rail_pos;
        uint8_t cell_pos;
    };
    

    
    extern uint8_t rail_cell_pos[60];   // stores current position of the rails
    extern MotorController Motors; // stores current state of the motors
    
    void MotorController_Init(MotorController* motor); /*initialize stepper motors to the starting position*/
    void MotorController_SetNextSymbol(MotorController* motor, uint8_t motor_dir); /*go to the first rail in the next symbol*/
    void MotorController_SetNextRail(MotorController* motor, uint8_t motor_dir); /*go to next rail in the same symbol*/
    void MotorController_SetCell(MotorController* motor, uint8_t position); /*set the rail to a specified position*/
    void MotorController_MoveToPos(MotorController* motor, uint8_t position); /* select one of the rails*/
    void MotorController_SetRail(MotorController* motor, uint8_t rail_pos, uint8_t cell_pos); /*choose a rail and then set it's position, uses both functions above*/
    void MotorController_SetSymbol(MotorController* motor, char symbol); /*set a пsymbol, referencing the char to braille table. Uses set rail to set the position of two rails in a symbol*/
    void MotorController_PrintText(MotorController *motor, char* data); /*prints out a word in braille*/
    
#endif /* MOTOR_CONTROLLER_H */ 
/* [] END OF FILE */
