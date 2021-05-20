#include <Arduino.h>
#include "controlCar.h"

void Car::motorsSetup(const int pin1, const int pin2, const int pin3, const int pin4, int Speed){
    in1 = pin1;
    in2 = pin2;
    in3 = pin3;
    in4 = pin4;
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    speed  =  Speed;
} 

void Car::forwardDrive () {
    analogWrite(in1, speed);
    analogWrite(in2, 0);
    analogWrite(in3, speed);
    analogWrite(in4, 0);
    
}
void Car::backwardDrive () {
    analogWrite(in1, 0);
    analogWrite(in2, speed);
    analogWrite(in3, 0);
    analogWrite(in4, speed);
}
void Car::leftTurn () {
    analogWrite(in4, speed);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in1, speed);
}
void Car::rightTurn () {
    analogWrite(in1, 0);
    analogWrite(in3, speed);
    analogWrite(in2, speed);
    analogWrite(in4, 0);
}
void Car::stopDrive() {
    analogWrite(in1, 0);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, 0);
}