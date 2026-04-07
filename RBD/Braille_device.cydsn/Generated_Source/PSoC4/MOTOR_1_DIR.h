/*******************************************************************************
* File Name: MOTOR_1_DIR.h  
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

#if !defined(CY_PINS_MOTOR_1_DIR_H) /* Pins MOTOR_1_DIR_H */
#define CY_PINS_MOTOR_1_DIR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MOTOR_1_DIR_aliases.h"


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
} MOTOR_1_DIR_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   MOTOR_1_DIR_Read(void);
void    MOTOR_1_DIR_Write(uint8 value);
uint8   MOTOR_1_DIR_ReadDataReg(void);
#if defined(MOTOR_1_DIR__PC) || (CY_PSOC4_4200L) 
    void    MOTOR_1_DIR_SetDriveMode(uint8 mode);
#endif
void    MOTOR_1_DIR_SetInterruptMode(uint16 position, uint16 mode);
uint8   MOTOR_1_DIR_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void MOTOR_1_DIR_Sleep(void); 
void MOTOR_1_DIR_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(MOTOR_1_DIR__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define MOTOR_1_DIR_DRIVE_MODE_BITS        (3)
    #define MOTOR_1_DIR_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MOTOR_1_DIR_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the MOTOR_1_DIR_SetDriveMode() function.
         *  @{
         */
        #define MOTOR_1_DIR_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define MOTOR_1_DIR_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define MOTOR_1_DIR_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define MOTOR_1_DIR_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define MOTOR_1_DIR_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define MOTOR_1_DIR_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define MOTOR_1_DIR_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define MOTOR_1_DIR_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define MOTOR_1_DIR_MASK               MOTOR_1_DIR__MASK
#define MOTOR_1_DIR_SHIFT              MOTOR_1_DIR__SHIFT
#define MOTOR_1_DIR_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MOTOR_1_DIR_SetInterruptMode() function.
     *  @{
     */
        #define MOTOR_1_DIR_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define MOTOR_1_DIR_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define MOTOR_1_DIR_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define MOTOR_1_DIR_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(MOTOR_1_DIR__SIO)
    #define MOTOR_1_DIR_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(MOTOR_1_DIR__PC) && (CY_PSOC4_4200L)
    #define MOTOR_1_DIR_USBIO_ENABLE               ((uint32)0x80000000u)
    #define MOTOR_1_DIR_USBIO_DISABLE              ((uint32)(~MOTOR_1_DIR_USBIO_ENABLE))
    #define MOTOR_1_DIR_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define MOTOR_1_DIR_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define MOTOR_1_DIR_USBIO_ENTER_SLEEP          ((uint32)((1u << MOTOR_1_DIR_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << MOTOR_1_DIR_USBIO_SUSPEND_DEL_SHIFT)))
    #define MOTOR_1_DIR_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << MOTOR_1_DIR_USBIO_SUSPEND_SHIFT)))
    #define MOTOR_1_DIR_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << MOTOR_1_DIR_USBIO_SUSPEND_DEL_SHIFT)))
    #define MOTOR_1_DIR_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(MOTOR_1_DIR__PC)
    /* Port Configuration */
    #define MOTOR_1_DIR_PC                 (* (reg32 *) MOTOR_1_DIR__PC)
#endif
/* Pin State */
#define MOTOR_1_DIR_PS                     (* (reg32 *) MOTOR_1_DIR__PS)
/* Data Register */
#define MOTOR_1_DIR_DR                     (* (reg32 *) MOTOR_1_DIR__DR)
/* Input Buffer Disable Override */
#define MOTOR_1_DIR_INP_DIS                (* (reg32 *) MOTOR_1_DIR__PC2)

/* Interrupt configuration Registers */
#define MOTOR_1_DIR_INTCFG                 (* (reg32 *) MOTOR_1_DIR__INTCFG)
#define MOTOR_1_DIR_INTSTAT                (* (reg32 *) MOTOR_1_DIR__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define MOTOR_1_DIR_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(MOTOR_1_DIR__SIO)
    #define MOTOR_1_DIR_SIO_REG            (* (reg32 *) MOTOR_1_DIR__SIO)
#endif /* (MOTOR_1_DIR__SIO_CFG) */

/* USBIO registers */
#if !defined(MOTOR_1_DIR__PC) && (CY_PSOC4_4200L)
    #define MOTOR_1_DIR_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define MOTOR_1_DIR_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define MOTOR_1_DIR_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define MOTOR_1_DIR_DRIVE_MODE_SHIFT       (0x00u)
#define MOTOR_1_DIR_DRIVE_MODE_MASK        (0x07u << MOTOR_1_DIR_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins MOTOR_1_DIR_H */


/* [] END OF FILE */
