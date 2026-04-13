#include "World.h"

World::World(int xLimit, int yLimit, int zLimit)
{
    _fields.resize(xLimit);

    for(int x=0;x<5;x++){

        _fields[x].resize(yLimit);

        for(int y=0;y<5;y++){

                _fields[x][y].resize(zLimit);

            for(int z=0;z<10;z++){
                _fields[x][y][z] = std::make_unique<Field>((rand()%9)+1);
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
