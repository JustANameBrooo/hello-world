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


#define speedPinR 3 // RIGHT PWM pin connect MODEL-X ENA 
#define RightDirectPin1 4 // Right Motor direction pin 1 to MODEL-X IN1 
#define RightDirectPin2 2 // Right Motor direction pin 2 to MODEL-X IN2 
#define speedPinL 6 // Left PWM pin connect MODEL-X ENB 
#define LeftDirectPin1 7 // Left Motor direction pin 1 to MODEL-X IN3 
#define LeftDirectPin2 5 //Left Motor direction pin 1 to MODEL-X IN4

/*From left to right, connect to D3,A1-A5 ,D10*/
#define LFSensor_2 A2 
#define LFSensor_3 A3 
#define LFSensor_4 A4

#define SPEED 255 //motor in 


void setup() 
{
  pinMode(speedPinL,OUTPUT); //left motor PWM pin 
  pinMode(speedPinR,OUTPUT); //rignt motor PWM pin 
  pinMode(RightDirectPin1,OUTPUT); //left motor direction pin1 
  pinMode(RightDirectPin2,OUTPUT); //left motor direction pin2 
  pinMode(LeftDirectPin1,OUTPUT); //right motor direction Pin 1 
  pinMode(LeftDirectPin2,OUTPUT); //right motor direction Pin 2
  
  /*line follow sensors */ 
  pinMode(LFSensor_2,INPUT); 
  pinMode(LFSensor_3,INPUT); 
  pinMode(LFSensor_4,INPUT); 
  Serial.begin(115200);
}


void loop()
{
  String debugstr = String(analogRead(LFSensor_2)) + " - " + String(analogRead(LFSensor_3)) + " - " + String(analogRead(LFSensor_4));
  Serial.println(debugstr);
}
