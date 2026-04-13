#include "SorterRobot.h"

SorterRobot::SorterRobot(IController& controller): Robot(controller)
{
    //ctor
}

SorterRobot::~SorterRobot()
{
    //dtor
}

void SorterRobot::dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields){
        std::vector<std::unique_ptr<Field>> column;


}
