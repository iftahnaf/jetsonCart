/*
Code Name: Arduino Bluetooth Control Car 
Code URI: https://circuitbest.com/category/arduino-projects/
Author: Make DIY
Author URI: https://circuitbest.com/author/admin/
Description: This program is used to control a robot using a app
that communicates with Arduino through a bluetooth module.
App URI: https://bit.ly/2BlMAea
Version: 1.0
License: Remixing or Changing this Thing is allowed. Commercial use is not allowed.
*/

#define in1 5 //L298n Motor Driver pins.
#define in2 6
#define in3 10
#define in4 11

int command; //Int to store app command state.                                                                                                                                                                                                   
int Speed = 75; // 0 - 255.
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0; //Set the radius of a turn, 0 - 255 Note:the robot will malfunction if this is higher than int Speed.
int brakeTime = 45;
int brkonoff = 1; //1 for the electronic braking system, 0 for normal.

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Stop();
}

void loop() {
  
  Stop();
}

void forward() {
  analogWrite(in1, Speed);
  analogWrite(in2, 0);
  analogWrite(in3, Speed);
  analogWrite(in4, 0);
}

void back() {
  analogWrite(in1, 0);
  analogWrite(in2, Speed);
  analogWrite(in3, 0);
  analogWrite(in4, Speed);
}

void right() {
  analogWrite(in1, 0);
  analogWrite(in3, Speed);
  analogWrite(in2, Speed);
  analogWrite(in4, 0);
}

void left() {
  analogWrite(in4, Speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in1, Speed);
}
void forwardleft() {
  analogWrite(in1, Speedsec);
  analogWrite(in3, Speed);
}
void forwardright() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speedsec);
}
void backright() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speedsec);
}
void backleft() {
  analogWrite(in2, Speedsec);
  analogWrite(in4, Speed);
}

void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

void brakeOff() {
}
