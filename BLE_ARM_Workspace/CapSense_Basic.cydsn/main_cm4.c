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


void bluePwmEnable();
void redPwmEnable();
void greenPwmEnable();
void bluePwmDisable();
void redPwmDisable();
void greenPwmDisable();

typedef struct{
    uint8_t select;
    TCPWM_Type* type;
    uint32_t num;
}ledSelect_s;

typedef enum{
    RED,
    BLUE,
    GREEN,
    MAX_COLOR
}ledColor_e;


ledSelect_s ledSelect[MAX_COLOR] = {
    {RED,PWM_HW,PWM_CNT_NUM},
    {GREEN,PWM_1_HW,PWM_1_CNT_NUM},
    {BLUE,PWM_2_HW,PWM_2_CNT_NUM}
};


int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    CapSense_Start();
    
    CapSense_ScanAllWidgets();
    
    PWM_Start();
    PWM_1_Start();
    PWM_2_Start();
    
    uint8_t ledIndex = 0;
    for(int i = 0;i<MAX_COLOR;i++)
    {
        Cy_TCPWM_PWM_SetCompare0(ledSelect[ledIndex].type,ledSelect[ledIndex].num,0);
    }
    
    for(;;)
    {
        if(!CapSense_IsBusy())
        {
            CapSense_ProcessAllWidgets();
            int pos;
            pos = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID);
            if(pos < 0xFFFF)
            {                
                Cy_TCPWM_PWM_SetCompare0(ledSelect[ledIndex].type,ledSelect[ledIndex].num,pos);
            }
              
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
#if 0


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
#endif

/* [] END OF FILE */
