// set whatever pin you would like except pins 0 and 1

/********* Right *********/
const int RightMotorEnablePin =8;
const int RightForwardPin = 13;
const int RightBackPin =12;

/********* Left *********/
const int LeftMotorEnablePin = 2;
const int LeftForwardPin = 5;
const int LeftBackPin =6;

const int pingPin = 7;          /***********************************/

int state = 0; 

int counter = 0;

int QRE1113_Pin = 1; //connected to analog 0
//int OnTapeThreshold = 900; // your thresholds will be different
//int OffTapeThreshold = 900;
int onTape = 950;

void setup() {
/*** First part of the contest: we control the robot using an Android device ***/
  // pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(RightMotorEnablePin,HIGH);
  pinMode(RightForwardPin,OUTPUT);
  pinMode(RightBackPin,OUTPUT);
  pinMode(RightMotorEnablePin,OUTPUT);

  digitalWrite(LeftMotorEnablePin,HIGH);
  pinMode(LeftForwardPin,OUTPUT);
  pinMode(LeftBackPin,OUTPUT);
  pinMode(LeftMotorEnablePin,OUTPUT);
}

void loop() {
  /*** bluetooth ***/
  if (Serial.available()>0) {
    state = Serial.read();
  }
  if (state == '1') {
    Forward();
  }
  else if (state == '2') {
    TurnRight();
  }
  else if (state == '3') {
    Backward();
  }
  else if (state == '4') {
    TurnLeft();
  }

  delay(100);
  Stop();
  state = 0;
  
/*** Auto: Second part of the contest where the robot will control itself ***/ 
//  long duration, inches, cm;
//  pinMode(pingPin, OUTPUT);
//  digitalWrite(pingPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(pingPin, HIGH);
//  delayMicroseconds(5);
//  digitalWrite(pingPin, LOW);
//  
//  pinMode(pingPin, INPUT);
//  duration = pulseIn(pingPin, HIGH);
//  
//  inches = microsecondsToInches(duration);
//  cm = microsecondsToCentimeters(duration);
//  
//  Serial.print(inches);
//  Serial.print("in, ");
//  Serial.print(cm);
//  Serial.print("cm");
//  Serial.println();
//
//  if (inches < 2) {
//    Kill();
//  }
//  delay(100);

//  Forward();


//  static int PreviousTape,CurrentTape;
//  CurrentTape = analogRead(QRE1113_Pin);
  // uncomment the below line to see your tape values
//  Serial.println(CurrentTape);

//  int counter = 0;
//  int temp;
//  if (CurrentTape > OnTapeThreshold && PreviousTape < OffTapeThreshold){
////    Backward();
//    delay(500);
////    TurnLeft();
//    PreviousTape = CurrentTape;  
//    
//  }
//  else if(CurrentTape < OffTapeThreshold && PreviousTape > OnTapeThreshold){
//    Serial.println("OFF Tape");
////    Forward();
//    PreviousTape=CurrentTape;
//  }

//  if (CurrentTape >= 900) {
//    counter++;
//    if (counter < 3) {
//
//      Stop();
//      Backward();
//      delay(250);
//      TurnLeft();
//      delay(250);
//      Stop();
//    }
//    else {
//
//      TurnRight();
//      delay(1000);
//      counter = 0;
//    }
//      
//  }
//
//  else {
//    Forward();
//
//  }

}

void Stop() {
  digitalWrite(RightForwardPin,LOW);
  digitalWrite(RightBackPin,LOW);
  
  digitalWrite(LeftForwardPin,LOW);
  digitalWrite(LeftBackPin,LOW);
}

void Forward() {
  digitalWrite(RightForwardPin,HIGH); // pin 2 on the schematic
  digitalWrite(RightBackPin,LOW); // pin 7 on the schematic
  
  digitalWrite(LeftForwardPin,HIGH); // pin 2 on the schematic
  digitalWrite(LeftBackPin,LOW); // pin 7 on the schematic
}

void Backward () {
  digitalWrite(RightForwardPin,LOW);
  digitalWrite(RightBackPin,HIGH);
  
  digitalWrite(LeftForwardPin,LOW);
  digitalWrite(LeftBackPin,HIGH);
}

void TurnLeft () {
  digitalWrite(RightForwardPin,HIGH);
  digitalWrite(RightBackPin,LOW);
  
  digitalWrite(LeftForwardPin,LOW);
  digitalWrite(LeftBackPin,LOW);

//  analogWrite(RightForwardPin,127);
//  digitalWrite(RightBackPin,LOW);
//  
//  digitalWrite(LeftForwardPin,LOW);
//  analogWrite(LeftBackPin,127); 
}

void TurnRight () {
  digitalWrite(RightForwardPin,LOW);
  digitalWrite(RightBackPin,LOW); 
  
  digitalWrite(LeftForwardPin,HIGH); 
  digitalWrite(LeftBackPin,LOW); 
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void Kill(){
  Forward();
  delay(500);
  Backward();
  delay(500);
  Forward();
  delay(500);
  Backward();
  delay(500);
  Forward();
  delay(500);
  Backward();
  delay(500);
  Forward();
  
  return;
}
