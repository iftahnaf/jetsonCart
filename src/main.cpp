/* Wiring:
---- Ultrasonic: -----
VCC  -> 5V
Trig -> D2
Echo -> D4
GND  -> GND
---- Servo: ----
PWM -> D9
---- Motors: -----
in1 -> D5
in2 -> D6
in3 -> D10
in4 -> D11
*/
#include <Arduino.h>
#include "readSonar.h"
#include "controlCar.h"
#include <Servo.h>
#include <ros.h>
#include <NewPing.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h>
#include <string.h>
// pins connection
#define TRIG_PIN 2
#define ECHO_PIN 4
#define MAX_DISTNACE 1200
#define IN_1 5
#define IN_2 6
#define SERVO_PIN 9
#define IN_3 10
#define IN_4 11
// cart's state
#define STOP 0
#define SCAN 1
#define FORWARD 2
#define BACKWARD 3
#define RIGHT_TURN 4
#define LEFT_TURN 5

ros::NodeHandle nh;

sensor_msgs::Range range_msg;
ros::Publisher pub_range("/ultrasound", &range_msg);
sonar ultrasonic;
std_msgs::UInt16 servoPos;
ros::Publisher pub_pos("/servo", &servoPos);
Servo myservo;
Car cart;
std_msgs::String cmd;

char frameid[] = "/ultrasound";
int flag = 0;
int minAngle = 36;
int maxAngle = 136;
int scansNum = 0;
int counter = 0;
int pos = minAngle;

void rotServo(int &pos, int &flag, int minAngle, int maxAngle, Servo &myservo, std_msgs::UInt16 &servoPos, ros::Publisher &pub_pos, int &scansNum)
{
  if ((pos <= maxAngle) && flag == 0)
  {
    pos = pos + 2;
  }
  else
  {
    flag = 1;
    pos = pos - 2;
  }
  if (pos < minAngle)
  {
    flag = 0;
    pos = minAngle;
    scansNum++;
    char str [17];
    sprintf(str,"Complete %d scans", scansNum*2);
    nh.loginfo(str);
  }
  myservo.write(pos);
  servoPos.data = pos;
  pub_pos.publish(&servoPos);
}

void getRange(sensor_msgs::Range &range_msg, ros::Publisher &pub_range)
{
  float distance;
  long duritation;
  duritation = ultrasonic.timeTravel(ECHO_PIN, TRIG_PIN);
  distance = ultrasonic.microSecondsToCentimeters(duritation);
  range_msg.range = distance;
  range_msg.header.stamp = nh.now();
  pub_range.publish(&range_msg);
}

void setupRangeMessage(sensor_msgs::Range &range_msg)
{
  range_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
  range_msg.header.frame_id = frameid;
  range_msg.field_of_view = 75.0;
  range_msg.min_range = 0.0;
  range_msg.max_range = 1200.00;
}

void scanning (int &pos, int &flag, int minAngle, int maxAngle, Servo &myservo, std_msgs::UInt16 &servoPos, ros::Publisher &pub_pos, int &scansNum, sensor_msgs::Range &range_msg, ros::Publisher &pub_range) 
{
  rotServo(pos, flag, minAngle, maxAngle, myservo, servoPos, pub_pos, scansNum);
  getRange(range_msg, pub_range);
}

void commandsCB (const std_msgs::Int8& commands)
{
  if (commands.data == SCAN && scansNum < 5)
  {
    scanning(pos, flag, minAngle, maxAngle, myservo, servoPos, pub_pos, scansNum, range_msg, pub_range);
    cart.stopDrive();
    if (counter % 50 == 0)
    {
      nh.loginfo("Scanning...\n");
    }
  }
  if (scansNum == 6)
  {
    myservo.write((minAngle+maxAngle)/2);
  }
  if (commands.data == FORWARD)
  {
    cart.forwardDrive();
    getRange(range_msg, pub_range);
    myservo.write((minAngle+maxAngle)/2);
    pos = minAngle;
    if (counter % 5 == 0)
    {
      nh.loginfo("Driving forward...\n");
      scansNum = 0;
    }
  }
  if (commands.data == BACKWARD)
  {
    cart.backwardDrive();
    getRange(range_msg, pub_range);
    myservo.write((minAngle+maxAngle)/2);
    pos = minAngle;
    if (counter % 5 == 0)
    {
      nh.loginfo("Driving backward...\n");
      scansNum = 0;
    }
  }
  if (commands.data == RIGHT_TURN)
  {
    cart.rightTurn();
    getRange(range_msg, pub_range);
    myservo.write((minAngle+maxAngle)/2);
    pos = minAngle;
    if (counter % 5 == 0)
    {
      nh.loginfo("Turning right...\n");
      scansNum = 0;
    }
  }
  if (commands.data == LEFT_TURN)
  {
    cart.leftTurn();
    getRange(range_msg, pub_range);
    myservo.write((minAngle+maxAngle)/2);
    pos = minAngle;
    if (counter % 5 == 0)
    {
      nh.loginfo("Turning left...\n");
      scansNum = 0;
    }
  }
  if (commands.data == STOP) 
  {
    cart.stopDrive();
    myservo.write((minAngle+maxAngle)/2);
    pos = minAngle;
    if (counter % 20 == 0)
    {
      nh.loginfo("Braking....\n");
      scansNum = 0;
    }
  }
  counter++;
}

ros::Subscriber<std_msgs::Int8> sub_commands ("/commands", &commandsCB);

void setup()
{
  int speed = 50;
  nh.initNode();
  nh.subscribe(sub_commands);
  nh.advertise(pub_range);
  nh.advertise(pub_pos);
  setupRangeMessage(range_msg);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myservo.attach(SERVO_PIN);
  myservo.write(minAngle);
  cart.motorsSetup(IN_1,IN_2,IN_3,IN_4,speed);
}

void loop()
{
  delay(5);
  nh.spinOnce();
}