/*******************************************************************************
* File Name: LCD_D7.h  
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

#if !defined(CY_PINS_LCD_D7_ALIASES_H) /* Pins LCD_D7_ALIASES_H */
#define CY_PINS_LCD_D7_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LCD_D7_0			(LCD_D7__0__PC)
#define LCD_D7_0_PS		(LCD_D7__0__PS)
#define LCD_D7_0_PC		(LCD_D7__0__PC)
#define LCD_D7_0_DR		(LCD_D7__0__DR)
#define LCD_D7_0_SHIFT	(LCD_D7__0__SHIFT)
#define LCD_D7_0_INTR	((uint16)((uint16)0x0003u << (LCD_D7__0__SHIFT*2u)))

#define LCD_D7_INTR_ALL	 ((uint16)(LCD_D7_0_INTR))


#endif /* End Pins LCD_D7_ALIASES_H */


/* [] END OF FILE */
