#include "World.h"


World::World()
{

    std::cout << "Give in  y-size of the world" << std::endl;
    std::cin  >> _ySize;
    std::cout << "Give in  x-size of the world" << std::endl;
    std::cin  >> _xSize;

    _sum = 0;
    _minedPoints = 0;
    _fields.resize(_ySize);
    for (int y = 0; y < _ySize; y++) {
        _fields[y].resize(_xSize);
        for (int x = 0; x < _xSize; x++) {
            for (int z = 0; z < 5; z++) {
                int fieldValue =  rand() % 9 + 1;
                _sum += fieldValue;
                _fields[y][x].push_back(std::make_unique<Field>(fieldValue));
            }
        }
    }
    std::cout << "Total sum of mineable values:" << _sum << std::endl;
}



World::~World()
{
    for(auto& robot: _robots){
        delete robot;
    }
}

int World::getMaxHeight(){
    int maxHeight = 0;
    for(int y=0; y<_ySize;y++){
        for(int x=0; x<_xSize;x++){
            maxHeight = std::max(maxHeight, static_cast<int>(_fields[y][x].size()));
        }
    }
    return maxHeight;

}


int World::getMaxRobotHeight(){
    int maxZ = 0;
    for(auto& robot : _robots){
            if(robot->getZPosition() > maxZ){
                maxZ = robot->getZPosition();
            }
    }
    return maxZ;
}

void World::renderWorld(){
    int maxHeight = this->getMaxHeight();
    int maxRobotHeight  =  this->getMaxRobotHeight();
    int height = (maxRobotHeight>maxHeight-1)? maxRobotHeight: maxHeight-1;
    for(int z=height;z>=0;z--){
       std::cout << "---------------------------------" <<  std::endl;
        for(int x=0;x<_xSize;x++){
            for(int y=0;y<_ySize;y++){
                bool robotHere = false;

                for(size_t i=0;i< _robots.size();i++){
                     const auto& robot = _robots[i];
                    if(robot->getXPosition() == x &&
                       robot->getYPosition() == y &&
                       robot->getZPosition() == z &&
                       robot->isAlive()){

                        std::cout << "#";
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



void World::createRobots(){
        for(int i=0;i<5;i++){
                    std::unique_ptr<IController> controller = std::make_unique<AIController>();
                        switch(selectRobot()){
                        case GLUTTON:
                            _robots.push_back(new GluttonRobot(std::move(controller),_xSize,_ySize));
                            std::cout << "creating glutton" << std::endl;
                            break;
                        case SORTER:
                            _robots.push_back(new SorterRobot(std::move(controller),_xSize,_ySize));
                            std::cout << "creating sorter" << std::endl;
                            break;
                        case COMMUNIST:
                            _robots.push_back(new CommunistRobot(std::move(controller),_xSize,_ySize));
                            std::cout << "you just created a communist :/" << std::endl;
                            break;
                        }

            }
        }





void World::spawnRobots(){
        for(const auto& robot: _robots){
                int y=rand()%_ySize;
                int x=rand()%_xSize;
            robot->setPosition(_fields,y,x);
            _minedPoints += _fields[y][x][robot->getZPosition()]->getValue();
            _fields[y][x].pop_back();
        }

}

void World::digField(std::mutex& m){
        std::vector<std::thread> workerThreads;
        for(auto& robot: _robots){
                workerThreads.push_back(std::thread(&World::executeRobot,this,robot,std::ref(m)));

        }

        for(auto& thread: workerThreads){
                thread.join();

        }

}


void World::exterMinateEnemiesOf(Robot* r){
        for(const auto& robot: _robots){
            if(robot != r
               && r->getXPosition() == robot->getXPosition()
               && r->getYPosition() == robot->getYPosition()
               && r->getZPosition() == robot->getZPosition()){
                robot->damage();


               }
        }

}
void World::executeRobot(Robot* robot, std::mutex& m){
        auto startTime = std::chrono::steady_clock::now();
        while(!this->isEmpty() && robot->isAlive()){
            m.lock();
            robot->move(_fields);
            this->exterMinateEnemiesOf(robot);
            robot->dismantle(_fields);
            //this->renderWorld();
            m.unlock();
        }
        auto endTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        m.lock();
        std::cout << "Robot/thread collected:" << robot->getPoints() << " points, and lasted: " << elapsedTime << "ms" << std::endl;
        m.unlock();
        _minedPoints+= robot->getPoints();
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


int World::getPointSum() const {
    return _sum;
}

int World::getMinedPoints() const {
    return _minedPoints;
}

