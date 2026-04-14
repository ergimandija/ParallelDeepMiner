#ifndef GLUTTONROBOT_H
#define GLUTTONROBOT_H
#include "Robot.h"

class GluttonRobot: public Robot
{
    public:
        GluttonRobot(std::unique_ptr<IController> controller);
        virtual ~GluttonRobot();
        //void dismantle() override;

    protected:

    private:
};

#endif // GLUTTONROBOT_H
