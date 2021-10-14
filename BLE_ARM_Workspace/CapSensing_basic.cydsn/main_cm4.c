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
#include <stdio.h>

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

#if 1
int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    CapSense_Start();
    
    CapSense_ScanAllWidgets();
    
    PWM_Start();
    PWM_1_Start();
    PWM_2_Start();
    UART_1_Start();
    uint8_t ledIndex = 0;
    for(int ledIndex = 0; ledIndex < MAX_COLOR;ledIndex++)
    {
        Cy_TCPWM_PWM_SetCompare0(ledSelect[ledIndex].type,ledSelect[ledIndex].num,0xFFF);
    }
    ledIndex = 0; 
    uint32_t gesture,prevGsture,Xcord;
    uint16_t Ycord;
    
    CapSense_dsRam.timestampInterval = 2u;
    Cy_SysTick_Init(CY_SYSTICK_CLOCK_SOURCE_CLK_IMO,80000);
    Cy_SysTick_SetCallback(0u, CapSense_IncrementGestureTimestamp);
    
    printf("\x1b[2J\x1b[;H");
    printf("UART TASK Started \r\n");
    
    for(;;)
    {
        if(!CapSense_IsBusy())
        {
            CapSense_ProcessAllWidgets();
            int pos;
            
            
            /* Stores the current detected gesture */
            gesture = CapSense_DecodeWidgetGestures(CapSense_LINEARSLIDER0_WDGT_ID);
            
            
            
            /* Controls specific LEDs based on the gesture that was captured */
            switch(gesture)
            {
                case CapSense_TMG_FLICK_EAST:
                    ledIndex++;
                printf("CapSense_TMG_FLICK_EAST %d\r\n",ledIndex );
                break; 
                case CapSense_TMG_FLICK_WEST:
                    ledIndex--;
                printf("CapSense_TMG_FLICK_WEST %d\r\n",ledIndex );
                break;
                case CapSense_ONE_FINGER_FLICK_UP:
                    ledIndex++;
                printf("CapSense_ONE_FINGER_FLICK_UP\r\n" );
                break;
                case CapSense_ONE_FINGER_FLICK_DOWN:
                printf("CapSense_ONE_FINGER_FLICK_DOWN\r\n" );
                    ledIndex--;
                break;
                case CapSense_ONE_FINGER_SINGLE_CLICK:
                printf("CapSense_ONE_FINGER_SINGLE_CLICK\r\n" );
                    break;
                case CapSense_ONE_FINGER_EDGE_SWIPE_LEFT:
                printf("CapSense_ONE_FINGER_EDGE_SWIPE_LEFT\r\n" );
                    break;
                case CapSense_ONE_FINGER_EDGE_SWIPE_RIGTH:
                    break;
                case CapSense_ONE_FINGER_ROTATE_CW:
                    break;
                case CapSense_ONE_FINGER_ROTATE_CCW:
                    break;
                case CapSense_TMG_TOUCHDOWN:
                printf("Touched Slider\r\n");
                break;
                case CapSense_TMG_LIFT_OFF:
                printf("Touched Removed from slider\r\n");
                break;
                default:
                if(prevGsture != gesture)
                printf("%X \r\n",gesture );
                prevGsture = gesture;
                    break;
            }
            
            if(ledIndex > MAX_COLOR)
            {
                ledIndex = MAX_COLOR-1;
            }
            if(ledIndex < 0)
            {
                ledIndex = 0;
            }
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
#endif
#if 0


int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    CapSense_Start();
    
    CapSense_ScanAllWidgets();
    
    PWM_Start();
    PWM_1_Start();
    PWM_2_Start();
                Cy_TCPWM_PWM_SetCompare0(PWM_1_HW,PWM_1_CNT_NUM,0);
                Cy_TCPWM_PWM_SetCompare0(PWM_2_HW,PWM_2_CNT_NUM,0);
                Cy_TCPWM_PWM_SetCompare0(PWM_HW,PWM_CNT_NUM,100);
                UART_1_Start();
                
    printf("\x1b[2J\x1b[;H");
    printf("UART TASK Started \r\n"); 
     
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
