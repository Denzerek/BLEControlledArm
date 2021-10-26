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

#include "FreeRTOS.h"
#include "project.h"
#include "semphr.h"
#include "task.h"
#include <stdio.h>
#include "event_groups.h"


#define SUPER_TRANSMITTER   printf
//#define TRANSMITTER 

#define serialPrint(x)  { SUPER_TRANSMITTER("[ UART ] : ");SUPER_TRANSMITTER(x);SUPER_TRANSMITTER("\r\n");}
#define serialPrintf(x,...)  { SUPER_TRANSMITTER("[ UART ] : ");SUPER_TRANSMITTER(x,__VA_ARGS__);SUPER_TRANSMITTER("\r\n");}



char temp[100];


/* [] END OF FILE */
