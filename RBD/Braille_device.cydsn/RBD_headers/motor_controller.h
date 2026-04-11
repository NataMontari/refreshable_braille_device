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
    /*Define fucntions and variables to work with the stepper motors */
   
    uint8_t rail_pos[60] = {}; /*array to save current rail positions*/
    
    
    typedef struct MotorController MotorController; /*a structure to track the current position of the motors*/
    
    void MotorController_Init(); /*initialize stepper motors to the starting position*/
    void MotorController_SetCell(MotorController* self, uint8_t position); /*set the rail to a specified position*/
    void MotorController_MoveToPos(MotorController* self, uint8_t position); /* select one of the rails*/
    void MotorController_SetRail(MotorController* self, uint8_t rail_pos, uint8_t cell_pos); /*choose a rail and then set it's position, uses both functions above*/
    void MotorController_SetSymbol(MotorController* self, uint8_t start_rail, char symbol); /*set a пsymbol, referencing the char to braille table. Uses set rail to set the position of two rails in a symbol*/
    

    
#endif /* MOTOR_CONTROLLER_H */ 
/* [] END OF FILE */
