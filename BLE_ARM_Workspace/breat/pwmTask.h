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

#define pwm_print(x)  { printf("[ PWM TASK ] : ");printf(x);printf("\r\n");}
#define pwm_printf(x,...)  { printf("[ PWM TASK ] : ");printf(x,__VA_ARGS__);printf("\r\n");}


void pwmTask(void * arg);

/* [] END OF FILE */
