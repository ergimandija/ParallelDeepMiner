#ifndef ROBOT_H
#define ROBOT_H
#include "Field.h"
#include  "IController.h"
#include "PlayerController.h"
#include "AIController.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

enum RobotType {
    GLUTTON, SORTER, COMMUNIST
};


class Robot
{
    public:
        Robot(std::unique_ptr<IController> controller);
        virtual ~Robot();
        void move(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields);
        virtual void dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields);
        void moveLeft();
        void moveRight();
        void moveForward();
        void moveBackward();
        void setPosition(int z,int y,int x);
        int getXPosition();
        int getYPosition();
        int getZPosition();
        int getPoints();
    protected:
        int _x,_y,_z;
         int _points;
    private:
        std::unique_ptr<IController> _controller;


        RobotType _type;

};

#endif // ROBOT_H
