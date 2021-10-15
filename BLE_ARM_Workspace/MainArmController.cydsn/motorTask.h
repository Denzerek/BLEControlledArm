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

//#define motorPrint(x)  { printf("[ MOTOR TASK ] : ");printf(x);printf("\r\n");}
//#define motorPrintf(x,...)  { printf("[ MOTOR TASK ] : ");printf(x,__VA_ARGS__);printf("\r\n");}

#define motorPrint(x)  { printf("[ MOTOR TASK ] : ");printf(x);printf("\r\n");}
#define motorPrintf(x,...)  { printf("[ MOTOR TASK ] : ");printf(x,__VA_ARGS__);printf("\r\n");}

typedef enum{
    M1 = 1,
    M2,
}motors_t;

typedef enum{
    POS_ABSOLUTE,
    POS_RELATIVE,
}motor_pos_type_t;

typedef struct PWM_Message{
    motors_t motor;
    motor_pos_type_t changeType;
    int percent;
}PWM_Message_t;

int getMotorPercent(motors_t motors);
int compareToPercent(int compare);

void motorTask(void*);

/* [] END OF FILE */
