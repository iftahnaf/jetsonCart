# JetsonCart - Jetson nano based autonomous car

## Table of contents
* [General info](#general-info)
* [Hardware](#hardware)
* [Mechanical design](#mechanical-design)
* [Software](#software)
* [Setup](#setup)
* [Launch](#launch)
* [Links](#links)


## General Info
JetsonCart is an autonomous car based on Nvidia Jetson nano. It can drive autonomous in-door by mapping the room and deciding which way to go based on servo-mounted distance sensor.
The low-level control - motors, distance sensor and servo done by an Arduino Uno.
The high-level control - mapping the room, generating the trajectory and navigate done by the Jetson nano.

![](https://user-images.githubusercontent.com/58637596/118992285-2a87c400-b98d-11eb-9c93-c4ace9f1630a.jpg)


## Hardware
* [x4 9v DC motors](https://www.amazon.com/ApplianPar-Shaft-Gearbox-Plastic-Arduino/dp/B086D5M65M/ref=sr_1_5?dchild=1&keywords=arduino+car+motor&qid=1621510784&sr=8-5)
* [L298N motor driver](https://www.amazon.com/Qunqi-2Packs-Controller-Stepper-Arduino/dp/B01M29YK5U/ref=sr_1_3?crid=3HAA8WN8KBEIQ&dchild=1&keywords=l298n&qid=1621510867&sprefix=L29%2Caps%2C347&sr=8-3)
* [SG90 servo motor](https://www.amazon.com/Smraza-Helicopter-Airplane-Control-Arduino/dp/B07L2SF3R4/ref=sr_1_1_sspa?dchild=1&keywords=servo+motor&qid=1621510890&sr=8-1-spons&psc=1&smid=AMIHZKLK542FQ&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyS0pOSU9ROFlBUUwzJmVuY3J5cHRlZElkPUEwOTQzOTEyM0sxWEJTOEhLRUcxQyZlbmNyeXB0ZWRBZElkPUEwMzI1MTA5MUFXNEtIUFJQUlZZMSZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=)
* [HC-SR04 ultrasonic distance sensor](https://www.amazon.com/Smraza-Ultrasonic-Distance-Mounting-Duemilanove/dp/B01JG09DCK/ref=sr_1_1_sspa?dchild=1&keywords=ultrasonic+sensor&qid=1621510929&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExNVVKUzcyUlhMRjExJmVuY3J5cHRlZElkPUExMDA5ODQ0MzdNS05USjgzUkNYTiZlbmNyeXB0ZWRBZElkPUEwNDIyMDEyMjNLSDE1TkdLU0lJQSZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=)
* [3S1P 1000 mah LiPo battery](https://www.amazon.com/1000mAh-Airplane-Quadcopter-Helicopter-Multi-Motor/dp/B07TJW4SY9/ref=sr_1_5?dchild=1&keywords=1000mah+3s1p+11.v+lipo&qid=1621510990&sr=8-5)
* [Arduino Uno](https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/ref=sr_1_3?dchild=1&keywords=arduino+uno&qid=1621511012&sr=8-3)
* [Jetson nano](https://www.amazon.com/NVIDIA-Jetson-Nano-Developer-945-13541-0000-000/dp/B08J157LHH/ref=sr_1_4?dchild=1&keywords=jetson+nano&qid=1621511032&sr=8-4)

## Mechanical design
![](https://user-images.githubusercontent.com/58637596/119221207-dc8ecf80-baf6-11eb-8cb1-7f8218945035.jpg)

STL files are located within /include/stl_files. Printed by Ender3 printer with default settings.

## Software
Low-level control developed using PlatformIO extension for VSC. Communication between Ardunio and Jetson nano based on rosserial package and the code written in C++ (src/main.cpp).
High-level control node created using Simulink with ROS Toolbox. Code generated files on the node exist in /include folder.

## Setup
### Arduino setup
1. Connect the Arduino to the PC.
2. Open VSC and download the nessesery Arduino package from PlatformIO extension.
3. Open src/main.cpp from VSC and upload the code to the Arduino.
4. Wiring setup are within the `main.cpp`.

### Jetson nano setup
1. Install the latest JetPack (4.5).
2. Install ROS-Melodic.
3. Install rosserial package.

## Launch
### Launch from Simulink
1. From Matlab, open jetsonCart.slx.
2. Verify that the ROS network setup is correct - `ROS_MASTER_URI` should be the Jetson nano address.
3. On Jetson nano - initiate roscore and rosserial node.
4. Run the Simulink model.

### Launch as standalone node
1. Build the generated node placed in /include/jetsonCart_nodeGen on the Jetson nano.
2. On Jetson nano - initiate roscore and rosserial node.
3. Run the generated node using rosrun.

## Links
* [ROS Wiki](http://wiki.ros.org/ROS/Introduction)
* [Getting started with Jetson nano](https://developer.nvidia.com/embedded/learn/get-started-jetson-nano-2gb-devkit)
* [rosserial](http://wiki.ros.org/rosserial)
* [PlatformIO](https://platformio.org/)
* [Generate ROS node from Simulink](https://www.mathworks.com/help/ros/ug/generate-a-standalone-ros-node-from-simulink.html)


