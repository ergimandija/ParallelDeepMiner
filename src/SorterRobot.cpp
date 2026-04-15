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

          if(fields[_y][_x].empty()) return;
          _z = static_cast<int>(fields[_y][_x].size()) - 1;

         std::sort(fields[_y][_x].begin(),fields[_y][_x].end(),[](std::unique_ptr<Field>& fieldA,std::unique_ptr<Field>& fieldB){
                                    return fieldA->getValue() < fieldB->getValue();
                      });
         _points += fields[_y][_x][_z]->getValue();
         fields[_y][_x].pop_back();


}
