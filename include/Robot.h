#ifndef ROBOT_H
#define ROBOT_H
#include "Field.h"
#include  "IController.h"
#include "PlayerController.h"
#include "AIController.h"
#include <iostream>
#include <vector>
#include <memory>

enum RobotType {
    GLUTTON, SORTER, COMMUNIST
};


class Robot
{
    public:
        Robot(std::unique_ptr<IController> controller);
        virtual ~Robot();
        void move();
        virtual void dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields);
        void moveLeft();
        void moveRight();
        void moveForward();
        void moveBackward();
        void setPosition(int z,int y,int x);
        int getXPosition();
        int getYPosition();
        int getZPosition();
    protected:
        int _x,_y,_z;
    private:
        std::unique_ptr<IController> _controller;

        int _points;
        RobotType _type;

};

#endif // ROBOT_H
