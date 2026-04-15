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
        virtual ~World();
        void renderWorld();
        void mixColumn(int y, int x);
        int getMaxHeight();
        void sortColumn(bool desc, int y, int x);
        void executeTurn();
        void createRobots();
        void spawnRobots();
        void displayPoints();
        RobotType selectRobot();
        ControllerType selectController();
        bool isEmpty();


    protected:

    private:
        std::vector<std::vector<std::vector<std::unique_ptr<Field>>>> _fields;
        std::vector<std::unique_ptr<Robot>> _robots;

};

#endif // WORLD_H
