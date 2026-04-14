#include "Game.h"

Game::Game(): _world()
{

}

Game::~Game()
{
    //dtor
}

void Game::start() {
    _world.createRobots();
    _world.spawnRobots();
    _world.renderWorld();


}
