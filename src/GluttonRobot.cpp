#include "GluttonRobot.h"

GluttonRobot::GluttonRobot(std::unique_ptr<IController> controller): Robot(std::move(controller))
{
    //ctor
}

GluttonRobot::~GluttonRobot()
{
    //dtor
}


void GluttonRobot::dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields){
    _points += fields[_z][_y][_x]->mine();
    for(int i = 1; i <= 2 && _z + i < static_cast<int>(fields.size()); i++){
        _points += fields[_z + i][_y][_x]->getValue();
    }

}
