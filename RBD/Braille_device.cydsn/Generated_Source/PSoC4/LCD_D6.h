/*******************************************************************************
* File Name: LCD_D6.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LCD_D6_H) /* Pins LCD_D6_H */
#define CY_PINS_LCD_D6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LCD_D6_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} LCD_D6_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LCD_D6_Read(void);
void    LCD_D6_Write(uint8 value);
uint8   LCD_D6_ReadDataReg(void);
#if defined(LCD_D6__PC) || (CY_PSOC4_4200L) 
    void    LCD_D6_SetDriveMode(uint8 mode);
#endif
void    LCD_D6_SetInterruptMode(uint16 position, uint16 mode);
uint8   LCD_D6_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LCD_D6_Sleep(void); 
void LCD_D6_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LCD_D6__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LCD_D6_DRIVE_MODE_BITS        (3)
    #define LCD_D6_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LCD_D6_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LCD_D6_SetDriveMode() function.
         *  @{
         */
        #define LCD_D6_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LCD_D6_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LCD_D6_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LCD_D6_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LCD_D6_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LCD_D6_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LCD_D6_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LCD_D6_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LCD_D6_MASK               LCD_D6__MASK
#define LCD_D6_SHIFT              LCD_D6__SHIFT
#define LCD_D6_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LCD_D6_SetInterruptMode() function.
     *  @{
     */
        #define LCD_D6_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LCD_D6_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LCD_D6_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LCD_D6_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LCD_D6__SIO)
    #define LCD_D6_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LCD_D6__PC) && (CY_PSOC4_4200L)
    #define LCD_D6_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LCD_D6_USBIO_DISABLE              ((uint32)(~LCD_D6_USBIO_ENABLE))
    #define LCD_D6_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LCD_D6_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LCD_D6_USBIO_ENTER_SLEEP          ((uint32)((1u << LCD_D6_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LCD_D6_USBIO_SUSPEND_DEL_SHIFT)))
    #define LCD_D6_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LCD_D6_USBIO_SUSPEND_SHIFT)))
    #define LCD_D6_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LCD_D6_USBIO_SUSPEND_DEL_SHIFT)))
    #define LCD_D6_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LCD_D6__PC)
    /* Port Configuration */
    #define LCD_D6_PC                 (* (reg32 *) LCD_D6__PC)
#endif
/* Pin State */
#define LCD_D6_PS                     (* (reg32 *) LCD_D6__PS)
/* Data Register */
#define LCD_D6_DR                     (* (reg32 *) LCD_D6__DR)
/* Input Buffer Disable Override */
#define LCD_D6_INP_DIS                (* (reg32 *) LCD_D6__PC2)

/* Interrupt configuration Registers */
#define LCD_D6_INTCFG                 (* (reg32 *) LCD_D6__INTCFG)
#define LCD_D6_INTSTAT                (* (reg32 *) LCD_D6__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LCD_D6_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LCD_D6__SIO)
    #define LCD_D6_SIO_REG            (* (reg32 *) LCD_D6__SIO)
#endif /* (LCD_D6__SIO_CFG) */

/* USBIO registers */
#if !defined(LCD_D6__PC) && (CY_PSOC4_4200L)
    #define LCD_D6_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LCD_D6_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LCD_D6_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LCD_D6_DRIVE_MODE_SHIFT       (0x00u)
#define LCD_D6_DRIVE_MODE_MASK        (0x07u << LCD_D6_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LCD_D6_H */


/* [] END OF FILE */
