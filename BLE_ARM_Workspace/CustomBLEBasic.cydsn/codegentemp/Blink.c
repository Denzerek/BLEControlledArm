/*******************************************************************************
* File Name: Blink.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the Blink
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Blink.h"

/** Indicates whether or not the Blink has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  Blink_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the Blink_Start() routine.
*/
uint8_t Blink_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated Blink_Init() function.
*/ 
cy_stc_tcpwm_pwm_config_t const Blink_config =
{
    .pwmMode = 4UL,
    .clockPrescaler = 0UL,
    .pwmAlignment = 0UL,
    .deadTimeClocks = 0UL,
    .runMode = 0UL,
    .period0 = 999UL,
    .period1 = 32768UL,
    .enablePeriodSwap = false,
    .compare0 = 500UL,
    .compare1 = 16384UL,
    .enableCompareSwap = false,
    .interruptSources = 0UL,
    .invertPWMOut = 1UL,
    .invertPWMOutN = 0UL,
    .killMode = 2UL,
    .swapInputMode = 3UL,
    .swapInput = CY_TCPWM_INPUT_CREATOR,
    .reloadInputMode = 3UL,
    .reloadInput = CY_TCPWM_INPUT_CREATOR,
    .startInputMode = 3UL,
    .startInput = CY_TCPWM_INPUT_CREATOR,
    .killInputMode = 3UL,
    .killInput = CY_TCPWM_INPUT_CREATOR,
    .countInputMode = 3UL,
    .countInput = CY_TCPWM_INPUT_CREATOR,
};


/*******************************************************************************
* Function Name: Blink_Start
****************************************************************************//**
*
*  Calls the Blink_Init() when called the first time and enables 
*  the Blink. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref Blink_initVar
*
*******************************************************************************/
void Blink_Start(void)
{
    if (0U == Blink_initVar)
    {
        (void) Cy_TCPWM_PWM_Init(Blink_HW, Blink_CNT_NUM, &Blink_config);

        Blink_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(Blink_HW, Blink_CNT_MASK);
    
    #if (Blink_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(Blink_HW, Blink_CNT_MASK);
    #endif /* (Blink_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
