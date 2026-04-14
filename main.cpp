#include <iostream>
#include <ctime>
#include "Game.h"
#include "PlayerController.h"
using namespace std;

int main()
{
    std::srand(std::time({}));
    Game game;
    game.start();

    return 0;
}
