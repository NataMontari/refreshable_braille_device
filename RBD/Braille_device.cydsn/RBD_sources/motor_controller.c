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

    #include <motor_controller.h>
    
    uint8_t rail_pos[60] = {}; /*array to save current rail positions*/
    MotorController Motors = {0, 0};

// Create an instance (optional global)
    void MotorController_Init(MotorController* motor)
    {
        int steps = 110*MOTOR_STEP;
        MOTOR_1_DIR_Write(1);
        MOTOR_2_DIR_Write(0);
        for(int i=0; i<steps; i++){
            MOTOR_1_STEP_Write(1);
            MOTOR_2_STEP_Write(1);
            CyDelay(1);
            MOTOR_1_STEP_Write(0);
            MOTOR_2_STEP_Write(0);
        };

        /*set each rail using motor2 and light sensor*/
        MOTOR_1_DIR_Write(0);
        MOTOR_2_DIR_Write(0);
        for(int i=0; i<steps; i++){
            MOTOR_1_STEP_Write(1);
            MOTOR_2_STEP_Write(1);
            CyDelay(1);
            MOTOR_1_STEP_Write(0);
            MOTOR_2_STEP_Write(0);
        };
        
        motor->rail_pos=0;
        motor->cell_pos=0;
    };
    void MotorController_SetCell(MotorController* motor, uint8_t position){}; /*set the rail to a specified position*/
    void MotorController_MoveToPos(MotorController* motor, uint8_t position){}; /* select one of the rails*/
    void MotorController_SetRail(MotorController* motor, uint8_t rail_pos, uint8_t cell_pos){}; /*choose a rail and then set it's position, uses both functions above*/
    void MotorController_SetSymbol(MotorController* motor, uint8_t start_rail, char symbol){}; /*set a пsymbol, referencing the char to braille table. Uses set rail to set the position of two rails in a symbol*/

/* [] END OF FILE */
