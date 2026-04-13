#include "Robot.h"

Robot::Robot(IController& controller): _controller(controller)
{
}

Robot::~Robot()
{
    //dtor
}


int Robot::getXPosition(){
    return _x;

}

int Robot::getYPosition(){
    return  _y;
}

int Robot::getZPosition(){
    return _z;
}

void Robot::setPosition(int x,int y,int z){
    _x=x;
    _y=y;
    _z=z;
}

void Robot::moveLeft(){
    _x-=1;
}
void Robot::moveRight(){
    _x+=1;
}
void Robot::moveForward(){
    _y-=1;
}
void Robot::moveBackward(){
    _y+=1;
}


void Robot::move(){
    switch(_controller.pickDirection()){
    case 'w':
        this->moveForward();
        break;
    case 's':
        this->moveBackward();
        break;
    case 'd':
        this->moveRight();
        break;
    case 'a':
        this->moveLeft();
        break;
    }
}
