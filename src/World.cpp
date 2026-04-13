#include "World.h"

World::World()
{
    _fields.resize(9);

    for(int z=0;z<9;z++){

        _fields[z].resize(5);

        for(int y=0;y<5;y++){

                _fields[z][y].resize(5);

            for(int x=0;x<5;x++){
                _fields[z][y][x] = std::make_unique<Field>((rand()%9)+1);
            }
        }
    }

}

World::~World()
{
    //dtor
}


void World::showWorld(){

    for(const auto& fieldList2D :  _fields){
            std::cout << "---------------------" << std::endl;
            for(const auto& fieldList: fieldList2D){
                    for(const auto& field: fieldList){
                        std::cout << field->getValue();
                    }
                   std::cout << std::endl;
            }
    }
}
