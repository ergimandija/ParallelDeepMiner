#ifndef COMMUNISTROBOT_H
#define COMMUNISTROBOT_H
#include "Robot.h"

class CommunistRobot: public Robot
{
    public:
        CommunistRobot(std::unique_ptr<IController> controller);
        virtual ~CommunistRobot();
        //void dismantle() override;
    protected:

    private:
};

#endif // COMMUNISTROBOT_H
