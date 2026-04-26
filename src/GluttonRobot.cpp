#include "GluttonRobot.h"

GluttonRobot::GluttonRobot(std::unique_ptr<IController> controller, int xBorder, int yBorder): Robot(std::move(controller), xBorder, yBorder)
{
    //ctor
}

GluttonRobot::~GluttonRobot()
{
    //dtor
}


void GluttonRobot::dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields){
    if(fields[_y][_x].empty()) return;
    int colSize = static_cast<int>(fields[_y][_x].size());
    _z = (colSize > 0) ? colSize - 1 : 0;

    int range = std::min(2,static_cast<int>(fields[_y][_x].size()));
    int sum = 0;

    if(range > 0){
    _points += fields[_y][_x][_z]->getValue();
    fields[_y][_x].pop_back();
    sum = std::accumulate(fields[_y][_x].rbegin(), fields[_y][_x].rbegin()+ range-1,0, [&fields, this](int acc, const std::unique_ptr<Field>& f) {
        int returnVal = acc + f->getValue();
        fields[_y][_x].pop_back();
        return returnVal;
    });
    _points +=sum;

    }
     colSize = static_cast<int>(fields[_y][_x].size());
    _z = (colSize > 0) ? colSize : 0;

}
