/*******************************************************************************
* File Name: MOTOR_2_STEP.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "MOTOR_2_STEP.h"

static MOTOR_2_STEP_BACKUP_STRUCT  MOTOR_2_STEP_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: MOTOR_2_STEP_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet MOTOR_2_STEP_SUT.c usage_MOTOR_2_STEP_Sleep_Wakeup
*******************************************************************************/
void MOTOR_2_STEP_Sleep(void)
{
    #if defined(MOTOR_2_STEP__PC)
        MOTOR_2_STEP_backup.pcState = MOTOR_2_STEP_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            MOTOR_2_STEP_backup.usbState = MOTOR_2_STEP_CR1_REG;
            MOTOR_2_STEP_USB_POWER_REG |= MOTOR_2_STEP_USBIO_ENTER_SLEEP;
            MOTOR_2_STEP_CR1_REG &= MOTOR_2_STEP_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(MOTOR_2_STEP__SIO)
        MOTOR_2_STEP_backup.sioState = MOTOR_2_STEP_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        MOTOR_2_STEP_SIO_REG &= (uint32)(~MOTOR_2_STEP_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: MOTOR_2_STEP_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to MOTOR_2_STEP_Sleep() for an example usage.
*******************************************************************************/
void MOTOR_2_STEP_Wakeup(void)
{
    #if defined(MOTOR_2_STEP__PC)
        MOTOR_2_STEP_PC = MOTOR_2_STEP_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            MOTOR_2_STEP_USB_POWER_REG &= MOTOR_2_STEP_USBIO_EXIT_SLEEP_PH1;
            MOTOR_2_STEP_CR1_REG = MOTOR_2_STEP_backup.usbState;
            MOTOR_2_STEP_USB_POWER_REG &= MOTOR_2_STEP_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(MOTOR_2_STEP__SIO)
        MOTOR_2_STEP_SIO_REG = MOTOR_2_STEP_backup.sioState;
    #endif
}


/* [] END OF FILE */
