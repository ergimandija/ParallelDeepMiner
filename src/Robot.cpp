#include "Robot.h"

Robot::Robot(std::unique_ptr<IController> controller, int xBorder, int yBorder)
{
    _xBorder = xBorder;
    _yBorder  = yBorder;
    _controller = std::move(controller);
    _points = 0;
    //_canDismantle = true;
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



void Robot::setPosition(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields,int y,int x){
    _x=x;
    _y=y;
    if (fields[y][x].empty()) {
        _z = 0;
    } else {
        _z=static_cast<int>(fields[y][x].size()-1);
    }

}

void Robot::moveLeft(){
    if(_y>0){
    _y-=1;
    }
}
void Robot::moveRight(){
    if(_y<_yBorder-1){
    _y+=1;
    }
}
void Robot::moveForward(){
    if(_x>0){
    _x-=1;
    }
}
void Robot::moveBackward(){
    if(_x<_xBorder-1){
    _x+=1;
    }
}


void Robot::move(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields){

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
    case '.':
        break;

    }

     int colSize = static_cast<int>(fields[_y][_x].size());
    _z = (colSize > 0) ? colSize - 1 : 0;
}



int Robot::getPoints(){
    return _points;
}
