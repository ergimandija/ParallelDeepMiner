#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <memory>
#include "Field.h"
#include "Robot.h"
#include <iostream>

class World
{
    public:
        World(int xLimit, int yLimit, int zLimit);
        virtual ~World();
        void deleteLayer();
        void showWorld();
        void mixPairs();
        void sortPairs();
        void executeTurn();
        void spawnRobots();


    protected:

    private:
        std::vector<std::vector<std::vector<std::unique_ptr<Field>>>> _fields;
        bool _isFinished;
        std::vector<std::unique_ptr<Robot>> _robots;

};

#endif // WORLD_H
