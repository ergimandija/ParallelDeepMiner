#include "SorterRobot.h"

SorterRobot::SorterRobot(std::unique_ptr<IController> controller): Robot(std::move(controller))
{
    //ctor
}

SorterRobot::~SorterRobot()
{
    //dtor
}


 void SorterRobot::dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields){


 }
