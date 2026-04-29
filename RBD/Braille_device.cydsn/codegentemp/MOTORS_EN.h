/*******************************************************************************
* File Name: MOTORS_EN.h  
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

#if !defined(CY_PINS_MOTORS_EN_H) /* Pins MOTORS_EN_H */
#define CY_PINS_MOTORS_EN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MOTORS_EN_aliases.h"


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
} MOTORS_EN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   MOTORS_EN_Read(void);
void    MOTORS_EN_Write(uint8 value);
uint8   MOTORS_EN_ReadDataReg(void);
#if defined(MOTORS_EN__PC) || (CY_PSOC4_4200L) 
    void    MOTORS_EN_SetDriveMode(uint8 mode);
#endif
void    MOTORS_EN_SetInterruptMode(uint16 position, uint16 mode);
uint8   MOTORS_EN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void MOTORS_EN_Sleep(void); 
void MOTORS_EN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(MOTORS_EN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define MOTORS_EN_DRIVE_MODE_BITS        (3)
    #define MOTORS_EN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MOTORS_EN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the MOTORS_EN_SetDriveMode() function.
         *  @{
         */
        #define MOTORS_EN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define MOTORS_EN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define MOTORS_EN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define MOTORS_EN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define MOTORS_EN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define MOTORS_EN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define MOTORS_EN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define MOTORS_EN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define MOTORS_EN_MASK               MOTORS_EN__MASK
#define MOTORS_EN_SHIFT              MOTORS_EN__SHIFT
#define MOTORS_EN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MOTORS_EN_SetInterruptMode() function.
     *  @{
     */
        #define MOTORS_EN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define MOTORS_EN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define MOTORS_EN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define MOTORS_EN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(MOTORS_EN__SIO)
    #define MOTORS_EN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(MOTORS_EN__PC) && (CY_PSOC4_4200L)
    #define MOTORS_EN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define MOTORS_EN_USBIO_DISABLE              ((uint32)(~MOTORS_EN_USBIO_ENABLE))
    #define MOTORS_EN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define MOTORS_EN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define MOTORS_EN_USBIO_ENTER_SLEEP          ((uint32)((1u << MOTORS_EN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << MOTORS_EN_USBIO_SUSPEND_DEL_SHIFT)))
    #define MOTORS_EN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << MOTORS_EN_USBIO_SUSPEND_SHIFT)))
    #define MOTORS_EN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << MOTORS_EN_USBIO_SUSPEND_DEL_SHIFT)))
    #define MOTORS_EN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(MOTORS_EN__PC)
    /* Port Configuration */
    #define MOTORS_EN_PC                 (* (reg32 *) MOTORS_EN__PC)
#endif
/* Pin State */
#define MOTORS_EN_PS                     (* (reg32 *) MOTORS_EN__PS)
/* Data Register */
#define MOTORS_EN_DR                     (* (reg32 *) MOTORS_EN__DR)
/* Input Buffer Disable Override */
#define MOTORS_EN_INP_DIS                (* (reg32 *) MOTORS_EN__PC2)

/* Interrupt configuration Registers */
#define MOTORS_EN_INTCFG                 (* (reg32 *) MOTORS_EN__INTCFG)
#define MOTORS_EN_INTSTAT                (* (reg32 *) MOTORS_EN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define MOTORS_EN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(MOTORS_EN__SIO)
    #define MOTORS_EN_SIO_REG            (* (reg32 *) MOTORS_EN__SIO)
#endif /* (MOTORS_EN__SIO_CFG) */

/* USBIO registers */
#if !defined(MOTORS_EN__PC) && (CY_PSOC4_4200L)
    #define MOTORS_EN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define MOTORS_EN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define MOTORS_EN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define MOTORS_EN_DRIVE_MODE_SHIFT       (0x00u)
#define MOTORS_EN_DRIVE_MODE_MASK        (0x07u << MOTORS_EN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins MOTORS_EN_H */


/* [] END OF FILE */
