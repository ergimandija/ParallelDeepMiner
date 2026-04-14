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
        World();
        virtual ~World();
        void deleteLayer();
        void renderWorld();
        void mixPairs();
        void sortPairs();
        void executeTurn();
        void createRobots();
        void spawnRobots();
        void displayPoints();
        int getAvailableLayerFields();
        RobotType selectRobot();
        bool isEmpty();


    protected:

    private:
        std::vector<std::vector<std::vector<std::unique_ptr<Field>>>> _fields;
        bool _isEmpty;
        std::vector<std::unique_ptr<Robot>> _robots;

};

#endif // WORLD_H
