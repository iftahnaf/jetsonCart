#include <Arduino.h>
#include <Ultrasonic.h>
#include "readSonar.h"



float sonar::microSecondsToCentimeters(long microseconds)
{
  // Sound travels at 1125 feet per second
  // or 29.386 microseconds per centimeter
  // This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  return microseconds / 29.387 / 2.0;
}

long sonar::timeTravel(const int echoPin, const int trigPin){
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //duration = 0.001;
  return duration;
}

// timeTravel uses delay function, which may interrupt the ros node. need to make another fucntion which read the sonar without delay..
long sonar::getUltrasonicRangeCm(const int echoPin, const int trigPin){
  int trigState = LOW; //state of trigPin
  unsigned long interval = 1; // interval in milliseconds at which trigPin turns on
  unsigned long previousMillis = 0; //microsecond at which the pin was last writen
  int duration;
  int distance; // cm measured

  unsigned long currentMillis = millis(); //time in milliseconds from which the code was started
	if (currentMillis-previousMillis > interval) { //check "blink without delay" code
		previousMillis = currentMillis;
		if (trigState == LOW){
			(trigState = HIGH);
		}
		else {
			(trigState = LOW);
		}
	}
	digitalWrite(trigPin,trigState);
	
	duration = pulseIn(echoPin,HIGH);
	distance = (duration/2) / 29.1;
  return distance;
}

unsigned long sonar::rdPulseIn(int pin, int value, unsigned long timeout) { // the following comments assume that we're passing HIGH as value. timeout is in milliseconds
    unsigned long now = micros();
    while(digitalRead(pin) == value) { // wait if pin is already HIGH when the function is called, but timeout if it never goes LOW
        if (micros() - now > (timeout*1000)) {
            return 0;
        }
    }

    now = micros(); // could delete this line if you want only one timeout period from the start until the actual pulse width timing starts
    while (digitalRead(pin) != value) { // pin is LOW, wait for it to go HIGH befor we start timing, but timeout if it never goes HIGH within the timeout period
        if (micros() - now > (timeout*1000)) { 
            return 0;
        }
    }

    now = micros();
    while (digitalRead(pin) == value) { // start timing the HIGH pulse width, but time out if over timeout milliseconds
        if (micros() - now > (timeout*1000)) {
            return 0;
        }
    }
    return micros() - now;
}