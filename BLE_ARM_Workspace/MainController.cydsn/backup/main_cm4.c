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
#include "uartTask.h"
#include "FreeRTOS.h"
#include "task.h"

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    xTaskCreate(UartTask,"UART TASK",400,0,2,0);
    xTaskCreate()
    
    /* Start the Scheduler*/
    vTaskStartScheduler();
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
