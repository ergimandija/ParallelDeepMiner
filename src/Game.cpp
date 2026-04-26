#include "Game.h"

Game::Game()
{

    _isFinished = false;
}

Game::~Game()
{

}

void Game::start() {
     auto startTime = std::chrono::steady_clock::now();
    _world.createRobots();
    _world.spawnRobots();
    _world.renderWorld();
    std::mutex m;
    _world.digField(m);
        //_world.executeTurn();
        //system("cls");
       // _world.renderWorld();
        if(_world.isEmpty()){
            auto endTime = std::chrono::steady_clock::now();
            _world.renderWorld();
            std::cout << "Game is Finished!" << std::endl;
            _isFinished = true;
            std::cout << "Max Points:" << _world.getPointSum() << std::endl;
            std::cout << "Mined Points: " << _world.getMinedPoints() << std::endl;
             auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        m.lock();
            std::cout << "Runtime: " << elapsedTime << "ms" << std::endl;
        }
        //_world.displayPoints();




}

