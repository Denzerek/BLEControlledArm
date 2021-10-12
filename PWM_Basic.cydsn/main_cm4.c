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
#include "uartTask.h"
#include "pwmTask.h"
#include "common.h"



#define UART_TASK_STACK_SIZE    400
#define PWM_TASK_STACK_SIZE     400
#define UART_TASK_PRIORITY      3
#define PWM_TASK_PRIORITY       2

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    //Setting uart with higher priority for allowing processing in between the pwm task
    xTaskCreate(UartTask,"UART TASK",UART_TASK_STACK_SIZE,0,UART_TASK_PRIORITY,0);
    
    /* PWM task that runs continuously*/
    xTaskCreate(pwmTask,"PWM TASK",PWM_TASK_STACK_SIZE,0,PWM_TASK_PRIORITY,0);
    
    /* Start the Scheduler*/
    vTaskStartScheduler();
    
    for(;;)
    {
    }
    
}

/* [] END OF FILE */
