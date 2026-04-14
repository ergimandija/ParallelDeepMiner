#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <memory>
#include "Field.h"
#include "Robot.h"
#include "SorterRobot.h"
#include "GluttonRobot.h"
#include "CommunistRobot.h"
#include <iostream>
#include <random>
class World
{
    public:
        World();
        virtual ~World();
        void deleteLayer();
        void renderWorld();
        void mixColumn(int y, int x);
        void sortColumn(bool desc, int y, int x);
        void executeTurn();
        void createRobots();
        void spawnRobots();
        void displayPoints();
        int getAvailableLayerFields();
        RobotType selectRobot();
        ControllerType selectController();
        bool isEmpty();


    protected:

    private:
        std::vector<std::vector<std::vector<std::unique_ptr<Field>>>> _fields;
        bool _isEmpty;
        std::vector<std::unique_ptr<Robot>> _robots;

};

#endif // WORLD_H
