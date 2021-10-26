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
#include "common.h"
#include "bmi160.h"

static struct bmi160_dev bmi160Dev;


typedef struct{
    uint32_t i2cEvent;
    char* i2cMessage;
}i2cEvents_s;

volatile static uint32_t i2cStatus = 0;

i2cEvents_s i2cEvents[] = {
    {CY_SCB_I2C_MASTER_MANUAL_ABORT_START,"CY_SCB_I2C_MASTER_MANUAL_ABORT_START"},
    {CY_SCB_I2C_MASTER_MANUAL_BUS_ERR,"CY_SCB_I2C_MASTER_MANUAL_BUS_ERR"},
    {CY_SCB_I2C_MASTER_MANUAL_ARB_LOST,"CY_SCB_I2C_MASTER_MANUAL_ARB_LOST"},
    {CY_SCB_I2C_MASTER_MANUAL_NAK,"CY_SCB_I2C_MASTER_MANUAL_NAK"},
    {CY_SCB_I2C_MASTER_MANUAL_ADDR_NAK,"CY_SCB_I2C_MASTER_MANUAL_ADDR_NAK"},
    {CY_SCB_I2C_MASTER_MANUAL_TIMEOUT,"CY_SCB_I2C_MASTER_MANUAL_TIMEOUT"},
    {CY_SCB_I2C_MASTER_NOT_READY,"CY_SCB_I2C_MASTER_NOT_READY"},
    {CY_SCB_I2C_BAD_PARAM,"CY_SCB_I2C_BAD_PARAM"},
    {0x00,"NONE"},
};

void i2cStatusDecode( cy_en_scb_i2c_status_t i2cStatus)
{
    for(int i = 0; i2cEvents[i].i2cEvent != 0x00 ; i++)
    {
        if((i2cEvents[i].i2cEvent & i2cStatus)  == i2cEvents[i].i2cEvent)
        {
            serialPrint(i2cEvents[i].i2cMessage);
        }
    }
}

#define I2C_TIMEOUT     20
#if 1
static int8_t BMI160BurstWrite(uint8_t devAddr,uint8_t regAddr,uint8_t *data,uint16_t len)
{
    cy_en_scb_i2c_status_t retStatus;
    retStatus = Cy_SCB_I2C_MasterSendStart(I2C_1_HW,devAddr,CY_SCB_I2C_WRITE_XFER,0,&I2C_1_context);
    if(retStatus)i2cStatusDecode(retStatus);
    
    retStatus = Cy_SCB_I2C_MasterWriteByte(I2C_1_HW,regAddr,I2C_TIMEOUT,&I2C_1_context);
    if(retStatus)i2cStatusDecode(retStatus);
    
    for(int i =0;i<len;i++)
    {
        retStatus = Cy_SCB_I2C_MasterWriteByte(I2C_1_HW,data[i],I2C_TIMEOUT,&I2C_1_context);
        if(retStatus)i2cStatusDecode(retStatus);
    }
    retStatus = Cy_SCB_I2C_MasterSendStop(I2C_1_HW,I2C_TIMEOUT,&I2C_1_context);
    if(retStatus)i2cStatusDecode(retStatus);
    return 0;
}


static int8_t BMI160BurstRead(uint8_t devAddr,uint8_t regAddr,uint8_t *data,uint16_t len)
{
    cy_en_scb_i2c_status_t retStatus;
    retStatus = Cy_SCB_I2C_MasterSendStart(I2C_1_HW,devAddr,CY_SCB_I2C_WRITE_XFER,I2C_TIMEOUT,&I2C_1_context);
    if(retStatus)i2cStatusDecode(retStatus);
    
    retStatus = Cy_SCB_I2C_MasterWriteByte(I2C_1_HW,regAddr,I2C_TIMEOUT,&I2C_1_context);
    if(retStatus)i2cStatusDecode(retStatus);
    
    retStatus = Cy_SCB_I2C_MasterSendReStart(I2C_1_HW,devAddr,CY_SCB_I2C_READ_XFER,I2C_TIMEOUT,&I2C_1_context);
    if(retStatus)i2cStatusDecode(retStatus);
    
    for(int i = 0; i < len - 1; i++)
    {
        retStatus = Cy_SCB_I2C_MasterReadByte(I2C_1_HW,CY_SCB_I2C_ACK,&data[i],I2C_TIMEOUT,&I2C_1_context);
        if(retStatus)i2cStatusDecode(retStatus);
    }
    retStatus = Cy_SCB_I2C_MasterReadByte(I2C_1_HW,CY_SCB_I2C_NAK,&data[len-1],I2C_TIMEOUT,&I2C_1_context);
    if(retStatus)i2cStatusDecode(retStatus);
    
    retStatus = Cy_SCB_I2C_MasterSendStop(I2C_1_HW,I2C_TIMEOUT,&I2C_1_context);
    if(retStatus)i2cStatusDecode(retStatus);
    
    return 0;
}
#else

static int8_t BMI160BurstWrite(uint8_t devAddr,uint8_t regAddr,uint8_t *data,uint16_t len)
{
    cy_stc_scb_i2c_master_xfer_config_t transfer;
    /* Configure write transaction */
    transfer.slaveAddress = devAddr;
    transfer.buffer[0] = regAddr;
    transfer.bufferSize   = len+1;
    memcpy(&transfer.buffer[1],data,len);
    //transfer.xferPending  = true; /* Do not generate Stop condition at the end of transaction */
    transfer.xferPending  = false; /* Generate Stop condition at the end of transaction */
    /* Initiate write transaction.
    * The Start condition is generated to begin this transaction.
    */
    (void) Cy_SCB_I2C_MasterWrite(I2C_1_HW, &transfer, &I2C_1_context);
    /* Wait for transaction completion */
    while (0UL != (CY_SCB_I2C_MASTER_BUSY & Cy_SCB_I2C_MasterGetStatus(I2C_1_HW, &I2C_1_context)))
    { 
    }
    
    return 0;
}

static int8_t BMI160BurstRead(uint8_t devAddr,uint8_t regAddr,uint8_t *data,uint16_t len)
{
    (void)regAddr;
    cy_stc_scb_i2c_master_xfer_config_t transfer;
    /* Configure write transaction */
    transfer.slaveAddress = devAddr;
    transfer.buffer = data;
    transfer.bufferSize   = len;
    //transfer.xferPending  = true; /* Do not generate Stop condition at the end of transaction */
    transfer.xferPending  = false; /* Generate Stop condition at the end of transaction */
    
    BMI160BurstWrite(devAddr,regAddr,(uint8_t*)"NONE",0);
    /* Initiate write transaction.
    * The Start condition is generated to begin this transaction.
    */
    (void) Cy_SCB_I2C_MasterRead(I2C_1_HW, &transfer, &I2C_1_context);
    /* Wait for transaction completion */
    while (0UL != (CY_SCB_I2C_MASTER_BUSY & Cy_SCB_I2C_MasterGetStatus(I2C_1_HW, &I2C_1_context)))
    { 
    }
    
    return 0;
}

#endif

static void bmi160Init(void)
{
    vTaskDelay(200);
    
    bmi160Dev.read = (bmi160_read_fptr_t)BMI160BurstRead;
    bmi160Dev.write = (bmi160_write_fptr_t)BMI160BurstWrite;
    bmi160Dev.delay_ms = (bmi160_delay_fptr_t) vTaskDelay;
    bmi160Dev.id = BMI160_I2C_ADDR;
    
    bmi160_init(&bmi160Dev); //initialize the device
    
    bmi160Dev.gyro_cfg.odr = BMI160_GYRO_ODR_800HZ;
    bmi160Dev.gyro_cfg.range = BMI160_GYRO_RANGE_125_DPS;
    bmi160Dev.gyro_cfg.bw = BMI160_GYRO_BW_OSR4_MODE;
    
    bmi160Dev.gyro_cfg.power = BMI160_GYRO_NORMAL_MODE;
    
    bmi160Dev.accel_cfg.odr = BMI160_ACCEL_ODR_1600HZ;
    bmi160Dev.accel_cfg.range = BMI160_ACCEL_RANGE_2G;
    bmi160Dev.accel_cfg.bw = BMI160_ACCEL_BW_OSR4_AVG1;
    bmi160Dev.accel_cfg.power = BMI160_ACCEL_NORMAL_MODE;
    
    bmi160_set_sens_conf(&bmi160Dev);
    bmi160Dev.delay_ms(50);   
    
}

#define MAXACCEL        32768*2

void motionTask(void *arg)
{
    (void) arg;
    serialPrint("\x1b[2J\x1b[;H");
    serialPrint("Starting Motion TASK");
    I2C_1_Start();
    
        vTaskDelay(20);
    bmi160Init();
    struct bmi160_sensor_data acc;
    
    float gx,gy,gz;
    while(1)
    {
        bmi160_get_sensor_data(BMI160_ACCEL_ONLY,&acc,NULL,&bmi160Dev);
        
        gx = (float)acc.x/MAXACCEL;
        gy = (float)acc.y/MAXACCEL;
        gz = (float)acc.z/MAXACCEL;
        
        serialPrintf("%1.2f\t%1.2f\t%1.2f\t",gx,gy,gz);
        vTaskDelay(100);
        
    }
}
int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    UART_1_Start();
    xTaskCreate(motionTask,"MOTION TASK",400,0,1,0);
    vTaskStartScheduler();
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
