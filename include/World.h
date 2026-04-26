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
#include <thread>
#include <mutex>
#include <chrono>

class World
{
    public:
        World();
        World(int ySize, int xSize);
        virtual ~World();
        void renderWorld();
        int getMaxHeight();
        void executeRobot(Robot* robot, std::mutex& m);
        void createRobots();
        void spawnRobots();
        void displayPoints();
        RobotType selectRobot();
        bool isEmpty();
        int getMaxRobotHeight();
        int getPointSum() const;
        int getMinedPoints() const;
        void digField(std::mutex& m);

    protected:

    private:


        int _ySize;
        int _xSize;
        int _sum;
        int _minedPoints;
        std::vector<std::vector<std::vector<std::unique_ptr<Field>>>> _fields;
        std::vector<Robot*> _robots;

};

#endif // WORLD_H
