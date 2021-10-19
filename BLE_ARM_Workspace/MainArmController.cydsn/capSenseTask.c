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
#include "motorTask.h"

void capsenseTask(void *arg)
{
    (void) arg;
    
    motors_t currentMotor = M1;
    PWM_Message_t myMessage;
    
    
    
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
                cap_printf("M%d PWM : %d",currentMotor,pos);
                myMessage.motor = currentMotor;
                myMessage.percent = pos;
                xQueueSend(pwmQueue,&myMessage,0);
                xQueueSend(servoControlQueue,&myMessage,0);
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
/* [] END OF FILE */
