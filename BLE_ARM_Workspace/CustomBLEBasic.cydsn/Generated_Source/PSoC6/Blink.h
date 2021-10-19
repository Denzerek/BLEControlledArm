/*******************************************************************************
* File Name: Blink.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the Blink
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(Blink_CY_TCPWM_PWM_PDL_H)
#define Blink_CY_TCPWM_PWM_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_pwm.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  Blink_initVar;
extern cy_stc_tcpwm_pwm_config_t const Blink_config;
/** @} group_globals */


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void Blink_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t Blink_Init(cy_stc_tcpwm_pwm_config_t const *config);
__STATIC_INLINE void Blink_DeInit(void);
__STATIC_INLINE void Blink_Enable(void);
__STATIC_INLINE void Blink_Disable(void);
__STATIC_INLINE uint32_t Blink_GetStatus(void);
__STATIC_INLINE void Blink_SetCompare0(uint32_t compare0);
__STATIC_INLINE uint32_t Blink_GetCompare0(void);
__STATIC_INLINE void Blink_SetCompare1(uint32_t compare1);
__STATIC_INLINE uint32_t Blink_GetCompare1(void);
__STATIC_INLINE void Blink_EnableCompareSwap(bool enable);
__STATIC_INLINE void Blink_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t Blink_GetCounter(void);
__STATIC_INLINE void Blink_SetPeriod0(uint32_t period0);
__STATIC_INLINE uint32_t Blink_GetPeriod0(void);
__STATIC_INLINE void Blink_SetPeriod1(uint32_t period1);
__STATIC_INLINE uint32_t Blink_GetPeriod1(void);
__STATIC_INLINE void Blink_EnablePeriodSwap(bool enable);
__STATIC_INLINE void Blink_TriggerStart(void);
__STATIC_INLINE void Blink_TriggerReload(void);
__STATIC_INLINE void Blink_TriggerKill(void);
__STATIC_INLINE void Blink_TriggerSwap(void);
__STATIC_INLINE uint32_t Blink_GetInterruptStatus(void);
__STATIC_INLINE void Blink_ClearInterrupt(uint32_t source);
__STATIC_INLINE void Blink_SetInterrupt(uint32_t source);
__STATIC_INLINE void Blink_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t Blink_GetInterruptMask(void);
__STATIC_INLINE uint32_t Blink_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define Blink_HW                 (Blink_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define Blink_CNT_HW             (Blink_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define Blink_CNT_NUM            (Blink_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define Blink_CNT_MASK           (1UL << Blink_CNT_NUM)
/** @} group_macros */

#define Blink_INPUT_MODE_MASK    (0x3U)
#define Blink_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: Blink_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t Blink_Init(cy_stc_tcpwm_pwm_config_t const *config)
{
    return(Cy_TCPWM_PWM_Init(Blink_HW, Blink_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: Blink_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_DeInit(void)                   
{
    Cy_TCPWM_PWM_DeInit(Blink_HW, Blink_CNT_NUM, &Blink_config);
}

/*******************************************************************************
* Function Name: Blink_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(Blink_HW, Blink_CNT_MASK);
}


/*******************************************************************************
* Function Name: Blink_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(Blink_HW, Blink_CNT_MASK);
}


/*******************************************************************************
* Function Name: Blink_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Blink_GetStatus(void)                
{
    return(Cy_TCPWM_PWM_GetStatus(Blink_HW, Blink_CNT_NUM));
}


/*******************************************************************************
* Function Name: Blink_SetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_SetCompare0(uint32_t compare0)      
{
    Cy_TCPWM_PWM_SetCompare0(Blink_HW, Blink_CNT_NUM, compare0);
}


/*******************************************************************************
* Function Name: Blink_GetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Blink_GetCompare0(void)              
{
    return(Cy_TCPWM_PWM_GetCompare0(Blink_HW, Blink_CNT_NUM));
}


/*******************************************************************************
* Function Name: Blink_SetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_SetCompare1(uint32_t compare1)      
{
    Cy_TCPWM_PWM_SetCompare1(Blink_HW, Blink_CNT_NUM, compare1);
}


/*******************************************************************************
* Function Name: Blink_GetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Blink_GetCompare1(void)              
{
    return(Cy_TCPWM_PWM_GetCompare1(Blink_HW, Blink_CNT_NUM));
}


/*******************************************************************************
* Function Name: Blink_EnableCompareSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnableCompareSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_EnableCompareSwap(bool enable)  
{
    Cy_TCPWM_PWM_EnableCompareSwap(Blink_HW, Blink_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: Blink_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_SetCounter(uint32_t count)          
{
    Cy_TCPWM_PWM_SetCounter(Blink_HW, Blink_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: Blink_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Blink_GetCounter(void)               
{
    return(Cy_TCPWM_PWM_GetCounter(Blink_HW, Blink_CNT_NUM));
}


/*******************************************************************************
* Function Name: Blink_SetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_SetPeriod0(uint32_t period0)          
{
    Cy_TCPWM_PWM_SetPeriod0(Blink_HW, Blink_CNT_NUM, period0);
}


/*******************************************************************************
* Function Name: Blink_GetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Blink_GetPeriod0(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod0(Blink_HW, Blink_CNT_NUM));
}


/*******************************************************************************
* Function Name: Blink_SetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_SetPeriod1(uint32_t period1)
{
    Cy_TCPWM_PWM_SetPeriod1(Blink_HW, Blink_CNT_NUM, period1);
}


/*******************************************************************************
* Function Name: Blink_GetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Blink_GetPeriod1(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod1(Blink_HW, Blink_CNT_NUM));
}


/*******************************************************************************
* Function Name: Blink_EnablePeriodSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnablePeriodSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_EnablePeriodSwap(bool enable)
{
    Cy_TCPWM_PWM_EnablePeriodSwap(Blink_HW, Blink_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: Blink_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(Blink_HW, Blink_CNT_MASK);
}


/*******************************************************************************
* Function Name: Blink_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(Blink_HW, Blink_CNT_MASK);
}


/*******************************************************************************
* Function Name: Blink_TriggerKill
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_TriggerKill(void)
{
    Cy_TCPWM_TriggerStopOrKill(Blink_HW, Blink_CNT_MASK);
}


/*******************************************************************************
* Function Name: Blink_TriggerSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_TriggerSwap(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(Blink_HW, Blink_CNT_MASK);
}


/*******************************************************************************
* Function Name: Blink_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Blink_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(Blink_HW, Blink_CNT_NUM));
}


/*******************************************************************************
* Function Name: Blink_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(Blink_HW, Blink_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: Blink_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(Blink_HW, Blink_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: Blink_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void Blink_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(Blink_HW, Blink_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: Blink_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Blink_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(Blink_HW, Blink_CNT_NUM));
}


/*******************************************************************************
* Function Name: Blink_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Blink_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(Blink_HW, Blink_CNT_NUM));
}

#endif /* Blink_CY_TCPWM_PWM_PDL_H */


/* [] END OF FILE */
