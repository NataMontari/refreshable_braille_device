/*******************************************************************************
* File Name: LCD_D4.h  
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

#if !defined(CY_PINS_LCD_D4_ALIASES_H) /* Pins LCD_D4_ALIASES_H */
#define CY_PINS_LCD_D4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LCD_D4_0			(LCD_D4__0__PC)
#define LCD_D4_0_PS		(LCD_D4__0__PS)
#define LCD_D4_0_PC		(LCD_D4__0__PC)
#define LCD_D4_0_DR		(LCD_D4__0__DR)
#define LCD_D4_0_SHIFT	(LCD_D4__0__SHIFT)
#define LCD_D4_0_INTR	((uint16)((uint16)0x0003u << (LCD_D4__0__SHIFT*2u)))

#define LCD_D4_INTR_ALL	 ((uint16)(LCD_D4_0_INTR))


#endif /* End Pins LCD_D4_ALIASES_H */


/* [] END OF FILE */
