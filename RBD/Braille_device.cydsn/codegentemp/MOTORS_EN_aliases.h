/*******************************************************************************
* File Name: MOTORS_EN.h  
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

#if !defined(CY_PINS_MOTORS_EN_ALIASES_H) /* Pins MOTORS_EN_ALIASES_H */
#define CY_PINS_MOTORS_EN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define MOTORS_EN_0			(MOTORS_EN__0__PC)
#define MOTORS_EN_0_PS		(MOTORS_EN__0__PS)
#define MOTORS_EN_0_PC		(MOTORS_EN__0__PC)
#define MOTORS_EN_0_DR		(MOTORS_EN__0__DR)
#define MOTORS_EN_0_SHIFT	(MOTORS_EN__0__SHIFT)
#define MOTORS_EN_0_INTR	((uint16)((uint16)0x0003u << (MOTORS_EN__0__SHIFT*2u)))

#define MOTORS_EN_INTR_ALL	 ((uint16)(MOTORS_EN_0_INTR))


#endif /* End Pins MOTORS_EN_ALIASES_H */


/* [] END OF FILE */
