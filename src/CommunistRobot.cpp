#include "CommunistRobot.h"

CommunistRobot::CommunistRobot(std::unique_ptr<IController> controller, int xBorder, int yBorder): Robot(std::move(controller), xBorder, yBorder)
{
    //ctor
}

CommunistRobot::~CommunistRobot()
{
    //dtor
}


void CommunistRobot::dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields)
{
    if(fields[_y][_x].empty()) return;
    int colSize = static_cast<int>(fields[_y][_x].size());
    _z = (colSize > 0) ? colSize - 1 : 0;


    _points += fields[_y][_x][_z]->getValue();
    auto rit = std::find_if(fields[_y][_x].rbegin() + 1, fields[_y][_x].rend(), [&fields,this](const std::unique_ptr<Field>& fieldA)
    {
        return fieldA->getValue() == fields[_y][_x][_z]->getValue();
    });
    if (rit != fields[_y][_x].rend())
    {

        _points += (*rit)->getValue();
        auto it = rit.base();
        --it;
        fields[_y][_x].erase(it);
    }
    _z = static_cast<int>(fields[_y][_x].size()) - 1;
    fields[_y][_x].pop_back();

}
