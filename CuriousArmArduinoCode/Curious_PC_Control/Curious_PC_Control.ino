// ARDUINO SKETCH CODE EXAMPLE #1 (4 SERVO)
// USE WITH ARM.UNO 4 SERVO ROBOTIC ARM. SET SERVO SPEED ADJUSTMENT VALUE BELOW.
// Defaults to 4 Servos, Uncomment as indicated for additional Servos
// Adjust the constant "servoSpeed" below to change arm movement speed 
// Use With MeCon Software for Robotic Arm Motion Control
// Number of MeCon Enabled Servo sliders must match number of Servos Enabled in this Arduino Code for correct opperation 

    


#include <Servo.h>

//SERVO OBJECTS
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int servoSpeed = 5;
#define INITIAL 0  

//servo positions values, expects 1-INITIAL deg.
volatile static int servo1Pos = INITIAL;
volatile static int servo2Pos = INITIAL;
volatile static int servo3Pos = INITIAL;
volatile static int servo4Pos = INITIAL;

// Setup runs once when you press reset or power the board
void setup() {        

  // assign servo to pin numbers, Make sure servo motor cables are connected to same pins
  servo1.attach(9);
  servo1.write(servo1.read());
  servo2.attach(8);
  servo3.attach(10);
  servo4.attach(7);
  // initialize serial port and set baud rate
  Serial.begin(115200);// make sure same baud rate is chosen in MeCon  
  Serial.print("*** MeCon Robotic Arm Demo (4 SERVO) ***\r\n");   // Arduino Boot Message
}//END OF SETUP

// ******************************************************************************************************
// ********************************** MAIN PROGRAM LOOP START *******************************************
// ******************************************************************************************************
char temp[40];

void loop() {

//  //Get servo position values from serial port
//  //serial in packet patern = Pos1Val,Pos2Val,Pos3Val,Pos4Val + end of packet char
//  if (Serial.available() ) {
//    servo1Pos = Serial.parseInt();
//    sprintf(temp,"%d\r\n",servo1Pos);
//    
//    Serial.print(temp);
//    servo2Pos = Serial.parseInt();
//    sprintf(temp,"%d\r\n",servo2Pos);
//    
//    Serial.print(temp);
//    servo3Pos = Serial.parseInt();
//    sprintf(temp,"%d\r\n",servo3Pos);
//    
//    Serial.print(temp);
//    servo4Pos = Serial.parseInt();
//  }
//  
setServoPos(servo1,servo1Pos,servoSpeed);
setServoPos(servo2,servo2Pos,servoSpeed);
setServoPos(servo3,servo3Pos,servoSpeed);
setServoPos(servo4,servo4Pos,servoSpeed);
 
}//END OF MAIN LOOP



//********************************************************************************************************
//************************************* CUSTOM FUNCTIONS *************************************************
//********************************************************************************************************
//




void testDelay()
{
  for(int i = 0;i< 20;i++)
  delay(1);
}

//move servo motors to new positions 
void setServoPos(Servo servoX,int targetPosition, int speedX){
    
    while(servoX.read()!=targetPosition){
    if (servoX.read() < targetPosition){
      servoX.write(servoX.read()+1);
      testDelay();
    }

    if (servoX.read() > targetPosition){
      servoX.write(servoX.read()-1);
      testDelay();
    }
    }
}



////move servo motors to new positions 
//void setServoPos(Servo servoX,int targetPosition, int speedX){
//    
//    if (servoX.read()==targetPosition){
//       return;
//    }
//    if (servoX.read() < targetPosition){
//      servoX.write(servoX.read()+1);
//      delay(speedX);
//      return;
//    }
//
//    if (servoX.read() > targetPosition){
//      servoX.write(servoX.read()-1);
//      delay(speedX);
//      return;
//    }
//}
