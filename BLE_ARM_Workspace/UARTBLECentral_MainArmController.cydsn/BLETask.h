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


typedef enum{
    M1,
    M2,
    M3,
    M4,
    M_MAX
}motors_t;

typedef enum{
    POS_ABSOLUTE,
    POS_RELATIVE,
}motor_change_t;

typedef struct
{
    motors_t motor;
    motor_change_t type;
    uint8_t charecteristicIndex;
}motorToControl_t;

#define MOTORS_TO_CONTROL_MAX   ( M_MAX * 2 )


#define ble_print(x)    printf("[ BLE CENTRAL ] : ");printf(x);printf("\r\n");
#define ble_printf(x,...)    printf("[ BLE CENTRAL ] : ");printf(x,__VA_ARGS__);printf("\r\n");


void writeMotorPosition(motors_t ,motor_change_t,uint8_t);

void bleTask(void*);


/* [] END OF FILE */
