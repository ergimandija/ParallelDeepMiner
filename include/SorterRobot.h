#ifndef SORTERROBOT_H
#define SORTERROBOT_H
#include "Robot.h"

class SorterRobot: public Robot
{
    public:
        SorterRobot(IController& controller);
        virtual ~SorterRobot();
        void dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields) override;
    protected:

    private:
};

#endif // SORTERROBOT_H
