#include <iostream>
#include <ctime>
#include "World.h"
#include "PlayerController.h"
using namespace std;

int main()
{
    std::srand(std::time({}));
    World world;
    world.showWorld();

    return 0;
}
