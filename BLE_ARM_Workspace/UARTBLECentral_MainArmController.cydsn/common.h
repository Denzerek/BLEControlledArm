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

#define serialPrint(x)  { printf("[ UART ] : ");printf(x);printf("\r\n");}
#define serialPrintf(x,...)  { printf("[ UART ] : ");printf(x,__VA_ARGS__);printf("\r\n");}
#define seralPrinter(x,...) { printf("[ UART ] : ");sprintf(temp,x,__VA_ARGS__);printf(temp);printf("\r\n"); }



/* [] END OF FILE */
