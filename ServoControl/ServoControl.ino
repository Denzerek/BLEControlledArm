/*
 * Author : Alen Austin
 * Purpose : Arduino Firmware to controller servo motor operation for Main Controller
 *            This firmware communicates with the Main controller which is a Cypress BLE Pioneer Kit
 * Date: 15/10/2021
 */

#include <Wire.h>
#include <Servo.h>


#define SLAVE_ADDRESS       0x08
#define DEBUG_COM_BAUDRATE  115200
#define I2C_CLOCK_SPEED     4000000
#define serialPrint         Serial.print
#define servo_print(x)      serialPrint("[ SERVO SLAVE ] : ");serialPrint(x);serialPrint("\r\n");
#define COM_ADDRESSED_MOTOR     *(receptionBuffer + 1 )
#define COM_PACKET_TAIL         *(receptionBuffer + 3 )
#define PROTOCOL_TAIL       0x0D      //tail will remaiin fixed for every transmission
#define COM_PWM_DATA            *(receptionBuffer + 2 )

#define PWM_COMMAND 0x0C

//Uncomment to observe debug messages
//#define MOTOR_DEBUG_ENABLE

typedef enum{
  MOTOR_MIN,
  MOTOR_1,
  MOTOR_2,
  MOTOR_MAX
}motors_t;

char temp[100];
char receptionBuffer[20];
volatile uint8_t index = 0;
volatile uint8_t motorFoundFlag = 0;

// create servo object to control the horizontal servo
Servo servHorizontal;                
Servo servvertical;                  
Servo servArm;                    
Servo servHand;                

void setup() {
  
  //Initialize debug monitor
  Serial.begin(DEBUG_COM_BAUDRATE);           
  servo_print("\x1b[2J\x1b[;H");
  servo_print("Debug COM Initialized");
  
  //Set I2C Clock speed
  Wire.setClock(I2C_CLOCK_SPEED);

  //Initialize I2c bus with slave address
  Wire.begin(SLAVE_ADDRESS);           

  //Register command reception callback
  Wire.onReceive(commandReceptionCalback);
  
  servo_print("I2c Initialized");
  servo_print("==========================================");
  servo_print("========== SERVO SLAVE ONLINE ============");
  servo_print("==========================================");

}

void setMotorPWMPercent(uint8_t motorNum,uint8_t percent)
{
  
  sprintf(temp,"Motor : %d\tPWM : %d",motorNum,percent);
  servo_print(temp);
}
void loop() {

  if(*receptionBuffer && (COM_PACKET_TAIL == PROTOCOL_TAIL))
  {
    switch(*receptionBuffer)
    {
      case PWM_COMMAND:
        for(int motorIndex = MOTOR_MIN + 1 ; motorIndex < MOTOR_MAX ; motorIndex++)
        {
          if(COM_ADDRESSED_MOTOR == motorIndex)
          {
#ifdef MOTOR_DEBUG_ENABLE
            sprintf(temp,"Motor %d addressed",motorIndex);
            servo_print(temp);
#endif
            motorFoundFlag = true;
            setMotorPWMPercent(motorIndex,COM_PWM_DATA);
          }
        }
        if(!motorFoundFlag)
        {
            sprintf(temp,"Invalid motor %d addressed",COM_ADDRESSED_MOTOR);
            servo_print(temp);
        }
        *receptionBuffer = NULL;
       break;
      
    }
  }
  
}


void commandReceptionCalback(int howMany)
{
  char *temp;
  while (1 < Wire.available()) 
  { 
    //char c = Wire.read(); // receive byte as a character
#ifndef MOTOR_DEBUG_ENABLE
    receptionBuffer[index++] = Wire.read();
#else 
    receptionBuffer[index] = Wire.read();
  Serial.print(receptionBuffer[index++],HEX);
  Serial.print(" ");
#endif
  }
  
#ifdef MOTOR_DEBUG_ENABLE
  Serial.print("\r\n");
#endif
  index = 0;

  //Necessary for the next i2c read operation (dont remove)
  int x = Wire.read();
}
