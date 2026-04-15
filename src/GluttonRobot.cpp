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
    if(fields[_y][_x].empty()) return;
    _z = static_cast<int>(fields[_y][_x].size()) - 1;

    int range = std::min(3,static_cast<int>(fields[_y][_x].size()));
    int sum = 0;

    if(range > 0){
    _points += fields[_y][_x][_z]->getValue();
    sum = std::accumulate(fields[_y][_x].rbegin()+1, fields[_y][_x].rbegin()+ range,0, [](int acc, const std::unique_ptr<Field>& f) {
        return acc + f->getValue();
    });
    _points +=sum;
    fields[_y][_x].pop_back();
    }

}
