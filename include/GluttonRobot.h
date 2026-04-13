#ifndef GLUTTONROBOT_H
#define GLUTTONROBOT_H
#include "Robot.h"

class GluttonRobot: public Robot
{
    public:
        GluttonRobot(IController& controller);
        virtual ~GluttonRobot();
        void dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields) override;

    protected:

    private:
};

#endif // GLUTTONROBOT_H
