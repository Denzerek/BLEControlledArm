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

#define serialPrint(x)  { printf("[ UART ] : ");printf(x);printf("\r\n");}
#define serialPrintf(x,...)  { printf("[ UART ] : ");printf(x,__VA_ARGS__);printf("\r\n");}
#define seralPrinter(x,...) { printf("[ UART ] : ");sprintf(temp,x,__VA_ARGS__);printf(temp);printf("\r\n"); }


#define PJT_NAME    "   MAIN CONTROLLER   " 


#define START_UP_DISP()   { \
                            serialPrint("======================================"); \
                            serialPrintf("=======%s=========",PJT_NAME); \
                            serialPrint("======================================"); \
                        }

char temp[100];


/* [] END OF FILE */
