#include "GluttonRobot.h"

GluttonRobot::GluttonRobot(IController& controller): Robot(controller)
{
    //ctor
}

GluttonRobot::~GluttonRobot()
{
    //dtor
}


void GluttonRobot::dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields){
    fields=fields;
}
