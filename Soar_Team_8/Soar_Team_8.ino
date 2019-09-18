 /*                                                                     
,-.----.                                                            
\    /  \  ,-.----.       ,---,               .---.           .---. 
|   :    \ \    /  \    .'  .' `\            /. ./|          /. ./| 
|   |  .\ :;   :    \ ,---.'     \       .--'.  ' ;      .--'.  ' ; 
.   :  |: ||   | .\ : |   |  .`\  |     /__./ \ : |     /__./ \ : | 
|   |   \ :.   : |: | :   : |  '  | .--'.  '   \' . .--'.  '   \' . 
|   : .   /|   |  \ : |   ' '  ;  :/___/ \ |    ' '/___/ \ |    ' ' 
;   | |`-' |   : .  / '   | ;  .  |;   \  \;      :;   \  \;      : 
|   | ;    ;   | |  \ |   | :  |  ' \   ;  `      | \   ;  `      | 
:   ' |    |   | ;\  \'   : | /  ;   .   \    .\  ;  .   \    .\  ; 
:   : :    :   ' | \.'|   | '` ,/     \   \   ' \ |   \   \   ' \ | 
|   | :    :   : :-'  ;   :  .'        :   '  |--"     :   '  |--"  
`---'.|    |   |.'    |   ,.'           \   \ ;         \   \ ;     
  `---`    `---'      '---'              '---"           '---"   
 */

//phoebe, weiwen, devid, sharmayne_2019_SOAR CHALLENGE


#define RightDirectPin1 3 // Right Motor direction pin 1 to MODEL-X IN1 
#define RightDirectPin2 5 // Right Motor direction pin 2 to MODEL-X IN2  
#define LeftDirectPin1 6 // Left Motor direction pin 1 to MODEL-X IN3 
#define LeftDirectPin2 9 //Left Motor direction pin 1 to MODEL-X IN4

/*From left to right, connect to D3,A1-A5 ,D10*/
#define LFSensor_2 A2 
#define LFSensor_3 A3 
#define LFSensor_4 A4

#define RitzUp 50
#define RitzDown 180

#define SPEED 255 //motor in 

#include <Servo.h>
Servo ServoR;
Servo ServoL;


void setup() 
{
  pinMode(RightDirectPin1,OUTPUT); //left motor direction pin1 
  pinMode(RightDirectPin2,OUTPUT); //left motor direction pin2 
  pinMode(LeftDirectPin1,OUTPUT); //right motor direction Pin 1 
  pinMode(LeftDirectPin2,OUTPUT); //right motor direction Pin 2
  
  /*line follow sensors */ 
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(LFSensor_2,INPUT_PULLUP);
  pinMode(LFSensor_3,INPUT_PULLUP);
  pinMode(LFSensor_4,INPUT_PULLUP);
  pinMode(A5,INPUT_PULLUP);
  Serial.begin(115200);


  linetracking(255);

  ServoR.attach (12);
  ServoL.attach (13);

  delay(2000);
  RitzBoxAngle(RitzUp);
  delay(2000);
  RitzBoxAngle(RitzDown);
  delay(2000);

  MoveYuntilT(255);
  }

void SetMotorL(int signedPower){ // signed power from -255 to 255
  if(signedPower < 0){
    analogWrite(LeftDirectPin1, abs(signedPower));
    analogWrite(LeftDirectPin2, 0);
  }else{
    analogWrite(LeftDirectPin1, 0);
    analogWrite(LeftDirectPin2, abs(signedPower));
  }
}

void SetMotorR(int signedPower){ // signed power from -255 to 255
  if(signedPower < 0){
    analogWrite(RightDirectPin1, abs(signedPower));
    analogWrite(RightDirectPin2, 0);
  }else{
    analogWrite(RightDirectPin1, 0);
    analogWrite(RightDirectPin2, abs(signedPower));
  }
}

//SetMotorY for A3<500 cos SetMotorY menas both wheels go same direction meaning that robot will go forward
void SetMotorY(int signedPower){
  SetMotorL(signedPower);
  SetMotorR(signedPower);
}

//SetMotorZ for A3>500 cos SetMotorZ means both wheels go opposite direction meaning that robot will turn
void SetMotorZ(int signedPower){
  SetMotorL(signedPower);
  SetMotorR(-1*signedPower);
}

//A3>500 means red light on means NOT ON black line, A3<500 means red light ON black line


void linetracking(int spd){
 if (analogRead(A3) < 500) {
 SetMotorY(spd);
}
 else{
 SetMotorZ(spd);
}
}

//String debugstr = String(analogRead(A0)) + ", " + String(analogRead(A1)) + ", " + String(analogRead(A2)) + ", " + String(analogRead(A3)) + ", " + String(analogRead(A4)) + ", " + String(analogRead(A5));
//Serial.println(debugstr);

    

void RitzBoxAngle(int deg){
  ServoL.write(deg);
  ServoR.write(180-deg);
}

void MoveYuntilT(int spd){
  SetMotorY(spd);
  while (!(analogRead(A2) < 500 && analogRead(A3) < 500 && analogRead(A4) < 500)) {}
  SetMotorY(0);
  
}

void loop(){} 
  

/*
  SetMotorY(255);
  delay(1000);
  SetMotorY(-255);
  delay(1000);
  SetMotorY(0);
  delay(1000);

  SetMotorZ(255);
  delay(1000);
  SetMotorZ(-255);
  delay(1000);
  SetMotorZ(0);
  delay(1000);

  SetMotorR(255);
  delay(1000);
  SetMotorR(-255);
  delay(1000);
  SetMotorR(0);
  delay(1000);

  SetMotorL(255);
  delay(1000);
  SetMotorL(-255);
  delay(1000);
  SetMotorL(0);
  delay(1000);
 */
