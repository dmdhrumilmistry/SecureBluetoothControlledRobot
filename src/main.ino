//Modied By ProfessorHulk And dmdhrumilmistry
//The One and Only Smasher Tech (TOAOST)
//Install AFMotor.h library before uploading code to Arduino Board

#include <AFMotor.h>

//initial motors pin
AF_DCMotor M1(1, MOTOR12_1KHZ); //M1 for Motor 1
AF_DCMotor M2(2, MOTOR12_1KHZ); //M1 for Motor 2
AF_DCMotor M3(3, MOTOR34_1KHZ); //M1 for Motor 3 
AF_DCMotor M4(4, MOTOR34_1KHZ); //M1 for Motor 4

String command; 
String passwd = "mypassword";



void forward()
{
  M1.setSpeed(255); //Define maximum velocity
  M1.run(FORWARD); //rotate the motor clockwise
  M2.setSpeed(255); //Define maximum velocity
  M2.run(FORWARD); //rotate the motor clockwise
  M3.setSpeed(255);//Define maximum velocity
  M3.run(FORWARD); //rotate the motor clockwise
  M4.setSpeed(255);//Define maximum velocity
  M4.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  M1.setSpeed(255); //Define maximum velocity
  M1.run(BACKWARD); //rotate the motor anti-clockwise
  M2.setSpeed(255); //Define maximum velocity
  M2.run(BACKWARD); //rotate the motor anti-clockwise
  M3.setSpeed(255); //Define maximum velocity
  M3.run(BACKWARD); //rotate the motor anti-clockwise
  M4.setSpeed(255); //Define maximum velocity
  M4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  M1.setSpeed(255); //Define maximum velocity
  M1.run(BACKWARD); //rotate the motor anti-clockwise
  M2.setSpeed(255); //Define maximum velocity
  M2.run(BACKWARD); //rotate the motor anti-clockwise
  M3.setSpeed(255); //Define maximum velocity
  M3.run(FORWARD);  //rotate the motor clockwise
  M4.setSpeed(255); //Define maximum velocity
  M4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  M1.setSpeed(255); //Define maximum velocity
  M1.run(FORWARD); //rotate the motor clockwise
  M2.setSpeed(255); //Define maximum velocity
  M2.run(FORWARD); //rotate the motor clockwise
  M3.setSpeed(255); //Define maximum velocity
  M3.run(BACKWARD); //rotate the motor anti-clockwise
  M4.setSpeed(255); //Define maximum velocity
  M4.run(BACKWARD); //rotate the motor anti-clockwise
} 

void stop_motors()
{
  M1.setSpeed(0); //Define minimum velocity
  M1.run(RELEASE); //stop the motor when release the button
  M2.setSpeed(0); //Define minimum velocity
  M2.run(RELEASE); //rotate the motor clockwise
  M3.setSpeed(0); //Define minimum velocity
  M3.run(RELEASE); //stop the motor when release the button
  M4.setSpeed(0); //Define minimum velocity
  M4.run(RELEASE); //stop the motor when release the button
}


void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
  // command format
  // passwd/command/
  if(Serial.available() > 0){
    String recvd_passwd = Serial.readStringUntil('/');
    command = Serial.readStringUntil('/');
    stop_motors(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   

    if (recvd_passwd == passwd){
      if (command == "F")       forward();
      else if (command == "B")  back();
      else if (command == "L")  left();
      else if (command == "R")  right();
     } else {
      Serial.println("Invalid Passwd! " + recvd_passwd);
    } 
  }
}
