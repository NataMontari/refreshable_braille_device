/*******************************************************************************
* File Name: MOTOR_1_DIR.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MOTOR_1_DIR_ALIASES_H) /* Pins MOTOR_1_DIR_ALIASES_H */
#define CY_PINS_MOTOR_1_DIR_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define MOTOR_1_DIR_0			(MOTOR_1_DIR__0__PC)
#define MOTOR_1_DIR_0_PS		(MOTOR_1_DIR__0__PS)
#define MOTOR_1_DIR_0_PC		(MOTOR_1_DIR__0__PC)
#define MOTOR_1_DIR_0_DR		(MOTOR_1_DIR__0__DR)
#define MOTOR_1_DIR_0_SHIFT	(MOTOR_1_DIR__0__SHIFT)
#define MOTOR_1_DIR_0_INTR	((uint16)((uint16)0x0003u << (MOTOR_1_DIR__0__SHIFT*2u)))

#define MOTOR_1_DIR_INTR_ALL	 ((uint16)(MOTOR_1_DIR_0_INTR))


#endif /* End Pins MOTOR_1_DIR_ALIASES_H */


/* [] END OF FILE */
