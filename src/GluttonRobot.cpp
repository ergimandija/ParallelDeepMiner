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


 }
