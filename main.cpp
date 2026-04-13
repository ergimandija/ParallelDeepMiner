#include <iostream>
#include <ctime>
#include "World.h"
#include "PlayerController.h"
using namespace std;

int main()
{
    std::srand(std::time({}));
    World world(5,5,10);
    world.showWorld();
    IController&& controller = PlayerController();

    return 0;
}
