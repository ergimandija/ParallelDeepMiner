#include "Game.h"

Game::Game()
{

    _isFinished = false;
}

Game::~Game()
{
    //dtor
}

void Game::start() {
    _world.createRobots();
    _world.spawnRobots();
    _world.renderWorld();
    while(!_isFinished){

        _world.executeTurn();
        //system("cls");
        _world.renderWorld();
        if(_world.isEmpty()){
            std::cout << "Game is Finished!" << std::endl;
            _isFinished = true;
        }
        _world.displayPoints();
    }



}

