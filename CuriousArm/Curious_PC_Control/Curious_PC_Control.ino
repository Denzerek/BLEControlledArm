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
//Servo servo5;//Uncomment for 5 servo arm setup
//Servo servo6;//Uncomment for 6 servo arm setup


//servo positions values, expects 1-180 deg.
int servo1Pos = 90;
int servo2Pos = 90;
int servo3Pos = 90;
int servo4Pos = 90;
//int servo5Pos = 90;//Uncomment for 5 servo arm setup
//int servo6Pos = 90;//Uncomment for 6 servo arm setup


// variables
char endOfPacketChar;//Data is sent via fixed lenght set of Integers, Terminated by a Char, Example Packet: int1,int2,int3,int4,x

// constants
const char servoEOPC = 'x';// If 'x' then serial data packet is Servo position values

//####################### SET SERVO SPEED VALUE ##################################################
//-->Adjustable Value!
const int servoSpeed = 5;// Adjustable delay in milliseconds between servo position updates, Expirement with diff values. 0= Full Speed, Higher Values = Slower Speed
//#############################################################################################

//*************** INIT AT STARTUP *******************************************************************

// Setup runs once when you press reset or power the board
void setup() {        

  // assign servo to pin numbers, Make sure servo motor cables are connected to same pins
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  //servo5.attach(6);//Uncomment for 5 servo arm setup
  //servo6.attach(7);//Uncomment for 6 servo arm setup


 
  // initialize serial port and set baud rate
  Serial.begin(9600);// make sure same baud rate is chosen in MeCon

    
  Serial.print("*** MeCon Robotic Arm Demo (4 SERVO) ***");   // Arduino Boot Message



}//END OF SETUP

// ******************************************************************************************************
// ********************************** MAIN PROGRAM LOOP START *******************************************
// ******************************************************************************************************

void loop() {

  //Get servo position values from serial port
  //serial in packet patern = Pos1Val,Pos2Val,Pos3Val,Pos4Val + end of packet char
  if (Serial.available() ) {
    servo1Pos = Serial.parseInt();
    //servo2Pos = Serial.parseInt();
    //servo3Pos = Serial.parseInt();
    //servo4Pos = Serial.parseInt();
    //servo5Pos = Serial.parseInt();//Uncomment for 5 servo arm setup
    //servo6Pos = Serial.parseInt();//Uncomment for 6 servo arm setup
    endOfPacketChar = Serial.read();
  }
  
//call function to set servo positions based on recived serial data 
setServoPos(servo1,(180 - servo1Pos),servoSpeed,servoEOPC);// (180 - Servo1Pos) Example of how to Reverse rotation of servo motor
//setServoPos(servo1,servo1Pos,servoSpeed,servoEOPC);
//setServoPos(servo2,servo2Pos,servoSpeed,servoEOPC);
//setServoPos(servo3,servo3Pos,servoSpeed,servoEOPC);
//setServoPos(servo4,servo4Pos,servoSpeed,servoEOPC);
//setServoPos(servo5,servo5Pos,servoSpeed,servoEOPC);//Uncomment for 5 servo arm setup
//setServoPos(servo6,servo6Pos,servoSpeed,servoEOPC);//Uncomment for 6 servo arm setup

 
}//END OF MAIN LOOP



//********************************************************************************************************
//************************************* CUSTOM FUNCTIONS *************************************************
//********************************************************************************************************

//move servo motors to new positions 
void setServoPos(Servo servoX,int targetPosition, int speedX, char servoEOPCX){
    if (servoEOPCX != servoEOPC){
       return;
    }
    if (servoX.read()==targetPosition){
       return;
    }
    if (servoX.read() < targetPosition){
      servoX.write(servoX.read()+1);
      delay(speedX);
      return;
    }

    if (servoX.read() > targetPosition){
      servoX.write(servoX.read()-1);
      delay(speedX);
      return;
    }
}
