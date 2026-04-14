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
        _points += fields[_z][_y][_x]->mine();
        int blockValue = fields[_z][_y][_x]->getValue();
        // um self counting zu vermeiden
        _points -= blockValue;
        for(const auto& fieldList: fields[_z]){
            for(const auto& field: fieldList){
                if(field->getValue() == blockValue && !field->isMined()){
                    _points += blockValue;
                }
            }
        }

}
