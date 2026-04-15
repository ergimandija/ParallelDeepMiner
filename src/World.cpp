#include "World.h"

World::World()
{
    _fields.resize(5);
    for (int y = 0; y < 5; y++) {
        _fields[y].resize(5);
        for (int x = 0; x < 5; x++) {
            for (int z = 0; z < 10; z++) {

                _fields[y][x].push_back(std::make_unique<Field>(rand() % 9 + 1));
            }
        }
    }
}



World::~World()
{
    //dtor
}

int World::getMaxHeight(){
    int maxHeight = 0;
    for(int y=0; y<5;y++){
        for(int x=0; x<5;x++){
            maxHeight = std::max(maxHeight, static_cast<int>(_fields[y][x].size()));
        }
    }
    return maxHeight;

}

void World::renderWorld(){
    int maxHeight = this->getMaxHeight();
    for(int z=maxHeight-1;z>=0;z--){
       std::cout << "---------------------------------" <<  std::endl;
        for(int x=0;x<5;x++){
            for(int y=0;y<5;y++){
                bool robotHere = false;

                for(size_t i=0;i< _robots.size();i++){
                     const auto& robot = _robots[i];
                    if(robot->getXPosition() == x &&
                       robot->getYPosition() == y &&
                       robot->getZPosition() == z){

                        std::cout << (i==0? "$" : "#");
                        robotHere = true;
                       }
                }
                if(!robotHere){
                if(z < static_cast<int>(_fields[y][x].size())){
                        std::cout <<  _fields[y][x][z]->getValue();
                } else {
                        std::cout << " ";
                }
                }

            }
            std::cout << std::endl;
        }
        std::cout <<  std::endl;
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

ControllerType World::selectController(){
        int input;
        while(true){
        std::cout << "Select the robot's controller: (0->AI, 1->Player)" << std::endl;
        std::cin >> input;
        if(input == 0 || input == 1){
            return static_cast<ControllerType>(input);
        }
        std::cout << "Input Invalid, try Again!" << std::endl;
        }

}



void World::createRobots(){
        for(int i=0;i<2;i++){
            switch(selectController()){
                case AI:
                        switch(selectRobot()){
                        case GLUTTON:
                            _robots.push_back(std::make_unique<GluttonRobot>(std::make_unique<AIController>()));
                            std::cout << "creating glutton" << std::endl;
                            break;
                        case SORTER:
                            _robots.push_back(std::make_unique<SorterRobot>(std::make_unique<AIController>()));
                            std::cout << "creating sorter" << std::endl;
                            break;
                        case COMMUNIST:
                            _robots.push_back(std::make_unique<CommunistRobot>(std::make_unique<AIController>()));
                            std::cout << "you just created a communist :/" << std::endl;
                            break;
                        }
                        break;
                case PLAYER:
                        switch(selectRobot()){
                        case GLUTTON:
                            _robots.push_back(std::make_unique<GluttonRobot>(std::make_unique<PlayerController>()));
                            std::cout << "creating glutton" << std::endl;
                            break;
                        case SORTER:
                            _robots.push_back(std::make_unique<SorterRobot>(std::make_unique<PlayerController>()));
                            std::cout << "creating sorter" << std::endl;
                            break;
                        case COMMUNIST:
                            _robots.push_back(std::make_unique<CommunistRobot>(std::make_unique<PlayerController>()));
                            std::cout << "you just created a communist :/" << std::endl;
                            break;
                        }
                        break;
            }



        }

}




void World::sortColumn(bool desc, int y, int x){

                if(!_fields[y][x].empty()){
                    std::sort(_fields[y][x].begin(),_fields[y][x].end(),[desc](std::unique_ptr<Field>& fieldA,std::unique_ptr<Field>& fieldB){
                                    if(desc){
                                    return fieldA->getValue() < fieldB->getValue();
                                    } else {
                                    return fieldA->getValue() > fieldB->getValue();
                                    }
                      });
                }



}


void World::mixColumn(int y, int x){
    if(!_fields[y][x].empty()){
        std::shuffle(_fields[y][x].begin(), _fields[y][x].end(),
                     std::mt19937{std::random_device{}()});
    }
}
void World::spawnRobots(){
        for(const auto& robot: _robots){
                int y=rand()%5;
                int x=rand()%5;
            robot->setPosition(_fields,y,x);
            _fields[y][x].pop_back();
        }

}

void World::executeTurn(){
        for(const auto& robot: _robots){

            robot->move(_fields);
            robot->dismantle(_fields);
            if (robot->getPoints() % 50 == 0) {

                for (int y = 0; y < 5; y++) {
                    for (int x = 0; x < 5; x++) {
                        switch (rand() % 3) {
                            case 0:
                                this->mixColumn(y, x);
                                break;

                            case 1:
                                this->sortColumn(false, y, x);
                                break;

                            case 2:
                                this->sortColumn(true, y, x);
                                break;
                        }
                    }
                }
            std::cout << "Board shuffled" << std::endl;
            }
        }

}


void World::displayPoints(){
    int counter=1;
        for(const auto& robot: _robots){
            std::cout <<"robot "<< counter << ": " << robot->getPoints() << std::endl;
            counter++;
        }
}



bool World::isEmpty() {
    for (const auto& plane : _fields) {
        for (const auto& column : plane) {
            if (!column.empty()) {
                return false;
            }
        }
    }
    return true;
}
