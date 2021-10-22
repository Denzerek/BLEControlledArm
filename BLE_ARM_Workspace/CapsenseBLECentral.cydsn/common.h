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


#include "project.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "semphr.h"
#include "limits.h"

#define TRANSMITTER     printf


#define serialPrint(x)  { TRANSMITTER("[ UART ] : ");TRANSMITTER(x);TRANSMITTER("\r\n");}
#define serialPrintf(x,...)  { TRANSMITTER("[ UART ] : ");TRANSMITTER(x,__VA_ARGS__);TRANSMITTER("\r\n");}
#define seralPrinter(x,...) { TRANSMITTER("[ UART ] : ");sprintf(temp,x,__VA_ARGS__);TRANSMITTER(temp);TRANSMITTER("\r\n"); }



/* [] END OF FILE */
