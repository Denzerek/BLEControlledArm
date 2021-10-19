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

#define ble_print(x)    printf("[ BLE ]");printf(x);printf("\r\n");
#define ble_printf(x,...)    printf("[ BLE ]");printf(x,__VA_ARGS__);printf("\r\n");


void bleTask(void* arg);


/* [] END OF FILE */
