#ifndef GAME_H
#define GAME_H
#include "World.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void start();


    protected:

    private:
        World _world;
        bool _isFinished;
};

#endif // GAME_H
