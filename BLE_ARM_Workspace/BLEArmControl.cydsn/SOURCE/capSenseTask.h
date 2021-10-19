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

#define cap_print(x)  { printf("[ CAP TASK ] : ");printf(x);printf("\r\n");}
#define cap_printf(x,...)  { printf("[ CAP TASK ] : ");printf(x,__VA_ARGS__);printf("\r\n");}


void capsenseTask(void *arg);

/* [] END OF FILE */
