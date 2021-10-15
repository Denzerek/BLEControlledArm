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

volatile static i2cStatus = 0;
void i2cCallback(uint32_t event)
{
   i2cStatus |= event;
}


int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    UART_1_Start();
    I2C_1_Start();
    PWM_1_Start();
    printf("i2c code start\r\n");
    Cy_SCB_I2C_RegisterEventCallback(I2C_1_HW, i2cCallback, &I2C_1_context);
    
    
    cy_stc_scb_i2c_master_xfer_config_t transfer;
    uint8_t readBuffer [5UL];
    uint8_t writeBuffer[3UL] = {54,34, 5U};
    /* Configure write transaction */
    transfer.slaveAddress = 0x08U;
    transfer.buffer       = writeBuffer;
    transfer.bufferSize   = sizeof(writeBuffer);
    transfer.xferPending  = true; /* Do not generate Stop condition at the end of transaction */
    //transfer.xferPending  = false; /* Generate Stop condition at the end of transaction */
    i2cStatus = 0;
    /* Initiate write transaction.
    * The Start condition is generated to begin this transaction.
    */
    (void) Cy_SCB_I2C_MasterWrite(I2C_1_HW, &transfer, &I2C_1_context);
    /* Wait for transaction completion */
    while (0UL != (CY_SCB_I2C_MASTER_BUSY & Cy_SCB_I2C_MasterGetStatus(I2C_1_HW, &I2C_1_context)))
    { 
    }
    writeBuffer[0] = 0xA;
     transfer.buffer       = writeBuffer;
    transfer.xferPending  = false; /* Generate Stop condition at the end of transaction */
    
    /* Initiate write transaction.
    * The Start condition is generated to begin this transaction.
    */
    (void) Cy_SCB_I2C_MasterWrite(I2C_1_HW, &transfer, &I2C_1_context);
    /* Wait for transaction completion */
    while (0UL != (CY_SCB_I2C_MASTER_BUSY & Cy_SCB_I2C_MasterGetStatus(I2C_1_HW, &I2C_1_context)))
    { 
    }
    printf("I2c master write operation complete %X\r\n",i2cStatus);
    
    
    
    
    

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
