#include "CommunistRobot.h"

CommunistRobot::CommunistRobot(std::unique_ptr<IController> controller): Robot(std::move(controller))
{
    //ctor
}

CommunistRobot::~CommunistRobot()
{
    //dtor
}


void CommunistRobot::dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields) {

}
