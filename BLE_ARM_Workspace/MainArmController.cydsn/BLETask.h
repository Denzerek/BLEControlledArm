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

#pragma once

#include "common.h"

#define ble_print(x)    TRANSMITTER("[ BLE ]");TRANSMITTER(x);TRANSMITTER("\r\n");
#define ble_printf(x,...)    TRANSMITTER("[ BLE ]");TRANSMITTER(x,__VA_ARGS__);TRANSMITTER("\r\n");


void bleTask(void* arg);


/* [] END OF FILE */
