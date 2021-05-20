#ifndef CONTROLCAR
#define CONTROLCAR

class Car
{
    private: 

    public:
        int in1;
        int in2;
        int in3;
        int in4;
        int speed;
        void motorsSetup(const int pin1, const int pin2, const int pin3, const int pin4, int Speed);
        void forwardDrive();
        void backwardDrive();
        void rightTurn();
        void leftTurn();
        void stopDrive();
};

#endif