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

#define ezi2cPrint(x)  { printf("[ EZI2C ] : ");printf(x);printf("\r\n");}
#define ezi2cPrintf(x,...)  { printf("[ EZI2C ] : ");printf(x,__VA_ARGS__);printf("\r\n");}

void ezI2CTask(void * arg);

/* [] END OF FILE */
