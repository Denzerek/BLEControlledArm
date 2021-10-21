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
#include "project.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

#define ble_print(x)    printf("[ BLE ] : ");printf(x);printf("\r\n");
#define ble_printf(x,...)    printf("[ BLE ] : ");printf(x,__VA_ARGS__);printf("\r\n");


void writeLED(uint8_t brightness)
{
    if(Cy_BLE_GetConnectionState(cy_ble_connHandle[0]) != CY_BLE_CONN_STATE_CLIENT_DISCOVERED)
    {
        ble_print("Not connected");
        return;
    }
    ble_printf("Brightness = %d",brightness);
    
    cy_stc_ble_gattc_write_req_t myVal;
    myVal.handleValPair.value.len = 1;
    myVal.handleValPair.value.val = &brightness;
    myVal.handleValPair.attrHandle = cy_ble_customCServ[CY_BLE_CUSTOMC_LED_SERVICE_INDEX].customServChar[CY_BLE_CUSTOMC_LED_GREEN_CHAR_INDEX].customServCharHandle[0];
    myVal.connHandle = cy_ble_connHandle[0];
    
    int i = 0;
    //wait for the data transfer to complete
    while(Cy_BLE_GATTC_WriteCharacteristicValue(&myVal) != CY_BLE_SUCCESS)
    {
        Cy_BLE_ProcessEvents();
        i++;
        if(i > 0xFFFE)
        {
            ble_print("BLE GATTC write error");
            return;
        }
    }
}


typedef struct{
    char * name;
    uint8_t * serviceUUID;
    int name_len;
    uint8_t servUUID_len;
}advInfo_t;
 
advInfo_t currentAdvInfo;

void findAdvInfo(uint8_t*adv,uint8_t len)
{
    memset (&currentAdvInfo,0,sizeof(currentAdvInfo));
    
    for(uint8_t i = 0; i< len;)
    {
        switch(adv[i+1])
        {
            //Service ID to check for the service uuid
            case 0x07:
                currentAdvInfo.serviceUUID = &adv[i+2];
                currentAdvInfo.servUUID_len = adv[i]-1;
                break;
            
            //Peripheral advertiser name
            case 0x09:
                currentAdvInfo.name = (char*)&adv[i+2];                
                currentAdvInfo.name_len = adv[i]-1;
            break;
            default:
            break;
                
        }
        //if packet id does not match, then skip the whole packet by adding i with length
        i = i +  adv[i] + 1;
    }
}

void genericEventHandler(uint32_t event,void* eventParameter)
{
    switch(event)
    {
        case CY_BLE_EVT_STACK_ON:
        case CY_BLE_EVT_GAP_DEVICE_DISCONNECTED:
            ble_print("Starting Scan");
            //Start scan operation
            Cy_BLE_GAPC_StartScan(CY_BLE_SCANNING_FAST,0);
            //turn off the led
            Cy_GPIO_Set(GREEN_PORT,GREEN_NUM);
            Cy_GPIO_Clr(RED_PORT,RED_NUM);
        break;
        case CY_BLE_EVT_GAPC_SCAN_PROGRESS_RESULT:
            //Print out information about the device that was found
            ble_print("Device");
            cy_stc_ble_gapc_adv_report_param_t *scanProgressParam = (cy_stc_ble_gapc_adv_report_param_t*) eventParameter;
            printf("[ BLE ] : BD Addr = ");
            for(unsigned int i = 0; i < CY_BLE_BD_ADDR_SIZE;i++)
            {
                printf("%02X ",scanProgressParam->peerBdAddr[i]);
            }
            printf("\r\n");
            ble_printf("Length = %d",scanProgressParam->dataLen);
            
            findAdvInfo(scanProgressParam->data,scanProgressParam->dataLen);
            if(currentAdvInfo.name != 0)
                ble_printf("%.*s",currentAdvInfo.name_len,currentAdvInfo.name);
            ble_print("");
            
            if( (currentAdvInfo.servUUID_len > 0 )
                 && (memcmp(currentAdvInfo.serviceUUID,cy_ble_customCServ[CY_BLE_CUSTOMC_LED_SERVICE_INDEX].uuid
                  ,currentAdvInfo.servUUID_len) == 0))
            {
                
                ble_print("Found LED Service 2");
                cy_stc_ble_bd_addr_t connectAddr;
                memcpy(&connectAddr.bdAddr[0],&scanProgressParam->peerBdAddr[0],CY_BLE_BD_ADDR_SIZE);
                connectAddr.type = scanProgressParam->peerAddrType;
                Cy_BLE_GAPC_ConnectDevice(&connectAddr,0);
                Cy_BLE_GAPC_StopScan();
            }
                
        break;
        case CY_BLE_EVT_GATT_DISCONNECT_IND:
            Cy_GPIO_Set(GREEN_PORT,GREEN_NUM);
            Cy_GPIO_Clr(RED_PORT,RED_NUM);
            ble_print("Disconnected");
        break;
        case CY_BLE_EVT_GATT_CONNECT_IND:
            Cy_GPIO_Clr(GREEN_PORT,GREEN_NUM);
            ble_print("Made a connection, starting service discovery");
            Cy_BLE_GATTC_StartDiscovery(cy_ble_connHandle[0]);
        break;
        
        case CY_BLE_EVT_GATTC_DISCOVERY_COMPLETE:
            ble_print("Discovery Complete");
        break;
            
        case CY_BLE_EVT_GATTC_ERROR_RSP:
            ble_print("GATTC Error Response");
        break;
            
        case CY_BLE_EVT_GATTC_WRITE_RSP:
            ble_print("GATTC Write Succeeded");
        break;
            
        default:
        break;
    }
}
void bleTask(void* arg)
{
    (void) arg;
    ble_print("Starting BLE Central Task");
    
    Cy_BLE_Start(genericEventHandler);
    
    char c;
    uint8_t brightness = 0;
    for(;;)
    {
        Cy_BLE_ProcessEvents();
        if(Cy_SCB_UART_GetNumInRxFifo(UART_1_HW))
        {
            c = getchar();
            switch(c)
            {
                case '+': //increase the brightness and then send it via BLE - wrap around at 100
                brightness = (brightness +10) %100;
                writeLED(brightness);
                break;
                case '-':
                brightness -= 10;
                if(brightness > 100) brightness = 100;
                writeLED(brightness);
                break;
            }
        }
    }
}

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    UART_1_Start();

    Cy_GPIO_Set(GREEN_PORT,GREEN_NUM);
    Cy_GPIO_Clr(RED_PORT,RED_NUM);
    CyDelay(10); 
    setvbuf(stdin,0,_IONBF,0);
    xTaskCreate(bleTask," BLE TASK",8*1024,0,1,0);
    vTaskStartScheduler();
    
    for(;;);
}

/* [] END OF FILE */
