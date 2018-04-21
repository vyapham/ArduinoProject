#include <Servo.h> //servo library
Servo myservo;

int Echo = A4;  
int Trig = A5; 
int rightDistance = 0,leftDistance = 0,middleDistance = 0;

/*define logic control output pin*/
int in1=9;
int in2=8;
int in3=7;
int in4=6;
/*define channel enable output pins*/
int ENA=10;
int ENB=5;

int LED = 13;
volatile int state = LOW;

char getInput;

/*define forward function*/
void Forward()
{ 
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,LOW);//digital output
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("Forward");
}
/*define back function*/
void Backward() 
{
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("Back");
}
/*define left function*/
void Left()
{
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("Left");
}
/*define right function*/
void Right() 
{
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("Right");
}
/*define stop function*/
void Stop() {
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("Stop");
}
/* LED */
void stateChange() {
  state = !state;
  digitalWrite(LED,state);
}

/*put your setup code here, to run once*/
void setup() {
  Serial.begin(9600); //Open the serial port and set the baud rate to 9600
/*Set the defined pins to the output*/
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(LED,OUTPUT);
}
/*main function*/
void loop() {
  getInput = Serial.read();
  if (getInput == 'f') {
    Forward();
  }
  else if (getInput == 'b') {
    Backward();
  }
  else if (getInput == 'l') {
    Left();
  }
  else if (getInput == 'r') {
    Right();
  }
  else if (getInput == 's') {
    Stop();
  }
  else if (getInput == 'a') {
    stateChange();
  }


}
