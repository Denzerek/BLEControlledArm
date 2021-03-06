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
#include "semphr.h"
#include "task.h"
#include "limits.h"
#include <stdio.h>

#define LED_ON  0
#define LED_OFF 1

#define ble_print(x)    printf("[ BLE PERIPHERAL ]");printf(x);printf("\r\n");
#define ble_printf(x,...)    printf("[ BLE PERIPHERAL ]");printf(x,__VA_ARGS__);printf("\r\n");

SemaphoreHandle_t bleSemaphore;

void genericEventHandler(uint32_t event,void* eventParam)
{
    cy_stc_ble_gatts_write_cmd_req_param_t *writeRequestParam;
    switch(event)
    {
        case CY_BLE_EVT_STACK_ON:
        case CY_BLE_EVT_GAP_DEVICE_DISCONNECTED:
        Blink_Start();
        Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_FAST,CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX);
        Cy_TCPWM_TriggerReloadOrIndex(PWM_DIM_HW,PWM_DIM_CNT_NUM);
        Cy_TCPWM_PWM_Disable(PWM_DIM_HW,PWM_DIM_CNT_NUM);
        break;
        
        case CY_BLE_EVT_GATT_CONNECT_IND:
        Cy_TCPWM_TriggerReloadOrIndex(Blink_HW,Blink_CNT_NUM);
        Cy_TCPWM_PWM_Disable(Blink_HW,Blink_CNT_NUM);
        PWM_DIM_Start();
        break;
        
        case CY_BLE_EVT_GATTS_WRITE_REQ:
        writeRequestParam = (cy_stc_ble_gatts_write_cmd_req_param_t*)eventParam;
        if(CY_BLE_LED_GREEN_CHAR_HANDLE == writeRequestParam->handleValPair.attrHandle)
        {
            uint32_t val = writeRequestParam->handleValPair.value.val[0];
            if(val > 100) val = 100;
            Cy_TCPWM_PWM_SetCompare0(PWM_DIM_HW,PWM_DIM_CNT_NUM,val);
        }
        Cy_BLE_GATTS_WriteRsp( writeRequestParam->connHandle);
        break;
        
    }
    
}

void bleInterruptNotify()
{
    BaseType_t xHigherPriorityTaskWoken;
    xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(bleSemaphore,&xHigherPriorityTaskWoken);
    //This part does a context switch by calling the scheduler to go the task where the semaphore caused an unblock.
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    
}

void bleTask(void * arg)
{
    (void)arg;
    ble_print("BLE Task started");
    bleSemaphore = xSemaphoreCreateBinary();
    
    //register the generic handler
    Cy_BLE_Start(genericEventHandler);
    
    //process all ble initialization processes until the ble state is set to on
    while(Cy_BLE_GetState() != CY_BLE_STATE_ON)
    {
        Cy_BLE_ProcessEvents();
    }
    
    Cy_BLE_RegisterAppHostCallback(bleInterruptNotify);
    //Cy_BLE_IAS_RegisterAttrCallback(iasEventHandler);
    for(;;)
    {
        xSemaphoreTake(bleSemaphore,portMAX_DELAY);
        Cy_BLE_ProcessEvents();
    }
    
}


/*
Author : Alen Austin
Brief : This project can be used as a standalone one or in combination 
with the BLECentralBasic project.
STANDALONE
==========
As a standalone pjt, the user can connect to the device over BLE (using
cysmart BLE app or any other ble scanner applications) and connect to 
the device named PSoC 6.
User can then write to the characteristic named LED to change the brightness
of the RGB green LED from 0 to 100 (0-64 in hex)

COMBO
=====
As a combo project, this firmware should be loaded into one 062 BLE pioneer
kit and the firmware of BLECentralBasic project into a different 062 BLE
pioneer kit. Then start both, and u will be able to see the BLE central
device connect to the peripheral device  and user can change the color
of the peripheral device by pressing the '+' or '-' in the uart terminal 
of the central device.
*/

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    UART_1_Start();
    setvbuf(stdin,NULL,_IONBF,0);
    setvbuf(stdout,NULL,_IONBF,0);
    CyDelay(10);
    ble_print("\x1b[2J\x1b[;H");
    ble_print("System Init Done.");
    ble_print("======================================"); 
    ble_print("======== BLE PERIPHERAL CODE ========="); 
    ble_print("======================================"); 
                       
    PWM_DIM_Start();
    Blink_Start();
    ble_print("System Started");
    xTaskCreate(bleTask,"BLE TASK",8*1024,0,2,0);
    
    vTaskStartScheduler();
    
    for(;;);
    
}
/* [] END OF FILE */
