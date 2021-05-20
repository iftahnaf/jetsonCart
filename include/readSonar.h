#ifndef READSONAR
#define READSONAR

class sonar
{
    private:
        long duritation;
        float distance;
    public:
        unsigned int pingSpeed = 50;
        unsigned long pingTimer;
        float microSecondsToCentimeters(long microseconds);
        long timeTravel(const int echoPin, const int trigPin);
        long getUltrasonicRangeCm(const int echoPin, const int trigPin);
        unsigned long rdPulseIn(int pin, int value, unsigned long timeout);
};
#endif