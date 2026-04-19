/*******************************************************************************
* File Name: LCD_D5.h  
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

#if !defined(CY_PINS_LCD_D5_ALIASES_H) /* Pins LCD_D5_ALIASES_H */
#define CY_PINS_LCD_D5_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LCD_D5_0			(LCD_D5__0__PC)
#define LCD_D5_0_PS		(LCD_D5__0__PS)
#define LCD_D5_0_PC		(LCD_D5__0__PC)
#define LCD_D5_0_DR		(LCD_D5__0__DR)
#define LCD_D5_0_SHIFT	(LCD_D5__0__SHIFT)
#define LCD_D5_0_INTR	((uint16)((uint16)0x0003u << (LCD_D5__0__SHIFT*2u)))

#define LCD_D5_INTR_ALL	 ((uint16)(LCD_D5_0_INTR))


#endif /* End Pins LCD_D5_ALIASES_H */


/* [] END OF FILE */
