#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <random>
#include <memory>
#include "Field.h"
#include "Robot.h"
#include "SorterRobot.h"
#include "GluttonRobot.h"
#include "CommunistRobot.h"
#include <iostream>
#include <algorithm>


class World
{
    public:
        World();
        World(int ySize, int xSize);
        virtual ~World();
        void renderWorld();
        int getMaxHeight();
        void executeTurn();
        void createRobots();
        void spawnRobots();
        void displayPoints();
        RobotType selectRobot();
        bool isEmpty();
        int getMaxRobotHeight();


    protected:

    private:
        int _ySize;
        int _xSize;
        int _sum;
        std::vector<std::vector<std::vector<std::unique_ptr<Field>>>> _fields;
        std::vector<std::unique_ptr<Robot>> _robots;

};

#endif // WORLD_H
