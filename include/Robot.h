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
#include <numeric>
#include <mutex>

enum RobotType {
    GLUTTON, SORTER, COMMUNIST
};


class Robot
{
    public:
        Robot(std::unique_ptr<IController> controller,int xBorder,int yBorder);
        virtual ~Robot();
        void move(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields);
        virtual void dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields)=0;
        void searchEffect();
        void moveLeft();
        void moveRight();
        void moveForward();
        void moveBackward();
        void setPosition(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields,int y,int x);
        int getXPosition();
        int getYPosition();
        int getZPosition();
        int getPoints();
        void damage();
        bool isAlive();
    protected:

        int _x,_y,_z;
         int _points;
    private:
        int _xBorder, _yBorder;
        int _health;
        std::unique_ptr<IController> _controller;


};

#endif // ROBOT_H
