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

static SemaphoreHandle_t uartSemaphore;
static void UARTIsr()
{
    // Disable and clear the interrupt
    Cy_SCB_SetRxInterruptMask(UART_HW,0);
    Cy_SCB_ClearRxInterrupt(UART_HW, CY_SCB_RX_INTR_NOT_EMPTY);
    NVIC_ClearPendingIRQ((IRQn_Type)UART_SCB_IRQ_cfg.intrSrc);
    
    //If the semaphore causes a task switch , you should yeild to that task
    BaseType_t xHigherPriorityTaskWoken;
    xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(uartSemaphore,&xHigherPriorityTaskWoken);
     
    if(xHigherPriorityTaskWoken != pdFALSE)
    {
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}


void UartTask(void * arg)
{
    (void) arg;
    UART_Start();
    setvbuf(stdin,NULL,_IONBF,0);
    
    /* \x1b[2J\x1b[;H - ANSI ESC sequence for clear screen */
    serialPrint("\x1b[2J\x1b[;H");
    serialPrint("UART Started ");
    serialPrint("Press ? to ensure reception operation");
    
    uartSemaphore = xSemaphoreCreateBinary();
    
    //configure the interrupt handler
    (void) Cy_SysInt_Init(&UART_SCB_IRQ_cfg,&UARTIsr);
    
    //enable the NVIC engine for uart
    NVIC_EnableIRQ(UART_SCB_IRQ_cfg.intrSrc);
    
    //enable the Receiver not empty interrupt
    Cy_SCB_SetRxInterruptMask(UART_HW,CY_SCB_RX_INTR_NOT_EMPTY);
    
    while(1)
    {
        xSemaphoreTake(uartSemaphore,portMAX_DELAY);
        
        //check if there are data in the uart rx buffer
        while(Cy_SCB_UART_GetNumInRxFifo(UART_HW))
        {
            //get character by character from the uart rx buffer
            char c = getchar();
            switch(c)
            {
                case '?':
                serialPrint("?\tPrint Help");
                break;
            }
        }
        
        //Once you have processed the rx fifo , re enable the interrupt
        Cy_SCB_SetRxInterruptMask(UART_HW,CY_SCB_RX_INTR_NOT_EMPTY);
    }
    
    
}
    

/* [] END OF FILE */
