#ifndef ROBOT_H
#define ROBOT_H
#include "Field.h"
#include  "IController.h"
#include <iostream>
#include <vector>
#include <memory>

enum RobotType {
    GLUTTON, SORTER, COMMUNIST
};


class Robot
{
    public:
        Robot(IController& controller);
        virtual ~Robot();
        void move();
        virtual void dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields)=0;
        void moveLeft();
        void moveRight();
        void moveForward();
        void moveBackward();
        void setPosition(int x,int y,int z);
        int getXPosition();
        int getYPosition();
        int getZPosition();
    protected:
        int _x,_y,_z;
    private:
        IController& _controller;

        int _points;
        RobotType _type;

};

#endif // ROBOT_H
