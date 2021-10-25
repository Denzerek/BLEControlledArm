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

#include "capSenseTask.h"
#include "BLETask.h"

void capsenseTask(void *arg)
{
    (void) arg;
    
    motors_t currentMotor = M1;
    static uint8_t pressReleased = true;
    
    
    
    CapSense_Start();
    CapSense_ScanAllWidgets();
    
    cap_print("Capsense Task Started")
    
    for(;;)
    {
        if(!CapSense_IsBusy())
        {
            CapSense_ProcessAllWidgets();
            int pos;
            pos = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID);
            
            if(pos < 0xFFFF)
            {
                writeMotorPosition(currentMotor,POS_ABSOLUTE,pos);
            }
            
            if(CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID))
            {
                if(pressReleased)
                {
                    if(currentMotor < M_MAX - 1)
                    {
                        currentMotor++;
                        pressReleased = false;
                        cap_printf("Motor M%d selected",currentMotor);
                    }
                }
            }
            else if(CapSense_IsWidgetActive(CapSense_BUTTON1_WDGT_ID))
            {
                if(pressReleased)
                {
                    if(currentMotor > M1)
                    {
                        currentMotor--;
                        pressReleased = false;
                        cap_printf("Motor M%d selected",currentMotor);
                    }
                }
            }
            else
            {
                pressReleased = true;
            }
            
            if(currentMotor >= M_MAX) currentMotor = M_MAX - 1;
            if(currentMotor < M1) currentMotor = M1;
            
            CapSense_UpdateAllBaselines();
            CapSense_ScanAllWidgets();
        }
        else
        {
            vTaskDelay(50);
        }
    }
}
#if 0
#include "capSenseTask.h"
#include "BLETask.h"

void capsenseTask(void *arg)
{
    (void) arg;
    
    motors_t currentMotor = M1;  
    
    CapSense_Start();
    CapSense_ScanAllWidgets();
    
    cap_print("Capsense Task Started")
    
    for(;;)
    {
        if(!CapSense_IsBusy())
        {
            CapSense_ProcessAllWidgets();
            int pos;
            pos = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID);
            
            if(pos < 0xFFFF)
            {
                writeMotorPosition(currentMotor,POS_ABSOLUTE,pos);
            }
            
            if(CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID))
            {
                cap_print("Motor M1 selected");
                currentMotor = M1;   
            }
            
            if(CapSense_IsWidgetActive(CapSense_BUTTON1_WDGT_ID))
            {
                cap_print("Motor M2 Selected");
                currentMotor = M2;   
            }
            CapSense_UpdateAllBaselines();
            CapSense_ScanAllWidgets();
        }
        else
        {
            vTaskDelay(50);
        }
    }
}
#endif
/* [] END OF FILE */
