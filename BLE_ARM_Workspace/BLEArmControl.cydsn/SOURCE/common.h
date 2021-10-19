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

#define serialPrint(x)  { printf("[ UART ] : ");printf(x);printf("\r\n");}
#define serialPrintf(x,...)  { printf("[ UART ] : ");printf(x,__VA_ARGS__);printf("\r\n");}
#define seralPrinter(x,...) { printf("[ UART ] : ");sprintf(temp,x,__VA_ARGS__);printf(temp);printf("\r\n"); }


#define PJT_NAME    "   MAIN CONTROLLER   " 


#define START_UP_DISP()   { serialPrint("System Init Done.");\
                            serialPrint("======================================"); \
                            serialPrintf("=======%s=========",PJT_NAME); \
                            serialPrint("======================================"); \
                        }
                            
                        
extern QueueHandle_t servoControlQueue;
extern QueueHandle_t pwmQueue;
                        
extern EventGroupHandle_t pwmEventGroup;
#define PWM_EVENT_I2C       ( 1 << 0 )
#define PWM_EVENT_BLE       ( 1 << 1 )
#define PWM_EVENT_ALL       ( PWM_EVENT_I2C | PWM_EVENT_BLE  )

char temp[100];


/* [] END OF FILE */
