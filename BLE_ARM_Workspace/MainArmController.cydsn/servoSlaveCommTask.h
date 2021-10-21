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
#include "motorTask.h"

#define I2C_MAX_EVENTS  2



#define ard_print(x)  { TRANSMITTER("[ ARD COMM TASK ] : ");TRANSMITTER(x);TRANSMITTER("\r\n");}
#define ard_printf(x,...)  { TRANSMITTER("[ ARD COMM TASK ] : ");TRANSMITTER(x,__VA_ARGS__);TRANSMITTER("\r\n");}

typedef struct{
    uint32_t i2cEvent;
    char* i2cMessage;
}i2cEvents_s;

void servoSlaveCommTask(void * arg);
void ardTransmitPWMPercent(motors_t motorNum,uint8_t percent);
void i2cStatusDecode();
/* [] END OF FILE */
