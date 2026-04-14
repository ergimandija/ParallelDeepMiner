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
        std::vector<std::unique_ptr<Field>> column;
        for (int z = 0; z < static_cast<int>(fields.size()); z++) {
                column.push_back(std::move(fields[z][_y][_x]));
            }

        std::sort(column.begin(),column.end(),[](const std::unique_ptr<Field>& fieldA,const std::unique_ptr<Field>& fieldB){
                    return fieldA->getValue() > fieldB->getValue();
             });

        for (int z = 0; z < static_cast<int>(fields.size()); z++) {
                fields[z][_y][_x] = std::move(column[z]);
            }
        _points += fields[_z][_y][_x]->mine();

}
