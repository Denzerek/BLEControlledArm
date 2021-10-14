/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    CapSense_Start();
    
    CapSense_ScanAllWidgets();
    
    PWM_Start();
    
    for(;;)
    {
        if(!CapSense_IsBusy())
        {
            CapSense_ProcessAllWidgets();
            int pos;
            pos = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID);
            if(pos < 0xFFFF)
                Cy_TCPWM_PWM_SetCompare0(PWM_HW,PWM_CNT_NUM,pos);
               
            if(CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID))
            {
                Cy_TCPWM_PWM_Disable(PWM_HW,PWM_CNT_NUM);
                Cy_GPIO_Write(BLUE_PORT,BLUE_NUM,0);
            }
            if(CapSense_IsWidgetActive(CapSense_BUTTON1_WDGT_ID))
            {
                Cy_TCPWM_PWM_Enable(PWM_HW,PWM_CNT_NUM);
                Cy_TCPWM_TriggerStart(PWM_HW,PWM_CNT_MASK);
                Cy_GPIO_Write(BLUE_PORT,BLUE_NUM,1);
            }
            CapSense_UpdateAllBaselines();
            CapSense_ScanAllWidgets();
        }
    }
}

/* [] END OF FILE */
