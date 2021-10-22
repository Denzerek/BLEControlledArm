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

#include "common.h"
#include "BLETask.h"
#include "uartTask.h"
#include "capSenseTask.h"



/*
Author : Alen Austin
Brief : This project canot be used as a standalone one but in combination 
with the CustomBLEBasic project.

COMBO
=====
As a combo project, this firmware should be loaded into one 062 BLE pioneer
kit and the firmware of CustomBLEBasic project into a different 062 BLE
pioneer kit. Then start both, and u will be able to see the BLE central
device connect to the peripheral device  and user can change the color
of the peripheral device by pressing the '+' or '-' in the uart terminal 
of this central device.
*/
int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    UART_Start();

    Cy_GPIO_Set(GREEN_PORT,GREEN_NUM);
    Cy_GPIO_Clr(RED_PORT,RED_NUM);
    CyDelay(10); 
    serialPrint("\x1b[2J\x1b[;H");
    serialPrint("System Init Done.");
    serialPrint("======================================"); 
    serialPrint("========== BLE CENTRAL CODE =========="); 
    serialPrint("======================================"); 
    setvbuf(stdin,0,_IONBF,0);
    xTaskCreate(bleTask," BLE TASK",8*1024,0,2,0);
    xTaskCreate(UartTask," UART TASK",1024,0,1,0);
    xTaskCreate(capsenseTask," CAPSENSE TASK",1024,0,1,0);
    vTaskStartScheduler();
    
    for(;;);
}

/* [] END OF FILE */
