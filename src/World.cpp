#include "World.h"

World::World()
{
    _fields.resize(2);
    for(int z=0;z<2;z++){
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


void World::renderWorld(){

    for(int z=0; z< static_cast<int>(_fields.size()); z++){
            std::cout << "---------------------" << std::endl;
            for(int y=0; y< static_cast<int>(_fields[z].size());y++){
                    for(int x=0; x< static_cast<int>(_fields[z][y].size()); x++){
                        bool robotHere = false;

                        for (size_t i = 0; i < _robots.size(); i++) {
                            if (_robots[i]->getZPosition() == z &&
                                _robots[i]->getYPosition() == y &&
                                _robots[i]->getXPosition() == x) {

                                std::cout << (i == 0 ? "$" : "#");
                                robotHere = true;
                                break;
                            }
                        }

                        if (!robotHere) {
                            if (!_fields[z][y][x]->isMined()) {
                                std::cout << _fields[z][y][x]->getValue();
                            } else {
                                std::cout << " ";
                            }
                        }

                    }
                   std::cout << std::endl;
            }
    }
    if(static_cast<int>(_fields.size()) == 0){
            _isEmpty= true;
            std::cout << "All Fields have been Mined!" << std::endl;
       }
}

RobotType World::selectRobot(){
        int input;
        while(true){
        std::cout << "Select which kind of robot you want to spawn: (0->Glutton, 1->Sorter, 2->Communist)" << std::endl;
        std::cin >> input;
        if(input == 0 || input == 1 || input == 2){
            return static_cast<RobotType>(input);
        }
        std::cout << "Input Invalid, try Again!" << std::endl;
        }


}




void World::createRobots(){
        for(int i=0;i<2;i++){
            switch(selectRobot()){
            case GLUTTON:
                _robots.push_back(std::make_unique<Robot>(std::make_unique<PlayerController>()));
                std::cout << "creating glutton" << std::endl;
                break;
            case SORTER:
                _robots.push_back(std::make_unique<Robot>(std::make_unique<PlayerController>()));
                std::cout << "creating sorter" << std::endl;
                break;
            case COMMUNIST:
                _robots.push_back(std::make_unique<Robot>(std::make_unique<PlayerController>()));
                std::cout << "creating communist" << std::endl;
                break;
            }



        }

}



void World::spawnRobots(){
        for(const auto& robot: _robots){
            robot->setPosition(0,rand()%5,rand()%5);
        }

}

void World::executeTurn(){
        for(const auto& robot: _robots){

            robot->move(_fields);

        }
        if(this->getAvailableLayerFields()==0){
                this->deleteLayer();
            }
}

void World::deleteLayer(){

            _fields.erase(_fields.begin());




}
void World::displayPoints(){
    int counter=1;
        for(const auto& robot: _robots){
            std::cout <<"robot "<< counter << ": " << robot->getPoints() << std::endl;
            counter++;
        }
}

int World::getAvailableLayerFields(){
    int availableFieldCounter=0;
    for(const auto& rows: _fields[0]){
        for(const auto& field: rows){
            if(!field->isMined()){
                availableFieldCounter++;
            }
        }
    }
    return availableFieldCounter;
}

bool World::isEmpty(){
        return _isEmpty;
}
