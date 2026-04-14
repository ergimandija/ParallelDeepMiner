#include "Robot.h"

Robot::Robot(std::unique_ptr<IController> controller)
{
    _controller = std::move(controller);
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

void Robot::setPosition(int z,int y,int x){
    _x=x;
    _y=y;
    _z=z;
}

void Robot::moveLeft(){
    if(_x>0){
    _x-=1;
    }
}
void Robot::moveRight(){
    if(_x<5){
    _x+=1;
    }
}
void Robot::moveForward(){
    if(_y>0){
    _y-=1;
    }
}
void Robot::moveBackward(){
    if(_y<5){
    _y+=1;
    }
}


void Robot::move(){
    switch(_controller->pickDirection()){
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

void Robot::dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields){
    fields[_z][_y][_x]->mine();
}
