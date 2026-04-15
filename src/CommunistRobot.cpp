#include "CommunistRobot.h"

CommunistRobot::CommunistRobot(std::unique_ptr<IController> controller): Robot(std::move(controller))
{
    //ctor
}

CommunistRobot::~CommunistRobot()
{
    //dtor
}


void CommunistRobot::dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields){
        if(fields[_y][_x].empty()) return;
        _z = static_cast<int>(fields[_y][_x].size()) - 1;


        _points += fields[_y][_x][_z]->getValue();
        auto it = std::find_if(fields[_y][_x].rbegin() + 1, fields[_y][_x].rend(), [&fields,this](const std::unique_ptr<Field>& fieldA){
                                                        return fieldA->getValue() == fields[_y][_x][_z]->getValue();
                                                });
        if (it != fields[_y][_x].rend()) {
            _points += (*it)->getValue();
        }
        fields[_y][_x].pop_back();

}
