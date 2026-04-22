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
    #include <math.h>
    
    uint8_t rail_cell_pos[60] = {}; /*array to save current rail positions*/
    MotorController Motors = {0, 0};

// Create an instance (optional global)
    void MotorController_Init(MotorController* motor)
    {
        /*int steps = 110*MOTOR_STEP;
        MOTOR_1_DIR_Write(1);
        MOTOR_2_DIR_Write(0);
        for(int i=0; i<steps; i++){
            MOTOR_1_STEP_Write(1);
            MOTOR_2_STEP_Write(1);
            CyDelay(1);
            MOTOR_1_STEP_Write(0);
            MOTOR_2_STEP_Write(0);
        };*/

        /*set each rail using motor2 and light sensor*/
        /*MOTOR_1_DIR_Write(0);
        MOTOR_2_DIR_Write(0);
        for(int i=0; i<steps; i++){
            MOTOR_1_STEP_Write(1);
            MOTOR_2_STEP_Write(1);
            CyDelay(1);
            MOTOR_1_STEP_Write(0);
            MOTOR_2_STEP_Write(0);
        };
        */
        
        motor->rail_pos=0;
        motor->cell_pos=0;
        for (int i = 0; i<60; i++){
            rail_cell_pos[i] = 0;
        }
    };

  

    
    void MotorController_SetRail(MotorController* motor, uint8_t rail_pos, uint8_t cell_pos){
        
    }; /*choose a rail and then set it's position, uses both functions above*/
    void MotorController_SetSymbol(MotorController* motor, char symbol) {
        if (motor->rail_pos >= 58) { // need 2 rails
            return;
        }

        MOTORS_EN_Write(0);

        uint8_t first  = braille_table[(int)symbol].left;
        uint8_t second = braille_table[(int)symbol].right;

        // First rail
        MotorController_SetCell(motor, first);

        // Move to second rail (relative move!)
        CyDelay(1000);
        MotorController_SetNextRail(motor, 1);
        CyDelay(1000);

        // Second rail
        MotorController_SetCell(motor, second);
        CyDelay(1000);
    
        // Move to next symbol start
        MotorController_SetNextSymbol(motor, 1);
        CyDelay(1000);

        MOTORS_EN_Write(1);
    } /*set a symbol, referencing the char to braille table. Uses set rail to set the position of two rails in a symbol*/

    void MotorController_SetNextSymbol(MotorController* motor, uint8_t motor_dir){
        MOTORS_EN_Write(0);
        MOTOR_1_DIR_Write(motor_dir);        
       
        int steps = 656;
        for(int i=0; i<steps; i++){
            MOTOR_1_STEP_Write(1);
            CyDelayUs(500);
            MOTOR_1_STEP_Write(0);
        }
        motor->rail_pos += (motor_dir ? 1 : -1);
        MOTORS_EN_Write(1);
    }
    void MotorController_SetNextRail(MotorController* motor, uint8_t motor_dir){
        MOTORS_EN_Write(0);
        MOTOR_1_DIR_Write(motor_dir);        
       
        int steps = 400;
        for(int i=0; i<steps; i++){
            MOTOR_1_STEP_Write(1);
            CyDelayUs(500);
            MOTOR_1_STEP_Write(0);
        }
        motor->rail_pos += (motor_dir ? 1 : -1);
        MOTORS_EN_Write(1);
    }
    void MotorController_MoveToPos(MotorController* motor, uint8_t position) {
        if (position > 59 | position < 0){
            return;
        }
        
        int diff = (int)position - (int)motor->rail_pos;

        if (diff == 0) {
            return;
        }
        MOTORS_EN_Write(0);
        int step = (diff > 0) ? 1 : -1;
        uint8_t motor_dir = (diff > 0) ? 1 : 0;
        uint8_t start_rail = motor->rail_pos;

        MOTOR_1_DIR_Write(motor_dir);

    for (int i = start_rail; i != position; i += step) {
        // XOR flips behavior when motor_dir == 0
        if ((i % 2 == 0) ^ (motor_dir == 0)) {
            MotorController_SetNextRail(motor, motor_dir);
        } else {
            MotorController_SetNextSymbol(motor, motor_dir);
        }
    }
        MOTORS_EN_Write(1);
    }; /* select one of the rails*/
    
    void MotorController_SetCell(MotorController* motor, uint8_t position){
        if (position > 7) {
            return;
        }
        
        int current = rail_cell_pos[motor->rail_pos];
        int diff = (int)position - current;

        if (diff == 0) {
            return;
        }
        MOTORS_EN_Write(0);
        uint8_t motor_dir = (diff > 0) ? 1 : 0;

        MOTOR_2_DIR_Write(motor_dir);

        int steps = abs(diff) * MOTOR_STEP;
    
        for(int i = 0; i < steps; i++){
            MOTOR_2_STEP_Write(1);
            CyDelayUs(500);
            MOTOR_2_STEP_Write(0);
        }

        rail_cell_pos[motor->rail_pos] = position;
        motor->cell_pos = position;
        MOTORS_EN_Write(1);
    } /*set the rail to a specified position*/
    
    void MotorController_PrintText(MotorController *motor, char* data){
        if (data == NULL){
            return;
        }
        for (int i = 0; data[i] != '\0'; i++)
        {
           MotorController_SetSymbol(motor, data[i]);
        }
    }
/* [] END OF FILE */
