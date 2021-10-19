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
#include "FreeRTOS.h"
#include <stdio.h>
#include "task.h"


#define pwm_print(x)  { printf("[ PWM TASK ] : ");printf(x);printf("\r\n");}
#define pwm_printf(x,...)  { printf("[ PWM TASK ] : ");printf(x,__VA_ARGS__);printf("\r\n");}


int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    UART_Start();
  
    uint8_t compareVal;
    
    /* Start the PWM operation */
    PWM_RED_Start();
    pwm_print("Heart Beat LED Started ...");
    LEDBlink_Start();
    Dimmer_Start();
    pwm_print("Kill Switch LEDs Started ...");
    Cy_TCPWM_PWM_SetCompare0(Dimmer_HW,Dimmer_CNT_NUM,95);
    
    /* Startup message display*/
    //START_UP_DISP();
    
    
    for(;;)
    {
        /* Set the compare value with modified one*/
        Cy_TCPWM_PWM_SetCompare0(PWM_RED_HW,PWM_RED_CNT_NUM,compareVal++);
        
        /* Update the compare value*/
        compareVal  = (compareVal + 1) % 100;
        
        vTaskDelay(10);
    }
}

/* [] END OF FILE */
