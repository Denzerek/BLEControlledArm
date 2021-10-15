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
int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    UART_1_Start();
    I2C_1_Start();
    PWM_1_Start();
    printf("i2c code start\r\n");
    
    
    cy_stc_scb_i2c_master_xfer_config_t transfer;
    uint8_t readBuffer [5UL];
    uint8_t writeBuffer[2UL] = {67, 5U};
    /* Configure write transaction */
    transfer.slaveAddress = 0x08U;
    transfer.buffer       = writeBuffer;
    transfer.bufferSize   = sizeof(writeBuffer);
    transfer.xferPending  = true; /* Do not generate Stop condition at the end of transaction */
    /* Initiate write transaction.
    * The Start condition is generated to begin this transaction.
    */
    (void) Cy_SCB_I2C_MasterWrite(I2C_1_HW, &transfer, &I2C_1_context);
    /* Wait for transaction completion */
    while (0UL != (CY_SCB_I2C_MASTER_BUSY & Cy_SCB_I2C_MasterGetStatus(I2C_1_HW, &I2C_1_context)))
    {
    }
    printf("I2c master write operation complete\r\n");
    
    /* Configure read transaction */
    transfer.buffer       = readBuffer;
    transfer.bufferSize   = sizeof(readBuffer);
    transfer.xferPending  = false; /* Generate Stop condition the end of transaction */
    /* Initiate read transaction.
    * The ReStart condition is generated to begin this transaction because
    * previous transaction was completed without Stop.
    */
    (void) Cy_SCB_I2C_MasterRead(I2C_1_HW, &transfer, &I2C_1_context);
    /* Wait for transaction completion */
    while (0UL != (CY_SCB_I2C_MASTER_BUSY & Cy_SCB_I2C_MasterGetStatus(I2C_1_HW, &I2C_1_context)))
    {
    }
    
    
    
    

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
