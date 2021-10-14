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
#include "motorTask.h"
#include "ezI2CTask.h"
#include "event_groups.h"



#define UART_TASK_STACK_SIZE        400
#define UART_TASK_PRIORITY          2

#define MOTOR_TASK_STACK_SIZE       400
#define MOTOR_TASK_PRIORITY         2

#define PWM_TASK_STACK_SIZE         400
#define PWM_TASK_PRIORITY           1

#define EZI2C_TASK_STACK_SIZE         400
#define EZI2C_TASK_PRIORITY           2

QueueHandle_t pwmQueue;
EventGroupHandle_t pwmEventGroup;

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    
    pwmQueue = xQueueCreate(4,sizeof(PWM_Message_t));
    
    pwmEventGroup = xEventGroupCreate();

    //Setting uart with higher priority for allowing processing in between the pwm task
    xTaskCreate(UartTask,"UART TASK",UART_TASK_STACK_SIZE,0,UART_TASK_PRIORITY,0);
    
    /* PWM task that runs continuously*/
    xTaskCreate(pwmTask,"PWM TASK",PWM_TASK_STACK_SIZE,0,PWM_TASK_PRIORITY,0);
    
    /* PWM Motor task that runs continuously*/
    xTaskCreate(motorTask,"MOTOR TASK",MOTOR_TASK_STACK_SIZE,0,MOTOR_TASK_PRIORITY,0);
    
    /* EZ I2C task that runs continuously*/
    xTaskCreate(ezI2CTask,"EZ I2C TASK",EZI2C_TASK_STACK_SIZE,0,EZI2C_TASK_PRIORITY,0);
    
    /* Start the Scheduler*/
    vTaskStartScheduler();
    
    for(;;)
    {
    }
    
}

/* [] END OF FILE */
