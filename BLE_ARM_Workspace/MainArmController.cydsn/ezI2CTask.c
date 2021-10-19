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
#include "ezI2CTask.h"
#include "motorTask.h"

//#define TEST_EZI2C

#if 1
void ezI2CTask(void * arg)
{
    (void) arg;
    uint8_t motorPercent[2];
    
    EZI2C_Start();
    ezi2cPrint("EZI2C Task Started ...");
    CyDelay(1);
    
    EZI2C_SetBuffer1(motorPercent,sizeof(motorPercent),0);
    
    while(1)
    {
        motorPercent[0] = getMotorPercent(M1);
        motorPercent[1] = getMotorPercent(M2);
        xEventGroupWaitBits(pwmEventGroup,  //.which event group
                            PWM_EVENT_I2C,  //which event to wait for
                            pdTRUE,         //clear the bit after it is set
                            pdFALSE,        //only wait for the i2c bit
                            portMAX_DELAY); //wait indefinitely
    }
}
#endif

#ifdef TEST_EZI2C
static SemaphoreHandle_t ezi2cSemaphore;
void ezI2CIsr()
{
    Cy_SCB_EZI2C_Interrupt(EZI2C_HW,&EZI2C_context);
    
    //ezi2cPrint("ezi2c Interrupt");
    //If the semaphore causes a task switch , you should yeild to that task
    BaseType_t xHigherPriorityTaskWoken;
    xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(ezi2cSemaphore,&xHigherPriorityTaskWoken);
     
    if(xHigherPriorityTaskWoken != pdFALSE)
    {
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

uint8_t buffer[20] ;
void ezI2CTask(void * arg)
{
    (void) arg;
    
    EZI2C_Start();
    PWM_3_Start();
    
    *buffer = 10;
    uint8_t motorPercent[2];
    
    //configure the interrupt handler
    (void) Cy_SysInt_Init(&EZI2C_SCB_IRQ_cfg,&ezI2CIsr);
    
    //enable the NVIC engine for uart
    NVIC_EnableIRQ(EZI2C_SCB_IRQ_cfg.intrSrc);
    
    /*Application to test bridge control panel ezi2c oepration*/
    //EZI2C_SetBuffer1(buffer,1,1);
    EZI2C_SetBuffer1(motorPercent,sizeof(motorPercent),0);
    
    ezi2cSemaphore = xSemaphoreCreateBinary();
    
    //Give interrupt on address match
    Cy_SCB_SetRxInterruptMask(EZI2C_HW,CY_SCB_I2C_INTR_WAKEUP);
    
    
    ezi2cPrint("EZI2C Task Started ...");
    
     for( ;; )
     {
        
        motorPercent[0] = getMotorPercent(M1);
        motorPercent[1] = getMotorPercent(M2);
        
        *buffer = ( motorPercent[0] + motorPercent[1]);
        ezi2cPrintf("Motor 1: %%%d Motor 2 : %%%d",*motorPercent,*(motorPercent+1));
        Cy_TCPWM_PWM_SetCompare0(PWM_3_HW,PWM_3_CNT_NUM,abs(*buffer ));
        
        xSemaphoreTake(ezi2cSemaphore,portMAX_DELAY);
        
     }
    
}
#endif
/* [] END OF FILE */
